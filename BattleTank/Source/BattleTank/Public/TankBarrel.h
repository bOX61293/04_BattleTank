// Andrew Sushko 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	void Elevate(float DegreesPerSecond);
	

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20; //Sensible Default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 25;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;

};
