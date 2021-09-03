// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DesignPatterns_UE/Level/LevelElement.h"
#include "Trap.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_UE_API ATrap : public ALevelElement
{
	GENERATED_BODY()

public:	
	ATrap();

	UFUNCTION(BlueprintImplementableEvent)
	void OpenState_Enter();
	UFUNCTION(BlueprintImplementableEvent)
	void StopState_Enter();
	UFUNCTION(BlueprintImplementableEvent)
	void CloseState_Enter();
	UFUNCTION(BlueprintImplementableEvent)  
	void UpState_Enter();
	UFUNCTION(BlueprintImplementableEvent)
	void DownState_Enter();


	UFUNCTION(BlueprintImplementableEvent)
	void OpenState_OpenTrap();
	UFUNCTION(BlueprintImplementableEvent)
	void StopState_OpenTrap();
	UFUNCTION(BlueprintImplementableEvent)
	void CloseState_OpenTrap();
	UFUNCTION(BlueprintImplementableEvent)  
	void UpState_OpenTrap();
	UFUNCTION(BlueprintImplementableEvent)
	void DownState_OpenTrap();

	UFUNCTION(BlueprintImplementableEvent)
	void OpenState_CloseTrap();
	UFUNCTION(BlueprintImplementableEvent)
	void StopState_CloseTrap();
	UFUNCTION(BlueprintImplementableEvent)
	void CloseState_CloseTrap();
	UFUNCTION(BlueprintImplementableEvent)  
	void UpState_CloseTrap();
	UFUNCTION(BlueprintImplementableEvent)
	void DownState_CloseTrap();
	
protected:
	virtual void BeginPlay() override;

};
