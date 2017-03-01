// Andrew Sushko 2017

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAiController.generated.h"


UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank* GetAiControlledTank() const;
	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;
};
