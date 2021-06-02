// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DesignPatterns_UE/PureMVC/Interfaces/INotifier.h"
#include "UObject/NoExportTypes.h"
#include "Notifier.generated.h"
/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UNotifier : public UObject, public IINotifier
{
	GENERATED_BODY()

	protected:
	FString _multitonKey;
	
	public:
	
	virtual void SendNotification(FString const& notificationName,FString const& body,FString const& type) override;
	virtual void InitializeNotifier(FString key) override;
	virtual FString GetMultitonKey() override;
};
