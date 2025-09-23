// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SmashCharacterMachine.h"

#include "SmashCharacterState.h"
#include "Arena/SmashCharacter.h"
#include "Character/SmashCharacterStateID.h"


void USmashCharacterMachine::Init(ASmashCharacter* InCharacter)
{
	Character = InCharacter;
	FindStates();
	InitStates();

	ChangeState(ESmashCharacterStateID::Idle);
}

ASmashCharacter* USmashCharacterMachine::GetCharacter() const
{
	return Character;
}

void USmashCharacterMachine::FindStates()
{
	TArray<UActorComponent*> FoundCompents = Character->K2_GetComponentsByClass(USmashCharacterState::StaticClass());
	for (UActorComponent* StateComponent : FoundCompents)
	{
		USmashCharacterState* State = Cast<USmashCharacterState>(StateComponent);
		if (State == nullptr)continue;
		if (State->GetStateID()==ESmashCharacterStateID::Nome)continue;
		AllStates.Add(State);
	}
}

void USmashCharacterMachine::InitStates()
{
	for (USmashCharacterState* State : AllStates)
	{
		State->StateInit(this);
	}
}

USmashCharacterState* USmashCharacterMachine::GetState(ESmashCharacterStateID StateID)
{
	for (USmashCharacterState* State : AllStates)
	{
		if (StateID == State->GetStateID())
			return State;
	}
	return nullptr;
}

void USmashCharacterMachine::ChangeState(ESmashCharacterStateID NextStateID)
{
	USmashCharacterState* NextState = GetState(NextStateID);

	if (NextState == nullptr)return;

	if (CurrentState != nullptr)
	{
		CurrentState->StateExit(NextStateID);
	}

	ESmashCharacterStateID PreviousStateID = CurrentStateID;
	CurrentStateID = NextStateID;
	CurrentState = NextState;

	if (CurrentState != nullptr)
	{
		CurrentState->StateEnter(PreviousStateID);
	}
}

void USmashCharacterMachine::Tick(float DeltaTime)
{
	if (CurrentState == nullptr) return;
	CurrentState->StateTick(DeltaTime);
}
