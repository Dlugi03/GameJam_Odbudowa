// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerManager_Actor.generated.h"

UCLASS()
class GAMEJAM_ODBUDOWA_API ATowerManager_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerManager_Actor();
	//Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Tower_Mesh;
	//Variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<UStaticMesh*> TowerStages;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int StagesLeft; //TowerStages count, -- for next unlocked server
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int CoinsForOneStage = 2;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int CointsForNextStage; //Coints left for next tower stage

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void CoinCollected();
};
