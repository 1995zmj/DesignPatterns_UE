// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Notification.generated.h"

USTRUCT()
struct FNotificationBody
{
	GENERATED_BODY()
	int32 num = 1;
};

//	TODO 改成结构体是不是更好

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API  UNotification : public UObject
{
	GENERATED_BODY()
private:
	FString _name;
	FNotificationBody _body;
	FString _type;
public:
	virtual void init(FString name,FNotificationBody body,FString type);

	void SetName(FString name);
	
	virtual FString const& GetName() const;

	virtual void SetBody(FNotificationBody body);
	
	virtual FNotificationBody GetBody() const;
	
	virtual void SetType(FString const& type);
	
	virtual FString ToString() const;
};
