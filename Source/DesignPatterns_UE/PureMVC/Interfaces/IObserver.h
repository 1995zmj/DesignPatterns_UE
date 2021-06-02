// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "INotification.h"
#include "UObject/Interface.h"
#include "IObserver.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIObserver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DESIGNPATTERNS_UE_API IIObserver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void NotifyObserver(IINotification const& Notification) = 0;
	virtual bool CompareNotifyContext(UObject const* object) const = 0;
};
