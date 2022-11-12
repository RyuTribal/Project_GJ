// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataStructs.generated.h"

USTRUCT(BlueprintType)
struct FItem
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
		FName ItemID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
		FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
		FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
		FText NoteText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		TSubclassOf<class AActor> ItemActor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		UTexture2D* ItemIcon;




};
