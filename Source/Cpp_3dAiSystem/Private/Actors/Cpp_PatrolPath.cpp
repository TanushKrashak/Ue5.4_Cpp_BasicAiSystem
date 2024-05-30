// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Cpp_PatrolPath.h"

// Sets default values
ACpp_PatrolPath::ACpp_PatrolPath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACpp_PatrolPath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACpp_PatrolPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

