// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //Put new includes above

//Forward Declerations
class UTankAimingComponent;
class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAT(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

protected:

	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = firing)
	float LaunchSpeed = 4000; // sensible starting value of 10000/ms

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBluePrint;
	
	//Local Barrel
	UTankBarrel* Barrel = nullptr;

	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;
	
};
