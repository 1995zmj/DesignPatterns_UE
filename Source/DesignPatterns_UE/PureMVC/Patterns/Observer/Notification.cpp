// Fill out your copyright notice in the Description page of Project Settings.


#include "Notification.h"

FString const& UNotification::GetName() const
{
	return _name;
}

void UNotification::SetBody(UObject const* body)
{
	_body = body;
}

UObject const* UNotification::GetBody() const
{
	return _body;
}

void UNotification::SetType(FString const& type)
{
	_type = type;
}

FString UNotification::ToString() const
{
	return "ToString";
}
