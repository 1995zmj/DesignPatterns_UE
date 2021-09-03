// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "PureMVCGameInstanceSubsystem.generated.h"

class UFacade;
/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UPureMVCGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
private:
	UFacade* _facade;
	int32 _count;
public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable)
	FString GetText();

};
