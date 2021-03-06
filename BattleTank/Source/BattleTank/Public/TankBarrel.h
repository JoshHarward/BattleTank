// Copyright Joshua Harward

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
	// -1 is max downward speed, and +1 is max up speed
	void Elevate(float RelativeSpeed);
		
private:
	UPROPERTY(EditAnywhere, Category = Setup) // sets the category in blueprint to be listed as 'Setup'
	float MaxDegreesPerSecond = 5; // sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;
};
