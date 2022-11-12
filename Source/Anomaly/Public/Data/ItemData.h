// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataStructs.h"
#include "Engine/DataAsset.h"
#include "ItemData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ANOMALY_API UItemData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
		TArray<FItem> Data;
	
};
