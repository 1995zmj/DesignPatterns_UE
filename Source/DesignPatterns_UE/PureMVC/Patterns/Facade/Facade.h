// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notifier.h"
#include "UObject/NoExportTypes.h"
#include "Facade.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UFacade : public UNotifier
{
	GENERATED_BODY()
private:
	// controller
	// model
	// view
protected:
	virtual void InitializeController();
	virtual void InitializeModel();
	virtual void InitializeView();
	
public:
	virtual void InitializeFacade();

	
	// Command
	
};

