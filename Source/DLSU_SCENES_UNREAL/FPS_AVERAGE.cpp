// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_AVERAGE.h"

// Sets default values
AFPS_AVERAGE::AFPS_AVERAGE()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPS_AVERAGE::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPS_AVERAGE::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

