// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelElementFactory.h"

#include "InteractionComponent.h"

// Sets default values
ALevelElementFactory::ALevelElementFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelElementFactory::BeginPlay()
{
	Super::BeginPlay();
}

AActor* ALevelElementFactory::CreateLevelElement()
{
	 UClass* tClass = LoadClass<AActor>(NULL, TEXT("Blueprint'/Game/Element/BP_LE.BP_LE_C'"));
	 if(tClass != NULL)  
	 { 
	 	AActor* actor = GetWorld()->SpawnActor<AActor>(tClass);
		UActorComponent* uac = actor->GetComponentByClass(UInteractionComponent::StaticClass());
	    if (uac)
	    {
			UE_LOG(LogTemp, Log, TEXT("Success"));
			LevelElements.Add(actor);
	    	return actor;
	    }
	 }
	UE_LOG(LogTemp, Error, TEXT("Error"));
	return nullptr;
}

// Called every frame
void ALevelElementFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

