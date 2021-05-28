// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSingleton.h"

#include "Patterns/Facade/Facade.h"

UBaseSingleton* UBaseSingleton::GetInstance()
{
	if (GEngine)
	{
		UBaseSingleton* Instance = Cast<UBaseSingleton>(GEngine->GameSingleton);
		return Instance;
	}
	return nullptr;
}

FString UBaseSingleton::GetString()
{
	UFacade* k = NewObject<UFacade>();
	k->InitializeFacade();
	return TEXT("sss");
}
