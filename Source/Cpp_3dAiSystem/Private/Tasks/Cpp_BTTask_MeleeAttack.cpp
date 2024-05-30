// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/Cpp_BTTask_MeleeAttack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC/Cpp_NPC.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Interfaces/Cpp_Interface_Combat.h"
#include "NPC/AiC_NPC.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "Engine/LatentActionManager.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

UCpp_BTTask_MeleeAttack::UCpp_BTTask_MeleeAttack() {
	// NodeNames are the names of the nodes in the BehaviorTree in the editor
	NodeName = TEXT("Melee Attack");
}

EBTNodeResult::Type UCpp_BTTask_MeleeAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

}

bool UCpp_BTTask_MeleeAttack::MontageHasFinished(const ACpp_NPC* npc) {

}
