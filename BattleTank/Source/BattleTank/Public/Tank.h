// Copyright Joshua Harward
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new above this

// Forward declarations
class UTankBarrel;
class UTankTurret;
class UTankTrack;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:	
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;


	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 10000; // TODO find sensible default

	UPROPERTY(EditDefaultsOnly, Category = Firing) // EditDefaultsOnly only allows you to edit as a whole (all the tanks), whereas if it is EditAnywhere, you can edit tanks individually.
	float ReloadTimeInSeconds = 3;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; // TODO remove

	double LastFireTime = 0;
};
