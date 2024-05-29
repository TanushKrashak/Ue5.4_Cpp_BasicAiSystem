// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/Cpp_NPC.h"

// Sets default values
ACpp_NPC::ACpp_NPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACpp_NPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACpp_NPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACpp_NPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

