// Fill out your copyright notice in the Description page of Project Settings.


#include "StateComponent.h"

// Sets default values for this component's properties
UStateComponent::UStateComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStateComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	_curState = TEXT("NO");
}


// Called every frame
void UStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UStateComponent::GetCurState()
{
	return _curState;
}

void UStateComponent::EnterState(FString key)
{
	if (_curState != key)
	{
		_curState = key;
		ExecuteStateEvent(TEXT("Enter"));
	}
}

void UStateComponent::RegisterStateFunction(TArray<FString> functionNames)
{
	_stateFunctionNames = functionNames;
}

void UStateComponent::ExecuteStateEvent(FString funcName)
{
	UE_LOG(LogTemp,Warning,TEXT("run %s_%s"),*_curState,*funcName);
	FString t = FString::Printf( TEXT("%s_%s"),*_curState,*funcName);
	UFunction* func = GetOwner()->FindFunction(FName(*t));
	if (func)
	{
		GetOwner()->ProcessEvent(func, NULL);
	}
}
