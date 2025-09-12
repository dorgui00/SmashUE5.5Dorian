// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SmashCharacterMachine.generated.h"

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
		
protected:
	UPROPERTY()
	TObjectPtr<ASmashCharacter> Character;

	// ReSharper disable once CppUE4ProbableMemoryIssuesWithUObjectsInContainer
	TArray<USmashCharacterState*> AllStates;
	void FindStates();
	void InitStates();
};
