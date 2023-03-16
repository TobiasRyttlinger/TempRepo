// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyShaders/Public/MySimpleComputeShader.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyComputeManager.generated.h"

UCLASS()
class MYSHADERS_API AMyComputeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyComputeManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FMySimpleComputeShaderDispatchParams Params;
};
