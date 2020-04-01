// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin_Actor.h"

// Sets default values
ACoin_Actor::ACoin_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Coin_Mesh
	Coin_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin Mesh"));
	RootComponent = Coin_Mesh;
	
	//Coin_Trigger
	Coin_Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Coin Trigger"));
	Coin_Trigger->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	Coin_Trigger->OnComponentBeginOverlap.AddDynamic(this, &ACoin_Actor::OnBeginOverlap)

}

// Called when the game starts or when spawned
void ACoin_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoin_Actor::OnBeginOverlap(AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
}

