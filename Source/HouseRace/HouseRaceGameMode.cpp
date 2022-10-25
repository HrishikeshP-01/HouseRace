// Copyright Epic Games, Inc. All Rights Reserved.

#include "HouseRaceGameMode.h"
#include "HouseRacePawn.h"
#include "HouseRaceHud.h"

AHouseRaceGameMode::AHouseRaceGameMode()
{
	DefaultPawnClass = AHouseRacePawn::StaticClass();
	HUDClass = AHouseRaceHud::StaticClass();
}
