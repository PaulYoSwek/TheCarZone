// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SuspensionComponent.generated.h"


UCLASS(BlueprintType)
class THECARZONE_API USuspensionComponent : public USceneComponent
{
	GENERATED_BODY()
	
public:	
	USuspensionComponent();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxSuspension = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SuspensionStrength = 90000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SuspensionDamping = 7000.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectsToTrace;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool InContact = false;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	bool InitializeSuspension();
	
	UPROPERTY()
	UStaticMeshComponent* VehicleBody;

	UPROPERTY()
	UStaticMeshComponent* Wheel;

	UPROPERTY()
	bool IsInitialized;

	UPROPERTY()
	float Radius;

	UPROPERTY()
	FVector TraceStartPosition;
	
	UPROPERTY()
	FVector TraceEndPosition;

	UPROPERTY()
	TArray<AActor*> ActorsToIgnore;

	UPROPERTY()
	float CurrentHover;
	
	UPROPERTY()
	float LastHover;

	UPROPERTY()
	float WheelOffset;
	
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
		
};
