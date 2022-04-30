// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonVehicleData.h"
#include "GameFramework/PlayerState.h"
#include "GamePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class THECARZONE_API AGamePlayerState : public APlayerState
{
	GENERATED_BODY()

	public:

	void SetVehicleData(FVehicleData inVehicleData);
	
	FVehicleData GetVehicleData();

	private:

	UPROPERTY(Replicated)
	FVehicleData VehicleData;
};
