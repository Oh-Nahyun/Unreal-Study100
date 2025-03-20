// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/TextRenderComponent.h"
//#include "Runtime/Engine/Classes/Components/TextRenderComponents.h"

#include "Countdown.generated.h"

UCLASS()
class U02_TIMER_API ACountdown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountdown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//// Called every frame
	//virtual void Tick(float DeltaTime) override;

public:
	///// Timer Number
	UPROPERTY(EditAnywhere)

	int32 CountdownTime;

	UTextRenderComponent* CountdownText;

public:
	///// 화면에 글자 출력하는 함수
	void UpdateTimerDisplay();

	///// 타이머 관련 함수
	void AdvencedTimer();

	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();
	virtual void CountdownHasFinished_Implementation();

	FTimerHandle CountdownTimerHandle;
};

