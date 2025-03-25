// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerSceneComponent.h"

// Sets default values for this component's properties
USpawnerSceneComponent::USpawnerSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	// 하나만 만들 경우
	// UStaticMeshComponent* child = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Child"));

	// 여러개 만들 경우 (반복문)
	for (int i = 0; i < 3; i++)
	{
		UStaticMeshComponent* Child = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("Child"), i));
		Child->SetupAttachment(this);

		ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid"));
		if (MeshAsset.Succeeded())
		{
			Child->SetStaticMesh(MeshAsset.Object);
		}

		// 위치값
		float radian = (2.0f * PI) / 3.0f;
		radian *= i;
		FVector Location = FVector(FMath::Cos(radian), FMath::Sin(radian), 0.0f) * 100.0f;
		Child->SetRelativeLocation(Location);

		Childs.Add(Child);
	}

	// 소멸 시간
	DestroyTimer = 5.0f;
}


// Called when the game starts
void USpawnerSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpawnerSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	// 타이머 값을 체크하여 컴포넌트를 소멸시켜 준다.
	DestroyTimer -= DeltaTime;

	if (DestroyTimer < 0.0f)
	{
		for (int i = 0; i < Childs.Num(); i++)
		{
			Childs[i]->DestroyComponent();
		}
		DestroyComponent();
	}
}

