// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/Cpp_AiC_NPC.h"
#include "NPC/Cpp_NPC.h"

ACpp_AiC_NPC::ACpp_AiC_NPC(FObjectInitializer const& ObjectInitializer) {

}

void ACpp_AiC_NPC::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);
	
	if (ACpp_NPC const npc = Cast<ACpp_NPC>(InPawn)) {
		if (UBehaviorTree* const BT = npc->GetBehaviorTree()) {
			UBlackboardComponent* BB_Main;
			UseBlackboard(BT->BlackboardAsset, BB_Main);
			Blackboard = BB_Main;
			RunBehaviorTree(BT);
		}
	}
}
