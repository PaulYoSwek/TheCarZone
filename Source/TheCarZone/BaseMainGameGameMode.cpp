// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMainGameGameMode.h"

#include "EngineUtils.h"
#include "GamePlayerState.h"
#include "VehicleDatabase.h"
#include "Net/UnrealNetwork.h"

ABaseMainGameGameMode::ABaseMainGameGameMode()
{
	bUseSeamlessTravel = true;

	GetAllPlayerStarts();
}

UClass* ABaseMainGameGameMode::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	AGamePlayerState* game_player_state = InController->GetPlayerState<AGamePlayerState>();
 	
 	UVehicleDatabase* vehicle_database = GetGameInstance()->GetSubsystem<UVehicleDatabase>();
 	
 	const TEnumAsByte<VehicleID> id = game_player_state->GetVehicleData().ID;
 	
 	const TSubclassOf<APawn> my_vehicle = vehicle_database->GetVehiclePawnByID(id);

    GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Green, FString::Printf(TEXT("Vehicle:  %s"), *my_vehicle->GetName()));
 	
 	if(my_vehicle == nullptr)
 		return nullptr;
 		
 	UClass* final_class = my_vehicle.Get();

	return final_class;
}

AActor* ABaseMainGameGameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	if(AllPlayerStarts.Num() <= 0)
	{
		GetAllPlayerStarts();
	}
	
	APlayerStart* my_player_start;
	
	for(auto* ps : AllPlayerStarts)
	{
		my_player_start = ps;
	}

	AllPlayerStarts.Remove(my_player_start);
		
	return my_player_start;
}

void ABaseMainGameGameMode::GetAllPlayerStarts()
{
	AllPlayerStarts.Empty();

	if(GetWorld() == nullptr)
		return;
	
	for (TActorIterator<APlayerStart> It(GetWorld()); It; ++It)
	{
		APlayerStart* player_start = *It;
		if(player_start != nullptr)
			AllPlayerStarts.Add(player_start);
	}
}
