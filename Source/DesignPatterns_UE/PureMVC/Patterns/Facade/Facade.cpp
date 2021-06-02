// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade.h"

#include "DesignPatterns_UE/PureMVC/Core/View.h"

void UFacade::InitializeController()
{
}

void UFacade::InitializeModel()
{
}

void UFacade::InitializeView()
{
	_view = NewObject<UView>();
}

void UFacade::InitializeFacade()
{
	InitializeController();
	InitializeModel();
	InitializeView();
	UE_LOG(LogTemp, Warning, TEXT("zmj: InitializeFacade"));
}

IIView const* UFacade::GetView()
{
	return _view;
}
