// Andrew Sushko 2017

#include "BattleTank.h"
#include "Tank.h"


///Functions

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	//No need to protect pointers as added at constructor
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}


void ATank::BeginPlay()
{
	Super::BeginPlay();
}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}



void ATank::AimAt(FVector HitLocation)
{
	auto OurTankName = GetName();
	TankAimingComponent->AimingGeneral(HitLocation, OurTankName, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}
