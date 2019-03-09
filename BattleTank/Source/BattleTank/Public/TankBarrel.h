// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision")) // Will hide the category 'Collission' when dev goes in to edit barrel in blueprint
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
		
private:
	UPROPERTY(EditAnywhere, Category = Setup) // sets the category in blueprint to be listed as 'Setup'
	float MaxDegreesPerSecond = 20; // sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;
};
