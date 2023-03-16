// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"
#include "C:\Users\tory\Desktop\Git\flockingbird\src\flockingbird.hpp"

// Sets default values
ABoidManager::ABoidManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ABoidManager::BeginPlay()
{
	Super::BeginPlay();
	flockSimParams = flockingbird::FlockSimulationParameters(
		speedLimit,
		forceLimit,
		positionIncrementScalingFactor,
		avoidanceRadius,
		visionRange,
		separationWeight,
		alignmentWeight,
		cohesionWeight,
		avoidanceWeight,
		twoD,
		bounds.x,
		bounds.y,
		bounds.z,
		targetPos

	);
	flock = flockingbird::Flock(numberOfBoids, bounds.x, bounds.y, bounds.z);
	flockSim = flockingbird::FlockSimulation(flockSimParams, flock, defaultRules);
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

