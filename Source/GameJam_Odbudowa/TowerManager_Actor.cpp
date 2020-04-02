// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerManager_Actor.h"

// Sets default values
ATowerManager_Actor::ATowerManager_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Tower_Mesh
	Tower_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tower Mesh"));
	RootComponent = Tower_Mesh; //->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void ATowerManager_Actor::BeginPlay()
{
	Super::BeginPlay();

	if(TowerBase != nullptr)
		Tower_Mesh->SetStaticMesh(TowerBase);

	CoinsAtStage = 0;
}

// Called every frame
void ATowerManager_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATowerManager_Actor::CoinCollected()
{
	//If Win Game, ignore this function
	if (StagesCoins.Num() <= CurrentStage)
		return;

	CoinsAtStage++;

	if (StagesCoins[CurrentStage] <= CoinsAtStage)
	{
		CoinsAtStage = 0;
		Tower_Mesh->SetStaticMesh(StagesMeshes[CurrentStage]);

		CurrentStage++;

		if (StagesCoins.Num() <= CurrentStage)
		{
			//TODO: WinGame
		}
	}
}

