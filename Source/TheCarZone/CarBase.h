// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VehicleBase.h"

#include "CarBase.generated.h"

UCLASS(Blueprintable)
class THECARZONE_API ACarBase : public AVehicleBase
{
	GENERATED_BODY()

public:
	ACarBase();
	
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
