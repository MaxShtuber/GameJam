// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class GAMEJAM_API AGBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGBaseCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArmComponent;

	virtual void BeginPlay() override;
private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);
};
