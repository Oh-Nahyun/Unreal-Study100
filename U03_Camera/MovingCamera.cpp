// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingCamera.h"

// Sets default values
AMovingCamera::AMovingCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timer += DeltaTime;

	FVector NewLocation = GetActorLocation();
	NewLocation.Y += FMath::Cos(Timer);
	SetActorLocation(NewLocation);
}

