// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Scavanger.h"

#include "Gamemodes/BaseGameMode.h"


AScavanger::AScavanger()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Init the capsule by setting the radius and half height of it
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	CameraBoom->TargetArmLength = 150.0f; // The length of which the camera is from the player
	CameraBoom->bUsePawnControlRotation = false; // Mouse moves the arm that is attached to camera

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	FollowCamera->bUsePawnControlRotation = false; // Mouse does not move the actual camera
}

void AScavanger::MoveRight(float Axis)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector FDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(FDirection, Axis);
}

void AScavanger::AddItem(FName ItemID)
{
	ABaseGameMode* GMode = GetWorld()->GetAuthGameMode<ABaseGameMode>();
	bool has_item = false;
	FItem Item = GMode->FindItem_Implementation(ItemID, has_item);
	if(has_item)
	{
		Inventory.Push(Item);
	}
}

bool AScavanger::HasFreeInventorySlots()
{
	return (Inventory.Num() < TotalInventorySlots);
}

void AScavanger::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveRight", this, &AScavanger::MoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APaperCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APaperCharacter::StopJumping);
}
