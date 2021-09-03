// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DesignPatterns_UE/PureMVC/Patterns/Observer/Notifier.h"
#include "UObject/NoExportTypes.h"
#include "Proxy.generated.h"

USTRUCT()
struct FProxyData
{
	GENERATED_BODY()
	
	int num;
};
/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UProxy : public UNotifier
{
	GENERATED_BODY()
private:
	FString _proxyName;
	FProxyData _data;
public:
	virtual void Init(FString name,FProxyData data);
	virtual FString const& GetProxyName();
	virtual void SetData(FProxyData data);
	virtual FProxyData GetData();
	virtual void OnRegister();
	virtual void OnRemove();
	
};
