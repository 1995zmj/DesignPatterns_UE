// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade.h"
#include "DesignPatterns_UE/PureMVC/Core/PMVCView.h"
#include "DesignPatterns_UE/PureMVC/Core/PMVCController.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notification.h"

void UFacade::InitializeController()
{
	if (nullptr != _controller)
	{
		return;
	}
	_controller = NewObject<UPMVCController>();
	_controller->Init(_multitonKey,_view);
}

void UFacade::InitializeModel()
{
}

void UFacade::InitializeView()
{
	if (nullptr != _view)
	{
		return;
	}
	_view = NewObject<UPMVCView>();
	_view->Init(_multitonKey);
}

void UFacade::InitializeFacade(FString key)
{
	InitializeView();
	InitializeController();
	InitializeModel();
	_multitonKey = key;
	UE_LOG(LogTemp, Warning, TEXT("zmj: InitializeFacade"));
}

void UFacade::RegisterMediator(UMediator* mediator)
{
	_view->RegisterMediator(mediator);
}

void UFacade::RemoveMediator(FString mediatorName)
{
	_view->RemoveMediator(mediatorName);
}

UMediator* UFacade::RetrieveMediator(FString mediatorName)
{
	return _view->RetrieveMediator(mediatorName);
}

bool UFacade::HasMediator(FString mediatorName)
{
	return _view->HasMediator(mediatorName);
}

void UFacade::SendNotification(FString const& notificationName, FNotificationBody body, FString const& type)
{
	auto notification = NewObject<UNotification>();
	notification->init(notificationName,body,type);
	NotifyObservers(notification);
}

void UFacade::NotifyObservers(UNotification* notification)
{
	_view->NotifyObservers(notification);
}

//IIView const* UFacade::GetView()
//{
//	return _view;
//}
