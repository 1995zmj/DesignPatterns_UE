// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifier.h"

void UNotifier::SendNotification(FString const& notificationName,FNotificationBody body,FString const& type)
{
	
}

void UNotifier::InitializeNotifier(FString key)
{
	_multitonKey = key;
}

FString UNotifier::GetMultitonKey()
{
	return _multitonKey;
}

