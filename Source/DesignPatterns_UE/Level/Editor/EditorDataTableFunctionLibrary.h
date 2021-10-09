// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EditorDataTableFunctionLibrary.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FVolumeItem : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FBoxSphereBounds bound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FStringAssetReference ar;
};


UCLASS()
class DESIGNPATTERNS_UE_API UEditorDataTableFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category = "Editor Scripting | DataTabe", DisplayName = "AddRowToDataTable")
	static void AddVolumeToDataTable(UDataTable* dataTable, FName rowName, const FVolumeItem& row);
	UFUNCTION(BlueprintCallable, Category = "Editor Scripting | DataTable", DisplayName =  "ClearDataTable")
	static void ClearDataTable(UDataTable* dataTable);
	UFUNCTION(BlueprintCallable, Category = "Editor Scripting | DataTabel", DisplayName = "DataTableRemoveRow")
	static void DataTableRemoveRow(UDataTable* dataTable,FName rowName);


	UFUNCTION(BlueprintCallable, Category = "Editor Scripting | DataAsset")
	static UDataTable* CreateNewDataTable(const FString PackagePath,const FString AssetName,UScriptStruct* RowStruct);

	UFUNCTION(BlueprintCallable, Category = "Editor Scripting | Asset")
	static UObject* CreateNewAsset(TSubclassOf<UObject> OjbectClass, const FString PackagePath, const FString AssetName);
	
	UFUNCTION(BlueprintCallable, Category = "Editor Scripting | DataAsset")
	static FString GetClassPath(UObject* object);
#endif
};
