// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTaskGraphActor.h"

// Sets default values
AMyTaskGraphActor::AMyTaskGraphActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FMyTaskItem AMyTaskGraphActor::CreateTask(FString TaskName, const TArray<FMyTaskItem>& Prerequisites, const TArray<FMyTaskItem>& ChildTasks, bool DispatchWhenReady /*= true*/)
{
	FGraphEventArray PrerequisiteEvents;
	TArray<TGraphTask<class FJustPrintTask>*> ChildEvents;
	UE_LOG(LogTemp, Log, TEXT("Task[%s] is Created."), *TaskName);
	if (Prerequisites.Num() > 0)
	{
		PrerequisiteEvents.Reserve(Prerequisites.Num());
		for (FMyTaskItem Item : Prerequisites)
		{
			if (Item.GraphTask)
			{
				PrerequisiteEvents.Add(Item.GraphTask->GetCompletionEvent());
				UE_LOG(LogTemp, Log, TEXT("Task[%s] wait Task[%s]."), *TaskName, *Item.TaskName);
			}
			else if (Item.GraphEvent.IsValid())
			{
				PrerequisiteEvents.Add(Item.GraphEvent);
				UE_LOG(LogTemp, Log, TEXT("Task[%s] wait Task[%s]."), *TaskName, *Item.TaskName);
			}
		}
	}

	if (ChildTasks.Num() > 0)
	{
		ChildEvents.Reserve(ChildTasks.Num());
		for (FMyTaskItem Item : ChildTasks)
		{
			if (Item.GraphTask)
			{
				ChildEvents.Add(Item.GraphTask);
				UE_LOG(LogTemp, Log, TEXT("Task[%s] wait Task[%s]."), *Item.TaskName, *TaskName);
			}
		}
	}

	if (DispatchWhenReady)
	{
		return FMyTaskItem(TaskName, TGraphTask<FJustPrintTask>::CreateTask(&PrerequisiteEvents).ConstructAndDispatchWhenReady(TaskName, ChildEvents, this));
	}

	return FMyTaskItem(TaskName, TGraphTask<FJustPrintTask>::CreateTask(&PrerequisiteEvents).ConstructAndHold(TaskName, ChildEvents, this));
}

void AMyTaskGraphActor::FireTask(const FMyTaskItem& Task)
{
	if (Task.GraphTask)
	{
		UE_LOG(LogTemp, Log, TEXT("Task[%s] Fire."), *Task.TaskName);
		Task.GraphTask->Unlock();
	}
}

// Called when the game starts or when spawned
void AMyTaskGraphActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTaskGraphActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

