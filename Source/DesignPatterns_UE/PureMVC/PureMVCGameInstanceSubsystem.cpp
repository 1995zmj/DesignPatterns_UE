// Fill out your copyright notice in the Description page of Project Settings.


#include "PureMVCGameInstanceSubsystem.h"

#include "DesignPatterns_UE/Level/Data/ElementData.h"
#include "Patterns/Facade/Facade.h"
#include "Patterns/Mediator/Mediator.h"

bool UPureMVCGameInstanceSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	Super::ShouldCreateSubsystem(Outer);
	return true;
}

void UPureMVCGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp,Warning,TEXT("init sub system"));
	_facade = NewObject<UFacade>();
	_facade->InitializeFacade(TEXT("Test"));

	auto mediator = NewObject<UMediator>();
	_facade->RegisterMediator(mediator);
	FNotificationBody data;
	data.num = 1;
	_facade->SendNotification("ttt",data,"ss");
	_count = 0;

	auto k = new ElementData();
}

void UPureMVCGameInstanceSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

FString UPureMVCGameInstanceSubsystem::GetText()
{
	_count++;
	FString NewString = FString::FromInt(_count);
	return NewString;
}
