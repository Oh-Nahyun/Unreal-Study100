// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh")); ///// StaticMeshComponent 가 Mesh 라는 이름을 가지도록 생성하고,
	VisualMesh->SetupAttachment(RootComponent);								 ///// RootComponent 에 붙여준다.

	///// D:/Unreal_Projects/Cpp/U01_Start/Content == Root == Game
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);					///// VisualMesh 에 CubeVisualAsset 를 붙여준다.
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));			///// VisualMesh 의 위치값 초기화 해준다.
	}
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
	///// 초기화
	FloatSpeed = 20.0f;
	RotationSpeed = 20.0f;

	VFloatSpeed = FVector(1.0f, 1.0f, 1.0f);
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//// #01. 기본 상하 이동 & 좌우 회전
	//FVector NewLocation = GetActorLocation();					///// 위치값 가져오기
	//FRotator NewRotation = GetActorRotation();				///// 회전값 가져오기

	//float RunningTime = GetGameTimeSinceCreation();			///// RunningTime += DeltaTime; 와 같은 의미

	//float DeltaHeight = FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime);
	//NewLocation.Z += DeltaHeight * 20.0f;

	//float DeltaRotation = DeltaTime * 20.0f;					///// 20도 회전 (DeltaTime + 20.0f => 가중치)
	//NewRotation.Yaw += DeltaRotation;

	//SetActorLocationAndRotation(NewLocation, NewRotation);	///// 위치 & 회전값 설정하기

	// ------------------------------

	//// #02. 기본 상하 이동 & 좌우 회전 (프로퍼티 입력)
	//FVector NewLocation = GetActorLocation();					///// 위치값 가져오기
	//FRotator NewRotation = GetActorRotation();				///// 회전값 가져오기

	//float RunningTime = GetGameTimeSinceCreation();			///// RunningTime += DeltaTime; 와 같은 의미

	//float DeltaHeight = FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime);
	//NewLocation.Z += DeltaHeight * FloatSpeed;

	//float DeltaRotation = DeltaTime * RotationSpeed;		
	//NewRotation.Yaw += DeltaRotation;

	//SetActorLocationAndRotation(NewLocation, NewRotation);

	// ------------------------------

	//// #02. 기본 상하 이동 & 좌우 회전 (프로퍼티 입력) + 이동 벡터 추가
	FVector NewLocation = GetActorLocation();					///// 위치값 가져오기
	FRotator NewRotation = GetActorRotation();					///// 회전값 가져오기

	float CurrentTime = GetGameTimeSinceCreation();				///// RunningTime += DeltaTime; 와 같은 의미
	VRunningTime = FVector(CurrentTime, CurrentTime, CurrentTime);

	float DeltaX = FMath::Sin(VRunningTime.X + DeltaTime * VFloatSpeed.X) - FMath::Sin(VRunningTime.X);
	float DeltaY = FMath::Sin(VRunningTime.Y + DeltaTime * VFloatSpeed.Y) - FMath::Sin(VRunningTime.X);
	float DeltaZ = FMath::Sin(VRunningTime.Z + DeltaTime * VFloatSpeed.Z) - FMath::Sin(VRunningTime.X);

	//float DeltaHeight = FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime);
	//NewLocation.Z += DeltaHeight * FloatSpeed;
	NewLocation += FVector(DeltaX, DeltaY, DeltaZ) * FloatSpeed;
	/////NewLocation += FVector(DeltaX, DeltaY, DeltaZ) * 20.0f;
	/////VRunningTime += DeltaTime * VFloatSpeed;

	float DeltaRotation = DeltaTime * RotationSpeed;		
	NewRotation.Yaw += DeltaRotation;

	SetActorLocationAndRotation(NewLocation, NewRotation);
}

