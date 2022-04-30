// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerStart.h"
#include "BaseMainGameGameMode.generated.h"

/**
 * 
 */
UCLASS()
class THECARZONE_API ABaseMainGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

	ABaseMainGameGameMode();
	
	protected:
	
		virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

		virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	private:

	void GetAllPlayerStarts();
	
	UPROPERTY()
	TArray<APlayerStart*> AllPlayerStarts;
};
