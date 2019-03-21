// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{ 
	Locked,
	Aiming,
	Reloading
};

 // Forward Declaration
class UTankBarrel;
class UTankTurret;

// Holds parameters for barrels properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector OutHitLocation, float LaunchSpeed);

protected:
	// Protected because it is being called by a subclass, the TankAimingComponent blueprint inside Unreal
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:	
	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

	UTankTurret* Turret = nullptr;
	void MoveTurretTowards(FVector AimDirection);
};
