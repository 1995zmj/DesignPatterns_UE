// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "INotification.h"
#include "UObject/Interface.h"
#include "IMediator.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIMediator : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DESIGNPATTERNS_UE_API IIMediator
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	typedef TArray<FString>* NotificationNamesPtr;
	
	virtual FString const& GetMediatorName() const = 0;
	virtual UObject const* GetViewComponent() const = 0;
	virtual void SetViewComponent(UObject const* viewComponent) = 0;
	virtual NotificationNamesPtr ListNotificationInterests() const = 0;
	virtual void HandleNotification(IINotification const& notification) = 0;
	virtual void OnRegister() = 0;
	virtual void OnRemove() = 0;
};
