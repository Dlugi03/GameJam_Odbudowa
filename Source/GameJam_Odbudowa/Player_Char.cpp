// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Char.h"

// Sets default values
APlayer_Char::APlayer_Char()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//FP_Cam
	FP_Cam = CreateDefaultSubobject<UCameraComponent>(TEXT("FP Cam"));
	FP_Cam->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	FP_Cam->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));

	bUseControllerRotationPitch = true;
}

// Called to bind functionality to input
void APlayer_Char::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward_Input", this, &APlayer_Char::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight_Input", this, &APlayer_Char::MoveRight);
	PlayerInputComponent->BindAxis("TurnRight_Input", this, &APlayer_Char::TurnRight);
	PlayerInputComponent->BindAxis("LookUp_Input", this, &APlayer_Char::LookUp);
}

void APlayer_Char::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor != nullptr && OtherActor != this)
	{
		//TODO: if(OtherActor.IsA(EnemyClass))
		//{
			//bGameOver = true;
		//}
	}
}

void APlayer_Char::OnContractPicked()
{
	IsPickingUpContract = true;
	FTimerHandle MemberTimerHandle;

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &APlayer_Char::DropContract, 8.0f, true);
}

void APlayer_Char::DropContract()
{
	IsCarryingContract = false;

	if (Delegate.IsBound())
	{
		Delegate.Broadcast();
	}
}

void APlayer_Char::MoveForward(float Value)
{
	FVector forward = FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::X);
	forward = FVector(forward.X, forward.Y, 0.0f).GetSafeNormal();
	AddMovementInput(forward, Value);
}

void APlayer_Char::MoveRight(float Value)
{
	FVector right = FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::Y);
	right = FVector(right.X, right.Y, 0.0f).GetSafeNormal();
	AddMovementInput(right, Value);
}

void APlayer_Char::TurnRight(float Value)
{
	AddControllerYawInput(Value);
}

void APlayer_Char::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

