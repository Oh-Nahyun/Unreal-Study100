// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CollidingPawn.generated.h"

UCLASS()
class U05_COLL_API ACollidingPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollidingPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 언리얼 엔진의 다른 클래스가 Pawn 에 사용 중인 UPawnMovementComponent 에 접근할 때, 사용하는 함수
	virtual UPawnMovementComponent* GetMovementComponent() const override;

public:
	class UParticleSystemComponent* OurPartivleSystem;

	class UCollidingPawnMovementComponent* OurMovementComponent;

public:
	void MoveForward(float AxisValue);

	void MoveRight(float AxisValue);

	void Turn(float AxisValue);

	void ParticleToggle();

};
