// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "C:\Users\tory\Desktop\Git\flockingbird\src\flockingbird.hpp"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BoidManager.generated.h"

UCLASS()
class FLOCKINGBIRD_API ABoidManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	flockingbird::FlockSimulationParameters flockSimParams;
	flockingbird::Flock flock;
	flockingbird::FlockSimulation flockSim;

	const bool twoD = true;
	float speedLimit = 5;
	float forceLimit = 3;
	float positionIncrementScalingFactor = 1;
	float avoidanceRadius = 50;
	float visionRange = 100;
	Vector3D bounds{ 3000,3000,3000 };
	Vector3D targetPos{ bounds.x / 2,bounds.y / 2,bounds.z / 2 };
	float angle = 0;
	float separationWeight = 1.5 * 3;
	float alignmentWeight = 1.0;
	float cohesionWeight = 1.0;
	float avoidanceWeight = 3;
	int numberOfBoids = 1000;
};
