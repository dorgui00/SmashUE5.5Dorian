// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/States/SmashCharacterStateldle.h"

#include "Character/SmashCharacterStateID.h"


// Sets default values for this component's properties
USmashCharacterStateldle::USmashCharacterStateldle()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USmashCharacterStateldle::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USmashCharacterStateldle::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

ESmashCharacterStateID USmashCharacterStateldle::GetStateID()
{
	return ESmashCharacterStateID::Idle;
}

void USmashCharacterStateldle::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Cyan,
		TEXT("Enter StateIdle")
		);
}

void USmashCharacterStateldle::StateExit(ESmashCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	
	GEngine->AddOnScreenDebugMessage(
	-1,
	3.f,
	FColor::Red,
	TEXT("Exit StateIdle")
	);
}


