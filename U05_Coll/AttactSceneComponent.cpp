// Fill out your copyright notice in the Description page of Project Settings.


#include "AttactSceneComponent.h"

// Sets default values for this component's properties
UAttactSceneComponent::UAttactSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAttactSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	TargetActor->AttachToActor(ParentActor, FAttachmentTransformRules::KeepRelativeTransform);
}


// Called every frame
void UAttactSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

