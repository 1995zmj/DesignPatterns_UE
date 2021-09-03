// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap.h"
#include "../StateComponent.h"
#include "Components/Button.h"
ATrap::ATrap()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATrap::BeginPlay()
{
	Super::BeginPlay();
	MyStateComponent->EnterState("CloseState");
}
