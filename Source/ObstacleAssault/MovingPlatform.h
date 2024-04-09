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

	UPROPERTY(EditAnywhere, Category="Movement")
	FVector Direction = FVector(0, 0, 1);
	
	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed = 100;

	UPROPERTY(EditAnywhere, Category="Movement")
	float Range = 1000;

	UPROPERTY(VisibleAnywhere)
	float Offset = 0;

	UPROPERTY(VisibleAnywhere)
	bool Increasing = true;

	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationToApply = FRotator(0, 0, 0);
	
	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);

	void UpdateLocation(float DeltaTime);

	void InverseIfReachedTheEnd();
};
