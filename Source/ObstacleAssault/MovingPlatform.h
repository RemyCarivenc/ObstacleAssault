// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:

	UPROPERTY(EditAnywhere)
	float movedDistance = 100;
	UPROPERTY(EditAnywhere)
	FRotator rotationVelocity;

	UPROPERTY(EditAnywhere)
	FVector platformVelocity = FVector(100, 0, 0);

	FVector startPosition;


	void MovePlatform(float _deltaTime);
	void RotatePlatform(float _deltaTime);

	bool ShouldPlatformReturn();
	float GetDistanceMoved();
};
