// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/Cpp_BTTask_FindPathPoint.h"
#include "NPC/Cpp_AiC_NPC.h"
#include "NPC/Cpp_NPC.h"


UCpp_BTTask_FindPathPoint::UCpp_BTTask_FindPathPoint(const FObjectInitializer& ObjectInitializer) {
	// NodeName is the name of the task that will be displayed in the Behavior Tree Editor
	NodeName = TEXT("Find Path Point");
}

EBTNodeResult::Type UCpp_BTTask_FindPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	// try to get NPC's controller
	if (const auto* AiCont = Cast<ACpp_AiC_NPC>(OwnerComp.GetAIOwner())) {
		// try to get blackboard component from the behavior tree
		if (const auto* BlackboardComp = OwnerComp.GetBlackboardComponent()) {
			// get the patrol path index 
			const auto PatrolPathIndex = BlackboardComp->GetValueAsInt(GetSelectedBlackboardKey());

			// get the NPC
			if (const auto* npc = Cast<ACpp_NPC>(AiCont->GetPawn())) {
				// get the patrol path's PointIndex's location
				const auto PathPoint = npc->GetPatrolPath()->GetPatrolPoint(PatrolPathIndex);

				// convert relative location to world location
				const auto GlobalLocation = npc->GetPatrolPath()->GetActorTransform().TransformPosition(PathPoint);

				// set the blackboard key to the global location
				BlackboardComp->SetValueAsVector(PatrolPathLocationKey.SelectedKeyName, GlobalLocation);

				// finish with success
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}
