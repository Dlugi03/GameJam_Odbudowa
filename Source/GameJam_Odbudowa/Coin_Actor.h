// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Coin_Actor.generated.h"

UCLASS()
class GAMEJAM_ODBUDOWA_API ACoin_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoin_Actor();
	//Components
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Coin_Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* Coin_Trigger;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
