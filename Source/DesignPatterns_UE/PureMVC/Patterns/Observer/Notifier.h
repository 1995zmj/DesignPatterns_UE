// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Notification.h"
#include "UObject/NoExportTypes.h"
#include "Notifier.generated.h"
/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UNotifier : public UObject
{
	GENERATED_BODY()

protected:
	FString _multitonKey;
public:
	virtual void SendNotification(FString const& notificationName,FNotificationBody body,FString const& type);
	void InitializeNotifier(FString key);
	FString GetMultitonKey();
};
