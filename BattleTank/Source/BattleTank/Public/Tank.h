// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //Put new includes above

//Forward Declerations
class UTankBarrel;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAT(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	

	UPROPERTY(EditAnywhere, Category = "firing")
	float LaunchSpeed = 4000; // sensible starting value of 10000/ms

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBluePrint;
	
	float ReloadTimeInSeconds = 3;
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
	
};
