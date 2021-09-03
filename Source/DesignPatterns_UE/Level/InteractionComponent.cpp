// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"

#include "Components/ShapeComponent.h"

// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInteractionComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp,Warning,TEXT("Begin %s %s"),*OverlappedComponent->GetName(),*OtherComp->GetName());
}

void UInteractionComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp,Warning,TEXT("end %s %s"),*OverlappedComponent->GetName(),*OtherComp->GetName());
}

void UInteractionComponent::RegisterInteractionCollisionEvents()
{
	auto list = GetInteractionCollisions();
	for (auto comp : list)
	{
		comp->OnComponentBeginOverlap.AddDynamic(this,&UInteractionComponent::OnOverlapBegin);
		comp->OnComponentEndOverlap.AddDynamic(this,&UInteractionComponent::OnOverlapEnd);
	}
}

void UInteractionComponent::RemoveInteractionCollisionEvents()
{
	auto list = GetInteractionCollisions();
	for (auto comp : list)
	{
		comp->OnComponentBeginOverlap.RemoveDynamic(this,&UInteractionComponent::OnOverlapBegin);
		comp->OnComponentEndOverlap.RemoveDynamic(this,&UInteractionComponent::OnOverlapEnd);
	}
}

TArray<UShapeComponent*> UInteractionComponent::GetInteractionCollisions()
{
	TArray<UShapeComponent*> collisions;
	auto owner = GetOwner();
	if (IsValid(owner))
	{
		auto list =owner->GetComponentsByTag(UShapeComponent::StaticClass(),TEXT("Interaction"));
		for (auto comp : list)
		{
			UShapeComponent* shapeComp = Cast<UShapeComponent>(comp);
			if (shapeComp)
			{
				collisions.Add(shapeComp);
			}
		}
	}
	return collisions;
}


// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	//RegisterInteractionCollisionEvents();
	// ...
	
}

bool UInteractionComponent::IsInteractionValid()
{
	return true;
}

void UInteractionComponent::OnEnterInteractionAreaEvent()
{
}

void UInteractionComponent::WaitingPlayerInput()
{
}

void UInteractionComponent::OnExecuteInteractionEvent()
{
}

void UInteractionComponent::OnLeaveInteractionAreaEvent()
{
	//ACameraActor* k =
}


// Called every frame
void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

