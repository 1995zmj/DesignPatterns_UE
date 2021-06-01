// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DesignPatterns_UE/PureMVC/Interfaces/IView.h"
#include "UObject/NoExportTypes.h"
#include "View.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UView : public UObject, public IIView
{
	GENERATED_BODY()
private:
	TMap<FString,TArray<IIObserver*>> _observerMap;
public:
	virtual void init();
	virtual void RegisterObserver(FString const& notificationName, IIObserver* observer) override;
	virtual void NotifyObservers(IINotification const& notification) override;
	virtual void RemoveObserver(FString const& notificationName, UObject* notifyContext) override;

	virtual void RegisterMediator(IIMediator* mediator) override;
	virtual IIMediator const& RetrieveMediator(FString const& mediatorName) const override;
	virtual IIMediator& RetrieveMediator(FString const& mediatorName) override;
	virtual IIMediator* RemoveMediator(FString const& mediatorName) override;
	virtual bool HasMediator(FString const& mediatorName) const override;
	virtual IIMediator::NotificationNamesPtr ListMediatorNames() const override;
};
