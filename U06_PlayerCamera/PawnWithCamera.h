// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnWithCamera.generated.h"

UCLASS()
class U06_PLAYERCAMERA_API APawnWithCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnWithCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComp;

public:
	// 입력 변수
	FVector2D MovementInput;
	FVector2D CameraInput;
	float ZoomFactor;		// 줌 인/아웃의 정도
	bool bZoomingIn;		// 줌 인/아웃의 여부
	
	// 추가
	float SpeedFactor;
	float CameraPitch;		// 카메라의 상하 방향 회전값

public:
	// 입력 함수
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void PitchCamera(float AxisValue);
	void YawCamera(float AxisValue);
	void ZoomIn();
	void ZoomOut();

	// 추가
	void StartSprint();
	void StopSprint();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float CameraAutoRotationSpeed = 3.0f;	// 보간 속도

};
