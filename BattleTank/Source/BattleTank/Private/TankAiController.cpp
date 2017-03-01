// Andrew Sushko 2017

#include "BattleTank.h"
#include "TankAiController.h"


///Functions
void ATankAiController::BeginPlay()
{
	Super::BeginPlay();



	return;
}


ATank* ATankAiController::GetAiControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

