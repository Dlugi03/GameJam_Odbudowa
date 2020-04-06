// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerManager_Actor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDynamicMulticastDelegate);

UCLASS()
class GAMEJAM_ODBUDOWA_API ATowerManager_Actor : public AActor
{
	GENERATED_BODY()
	
public:	

	ATowerManager_Actor();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Tower_Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMesh* TowerBase;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UStaticMesh*> MeshesAtStage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<int32> CoinsForNextStage;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int CoinsAtStage = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int CurrentStage = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int StagesCount = 0;

	UPROPERTY(BlueprintAssignable)
	FDynamicMulticastDelegate OnCoinCollected;

	UPROPERTY(BlueprintAssignable)
	FDynamicMulticastDelegate OnStageChanged;

	UPROPERTY(BlueprintAssignable)
	FDynamicMulticastDelegate OnGameFinished;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bWinGame = false;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
		void CoinCollected();
};
