// Fill out your copyright notice in the Description page of Project Settings.


#include "Observer.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notification.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notifier.h"

void UObserver::Init(TFunction<void(UNotification*)> notifyMethod, UNotifier* notifyContext)
{
	_notifier = notifyContext;
	_notifyMethod = notifyMethod;
}

void UObserver::NotifyObserver(UNotification* notification)
{
	notifyMethodDelegate.Broadcast(notification);
	//_notifyMethod(notification);
}

void UObserver::SetNotifyContext(UNotifier* notifyContext)
{
	_notifier = notifyContext;
}

//FNotifyMethod& UObserver::GetNotifyMethod()
//{
//	return  _notifyMethod;
//}

bool UObserver::CompareNotifyContext(UNotifier const* notifyContext) const
{
	return  _notifier == notifyContext;
}
