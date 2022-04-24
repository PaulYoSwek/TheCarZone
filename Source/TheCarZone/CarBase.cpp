// Fill out your copyright notice in the Description page of Project Settings.

#include "CarBase.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BillboardComponent.h"

ACarBase::ACarBase()
{
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RootComponent = Body;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Body);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	
	PrimaryActorTick.bCanEverTick = true;
}

void ACarBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACarBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

