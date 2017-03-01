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


ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerPawn);
	}
}

