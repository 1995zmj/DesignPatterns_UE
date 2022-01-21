// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadTest.h"
#include "Engine/ObjectLibrary.h"
#include "Engine/StreamableManager.h"
#include "GameAssetManager.h"
#include "DesignPatterns_UE/Level/LevelElement.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ALoadTest::ALoadTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALoadTest::BeginPlay()
{
	Super::BeginPlay();
	FPrimaryAssetId assetId = UGameAssetManager::Get().GetPrimaryAssetIdForPath(TEXT("/Game/Element/Editor/Tts/BP_T1.BP_T1_C"));
	/*UE_LOG(LogTemp, Warning, TEXT("p a id %s"), *(assetId.ToString()));
	UE_LOG(LogTemp, Warning, TEXT("p s id %s"), *(softPath.ToString()));*/
	UGameAssetManager::Get().LoadPrimaryAsset(assetId);
}

// Called every frame
void ALoadTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALoadTest::LoadActor()
{
	FAssetData assetData;
	FPrimaryAssetId assetId = UGameAssetManager::Get().GetPrimaryAssetIdForPath(TEXT("/Game/Element/Editor/Tts/BP_T1.BP_T1_C"));
	auto softPath = UGameAssetManager::Get().GetPrimaryAssetPath(assetId);
	UGameAssetManager::Get().GetAssetDataForPath(softPath, assetData);
	if (assetData.IsAssetLoaded())
	{
		auto as = assetData.ToStringReference().ResolveObject();
		//UClass* t = LoadClass<ALevelElement>(nullptr, TEXT("/Game/Element/Editor/Tts/BP_T1.BP_T1_C"));
		UObject* t = LoadClass<UObject>(nullptr, *assetData.ToSoftObjectPath().ToString());
		//Cast<UBlueprint>(assetData.GetAsset())->GeneractedClass
		GetWorld()->SpawnActor<ALevelElement>(Cast<UClass>(t));
	}

	//GetWorld()->SpawnActor<ALevelElement>(ALevelElement::StaticClass());
}

void ALoadTest::LoadStreamLevel()
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(this, "NewWorld_2", true, true, LatentInfo);
}

