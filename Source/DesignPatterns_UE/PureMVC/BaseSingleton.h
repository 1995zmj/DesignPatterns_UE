// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseSingleton.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class DESIGNPATTERNS_UE_API UBaseSingleton : public UObject
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static UBaseSingleton* GetInstance();

public:
	UFUNCTION(BlueprintCallable)
	FString GetString();

	class UFacade* GetFacade();
};
