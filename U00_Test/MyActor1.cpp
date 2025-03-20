// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"

// Sets default values
AMyActor1::AMyActor1() : CharacterName(TEXT("장원영")), TotalDamage(100), DamageTimeInSecond(1.0f), bAttackable(true)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Log, TEXT("Constructor1")); /////

	///// ==============================
	
	UE_LOG(LogTemp, Error,   TEXT("Error Message"));	// 빨간색
	UE_LOG(LogTemp, Warning, TEXT("Warning Message"));	// 노란색
	UE_LOG(LogTemp, Display, TEXT("Display Message"));	// 하얀색
	//UE_LOG(LogTemp, Fatal,   TEXT("Fatal Message"));	// 크래쉬 리포트 발생!!! (프로그램 중지!!!)
	
	///// ==============================

	//TotalDamage = 200;
	//DamageTimeInSecond = 1.0f;
	//CharacterName = TEXT("장원영");
	//bAttackable = true;
}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("BefinPlay1")); /////

	// Cpp 에서 호출...
	CallFromCpp();
	
}

// Called every frame
void AMyActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/////UE_LOG(LogTemp, Log, TEXT("Tick1")); /////
}

// ------------------------------

void AMyActor1::CallFromCpp_Implementation()
{
	str.Append(TEXT("_Implementation"));
	CharacterName.Append(TEXT("_Implementation"));
}

void AMyActor1::FunctionName()
{
	// 동작 및 행동 추가하기...
}

/// <summary>
/// 초당 데미지 계산 함수
/// </summary>
void AMyActor1::CalculateDPS()
{
	DamagePerSecond = TotalDamage / DamageTimeInSecond;
}

void AMyActor1::PostInitProperties()
{
	Super::PostInitProperties();
	CalculateDPS();
}

void AMyActor1::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	CalculateDPS();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
