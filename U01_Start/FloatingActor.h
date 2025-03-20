// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class U01_START_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;	///// StaticMesh 포인터 선언

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
	float FloatSpeed;					// 여기서 초기화 해도 되고, 생성자에서 초기화 해줘도 된다. (float FloatSpeed = 20.0f;)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
	float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
	FVector VRunningTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
	FVector VFloatSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
