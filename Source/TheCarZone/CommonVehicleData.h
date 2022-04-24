// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"

#include "CommonVehicleData.generated.h"

UENUM()
enum ECarType
{
	Tank      UMETA(DisplayName = "Tank"),
	Speed     UMETA(DisplayName = "Speed"),
	Support   UMETA(DisplayName = "Support"),
};


UENUM(BlueprintType)
enum VehicleID
{
	Tank1      UMETA(DisplayName = "TankHarry"),
	Speed1     UMETA(DisplayName = "SpeedyStevy"),
	Support1   UMETA(DisplayName = "SupportLans"),
	Tank2      UMETA(DisplayName = "SuperTanker"),
};

USTRUCT(BlueprintType)
struct FVehicleData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<VehicleID> ID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TEnumAsByte<ECarType> VehicleType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;

	//Add more common vehicle data here
};

class THECARZONE_API CommonVehicleData
{
public:
	CommonVehicleData();
	~CommonVehicleData();
	
};
