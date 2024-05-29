// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/Cpp_AiC_NPC.h"
#include "./NPC/Cpp_NPC.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"

ACpp_AiC_NPC::ACpp_AiC_NPC(FObjectInitializer const& ObjectInitializer) {
	SetupPerceptionSystem();
}

void ACpp_AiC_NPC::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);
	
	if (ACpp_NPC* const npc = Cast<ACpp_NPC>(InPawn)) {
		if (UBehaviorTree* const BT = npc->GetBehaviorTree()) {
			UBlackboardComponent* BB_Main;
			UseBlackboard(BT->BlackboardAsset, BB_Main);
			Blackboard = BB_Main;
			RunBehaviorTree(BT);
		}
	}
}

void ACpp_AiC_NPC::SetupPerceptionSystem() {
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	if (SightConfig) {
		SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
		SightConfig->SightRadius = 500.0f;
		SightConfig->LoseSightRadius = SightConfig->SightRadius + 50.0f;
		SightConfig->PeripheralVisionAngleDegrees = 90.0f;
		// Time in seconds after which the target is considered lost if not seen
		SightConfig->SetMaxAge(5.0f);
		SightConfig->AutoSuccessRangeFromLastSeenLocation = 520.0f;
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

		GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
		// Call the OnTargetDetected function when the target is detected
		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ACpp_AiC_NPC::OnTargetDetected);
		GetPerceptionComponent()->ConfigureSense(*SightConfig);
	}
}

void ACpp_AiC_NPC::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus) {

}
