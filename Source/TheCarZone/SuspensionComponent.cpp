// Fill out your copyright notice in the Description page of Project Settings.


#include "SuspensionComponent.h"

#include "ComponentUtils.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

USuspensionComponent::USuspensionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USuspensionComponent::BeginPlay()
{
	Super::BeginPlay();

	IsInitialized = InitializeSuspension();

}

bool USuspensionComponent::InitializeSuspension()
{
		
	VehicleBody = Cast<UStaticMeshComponent>(ComponentUtils::GetAttachedParent(this));

	auto* child_component = GetChildComponent(0);
	
	if(child_component == nullptr)
		return false;

	Wheel = Cast<UStaticMeshComponent>(child_component);

	FVector min;
	FVector max;
	
	Wheel->GetLocalBounds(min, max);

	Radius = ((max - min) / 2).Z;
	//Radius = 10;
	
	return true;
}

void USuspensionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(!IsInitialized)
		return;

	const FVector my_location = GetComponentLocation();
	
	TraceStartPosition = my_location;
	
	TraceEndPosition = TraceStartPosition + -GetUpVector() * MaxSuspension;

	FHitResult out_hit;
	InContact = UKismetSystemLibrary::SphereTraceSingleForObjects(GetWorld(), TraceStartPosition, TraceEndPosition, 10, ObjectsToTrace, false, ActorsToIgnore, EDrawDebugTrace::None, out_hit, true, FColor::Red, FColor::Green, 5.0f);

	const float distance = (out_hit.ImpactPoint - my_location).Length();
	
	if(InContact)
	{
		CurrentHover = MaxSuspension - distance;

		const float damping = (CurrentHover - LastHover) / DeltaTime * SuspensionDamping;
		const float force_amount = damping + CurrentHover * SuspensionStrength;
		const FVector final_force = out_hit.ImpactNormal * force_amount;

		VehicleBody->AddForceAtLocation(final_force, my_location);

		LastHover = CurrentHover;
	}

	const float suspension = InContact ? distance : MaxSuspension;
		
	WheelOffset = UKismetMathLibrary::FInterpTo(WheelOffset, (suspension - Radius) * -1, DeltaTime, 20.0f);
		
	Wheel->SetRelativeLocation(FVector(0, 0, WheelOffset));
}

