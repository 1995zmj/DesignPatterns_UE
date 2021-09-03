// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SplineRoad.generated.h"

class UBoxComponent;
class USplineComponent;
//class ACameraRig_Rail;
UCLASS()
class DESIGNPATTERNS_UE_API ASplineRoad : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ASplineRoad();
	UPROPERTY(EditAnywhere)
	UBoxComponent* startArea;
	UPROPERTY(EditAnywhere)
	UBoxComponent* endArea;
	UPROPERTY(EditAnywhere)
	USplineComponent* splineRoad;
	/*UPROPERTY(EditAnywhere)
	ACameraRig_Rail* cameraRigRail;*/
	UPROPERTY(BlueprintReadOnly)
	AActor* curAcotr;
	int count;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	float GetTime();

	UFUNCTION(BlueprintCallable)
	float GetInputKey();

	UFUNCTION(BlueprintImplementableEvent)
	void EnterRoad();

	UFUNCTION()
	void OnBeginOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnEndOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
