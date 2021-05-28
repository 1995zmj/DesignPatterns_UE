// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade.h"

void UFacade::InitializeController()
{
}

void UFacade::InitializeModel()
{
}

void UFacade::InitializeView()
{
}

void UFacade::InitializeFacade()
{
	InitializeController();
	InitializeModel();
	InitializeView();
	UE_LOG(LogTemp, Warning, TEXT("zmj: InitializeFacade"));
}
