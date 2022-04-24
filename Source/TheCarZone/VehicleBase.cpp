// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleBase.h"

AVehicleBase::AVehicleBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void AVehicleBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVehicleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

