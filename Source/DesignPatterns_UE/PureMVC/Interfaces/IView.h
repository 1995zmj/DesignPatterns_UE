// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "IMediator.h"
#include "INotifier.h"
#include "IObserver.h"
#include "UObject/Interface.h"
#include "IView.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIView : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DESIGNPATTERNS_UE_API IIView
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	typedef TArray<FString> MediatorNames;
	
	virtual void RegisterObserver(FString const& notificationName, IIObserver* observer) = 0;
	virtual void RemoveObserver(FString const& notificationName, UObject* notifyContext) = 0;
	virtual void NotifyObservers(IINotification const& notification) = 0;
	
	virtual void RegisterMediator(IIMediator* mediator) = 0;
	virtual IIMediator const& RetrieveMediator(FString const& mediatorName) const = 0;
	virtual IIMediator& RetrieveMediator(FString const& mediatorName) = 0;
	virtual IIMediator* RemoveMediator(FString const& mediatorName) =0;
	virtual bool HasMediator(FString const& mediatorName) const = 0;
	virtual MediatorNames ListMediatorNames() const = 0;
};
