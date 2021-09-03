// Fill out your copyright notice in the Description page of Project Settings.


#include "PMVCView.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Mediator/Mediator.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Observer.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notification.h"

void UPMVCView::Init(FString key)
{
	_multitonKey = key;
}

void UPMVCView::RegisterObserver(FString const& notificationName, UObserver* observer)
{
	if (_observerMap.Contains(notificationName))
	{
		_observerMap[notificationName].Add(observer);
	}
	else
	{
		_observerMap.Add(notificationName,TArray<UObserver*>());
		_observerMap[notificationName].Add(observer);
	}
}

void UPMVCView::NotifyObservers(UNotification* notification)
{
	if (_observerMap.Contains(notification->GetName()))
	{
		auto list = _observerMap[notification->GetName()];
		for (auto observer : list)
		{
			observer->NotifyObserver(notification);
		}
	}
}

void UPMVCView::RemoveObserver(FString const& notificationName, UNotifier* notifyContext)
{
	if (_observerMap.Contains(notificationName))
	{
		auto list = _observerMap[notificationName];
		for (auto observer : list)
		{
			if (observer->CompareNotifyContext(notifyContext))
			{
				list.Remove(observer);
				break;
			}
		}

		if (0 == list.Num())
		{
			_observerMap.Remove(notificationName);
		}
	}
}

void UPMVCView::RegisterMediator(UMediator* mediator)
{
	if (_mediatorMap.Contains(mediator->GetMediatorName()))
	{
		UE_LOG(LogTemp,Warning,TEXT("已经注册过，%s"),*mediator->GetMediatorName());
	}
	else
	{
		auto notifier = Cast<UNotifier>(mediator);
		if (notifier)
		{
			UE_LOG(LogTemp,Warning,TEXT("IINotifier"));
			notifier->InitializeNotifier(_multitonKey);
			_mediatorMap.Add(mediator->GetMediatorName(),mediator);
			auto interests = mediator->ListNotificationInterests();
			for (auto notificationName : interests)
			{
				// TODO 还有待优化
				auto observer = NewObject<UObserver>();
				observer->notifyMethodDelegate.AddDynamic(mediator,&UMediator::HandleNotification);
				//observer->Init(mediator->HandleNotification,mediator);
				RegisterObserver(notificationName,observer);
			}
			mediator->OnRegister();
		}
		else
		{
			UE_LOG(LogTemp,Error,TEXT("mediator 没有继承IINotifier"));
		}
	}
	
}

UMediator const& UPMVCView::RetrieveMediator(FString const& mediatorName) const
{
	return *_mediatorMap[mediatorName];
}

UMediator* UPMVCView::RetrieveMediator(FString const& mediatorName)
{
	return _mediatorMap[mediatorName];
}

UMediator* UPMVCView::RemoveMediator(FString const& mediatorName)
{
	if (_mediatorMap.Contains(mediatorName))
	{
		auto mediator = _mediatorMap[mediatorName];
		auto interests = mediator->ListNotificationInterests();

		for (auto notificationName : interests)
		{
			RemoveObserver(notificationName,mediator);
		}
		_mediatorMap.Remove(mediatorName);
		return  mediator;
	}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("RemoveMediator 没有注册过 %s"),*mediatorName);
		return nullptr;
	}
}

bool UPMVCView::HasMediator(FString const& mediatorName) const
{
	return _mediatorMap.Contains(mediatorName);
}

UPMVCView::MediatorNames UPMVCView::ListMediatorNames() const
{
	MediatorNames names;
	for (auto mediator : _mediatorMap)
	{
		names.Add(mediator.Key);
		UE_LOG(LogTemp,Warning,TEXT("ListMediatorNames MediatorName %s"),*(mediator.Key));
	}
	return names;
}
