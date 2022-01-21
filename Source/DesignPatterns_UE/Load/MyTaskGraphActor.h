// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTaskGraphActor.generated.h"
USTRUCT(BlueprintType)
struct FMyTaskItem {
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString TaskName;
	FGraphEventRef GraphEvent;
	TGraphTask<class FJustPrintTask>* GraphTask;

	FMyTaskItem() :TaskName(TEXT("NoName")), GraphEvent(nullptr), GraphTask(nullptr) {}
	FMyTaskItem(FString Name, FGraphEventRef EventRef = FGraphEventRef()) :TaskName(Name), GraphEvent(EventRef), GraphTask(nullptr) {}
	FMyTaskItem(FString Name, TGraphTask<class FJustPrintTask>* Task = nullptr) :TaskName(Name), GraphEvent(nullptr), GraphTask(Task) {}
	~FMyTaskItem() { GraphEvent = nullptr; }
};




UCLASS()
class DESIGNPATTERNS_UE_API AMyTaskGraphActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTaskGraphActor();

	UFUNCTION(BlueprintCallable)
	FMyTaskItem CreateTask(FString TaskName, const TArray<FMyTaskItem>& Prerequisites, const TArray<FMyTaskItem>& ChildTasks, bool DispatchWhenReady = true);

	UFUNCTION(BlueprintCallable)
	FMyTaskItem CreateTaskPure(FString TaskName, bool DispatchWhenReady = true)
	{
		TArray<FMyTaskItem> Empty;
		return CreateTask(TaskName, Empty, Empty, DispatchWhenReady);
	}

	UFUNCTION(BlueprintCallable)
	FMyTaskItem CreaetTaskWithPrerequisitesOnly(FString TaskName, const TArray<FMyTaskItem>& Prerequisites, bool DispatchWhenReady = true)
	{
		return CreateTask(TaskName, Prerequisites, TArray<FMyTaskItem>(), DispatchWhenReady);
	}
	UFUNCTION(BlueprintCallable)
	FMyTaskItem CreateTaskWithChildTasksOnly(FString TaskName, const TArray<FMyTaskItem>& ChildTasks, bool DispatchWhenReady = true)
	{
		return CreateTask(TaskName, TArray<FMyTaskItem>(), ChildTasks, DispatchWhenReady);
	}


	UFUNCTION(BlueprintCallable)
		void FireTask(const FMyTaskItem& Task);

	UFUNCTION(BlueprintImplementableEvent)
		void OnTaskComplete(const FString& TaskName);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

class FReportTask
{
	FString TaskName;
	AActor* TaskOwner;
public:
	FReportTask(FString Name, AActor* Actor) : TaskName(Name), TaskOwner(Actor) {}
	~FReportTask() {}
	FORCEINLINE TStatId GetStatId() const { RETURN_QUICK_DECLARE_CYCLE_STAT(FReportTask, STATGROUP_TaskGraphTasks); }

	static ENamedThreads::Type GetDesiredThread()
	{
		return ENamedThreads::GameThread;
	}
	static ESubsequentsMode::Type GetSubsequentsMode() { return ESubsequentsMode::TrackSubsequents; }
	void DoTask(ENamedThreads::Type CurrentThread, const FGraphEventRef& MyCompletionGraphEvent)
	{
		AMyTaskGraphActor* Actor = Cast<AMyTaskGraphActor>(TaskOwner);
		if (IsValid(Actor))
		{
			Actor->OnTaskComplete(TaskName);
		}
	}
};

class FJustPrintTask
{
	FString TaskName;
	TArray<TGraphTask<FJustPrintTask>*> ChildEvents;
	AActor* TaskOwner;
public:
	FJustPrintTask(FString Name, TArray<TGraphTask<FJustPrintTask>*> Events, AActor* Actor) :TaskName(Name), ChildEvents(Events), TaskOwner(Actor) {}
	~FJustPrintTask() {}
	FORCEINLINE TStatId GetStatId() const { RETURN_QUICK_DECLARE_CYCLE_STAT(FJustPrintTask, STATGROUP_TaskGraphTasks); }

	static ENamedThreads::Type GetDesiredThread()
	{
		return ENamedThreads::AnyThread;
	}

	static ESubsequentsMode::Type GetSubsequentsMode() { return ESubsequentsMode::TrackSubsequents; }

	void DoTask(ENamedThreads::Type CurrentThread, const FGraphEventRef& MyCompletionGraphEvent)
	{
		UE_LOG(LogTemp, Log, TEXT(__FUNCTION__ " %s:Begin"), *TaskName);
		for (TGraphTask<FJustPrintTask>* Task : ChildEvents)
		{
			if (Task)
			{
				Task->Unlock();
				MyCompletionGraphEvent->DontCompleteUntil(Task->GetCompletionEvent());
				/*while (!Task->GetCompletionEvent()->IsComplete())
				{
					FPlatformProcess::Sleep(0.01f);
				}*/
			}
		}
		// do something
		MyCompletionGraphEvent->DontCompleteUntil(TGraphTask<FReportTask>::CreateTask().ConstructAndDispatchWhenReady(TaskName, TaskOwner));
		UE_LOG(LogTemp, Log, TEXT(__FUNCTION__ " %s:End"), *TaskName);
	}
};

