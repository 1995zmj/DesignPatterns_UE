// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineRoad.h"
#include "Components/BoxComponent.h"
#include "Components/SplineComponent.h"

// Sets default values
ASplineRoad::ASplineRoad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	startArea = CreateDefaultSubobject<UBoxComponent>(TEXT("StartArea"));
	endArea = CreateDefaultSubobject<UBoxComponent>(TEXT("endArea"));
	splineRoad = CreateDefaultSubobject<USplineComponent>(TEXT("SplineRoad"));
	// mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("test"));
	RootComponent = splineRoad;
	startArea->SetupAttachment(RootComponent);
	startArea->OnComponentBeginOverlap.AddDynamic(this,&ASplineRoad::OnBeginOverlapEvent);
	endArea->OnComponentBeginOverlap.AddDynamic(this,&ASplineRoad::OnBeginOverlapEvent);
	startArea->OnComponentEndOverlap.AddDynamic(this,&ASplineRoad::OnEndOverlapEvent);
	endArea->OnComponentEndOverlap.AddDynamic(this,&ASplineRoad::OnEndOverlapEvent);
	endArea->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASplineRoad::BeginPlay()
{
	Super::BeginPlay();
	auto startRelativeLocation = splineRoad->GetLocationAtSplinePoint(0,ESplineCoordinateSpace::Type::Local);
	startArea->SetRelativeLocation(startRelativeLocation);

	auto endRelativeLocation = splineRoad->GetLocationAtDistanceAlongSpline(splineRoad->GetSplineLength(),ESplineCoordinateSpace::Type::Local);
	endArea->SetRelativeLocation(endRelativeLocation);
}

// Called every frame
void ASplineRoad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

float ASplineRoad::GetTime()
{
	auto inputKey = GetInputKey();
	auto key1 = FMath::FloorToInt(inputKey);
	auto key2 = inputKey - key1;
	auto distance = 0.0f;
	if (key1 >= splineRoad->SplineCurves.Position.Points.Num() - 1)
	{
		distance = splineRoad->GetDistanceAlongSplineAtSplinePoint(key1);
		
	}
	else
	{
		distance = splineRoad->SplineCurves.GetSegmentLength(key1, key2) + splineRoad->GetDistanceAlongSplineAtSplinePoint(key1);
	}
	return distance / splineRoad->GetSplineLength();
}

float ASplineRoad::GetInputKey()
{
	if (curAcotr)
	{
		auto worldPosition = curAcotr->GetActorLocation();
		return splineRoad->FindInputKeyClosestToWorldLocation(worldPosition);
	}
	return 0.0f;
}

void ASplineRoad::OnBeginOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(curAcotr)
	{
		IsValid(OtherActor);
		//UE_LOG(LogTemp,Warning,TEXT("已经有人了"));
	}
	else
	{
		curAcotr = OtherActor;
		EnterRoad();
		count++;
	}
}

void ASplineRoad::OnEndOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

