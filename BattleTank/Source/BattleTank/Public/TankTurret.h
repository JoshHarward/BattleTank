// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision")) // Makes the class avaliable in the components for a blueprint
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup) // sets the category in blueprint to be listed as 'Setup'
	float MaxDegreesPerSecond = 20; // sensible default
};
