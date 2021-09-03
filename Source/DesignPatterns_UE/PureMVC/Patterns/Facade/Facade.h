// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notifier.h"
#include "UObject/NoExportTypes.h"
#include "Facade.generated.h"

class UPMVCView;
class UPMVCController;
class UMediator;
class UNotification;
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
	UPMVCView* _view;
	UPMVCController* _controller;
protected:
	virtual void InitializeController();
	virtual void InitializeModel();
	virtual void InitializeView();
	
public:

	//UFacade();
	//getInstance
	virtual void InitializeFacade(FString key);

	//Command
	/*virtual void RegisterCommand();

	virtual void RemoveCommand();

	virtual void RetrieveCommand();

	virtual void HasCommand();*/

	////Proxy
	//virtual void RegisterProxy();

	//virtual void RemoveProxy();

	//virtual void RetrieveProxy();

	//virtual void HasProxy();

	//// Mediator
	void RegisterMediator(UMediator* mediator);

	void RemoveMediator(FString mediatorName);

	UMediator* RetrieveMediator(FString mediatorName);

	bool HasMediator(FString mediatorName);


	virtual void SendNotification(FString const& notificationName,FNotificationBody body,FString const& type) override;

	void NotifyObservers(UNotification* notification);
	//notifyObservers

	//virtual IIView const* GetView();
	
	// Command
	
};

