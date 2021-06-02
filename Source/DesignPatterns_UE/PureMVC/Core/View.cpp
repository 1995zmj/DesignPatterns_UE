// Fill out your copyright notice in the Description page of Project Settings.


#include "View.h"

#include "DesignPatterns_UE/PureMVC/Patterns/Mediator/Mediator.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Observer.h"

// void UView::init()
// {
// }

void UView::init(FString key)
{
	_multitonKey = key;
}

void UView::RegisterObserver(FString const& notificationName, IIObserver* observer)
{
	if (_observerMap.Contains(notificationName))
	{
		_observerMap[notificationName].Add(observer);
	}
	else
	{
		_observerMap.Add(notificationName,TArray<IIObserver*>());
		_observerMap[notificationName].Add(observer);
	}
}

void UView::NotifyObservers(IINotification const& notification)
{
	if (_observerMap.Contains(notification.GetName()))
	{
		auto list = _observerMap[notification.GetName()];
		for (auto observer : list)
		{
			observer->NotifyObserver(notification);
		}
	}
}

void UView::RemoveObserver(FString const& notificationName, UObject* notifyContext)
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

void UView::RegisterMediator(IIMediator* mediator)
{
	if (_mediatorMap.Contains(mediator->GetMediatorName()))
	{
		UE_LOG(LogTemp,Warning,TEXT("已经注册过，%s"),*mediator->GetMediatorName());
	}
	else
	{
		auto notifier = Cast<IINotifier>(mediator);
		if (notifier)
		{
			UE_LOG(LogTemp,Warning,TEXT("IINotifier"));
			notifier->InitializeNotifier(_multitonKey);
			_mediatorMap.Add(mediator->GetMediatorName(),mediator);
			auto interests = mediator->ListNotificationInterests();
			for (auto notificationName : interests)
			{
				// TODO 需要改进
				auto observer = NewObject<UObserver>();
				observer->Init( Cast<UObject>(mediator),[mediator](IINotification const& notification)
				{
					mediator->HandleNotification(notification);
				});
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

IIMediator const& UView::RetrieveMediator(FString const& mediatorName) const
{
	return *_mediatorMap[mediatorName];
}

IIMediator& UView::RetrieveMediator(FString const& mediatorName)
{
	return *_mediatorMap[mediatorName];
}

IIMediator* UView::RemoveMediator(FString const& mediatorName)
{
	if (_mediatorMap.Contains(mediatorName))
	{
		auto mediator = _mediatorMap[mediatorName];
		auto interests = mediator->ListNotificationInterests();

		for (auto notificationName : interests)
		{
			RemoveObserver(notificationName,Cast<UObject>(mediator));
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

bool UView::HasMediator(FString const& mediatorName) const
{
	return _mediatorMap.Contains(mediatorName);
}

IIView::MediatorNames UView::ListMediatorNames() const
{
	MediatorNames names;
	for (auto mediator : _mediatorMap)
	{
		names.Add(mediator.Key);
		UE_LOG(LogTemp,Warning,TEXT("ListMediatorNames MediatorName %s"),*(mediator.Key));
	}
	return names;
}
