// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class DESIGNPATTERNS_UE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Test(FString t,int32 num);

	TFunction<void(FString)> tFuncOne;
	void RegFunOne(TFunction<void(FString)> targetFun)
	{
		tFuncOne = targetFun;
		tFuncOne(TEXT("RegFunOne"));
	}

	DECLARE_DELEGATE(FWDE_Single_Zero)
	template<class T>
	void RegFunTwo(T* TarObj, typename TMemFunPtrType<false,T,void(FString,int32)>::Type InMethod)
	{
		FWDE_Single_Zero ExeDel;
		ExeDel.BindUObject(TarObj,InMethod,FString("RegFunTwo"),54);
		ExeDel.ExecuteIfBound();
	}


	DECLARE_DELEGATE_TwoParams(FWDE_Single_Two,FString,int32)
	template<class T>
	void RegFunThree(T* TarObj,typename TMemFunPtrType<false,T,void(FString,int32)>::Type InMethod)
	{
		//定义一个委托
		FWDE_Single_Two ExeDel;
		//将委托绑定到传入的函数中
		ExeDel.BindUObject(TarObj,InMethod);
		//执行委托
		ExeDel.ExecuteIfBound(FString("RegFunThree"),54);
	}

};
