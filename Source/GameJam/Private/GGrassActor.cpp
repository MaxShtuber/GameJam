// Fill out your copyright notice in the Description page of Project Settings.

#include "GGrassActor.h"

AGGrassActor::AGGrassActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

void AGGrassActor::BeginPlay()
{
	Super::BeginPlay();
	
}

