// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin_Actor.h"

// Sets default values
ACoin_Actor::ACoin_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Coin_Mesh
	Coin_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin Mesh"));
	Coin_Mesh->SetupAttachment(RootComponent);
	
	//Coin_Trigger
	Coin_Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Coin Trigger"));
	Coin_Trigger->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	Coin_Trigger->OnComponentBeginOverlap.AddDynamic(this, &ACoin_Actor::OnOverlapBegin);

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

	AddActorLocalRotation(FRotator(0.0f, 0.0f, 5.0f * DeltaTime).Quaternion());
}

void ACoin_Actor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Other Actor is the actor that triggered the event. Check that is not ourself.  
	if ((OtherActor != nullptr))
	{
		//TODO: if OtherActor == PlayerActor Class
		this->Destroy();
	}
}
