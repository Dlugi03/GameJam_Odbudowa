// Fill out your copyright notice in the Description page of Project Settings.

#include "Coin_Actor.h"
#include "TowerManager_Actor.h"
#include "Player_Char.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

ACoin_Actor::ACoin_Actor()
{
	Coin_Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Coin Trigger"));
	Coin_Trigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ACoin_Actor::BeginPlay()
{
	Coin_Trigger->OnComponentBeginOverlap.AddDynamic(this, &ACoin_Actor::OnOverlapBegin);

	Super::BeginPlay();
	
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATowerManager_Actor::StaticClass(), FoundActors);
	TowerManager = Cast<ATowerManager_Actor>(FoundActors[0]);
}

void ACoin_Actor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr && OtherActor->GetClass() == APlayer_Char::StaticClass())
	{
		TowerManager->CoinCollected();
		this->Destroy();
	}
}
