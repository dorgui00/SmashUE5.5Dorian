// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SmashCharacterMachine.generated.h"

enum class ESmashCharacterStateID: uint8;
enum class ESmashCharacterState : uint8;
class USmashCharacterState;
class ASmashCharacter;
/**
 * 
 */
UCLASS()
class SMASHUE_API USmashCharacterMachine : public UObject
{
	GENERATED_BODY()

public:
	void Init(ASmashCharacter* InCharacter);
	ASmashCharacter* GetCharacter() const;
	UFUNCTION(BlueprintCallable)
	void ChangeState(ESmashCharacterStateID NexStateID);
	USmashCharacterState* GetState(ESmashCharacterStateID NexStateID);
		
protected:
	UPROPERTY()
	TObjectPtr<ASmashCharacter> Character;

	UPROPERTY(BlueprintReadOnly)
	ESmashCharacterStateID CurrentStateID;

	UPROPERTY()
	TObjectPtr<USmashCharacterState> CurrentState;
	
	// ReSharper disable once CppUE4ProbableMemoryIssuesWithUObjectsInContainer
	TArray<USmashCharacterState*> AllStates;
	void FindStates();
	void InitStates();
};
