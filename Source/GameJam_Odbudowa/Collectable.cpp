// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable.h"

// Sets default values
ACollectable::ACollectable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollectableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin Mesh"));
	RootComponent = CollectableMesh; // ->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	CollectableMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	
	BaseHeight = GetActorLocation().Z;

	if (MeshRef != nullptr)
	{
		CollectableMesh->SetStaticMesh(MeshRef);
	}
}

// Called every frame
void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));

	AddActorLocalOffset(FVector(0.0f, 0.0f, FloatingSpeed * DeltaTime * (bFloatingUp ? 1.0f : -1.0f)));

	if (GetActorLocation().Z >= BaseHeight + FloatingHeight)
	{
		bFloatingUp = false;
	}
	else if (GetActorLocation().Z <= BaseHeight)
	{
		bFloatingUp = true;
	}
}

