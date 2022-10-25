// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "Car_WV.generated.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
/**
 * 
 */
UCLASS()
class HOUSERACE_API ACar_WV : public AWheeledVehicle
{
	GENERATED_BODY()
	
public:
	ACar_WV();
	virtual void Tick(float Delta)override;

protected:
	virtual void BeginPlay()override;

public:
	void Accelerate(float val);
	void Steer(float val);

};

PRAGMA_ENABLE_DEPRECATION_WARNINGS
