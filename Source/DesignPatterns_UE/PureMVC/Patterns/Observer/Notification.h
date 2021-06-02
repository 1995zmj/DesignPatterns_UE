// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "DesignPatterns_UE/PureMVC/Interfaces/INotification.h"
#include "UObject/NoExportTypes.h"
#include "Notification.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API UNotification : public UObject, public IINotification
{
	GENERATED_BODY()
private:
	FString _name;
	UObject const* _body;
	FString _type;
public:
	virtual void init(FString name,UObject* body,FString type);

	void SetName(FString name);
	
	virtual FString const& GetName() const;

	virtual void SetBody(UObject const* body);
	
	virtual UObject const* GetBody() const;
	
	virtual void SetType(FString const& type);
	
	virtual FString ToString() const;
};
