// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notification.h"
#include "UObject/NoExportTypes.h"
#include "PMVCController.generated.h"

class UPMVCView;
class UCommand;
/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UPMVCController : public UObject
{
	GENERATED_BODY()
private:
	FString _multitonKey;
	TMap<FString,UCommand*> _commandMap;
	UPMVCView* _view;
public:
	virtual void Init(FString key,UPMVCView* view);
	virtual void ExecuteCommand(UNotification* notification);
	virtual void RegisterCommand(FString const& notificationName, UCommand* command);
	virtual bool HasCommand(FString const& notificationName);
	virtual UCommand* RetrieveCommand(FString const& notificationName);
	virtual void RemoveCommand(FString const& notificationName);
};
