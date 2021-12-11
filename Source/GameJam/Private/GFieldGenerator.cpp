// Fill out your copyright notice in the Description page of Project Settings.

#include "GFieldGenerator.h"
#include "GGrassActor.h"

AGFieldGenerator::AGFieldGenerator()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AGFieldGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGFieldGenerator::GenerateField()
{
	auto TypesNum = BlockTypes.Num();

	for (auto i = 0; i < 5; i++)
	{
	}
}