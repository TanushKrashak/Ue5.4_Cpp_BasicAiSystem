// Fill out your copyright notice in the Description page of Project Settings.


#include "Services/Cpp_BTService_ChangeSpeed.h"
#include "NPC/Cpp_AiC_NPC.h"
#include "NPC/Cpp_NPC.h"
#include "GameFramework/CharacterMovementComponent.h"


UCpp_BTService_ChangeSpeed::UCpp_BTService_ChangeSpeed() {
	// Enable the service to be called when the node becomes relevant
	bNotifyBecomeRelevant = true;

	// NodeName is the name shown in the Behavior Tree Editor
	NodeName = TEXT("Change Speed");
}

void UCpp_BTService_ChangeSpeed::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);

	// try to get npc's controller
	if (const auto* AiCont = Cast<ACpp_AiC_NPC>(OwnerComp.GetAIOwner())) {
		// Try to get the npc
		if (const auto* npc = Cast<ACpp_NPC>(AiCont->GetPawn())) {
			npc->GetCharacterMovement()->MaxWalkSpeed = Speed;
		}
	}
}
