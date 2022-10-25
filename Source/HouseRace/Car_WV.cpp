// Fill out your copyright notice in the Description page of Project Settings.


#include "Car_WV.h"
#include "HouseRaceWheelFront.h"
#include "HouseRaceWheelRear.h"
#include "WheeledVehicleMovementComponent4W.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"

#define LOCTEXT_NAMESPACE "VehilePawn"
PRAGMA_DISABLE_DEPRECATION_WARNINGS

ACar_WV::ACar_WV()
{
	// Car mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CarMesh(TEXT("/Game/Vehicle/Sedan/Sedan_SkelMesh.Sedan_SkelMesh"));
	GetMesh()->SetSkeletalMesh(CarMesh.Object);
	// Set car mesh animation
	static ConstructorHelpers::FClassFinder<UObject> AnimBPClass(TEXT("/Game/Vehicle/Sedan/Sedan_AnimBP"));
	GetMesh()->SetAnimInstanceClass(AnimBPClass.Class);
	//Simulation
	UWheeledVehicleMovementComponent4W* Vehicle4W = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovementComponent());
	check(Vehicle4W->WheelSetups.Num() == 4);

	// Wheel Setups
	Vehicle4W->WheelSetups[0].WheelClass = UHouseRaceWheelFront::StaticClass();
	Vehicle4W->WheelSetups[0].BoneName = FName("Wheel_Front_Left");
	Vehicle4W->WheelSetups[0].AdditionalOffset = FVector(0.f, -12.f, 0.f);

	Vehicle4W->WheelSetups[1].WheelClass = UHouseRaceWheelFront::StaticClass();
	Vehicle4W->WheelSetups[1].BoneName = FName("Wheel_Front_Right");
	Vehicle4W->WheelSetups[1].AdditionalOffset = FVector(0.f, 12.f, 0.f);

	Vehicle4W->WheelSetups[2].WheelClass = UHouseRaceWheelRear::StaticClass();
	Vehicle4W->WheelSetups[2].BoneName = FName("Wheel_Rear_Left");
	Vehicle4W->WheelSetups[2].AdditionalOffset = FVector(0.f, -12.f, 0.f);

	Vehicle4W->WheelSetups[3].WheelClass = UHouseRaceWheelRear::StaticClass();
	Vehicle4W->WheelSetups[3].BoneName = FName("Wheel_Rear_Right");
	Vehicle4W->WheelSetups[3].AdditionalOffset = FVector(0.f, 12.f, 0.f);
}

void ACar_WV::Accelerate(float val)
{
	GetVehicleMovementComponent()->SetThrottleInput(val);
}

void ACar_WV::Steer(float val)
{
	GetVehicleMovementComponent()->SetSteeringInput(val);
}

void ACar_WV::BeginPlay()
{
	Super::BeginPlay();
}

void ACar_WV::Tick(float Delta)
{
	Super::Tick(Delta);
}

PRAGMA_ENABLE_DEPRECATION_WARNINGS