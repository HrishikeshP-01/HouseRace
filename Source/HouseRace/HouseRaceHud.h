// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/HUD.h"
#include "HouseRaceHud.generated.h"


UCLASS(config = Game)
class AHouseRaceHud : public AHUD
{
	GENERATED_BODY()

public:
	AHouseRaceHud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface
};
