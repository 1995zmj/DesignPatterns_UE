// Fill out your copyright notice in the Description page of Project Settings.


#include "Notification.h"

void UNotification::init(FString name,UObject* body,FString type)
{
	_name = name;	
	_body = body;
	_type = type;
}

void UNotification::SetName(FString name)
{
	_name = name;
}

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
