// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Mediator/Mediator.h"
#include "ActorMediator.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UActorMediator : public UMediator
{
	GENERATED_BODY()

public:
	void InitConfig();

	void LoadActorView();
};
