// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DesignPatterns_UE/PureMVC/Interfaces/IMediator.h"
#include "DesignPatterns_UE/PureMVC/Interfaces/INotifier.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notifier.h"
#include "UObject/NoExportTypes.h"
#include "Mediator.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UMediator : public UNotifier,public IIMediator
{
	GENERATED_BODY()
private:
	FString _mediatorName;
	UObject const* _viewComponent;
public:
	virtual void SetMediatorName(FString name);
	virtual FString const& GetMediatorName() const override;
	virtual UObject const* GetViewComponent() const override;
	virtual void SetViewComponent(UObject const* viewComponent) override;
	virtual NotificationNames ListNotificationInterests() const override;
	virtual void HandleNotification(IINotification const& notification) override;
	virtual void OnRegister() override;
	virtual void OnRemove() override;
};
