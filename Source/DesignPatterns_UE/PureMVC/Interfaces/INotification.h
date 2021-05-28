// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "INotification.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UINotification : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DESIGNPATTERNS_UE_API IINotification
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FString const& GetName() const = 0;
	virtual void SetBody(FString const& body) = 0;
	virtual FString GetBody() const = 0;
	virtual void SetType(FString const& type) = 0;
	virtual FString ToString() const = 0;
};
