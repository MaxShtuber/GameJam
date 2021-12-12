// Fill out your copyright notice in the Description page of Project Settings.

#include "GBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

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
	InputComponent->BindAction("EscapeButton", IE_Pressed, this, &AGBaseCharacter::OpenMenu);
	InputComponent->BindAction("Hint", IE_Pressed, this, &AGBaseCharacter::Hint);
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

void AGBaseCharacter::OpenMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), "StartLevel");
}

void AGBaseCharacter::OnDead()
{
	SetLifeSpan(5.0f);
	if (Controller)
	{
		Controller->ChangeState(NAME_Spectating);
	}

}

float AGBaseCharacter::GetDirection()
{
	if (GetVelocity().IsNearlyZero()) return 0.0f;
	auto VelocityNormal = GetVelocity().GetSafeNormal();
	auto AngleBetween = FMath::Acos(FVector::DotProduct(GetActorForwardVector(), VelocityNormal));
	auto Degrees = FMath::RadiansToDegrees(AngleBetween);
	auto CrossProduct = FVector::CrossProduct(GetActorForwardVector(), VelocityNormal);
	return CrossProduct.IsNearlyZero() ? Degrees : Degrees * FMath::Sign(CrossProduct.Z);

}

void AGBaseCharacter::Hint()
{
	IsActive = IsActive ? false : true;
}