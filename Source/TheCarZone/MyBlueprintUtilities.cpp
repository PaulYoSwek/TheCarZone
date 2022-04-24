// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintUtilities.h"

#include "GameFramework/GameState.h"

APlayerController* UMyBlueprintUtilities::GetLocalPlayerController(const UObject* inWorld)
{
	if(IsRunningDedicatedServer() == true)
	{
		return nullptr;
	}

	if(inWorld == nullptr)
	{
		return nullptr;
	}

	UWorld* world = inWorld->GetWorld();

	for (auto it = GEngine->GetLocalPlayerIterator(world); it; ++it)
	{
		ULocalPlayer* player = *it;
		if(player == nullptr)
		{
			continue;
		}

		APlayerController* controller = player->GetPlayerController(world);
		if(controller == nullptr || controller->IsLocalController() == false)
		{
			continue;
		}

		return controller;
	}
	
	return nullptr;
}

APlayerState* UMyBlueprintUtilities::GetLocalPlayerState(const UObject* inWorld)
{
	APlayerController* local_player_controller = GetLocalPlayerController(inWorld);
	if(local_player_controller == nullptr)
	{
		return nullptr;
	}
	
	return local_player_controller->PlayerState;
}

TArray<APlayerState*> UMyBlueprintUtilities::GetAllPlayerStates(const UObject* inWorld)
{
	
	if(inWorld == nullptr)
	{
		return TArray<APlayerState*>();
	}
	
	const UWorld* world = inWorld->GetWorld();
	
	return world->GetGameState()->PlayerArray;
}
