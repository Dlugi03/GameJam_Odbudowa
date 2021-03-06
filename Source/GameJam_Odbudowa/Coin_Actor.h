// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectable.h"
#include "GameFramework/Actor.h"
#include "Coin_Actor.generated.h"

class UBoxComponent;
class ATowerManager_Actor;

UCLASS()
class GAMEJAM_ODBUDOWA_API ACoin_Actor : public ACollectable
{
	GENERATED_BODY()
	
public:	

	ACoin_Actor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* Coin_Trigger;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ATowerManager_Actor* TowerManager;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
