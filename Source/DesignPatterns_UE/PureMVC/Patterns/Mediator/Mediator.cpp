// Fill out your copyright notice in the Description page of Project Settings.


#include "Mediator.h"

void UMediator::SetMediatorName(FString name)
{
	_mediatorName = name;
}

FString const& UMediator::GetMediatorName() const
{
	return _mediatorName;
}

UObject const* UMediator::GetViewComponent() const
{
	return _viewComponent;
}

void UMediator::SetViewComponent(UObject const* viewComponent) 
{
	_viewComponent = viewComponent;
}

IIMediator::NotificationNames UMediator::ListNotificationInterests() const
{
	NotificationNames names;
	names.Add("ttt");
	return names;
}

void UMediator::HandleNotification(IINotification const& notification)
{
	UE_LOG(LogTemp,Warning,TEXT("HandleNotification 收到消息 %s"),*(notification.GetName()));
}

void UMediator::OnRegister()
{
}

void UMediator::OnRemove()
{
}
