// Fill out your copyright notice in the Description page of Project Settings.


#include "PMVCController.h"

#include "PMVCView.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Command/Command.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Observer.h"

void UPMVCController::Init(FString key, UPMVCView* view)
{
	_multitonKey = key;
	_view = view;
}

void UPMVCController::ExecuteCommand(UNotification* notification)
{
	if (_commandMap.Contains(notification->GetName()))
	{
		auto command = _commandMap[notification->GetName()];
		command->Execute(notification);
	}	
}

void UPMVCController::RegisterCommand(FString const& notificationName, UCommand* command)
{
	if (_commandMap.Contains(notificationName))
	{
	}
	else
	{
		// TODO 还有待优化
		auto observer = NewObject<UObserver>();
		observer->notifyMethodDelegate.AddDynamic(this,&UPMVCController::ExecuteCommand);
		_view->RegisterObserver(notificationName,observer);
	}
	_commandMap[notificationName] = command;

}

bool UPMVCController::HasCommand(FString const& notificationName)
{
	return _commandMap.Contains(notificationName);
}

UCommand* UPMVCController::RetrieveCommand(FString const& notificationName)
{
	return _commandMap[notificationName];
}

void UPMVCController::RemoveCommand(FString const& notificationName)
{
	if (HasCommand(notificationName))
	{
		auto command = _commandMap[notificationName];
		_view->RemoveObserver(notificationName,command);
		_commandMap.Remove(notificationName);
	}
}
