// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	startPosition = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float _deltaTime)
{

	if (ShouldPlatformReturn())
	{
		FVector moveDirection = platformVelocity.GetSafeNormal();
		startPosition = startPosition + moveDirection * movedDistance;
		SetActorLocation(startPosition);
		platformVelocity = -platformVelocity;
	}
	else
	{
		FVector currentPosition = GetActorLocation();
		currentPosition = currentPosition + platformVelocity * _deltaTime;
		SetActorLocation(currentPosition);
	}
}

void AMovingPlatform::RotatePlatform(float _deltaTime)
{
	AddActorLocalRotation(rotationVelocity * _deltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn()
{
	return GetDistanceMoved() > movedDistance;
}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(startPosition, GetActorLocation());
}
