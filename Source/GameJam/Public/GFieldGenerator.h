// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GFieldGenerator.generated.h"

class AGGrassActor;

UCLASS()
class GAMEJAM_API AGFieldGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	AGFieldGenerator();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UStaticMesh*> BlockTypes;

	void GenerateField();
};
