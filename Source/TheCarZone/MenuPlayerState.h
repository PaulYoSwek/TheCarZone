// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonVehicleData.h"
#include "GameFramework/PlayerState.h"
#include "MenuPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class THECARZONE_API AMenuPlayerState : public APlayerState
{
	GENERATED_BODY()

	public:
	
	UFUNCTION(BlueprintCallable)
	void SetVehicleData(FVehicleData inVehicleData);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVehicleData GetVehicleData();

	virtual void CopyProperties(APlayerState* PlayerState) override;
	
	UPROPERTY(Replicated, BlueprintReadonly)
	FVehicleData VehicleData;
};
