// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectable.h"
#include "GameFramework/Actor.h"
#include "Contract.generated.h"

class UBoxComponent;

UCLASS()
class GAMEJAM_ODBUDOWA_API AContract : public ACollectable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AContract();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* CollectableTrigger;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};