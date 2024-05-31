// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/Cpp_AiCharacter_Master.h"

ACpp_AiCharacter_Master::ACpp_AiCharacter_Master()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACpp_AiCharacter_Master::BeginPlay()
{
	Super::BeginPlay();
	
}
void ACpp_AiCharacter_Master::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ACpp_AiCharacter_Master::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ACpp_AiCharacter_Master::GetHealth() const {

}

float ACpp_AiCharacter_Master::GetMaxHealth() const {

}

void ACpp_AiCharacter_Master::SetHealth(const float newHealth) {

}

