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
	return TEXT("sss");
}

UFacade* UBaseSingleton::GetFacade()
{
	UFacade* k = NewObject<UFacade>();
	k->InitializeFacade();
	return k;
}
