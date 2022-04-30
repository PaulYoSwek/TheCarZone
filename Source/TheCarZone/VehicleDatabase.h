// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CommonVehicleData.h"
#include "VehicleBase.h"
#include "AssetsPaths.h"

#include "VehicleDatabase.generated.h"


USTRUCT(BlueprintType)
struct FVehicleDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVehicleData CommonVehicleDataRow;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AVehicleBase> Vehicle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> PaperDoll;
};

UCLASS()
class THECARZONE_API UVehicleDatabase : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	public:
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	//This will have to be replaced to be done in C++
	//Is now getting called in MainMenu levelblueprint
	UFUNCTION(BlueprintCallable)
	void SetVehicleDatabase(UDataTable* VehicleDatabase);
	
	UFUNCTION(BlueprintCallable)
	TArray<FVehicleDataRow> GetAllVehiclesData();
	
	UFUNCTION(BlueprintCallable)
    TSubclassOf<AActor> GetVehiclePaperDollByID(TEnumAsByte<VehicleID> ID);

	UFUNCTION(BlueprintCallable)
	TSubclassOf<APawn> GetVehiclePawnByID(TEnumAsByte<VehicleID> ID);
	
	private:
	
	UPROPERTY()
	UDataTable* m_Database = nullptr;

	void LoadDatabase();
};
