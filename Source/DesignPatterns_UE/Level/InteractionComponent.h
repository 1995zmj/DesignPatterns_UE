// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"


UCLASS(DefaultToInstanced, BlueprintType, Blueprintable, ClassGroup=("Interaction"), meta=(BlueprintSpawnableComponent) )
class DESIGNPATTERNS_UE_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void RegisterInteractionCollisionEvents();
	void RemoveInteractionCollisionEvents();
	TArray<UShapeComponent*> GetInteractionCollisions();

	TArray<UShapeComponent*> ShapeComponents;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	bool IsInteractionValid();
	void OnEnterInteractionAreaEvent();
	void WaitingPlayerInput();
	void OnExecuteInteractionEvent();
	void OnLeaveInteractionAreaEvent();
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddInteractionComponent();
	void RemoveInteractionCollisionComponent();
};
