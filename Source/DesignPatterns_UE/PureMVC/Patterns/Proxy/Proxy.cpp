// Fill out your copyright notice in the Description page of Project Settings.


#include "Proxy.h"

void UProxy::Init(FString name, FProxyData data)
{
	_proxyName = name;
	_data = data;
}

FString const& UProxy::GetProxyName()
{
	return _proxyName;
}

void UProxy::SetData(FProxyData data)
{
	_data = data;
}

FProxyData UProxy::GetData()
{
	return _data;
}

void UProxy::OnRegister()
{
}

void UProxy::OnRemove()
{
}
