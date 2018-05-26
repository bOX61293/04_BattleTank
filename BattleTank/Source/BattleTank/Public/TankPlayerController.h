// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be the last include (Generated)

// Forward Declaration
class ATank;


UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	//Start the tank moving the barrel so that the show will hit towards the crosshair intersects the world
	void AimTowardsCrosshair();

	//Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	//Variables for Finding Crosshair Location
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0;
};
