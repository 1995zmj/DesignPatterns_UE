// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

#include "BehaviorTree/BehaviorTreeTypes.h"
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
	auto p = NewObject<UObserver>();
	p->Init(this,[this](IINotification const* notification)
	{
		
		// FString body = notification->GetBody();
		UE_LOG(LogTemp, Warning, TEXT("observer %s"), *(notification->GetName()));
		Test(GetName(),2);
	});

	auto data = NewObject<UNotification>();
	// data->SetBody(TEXT("hello"));
	p->NotifyObserver(data);
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

