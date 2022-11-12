// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemodes/BaseGameMode.h"

FItem ABaseGameMode::FindItem_Implementation(FName ItemID, bool& Success)
{
	Success = false;

	FItem Item;
	if (ItemDatabase == nullptr) { return Item; }

	for (int i = 0; i < ItemDatabase->Data.Num(); i++)
	{
		if(ItemDatabase->Data[i].ItemID == ItemID)
		{
			Success = true;
			return ItemDatabase->Data[i];
		}
	}

	return Item;
}


