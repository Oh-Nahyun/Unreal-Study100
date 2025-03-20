// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"

#include "Kismet/GameplayStatics.h"
// #include <Kismet/GameplayStatics.h>		// 위와 같은 헤더

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float TimeBetweenCameraChange = 2.0f;
	const float SmoothBlendTime = 0.75f;

	TimeToNextCameraChange -= DeltaTime;

	if (TimeToNextCameraChange <= 0)
	{
		TimeToNextCameraChange += TimeBetweenCameraChange;

		// 카메라를 전환하는 코드

		// 플레이어의 컨트롤 액터를 찾는다.
		APlayerController* controller = UGameplayStatics::GetPlayerController(this, 0);	// 플레이어0은 본인이면서 서버

		if (controller)
		{
			if (controller->GetViewTarget() != CameraOne && (CameraOne != nullptr))
			{
				// 카메라를 컷 해서 들어간다. (레디-액션-컷 할 때의 컷!)
				controller->SetViewTarget(CameraOne);
			}
			else if (controller->GetViewTarget() != CameraTwo && (CameraTwo != nullptr))
			{
				// 카메라로 부드럽게 블랜딩 한다. (카메라의 위치로 이동하면서 장면 전환)
				controller->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			}
		}
	}
}

