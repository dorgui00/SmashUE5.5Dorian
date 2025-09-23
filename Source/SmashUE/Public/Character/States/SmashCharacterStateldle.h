// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/SmashCharacterState.h"
#include "SmashCharacterStateldle.generated.h"


UCLASS(ClassGroup=(SmashCharacterState), meta=(BlueprintSpawnableComponent))
class SMASHUE_API USmashCharacterStateldle : public USmashCharacterState
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	//USmashCharacterStateldle();
	virtual ESmashCharacterStateID GetStateID() override;
	virtual void StateEnter(ESmashCharacterStateID PreviousStateID) override;
	virtual void StateExit(ESmashCharacterStateID NextStateID)override;
	virtual  void StateTick(float DeltaTime) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
