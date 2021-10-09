// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadTest.h"
#include "Engine/ObjectLibrary.h"
#include "Engine/StreamableManager.h"

// Sets default values
ALoadTest::ALoadTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("my mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> staticMeshAsset(TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
    if (staticMeshAsset.Succeeded())
    {
	    StaticMeshComp->SetStaticMesh(staticMeshAsset.Object);
    }
    RootComponent = StaticMeshComp;

	ChildActorComp = CreateDefaultSubobject<UChildActorComponent>(TEXT("my child"));
	static ConstructorHelpers::FClassFinder<AActor> BPActor(TEXT("/Game/Element/Editor/BP_Item.BP_Item_C"));
    if (BPActor.Succeeded())
    {
    	ChildActorComp->SetChildActorClass(BPActor.Class);
    }
}

// Called when the game starts or when spawned
void ALoadTest::BeginPlay()
{
	Super::BeginPlay();
	UStaticMesh* pStaticmesh =  LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
	// if (pStaticmesh)
	// {
	// 	StaticMeshComp->SetStaticMesh(pStaticmesh);
	// }
	//
	// UStaticMesh* mesh = FindObject<UStaticMesh>(nullptr, TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));

	StreamableManagerOperate();
}

// Called every frame
void ALoadTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALoadTest::Load()
{
	// auto objectLibrary = UObjectLibrary::CreateLibrary(UObject::StaticClass(),false,false);
	// objectLibrary->AddToRoot();
	// objectLibrary->LoadAssetDataFromPath(TEXT("/Game/FirstPerson/Textures"));
	//
	// TArray<FAssetData> TextureData;
	// objectLibrary->GetAssetDataList(TextureData);
	// for (int i = 0; i < TextureData.Num(); ++i)
	// {
	// 	UE_LOG(LogTemp,Warning,TEXT("%s"),*TextureData[i].ToSoftObjectPath().ToString());
	// }
}

void ALoadTest::StreamableManagerOperate()
{
	// 创建加载管理器
	auto loader = new FStreamableManager();
	// 执行异步加载，添加资源连接数组和加载完毕的回调
	UE_LOG(LogTemp,Warning,TEXT("%s"),*actorPath.ToString());
	FSoftObjectPath tt("/Game/Element/BP_Door.BP_Door_C");
	handle = loader->RequestAsyncLoad(actorPath, FStreamableDelegate::CreateUObject(this, &ALoadTest::StreamableManagerLoadComplete));
}

void ALoadTest::StreamableManagerLoadComplete()
{
	TArray<UObject*> wealthObjects;
	handle->GetLoadedAssets(wealthObjects);
	for (int i = 0; i < wealthObjects.Num(); ++i)
	{
		UClass* wealthClass = Cast<UClass>(wealthObjects[i]);
		auto actor = GetWorld()->SpawnActor<AActor>(wealthClass);
	}
}

