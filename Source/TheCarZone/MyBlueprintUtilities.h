// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintUtilities.generated.h"

/**
 * 
 */
UCLASS()
class THECARZONE_API UMyBlueprintUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, meta = (WorldContext = "inWorld", CompactNodeTitle = "LocalPC"))
	static APlayerController* GetLocalPlayerController(const UObject* inWorld);

	UFUNCTION(BlueprintPure, meta = (WorldContext = "inWorld", CompactNodeTitle = "LocalPlayerState"))
	static APlayerState* GetLocalPlayerState(const UObject* inWorld);

	UFUNCTION(BlueprintPure, meta = (WorldContext = "inWorld", CompactNodeTitle = "AllPlayerStates"))
	static TArray<APlayerState*> GetAllPlayerStates(const UObject* inWorld);
};
