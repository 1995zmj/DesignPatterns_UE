// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PMVCView.generated.h"

class UObserver;
class UMediator;
class UNotification;
class UNotifier;
/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UPMVCView : public UObject
{
	GENERATED_BODY()
private:
	FString _multitonKey;
	TMap<FString,TArray<UObserver*>> _observerMap;
	TMap<FString,UMediator*> _mediatorMap;
public:
	typedef TArray<FString> MediatorNames;

	virtual void Init(FString key);
	
	virtual void RegisterObserver(FString const& notificationName, UObserver* observer);
	virtual void NotifyObservers(UNotification* notification);
	virtual void RemoveObserver(FString const& notificationName, UNotifier* notifyContext);

	virtual void RegisterMediator(UMediator* mediator);
	virtual UMediator const& RetrieveMediator(FString const& mediatorName) const;
	virtual UMediator* RetrieveMediator(FString const& mediatorName);
	virtual UMediator* RemoveMediator(FString const& mediatorName);
	virtual bool HasMediator(FString const& mediatorName) const;
	virtual MediatorNames ListMediatorNames() const;
};
