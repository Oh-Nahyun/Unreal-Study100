// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// ... (여기에 추가)
#include "MyActor1.generated.h"					// 무조건 최하단에 넣어야한다!

UCLASS()										// UCLASS() : 언리얼에서만 쓰는 정의 (언리얼에서 빨리 찾기 위함)
class U00_TEST_API AMyActor1 : public AActor	// class 뒤에는 프로젝트 이름이 붙는다.
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor1();

	/*
	// 내부 코드 형식..
	int a = 10;
	int8 i8;
	int32 i32;
	int64 i64;

	uint8 i8;
	uint32 i32;
	uint64 i64;

	float f;
	double d;

	FString str;

	bool b;
	*/

	// ------------------------------

	// 프로퍼티 (지정자 모음) ( UPROPERTY() / UFUNCTION() )
	// Blueprintable;							// 블루프린트로 확장시킬 수 있다.
	// BlueprintReadOnly;						// 블루프린트에서 읽을 수는 있지만, 쓰기는 불가능 하다.
	// EditAnywhere;							// 인스턴트의 프로퍼티 창에서 수정할 수 있다. (눈 켜는 효과와 동일하다.)
	// Category;								// 섹션 정리용
	// Blueprintcallable;						// 블루프린트에서 호출할 수 있다.
	// 
	// BlueprintAuthorityOnly;					// 네트워크 권한 (서버 권한) 이 있는 블루프린트 코드만 실행된다.
	// BlueprintNativeEvent;					// 블루프린트로 덮어쓰도록 (오버라이딩) 디자인 되어있지만, 기본 내장 구현이 있기도 할 경우 사용한다.
	// BlueprintImplementableEvent;				// (함수) 블루프린트 또는 레벨 블루프린트에서 구현할 수 있다.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")	// 언리얼에서 쓰는 프로퍼티 (변수) 라는 의미
	int32 TotalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float DamageTimeInSecond;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
	float DamagePerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	bool bAttackable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	FString str;

public:
	//UFUNCTION(BlueprintImplementableEvent, Category = "Damage")	// 블루프린트에서 정의하라는 의미!
	UFUNCTION(BlueprintNativeEvent, Category = "Damage")			// 블루프린트에서 검색 및 구현(정의) 가능
	void CallFromCpp();												// ( 역할 분담 가능 )
	virtual void CallFromCpp_Implementation();						// 임시로(?) 돌아가는 것

	void FunctionName();											// 블루프린트에서 검색 불가능

	UFUNCTION(BlueprintCallable, Category = "Damage")				// 블루프린트에서 검색 가능
	void CalculateDPS();

	virtual void PostInitProperties() override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
