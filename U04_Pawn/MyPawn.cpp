// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Camera/CameraComponent.h"		// "Engine/Classes/Camera/Camera/CameraComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 컨트롤러 입력이 가능하도록 설정하기
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// 붙일 더미 루트 컴포넌트 생성하기
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// 카메라와 보이는 오브젝트
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	// 루트 컴포넌트에 카메라와 보이는 오브젝트 붙이기
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	OurVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ------------------------------
	// 여기에서 이동 & 액션 처리

	// 크고 작아지는 부분
	float CurrentScale = OurVisibleComponent->GetComponentScale().X;
	if (bGrowing)
	{
		CurrentScale += DeltaTime;
	}
	else
	{
		CurrentScale -= DeltaTime * 0.5f;
	}
	CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 2.0f);
	OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));

	// 이동 처리 부분
	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 스페이스 키를 누르거나 뗄 때의 반응
	PlayerInputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawn::StartGrowing);
	PlayerInputComponent->BindAction("Grow", IE_Released, this, &AMyPawn::StopGrowing);

	// 매 프레임마다의 반응 (이동)
	PlayerInputComponent->BindAxis("MoveX", this, &AMyPawn::Move_XAxis);
	PlayerInputComponent->BindAxis("MoveY", this, &AMyPawn::Move_YAxis);
}

void AMyPawn::Move_XAxis(float AxisValue)
{
	// 초당 100의 속도로 유닛을 앞 또는 뒤로 이동시킨다.
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100;
}

void AMyPawn::Move_YAxis(float AxisValue)
{
	// 초당 100의 속도로 유닛을 오른쪽 또는 왼쪽으로 이동시킨다.
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100;
}

void AMyPawn::StartGrowing()
{
	bGrowing = true;
}

void AMyPawn::StopGrowing()
{
	bGrowing = false;
}
