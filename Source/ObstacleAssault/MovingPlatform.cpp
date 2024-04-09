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

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("%s speed: %f"), *GetName(), Speed);
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	UpdateLocation(DeltaTime);
	InverseIfReachedTheEnd();
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationToApply * DeltaTime);
}

void AMovingPlatform::UpdateLocation(float DeltaTime)
{
	if(Increasing)
	{
		Offset = FMath::Clamp(Offset + Speed * DeltaTime, 0, Range);
	}
	else
	{
		Offset = FMath::Clamp(Offset - Speed * DeltaTime, 0, Range);
	}

	SetActorLocation(StartLocation + Direction.GetSafeNormal() * Offset);
}

void AMovingPlatform::InverseIfReachedTheEnd()
{
	if(Offset >= Range)
	{
		Increasing = false;
	}
	else if(Offset <= 0)
	{
		Increasing = true;
	}
}
