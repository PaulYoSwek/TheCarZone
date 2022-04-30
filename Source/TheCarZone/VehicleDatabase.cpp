// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleDatabase.h"

void UVehicleDatabase::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	LoadDatabase();
}

void UVehicleDatabase::SetVehicleDatabase(UDataTable* VehicleDatabase)
{
	m_Database = VehicleDatabase;
}

TArray<FVehicleDataRow> UVehicleDatabase::GetAllVehiclesData()
{
	TArray<FVehicleDataRow> vehicle_data;
	
	if(IsValid(m_Database) == false)
	{
		return vehicle_data;
	}

	FString context_string;
	TArray<FName> RowNames = m_Database->GetRowNames();

	for (const auto& name : RowNames )
	{
		FVehicleDataRow* row = m_Database->FindRow<FVehicleDataRow>(name, context_string);
		if ( row )
		{
			vehicle_data.Add(*row);
		}
	}
	
	return vehicle_data;
}

TSubclassOf<AActor> UVehicleDatabase::GetVehiclePaperDollByID(TEnumAsByte<VehicleID> ID)
{
	if(IsValid(m_Database) == false)
	{
		return nullptr;
	}

	FString context_string;
	TArray<FName> RowNames = m_Database->GetRowNames();

	for (const auto& name : RowNames )
	{
		FVehicleDataRow* row = m_Database->FindRow<FVehicleDataRow>(name, context_string);
		if ( row->CommonVehicleDataRow.ID == ID )
		{
			return row->PaperDoll;
		}
	}
	
	return nullptr;
}

TSubclassOf<APawn> UVehicleDatabase::GetVehiclePawnByID(TEnumAsByte<VehicleID> ID)
{
	if(IsValid(m_Database) == false)
	{
		return nullptr;
	}

	FString context_string;
	TArray<FName> RowNames = m_Database->GetRowNames();

	for (const auto& name : RowNames )
	{
		FVehicleDataRow* row = m_Database->FindRow<FVehicleDataRow>(name, context_string);
		if ( row->CommonVehicleDataRow.ID == ID )
		{
			return row->Vehicle;
		}
	}
	
	return nullptr;
}

void UVehicleDatabase::LoadDatabase()
{
	m_Database = LoadObject<UDataTable>(nullptr, TABLE_VEHICLE_DATABASE);
}
