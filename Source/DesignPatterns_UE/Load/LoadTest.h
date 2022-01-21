// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DesignPatterns_UE/PureMVC/Patterns/Proxy/Proxy.h"
#include "Engine/StreamableManager.h"
#include "GameFramework/Actor.h"
#include "LoadTest.generated.h"

UCLASS()
class DESIGNPATTERNS_UE_API ALoadTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALoadTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void LoadActor();


	UFUNCTION(BlueprintCallable)
	void LoadStreamLevel();
};
