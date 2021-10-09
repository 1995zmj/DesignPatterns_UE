// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "EditorDataTableFunctionLibrary.h"
#include "Engine/DataAsset.h"
#include "UItemBase.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UUItemBase : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = Item)
	FVolumeItem ItemProperty;
};
