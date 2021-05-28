// Fill out your copyright notice in the Description page of Project Settings.


#include "Observer.h"

void UObserver::Init(UObject* object, TFunction<void(IINotification*)> method)
{
	_object = object;
	_method = method;
}

void UObserver::NotifyObserver(IINotification* notification)
{
	_method(notification);
}
