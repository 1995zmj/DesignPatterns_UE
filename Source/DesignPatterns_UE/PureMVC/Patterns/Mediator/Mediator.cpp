// Fill out your copyright notice in the Description page of Project Settings.


#include "Mediator.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notification.h"
#include "DesignPatterns_UE/PureMVC/Interfaces/ViewComponentInterface.h"

void UMediator::SetMediatorName(FString name)
{
	_mediatorName = name;
}

FString const& UMediator::GetMediatorName() const
{
	return _mediatorName;
}

IViewComponentInterface* UMediator::GetViewComponent() const
{
	return _viewComponent;
}

void UMediator::SetViewComponent(IViewComponentInterface* viewComponent) 
{
	_viewComponent = viewComponent;
}

UMediator::NotificationNames UMediator::ListNotificationInterests() const
{
	NotificationNames names;
	names.Add("ttt");
	return names;
}

void UMediator::HandleNotification(UNotification* notification)
{
	UE_LOG(LogTemp,Warning,TEXT("HandleNotification 收到消息 %s"),*(notification->GetName()));
}

void UMediator::OnRegister()
{
}

void UMediator::OnRemove()
{
}
