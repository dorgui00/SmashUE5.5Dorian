﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashCharacterState.h"

#include "Character/SmashCharacterMachine.h"
#include "Character/SmashCharacterStateID.h"


// Sets default values for this component's properties
USmashCharacterState::USmashCharacterState()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

ESmashCharacterStateID USmashCharacterState::GetStateID()
{
	return ESmashCharacterStateID::Nome;
}

void USmashCharacterState::StateInit(USmashCharacterMachine* InStateMachine)
{
	StateMachine = InStateMachine;
	Character = InStateMachine->GetCharacter();
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Magenta,
		FString::Printf(TEXT("Init State %d"),GetStateID())
		);
}





