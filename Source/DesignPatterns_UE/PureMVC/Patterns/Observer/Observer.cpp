// Fill out your copyright notice in the Description page of Project Settings.


#include "Observer.h"

void UObserver::Init(UObject* object, TFunction<void(IINotification const*)> method)
{
	_object = object;
	_method = method;
}

void UObserver::NotifyObserver(IINotification const* notification)
{
	_method(notification);
}
