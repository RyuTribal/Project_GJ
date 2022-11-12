// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/DataStructs.h"
#include "GameFramework/GameModeBase.h"
#include "Data/ItemData.h"
#include "BaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ANOMALY_API ABaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item System")
		class UItemData* ItemDatabase;

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Item System")
		FItem FindItem(FName ItemID, bool& Success);

	FItem FindItem_Implementation(FName ItemID, bool& Success);
	
};
