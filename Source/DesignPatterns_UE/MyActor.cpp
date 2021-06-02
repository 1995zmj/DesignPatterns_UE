// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "PureMVC/BaseSingleton.h"
#include "PureMVC/Core/View.h"
#include "PureMVC/Patterns/Facade/Facade.h"
#include "PureMVC/Patterns/Mediator/Mediator.h"
#include "PureMVC/Patterns/Observer/Notification.h"
#include "PureMVC/Patterns/Observer/Notifier.h"
#include "PureMVC/Patterns/Observer/Observer.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	// auto facade = Cast<UBaseSingleton>(GEngine->GameSingleton)->GetFacade();
	// auto view = facade->GetView();

	UView* view = NewObject<UView>();
	view->init("testView");
	UMediator* mediator = NewObject<UMediator>();
	mediator->SetMediatorName("mediator");
	view->RegisterMediator(mediator);
	view->ListMediatorNames();
	// UObserver* observer = NewObject<UObserver>();
	// observer->Init(this,[this](IINotification const& notification)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("observer %s"), *(notification.GetName()));
	// });
	// view->RegisterObserver(TEXT("ttt"),observer);
	UNotification* notification = NewObject<UNotification>();
	notification->SetName(TEXT("ttt"));
	view->NotifyObservers(*notification);

	// auto mediator = NewObject<UMediator>();
	// mediator->SetMediatorName("fff");
	// view->RegisterMediator(mediator);
	auto list = GetArrayPtr();
	for (auto name : *list)
	{
		UE_LOG(LogTemp, Warning, TEXT("name %s"), *(name));
	}
	TArray<int> k;
	k.Init(2,2);
	auto p = &k;
	auto pt = GetNumberPtr();
	UE_LOG(LogTemp, Warning, TEXT("name %d"), *pt );

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Test(FString t,int32 num)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"),*t);
}

TArray<FString>* AMyActor::GetArrayPtr()
{
	TArray<FString>* k = &arrayPtr;
	k->Emplace(TEXT("55"));
	return k;
}

TArray<FString> AMyActor::GetArray()
{
	TArray<FString> k;
	k.Emplace(TEXT("44"));
	k.Emplace(TEXT("44"));
	k.Emplace(TEXT("44"));
	return k;
}

int* AMyActor::GetNumberPtr()
{
	
	int* p = &testNum;
	return p;
}

