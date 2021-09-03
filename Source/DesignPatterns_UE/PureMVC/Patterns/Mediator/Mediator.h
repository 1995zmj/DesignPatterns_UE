// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notifier.h"
#include "UObject/NoExportTypes.h"
#include "Mediator.generated.h"

class IViewComponentInterface;
class UNotification;

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UMediator : public UNotifier
{
	GENERATED_BODY()
private:
	FString _mediatorName;
	IViewComponentInterface* _viewComponent;
public:
	typedef TArray<FString> NotificationNames;

	void SetMediatorName(FString name);
	FString const& GetMediatorName() const;
	IViewComponentInterface* GetViewComponent() const;
	void SetViewComponent(IViewComponentInterface* viewComponent);
	NotificationNames ListNotificationInterests() const;
	UFUNCTION()
	void HandleNotification(UNotification* notification);
	void OnRegister();
	void OnRemove();
};
