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
	// check if in range
	const auto* OutOfRange = !OwnerComp.GetBlackboardComponent()->GetValueAsBool(GetSelectedBlackboardKey());
	if (OutOfRange) {
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}

	// get npc's ai controller
	const auto* AiCont = Cast<ACpp_AiC_NPC>(OwnerComp.GetAIOwner());
	// get npc
	const auto* npc = Cast<ACpp_NPC>(AiCont->GetPawn());

	// try to get npc's combat interface
	if (const auto ICombat = Cast<ICpp_Interface_Combat>(npc)) {
		if (MontageHasFinished(npc)) {
			ICombat->Execute_MeleeAttack(npc);
		}
	}
	// finish task
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

bool UCpp_BTTask_MeleeAttack::MontageHasFinished(const ACpp_NPC* npc) {

}
