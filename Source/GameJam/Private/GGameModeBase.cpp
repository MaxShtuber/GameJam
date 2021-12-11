// Fill out your copyright notice in the Description page of Project Settings.

#include "GGameModeBase.h"
#include "GBaseCharacter.h"
#include "GPlayerController.h"

AGGameModeBase::AGGameModeBase()
{
	DefaultPawnClass = AGBaseCharacter::StaticClass();
	PlayerControllerClass = AGPlayerController::StaticClass();
}