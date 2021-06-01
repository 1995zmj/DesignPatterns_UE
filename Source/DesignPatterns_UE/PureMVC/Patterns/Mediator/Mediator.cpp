// Fill out your copyright notice in the Description page of Project Settings.


#include "Mediator.h"

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

IIMediator::NotificationNamesPtr UMediator::ListNotificationInterests() const
{
	return new TArray<FString>();
}

void UMediator::HandleNotification(IINotification const& notification)
{
}

void UMediator::OnRegister()
{
}

void UMediator::OnRemove()
{
}
