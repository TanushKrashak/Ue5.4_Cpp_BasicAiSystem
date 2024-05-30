// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/Cpp_NPC.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Actors/Cpp_PatrolPath.h"

// Sets default values
ACpp_NPC::ACpp_NPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void ACpp_NPC::BeginPlay()
{
	Super::BeginPlay();
	
}
void ACpp_NPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ACpp_NPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UBehaviorTree* ACpp_NPC::GetBehaviorTree() const {
	
	return BT_Brain;
}

ACpp_PatrolPath* ACpp_NPC::GetPatrolPath() const {
	return PatrolPath;
}
