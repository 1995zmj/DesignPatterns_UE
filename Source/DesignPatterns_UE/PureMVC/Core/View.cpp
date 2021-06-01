// Fill out your copyright notice in the Description page of Project Settings.


#include "View.h"

void UView::RegisterObserver(FString const& notificationName, IIObserver* observer)
{
	_observerMap[notificationName].Add(observer);
}

void UView::NotifyObservers(IINotification const& notification)
{
	auto list = _observerMap[notification.GetName()];
}
