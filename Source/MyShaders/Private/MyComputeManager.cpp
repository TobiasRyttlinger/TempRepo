// Fill out your copyright notice in the Description page of Project Settings.


#include "MyComputeManager.h"
#include "UObject/ObjectMacros.h"
// Sets default values
AMyComputeManager::AMyComputeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyComputeManager::BeginPlay()
{
	Super::BeginPlay();

	Params = FMySimpleComputeShaderDispatchParams(1, 1, 1);
	Params.Input[0] = 2;
	Params.Input[1] = 5;
}

// Called every frame
void AMyComputeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Params struct used to pass args to our compute shader
	
	// Executes the compute shader and calls the TFunction when complete.
	FMySimpleComputeShaderInterface::Dispatch(Params, [](int OutputVal) {
		// OutputVal == 10
		// Called when the results are back from the GPU.
		UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::FromInt(OutputVal));
		});
}

