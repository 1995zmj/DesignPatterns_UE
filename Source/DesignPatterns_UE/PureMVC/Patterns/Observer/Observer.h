// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Observer.generated.h"

class UNotification;
class UNotifier;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotifyMethod, UNotification*, notification);
/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UObserver : public UObject
{
	GENERATED_BODY()
private:
	UNotifier* _notifier;
	TFunction<void(UNotification*)> _notifyMethod;
public:
	FNotifyMethod notifyMethodDelegate;

	void Init(TFunction<void(UNotification*)> notifyMethod,UNotifier* notifyContext);
	void NotifyObserver(UNotification* notification);
	void SetNotifyContext(UNotifier* notifyContext);
	//FNotifyMethod& GetNotifyMethod();
	bool CompareNotifyContext(UNotifier const* notifyContext) const;
};
