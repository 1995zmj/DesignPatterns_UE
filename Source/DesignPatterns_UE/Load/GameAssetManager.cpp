// Fill out your copyright notice in the Description page of Project Settings.


#include "GameAssetManager.h"

const FPrimaryAssetType UGameAssetManager::PotionItemType = TEXT("Potion");
const FPrimaryAssetType UGameAssetManager::SkillItemType = TEXT("Skill");
const FPrimaryAssetType UGameAssetManager::TokenItemType = TEXT("Token");
const FPrimaryAssetType UGameAssetManager::WeaponItemType = TEXT("Weapon");


UGameAssetManager& UGameAssetManager::Get()
{
	UGameAssetManager* Singleton = Cast<UGameAssetManager>(GEngine->AssetManager);

	if (Singleton)
	{
		return *Singleton;
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("Cannot use AssetManager if no AssetManagerClassName is defined!"));
		return *NewObject<UGameAssetManager>(); // never calls this
	}
}

void UGameAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
}

void UGameAssetManager::ForceLoadItem(const FPrimaryAssetId& PrimaryAssetId, bool bLogWarning)
{
	FSoftObjectPath ItemPath = GetPrimaryAssetPath(PrimaryAssetId);

	auto* loadedItem = (ItemPath.TryLoad());

	if (bLogWarning && loadedItem == nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("failed to load item for identifier %s!"), *PrimaryAssetId.ToString());
	}
	
}
