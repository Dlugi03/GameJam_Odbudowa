// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerManager_Actor.h"

// Sets default values
ATowerManager_Actor::ATowerManager_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Tower_Mesh
	Tower_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tower Mesh"));
	Tower_Mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void ATowerManager_Actor::BeginPlay()
{
	Super::BeginPlay();
	
	StagesLeft = TowerStages.Num();
	CointsForNextStage = CoinsForOneStage;

	Tower_Mesh->SetStaticMesh(TowerStages[TowerStages.Num() - StagesLeft]);
}

// Called every frame
void ATowerManager_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATowerManager_Actor::CoinCollected()
{
	CointsForNextStage--;
	if (CointsForNextStage <= 0)
	{
		StagesLeft--;
		if (StagesLeft <= 0)
		{
			//TODO: Call Game Manager Win Game
		}
		CointsForNextStage = CoinsForOneStage;

		Tower_Mesh->SetStaticMesh(TowerStages[TowerStages.Num() - StagesLeft]);
	}
}

