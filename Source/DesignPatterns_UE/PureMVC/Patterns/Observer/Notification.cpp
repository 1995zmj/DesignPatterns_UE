// Fill out your copyright notice in the Description page of Project Settings.


#include "Notification.h"

FString const& UNotification::GetName() const
{
	return _name;
}

void UNotification::SetBody(FString const& body)
{
	_body = body;
}

FString UNotification::GetBody() const
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
