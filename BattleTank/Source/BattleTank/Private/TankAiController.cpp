// Andrew Sushko 2017

#include "BattleTank.h"
#include "TankAiController.h"


///Functions
void ATankAiController::BeginPlay()
{
	Super::BeginPlay();



	return;
}

//Called Every Frame
void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetAiControlledTank())
	{
		if (GetPlayerTank())
		{
			//TODO Move Towards the Player

			//Aim Towards the Player
			GetAiControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

			//TODO Fire if Ready
		}
	}

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

