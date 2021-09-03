// Fill out your copyright notice in the Description page of Project Settings.


#include "PMVCModel.h"
#include "DesignPatterns_UE/PureMVC/Patterns/Proxy/Proxy.h"

void UPMVCModel::Init(FString key)
{
	_multitonKey = key;
}

void UPMVCModel::RegisterProxy(UProxy* proxy)
{
	proxy->InitializeNotifier(_multitonKey);
	if (_proxyMap.Contains(proxy->GetProxyName()))
	{
		
	}
	else
	{
		_proxyMap[proxy->GetProxyName()] = proxy;
		proxy->OnRegister();
	}
	
}

UProxy* UPMVCModel::RetrieveProxy(FString const& proxyName)
{
	return _proxyMap[proxyName];
}

bool UPMVCModel::HasProxy(FString const& proxyName)
{
	return _proxyMap.Contains(proxyName);
}

void UPMVCModel::RemoveProxy(FString const& proxyName)
{
	if (_proxyMap.Contains(proxyName))
	{
		auto proxy = _proxyMap[proxyName];
		proxy->OnRemove();
		_proxyMap.Remove(proxyName);
	}
}
