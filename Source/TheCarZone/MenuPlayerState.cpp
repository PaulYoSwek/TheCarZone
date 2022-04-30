// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerState.h"

#include "GamePlayerState.h"
#include "Net/UnrealNetwork.h"

void AMenuPlayerState::SetVehicleData(FVehicleData inVehicleData)
{
	VehicleData = inVehicleData;
	
	FString id_name = "none";

	if (VehicleData.ID.GetValue() == VehicleID::Tank1)
	{
		id_name = "TANK - BLUE";
	}

	if (VehicleData.ID.GetValue() == VehicleID::Speed1)
	{
		id_name = "TANK - RED";
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, FString::Printf(TEXT("Vehicle:  %s"), *id_name));
}

FVehicleData AMenuPlayerState::GetVehicleData()
{
	return VehicleData;
}

void AMenuPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMenuPlayerState, VehicleData);
}

void AMenuPlayerState::CopyProperties(APlayerState* PlayerState)
{
	Super::CopyProperties(PlayerState);

	AGamePlayerState* game_player_state = Cast<AGamePlayerState>(PlayerState);

	const FVehicleData vehicle_date = GetVehicleData();

	FString id_name = "none";

	if (vehicle_date.ID == VehicleID::Tank1)
	{
		id_name = "TANK - BLUE";
	}

	if (vehicle_date.ID.GetValue() == VehicleID::Speed1)
	{
		id_name = "TANK - RED";
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Red, FString::Printf(TEXT("Vehicle:  %s"), *id_name));
	
	game_player_state->SetVehicleData(vehicle_date);
}

