// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/Cpp_BTTask_FindRandomLocation.h"
#include "NPC/Cpp_AiC_NPC.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"



UCpp_BTTask_FindRandomLocation::UCpp_BTTask_FindRandomLocation(FObjectInitializer const& ObjectInitializer) : 
	UBTTask_BlackboardBase{ObjectInitializer} {
	// the NodeName is the name of the task that will be displayed in the Behavior Tree Editor
	NodeName = "Find Random Location";
}

EBTNodeResult::Type UCpp_BTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	// get the AI controller and the controlled pawn
	if (const auto* AiController = Cast<ACpp_AiC_NPC>(OwnerComp.GetAIOwner())) {
		if (const auto* Npc = AiController->GetPawn()) {
			// get npc location as origin for the random location
			const auto Origin = Npc->GetActorLocation();

			// get the navigation system and generate a random location
			if (const auto* NavSys = UNavigationSystemV1::GetCurrent(GetWorld())) {
				FNavLocation ResultLocation;

				if (NavSys->GetRandomPointInNavigableRadius(Origin, SearchRadius, ResultLocation)) {
					// write the result location to the blackboard
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), ResultLocation.Location);
				}
				// Finish with success
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	// Finish with failure
	return EBTNodeResult::Failed;
}
