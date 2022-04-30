// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayerState.h"

#include "MenuPlayerState.h"
#include "Net/UnrealNetwork.h"

void AGamePlayerState::SetVehicleData(FVehicleData inVehicleData)
{
	VehicleData = inVehicleData;
}

FVehicleData AGamePlayerState::GetVehicleData()
{
	return VehicleData;
}

void AGamePlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGamePlayerState, VehicleData);
}

