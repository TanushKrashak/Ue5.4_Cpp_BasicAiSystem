// Fill out your copyright notice in the Description page of Project Settings.


#include "Services/Cpp_BTS_IsPlayerInMeleeRange.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC/Cpp_NPC.h"
#include "NPC/AiC_NPC.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"


UCpp_BTS_IsPlayerInMeleeRange::UCpp_BTS_IsPlayerInMeleeRange() {
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Is Player In Melee Range");
}

void UCpp_BTS_IsPlayerInMeleeRange::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	// get npc's ai controller
	const auto* AiCont = Cast<ACpp_AiC_NPC>(OwnerComp.GetAIOwner());
	// get npc
	const auto* npc = Cast<ACpp_NPC>(AiCont->GetPawn());

	// get player
	const auto* player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	// get distance between npc and player
	const auto distance = npc->GetDistanceTo(player);
	// set bool value in blackboard
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), distance <= MeleeRange);

}
