// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


///Functions
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();



	return;
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();

	return;
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	//Get world location through the crosshair
	//If it hits the landscape
		//Tell controlled tank to aim at this point

	return;
}