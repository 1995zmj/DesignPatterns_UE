// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notifier.h"
#include "UObject/NoExportTypes.h"
#include "Command.generated.h"

class UNotification; 
/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UCommand : public UNotifier
{
	GENERATED_BODY()
public: 
	virtual void Execute(UNotification* notificcation);
};
