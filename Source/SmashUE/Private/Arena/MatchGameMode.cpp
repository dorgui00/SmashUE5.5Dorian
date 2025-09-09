// Fill out your copyright notice in the Description page of Project Settings.


#include "Arena/MatchGameMode.h"
#include "Arena/ArenaPlayerStart.h"
#include "kismet/GameplayStatics.h"

void AMatchGameMode::FindPlayerStartActorsInArena(TArray<AArenaPlayerStart*>& ResultsActors)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AArenaPlayerStart::StaticClass(), FoundActors);

	for (int i = 0; i < FoundActors.Num(); i++)
	{
		AArenaPlayerStart* ArenaPlayerStarActor = Cast<AArenaPlayerStart>(FoundActors[i]);
		if (ArenaPlayerStarActor == nullptr) continue;
		
		ResultsActors.Add(ArenaPlayerStarActor);
	}
}

void AMatchGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AArenaPlayerStart*> PlayerStartPoints;
	FindPlayerStartActorsInArena(PlayerStartPoints);

	for (AArenaPlayerStart* PlayerStartPoint : PlayerStartPoints)
	{
		GEngine->AddOnScreenDebugMessage(
		 - 1,
		 3.f,
		 FColor::Cyan,
		 PlayerStartPoint -> GetFName().ToString()
		 );
	}
	
}