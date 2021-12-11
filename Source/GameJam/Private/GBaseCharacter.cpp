// Fill out your copyright notice in the Description page of Project Settings.

#include "GBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"

AGBaseCharacter::AGBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void AGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveForward", this, &AGBaseCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AGBaseCharacter::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AGBaseCharacter::Jump);
	InputComponent->BindAxis("TurnAround", this, &AGBaseCharacter::AddControllerYawInput);
}

void AGBaseCharacter::MoveForward(float Amount)
{
	if (FMath::IsNearlyZero(Amount)) return;

	AddMovementInput(GetActorForwardVector(), Amount);
}

void AGBaseCharacter::MoveRight(float Amount)
{
	if (FMath::IsNearlyZero(Amount)) return;

	AddMovementInput(GetActorRightVector(), Amount);
}
