// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GGrassActor.generated.h"

UCLASS()
class GAMEJAM_API AGGrassActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AGGrassActor();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMeshComponent* Mesh;


	virtual void BeginPlay() override;

};
