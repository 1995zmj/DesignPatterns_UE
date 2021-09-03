// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorMediator.h"

#include "DesignPatterns_UE/PureMVC/Interfaces/ViewComponentInterface.h"

void UActorMediator::InitConfig()
{
	
}

void UActorMediator::LoadActorView()
{
	/*UClass* tClass = LoadClass<AActor>(NULL, TEXT("Blueprint'/Game/Element/BP_LE.BP_LE_C'"));
	
	if (tClass)
	{
		auto actor = GetWorld()->SpawnActor(tClass);
		SetViewComponent(actor);
	}*/
	GetViewComponent()->Init(this);
}
