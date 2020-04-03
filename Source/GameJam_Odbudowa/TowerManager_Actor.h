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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int CurrentStage = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UStaticMesh* TowerBase; //Tower Mesh at game start
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<UStaticMesh*> MeshesAtStage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<int32> CoinsForNextStage;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int CoinsAtStage = 0; //Current Coins for Current Stage

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
		void CoinCollected();
};
