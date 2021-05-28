// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DesignPatterns_UE/PureMVC/Interfaces/INotification.h"
#include "UObject/NoExportTypes.h"
#include "Observer.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UObserver : public UObject
{
	GENERATED_BODY()
private:
	UObject* _object;
	TFunction<void(IINotification*)> _method;
public:	
	virtual void Init(UObject* object,TFunction<void(IINotification*)> method);
	virtual void NotifyObserver(IINotification* notification);
	// virtual void CompareNotifyContext(UObject const* object);
};
