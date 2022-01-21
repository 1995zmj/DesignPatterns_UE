// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelElement.h"
#include "StateComponent.h"
#include "../Load/GameAssetManager.h"

// Sets default values
ALevelElement::ALevelElement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	MyStateComponent = CreateDefaultSubobject<UStateComponent>(TEXT("StateComponent"));
}

// Called when the game starts or when spawned
void ALevelElement::BeginPlay()
{
	Super::BeginPlay();
}

void ALevelElement::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void ALevelElement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FPrimaryAssetId ALevelElement::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(UGameAssetManager::LevelElementType, GetFName());
}

