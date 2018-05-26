// Andrew Sushko 2017

#pragma once

#include "AIController.h"
#include "TankAiController.generated.h"

// Forward Declaration
class ATank;

UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank* GetAiControlledTank() const;
	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
