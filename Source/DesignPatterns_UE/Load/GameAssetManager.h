// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "GameAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UGameAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	UGameAssetManager(){}

	static const FPrimaryAssetType PotionItemType;
	static const FPrimaryAssetType SkillItemType;
	static const FPrimaryAssetType TokenItemType;
	static const FPrimaryAssetType WeaponItemType;

	static UGameAssetManager& Get();
	
	virtual void StartInitialLoading() override;

	void ForceLoadItem(const FPrimaryAssetId& PrimaryAssetId, bool bLogWarning = true);
	
};
