// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Player_Char.generated.h"

UCLASS()
class GAMEJAM_ODBUDOWA_API APlayer_Char : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayer_Char();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCameraComponent* FP_Cam;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveForward(float Value);
	UFUNCTION()
		void MoveRight(float Value);
	UFUNCTION()
		void TurnRight(float Value);
	UFUNCTION()
		void LookUp(float Value);
};
