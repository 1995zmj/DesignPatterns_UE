// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelElementFactory.generated.h"

UCLASS()
class DESIGNPATTERNS_UE_API ALevelElementFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelElementFactory();

private:
	TArray<AActor*> LevelElements;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	AActor* CreateLevelElement();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
