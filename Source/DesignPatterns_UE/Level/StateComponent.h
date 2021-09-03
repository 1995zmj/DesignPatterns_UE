// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DESIGNPATTERNS_UE_API UStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FString _oldState;
	FString _curState;
	TArray<FString> _stateFunctionNames;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	FString GetCurState();
	
	UFUNCTION(BlueprintCallable)
	void EnterState(FString key);
	
	void RegisterStateFunction(TArray<FString> functionNames);
	
	UFUNCTION(BlueprintCallable)
	void ExecuteStateEvent(FString funcName);
		
};
