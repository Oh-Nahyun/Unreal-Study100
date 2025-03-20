// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"

// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;													///// false : Tick 사용 안함

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownText"));	///// CountdownText 만들기
	CountdownText->SetHorizontalAlignment(EHTA_Center);										///// 가운데 정렬
	CountdownText->SetWorldSize(150.0f);
	CountdownText->SetupAttachment(RootComponent);											///// 루트에 붙여주기 (위치 이동)

	CountdownTime = 3;
}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();
	
	UpdateTimerDisplay();	///// 시작하자마자 글자 출력
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvencedTimer, 1.0f, true);
}

//// Called every frame
//void ACountdown::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

///// 화면에 글자 출력하는 함수
///// (0으로 최솟값 설정한다.)
void ACountdown::UpdateTimerDisplay()
{
	///// CountdownText->SetText(FText::FromString(FString::FromInt(FMath::Max(CountdownTime, 0))));	///// 방법1
	CountdownText->SetText(FText::AsNumber(FMath::Max(CountdownTime, 0)));								///// 방법2
}

///// 타이머가 호출되는 함수
void ACountdown::AdvencedTimer()
{
	--CountdownTime;
	UpdateTimerDisplay();

	if (CountdownTime < 1)
	{
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);	///// 타이머 삭제
		CountdownHasFinished();										///// Countdown 종료
	}
}

///// 타이머가 종료될 때 실행되는 함수
//void ACountdown::CountdownHasFinished()
//{
//	CountdownText->SetText(FText::FromString(TEXT("GO!")));
//}

///// 타이머가 종료될 때 실행되는 함수
void ACountdown::CountdownHasFinished_Implementation()
{
	CountdownText->SetText(FText::FromString(TEXT("GO!")));
}

