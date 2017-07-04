// Andrew Sushko 2017

#include "TankBarrel.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"

class UTankBarrel; //Forward declaration

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO Should this tick
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimingGeneral(FVector WorldSpaceAim, FString CurrentTankName, float LaunchSpeed)
{
	//Protect the pointers
	if (!Barrel)
	{
		return;
	}

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, WorldSpaceAim, LaunchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace)) //Calculate the OutLaunchVelocity
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveBarrelTowards(AimDirection);

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);
	}
	else
	{
		auto TimeNoSolution = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No aiming solution found"), TimeNoSolution);
	}
}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//Work out difference between current barrel and aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5); //TODO Remove magic number


	return;
}

