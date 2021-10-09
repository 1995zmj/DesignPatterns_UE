// Fill out your copyright notice in the Description page of Project Settings.


#include "EditorDataTableFunctionLibrary.h"

#include "AssetRegistryModule.h"
#include "UItemBase.h"

void UEditorDataTableFunctionLibrary::AddVolumeToDataTable(UDataTable* dataTable, FName rowName, const FVolumeItem& row)
{
	if (dataTable == nullptr)
	{
		return;
	}

	dataTable->AddRow(rowName, row);
	dataTable->GetOutermost()->MarkPackageDirty();
}

void UEditorDataTableFunctionLibrary::ClearDataTable(UDataTable* dataTable)
{
	if (dataTable == nullptr)
	{
		return;
	}

	dataTable->EmptyTable();
	dataTable->GetOutermost()->MarkPackageDirty();
}

void UEditorDataTableFunctionLibrary::DataTableRemoveRow(UDataTable* dataTable, FName rowName)
{
	if (dataTable == nullptr)
	{
		return;
	}

	dataTable->RemoveRow(rowName);
	dataTable->GetOutermost()->MarkPackageDirty();
}

UDataTable* UEditorDataTableFunctionLibrary::CreateNewDataTable(const FString PackagePath, const FString AssetName,
	UScriptStruct* RowStruct)
{
	auto dataTableAsset = Cast<UDataTable>(CreateNewAsset(UDataTable::StaticClass(),PackagePath,AssetName));
	dataTableAsset->RowStruct = RowStruct;
	return dataTableAsset;
}

UObject* UEditorDataTableFunctionLibrary::CreateNewAsset(TSubclassOf<UObject> OjbectClass, const FString PackagePath,
                                                         const FString AssetName)
{
	//创建package
	UPackage* MyPackage = CreatePackage(nullptr, *PackagePath);

	//创建Object
	auto asset = NewObject<UObject>(MyPackage, OjbectClass, *AssetName,EObjectFlags::RF_Public | RF_Standalone);
	if (nullptr == asset)
	{
		return nullptr;
	}

	FAssetRegistryModule::AssetCreated(asset); //告知资源浏览器
	asset->GetOutermost()->MarkPackageDirty(); //标星号
	return asset;
}


FString UEditorDataTableFunctionLibrary::GetClassPath(UObject* object)
{
	auto tc = object->GetClass();
	auto t = tc->GetPathName();
	auto tt = object->GetPathName();

	UE_LOG(LogTemp,Warning,TEXT("soft object %s"),*tt);
	UE_LOG(LogTemp,Warning,TEXT("soft class %s"),*t);
	return t;
}
