// Fill out your copyright notice in the Description page of Project Settings.


#include "Contract.h"
#include "Components/BoxComponent.h"
#include "Player_Char.h"

// Sets default values
AContract::AContract()
{
	CollectableTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Coin Trigger"));
	CollectableTrigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AContract::BeginPlay()
{
	CollectableTrigger->OnComponentBeginOverlap.AddDynamic(this, &AContract::OnOverlapBegin);

	Super::BeginPlay();
}

void AContract::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr)
	{
		return;
	}

	APlayer_Char* Player = Cast<APlayer_Char>(OtherActor);

	if (Player)
	{
		Player->IsPickingUpContract = true;
		this->Destroy();
	}
}

