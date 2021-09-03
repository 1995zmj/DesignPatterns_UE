// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UObject/NoExportTypes.h"
#include "PMVCModel.generated.h"

class UProxy;
/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UPMVCModel : public UObject
{
	GENERATED_BODY()
private:
	FString _multitonKey;
	TMap<FString,UProxy*> _proxyMap;
public:
	virtual void Init(FString key);
	virtual void RegisterProxy(UProxy* proxy);
	virtual UProxy* RetrieveProxy(FString const& proxyName);
	virtual bool HasProxy(FString const& proxyName);
	virtual void RemoveProxy(FString const& proxyName);
};
