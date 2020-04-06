// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectable.generated.h"

class UBoxComponent;

UCLASS()
class GAMEJAM_ODBUDOWA_API ACollectable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectable();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* CollectableMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMesh* MeshRef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RotationSpeed = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float FloatingSpeed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float FloatingHeight = 50.0f;

	UPROPERTY(VisibleDefaultsOnly)
	float BaseHeight;

	UPROPERTY(VisibleDefaultsOnly)
	bool bFloatingUp = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
