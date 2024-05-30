// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/Cpp_BTTask_IncrementPathhIndex.h"
#include "NPC/Cpp_AiC_NPC.h"
#include "Actors/Cpp_PatrolPath.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC/Cpp_NPC.h"


UCpp_BTTask_IncrementPathhIndex::UCpp_BTTask_IncrementPathhIndex(const FObjectInitializer& ObjectInitializer) : UBTTask_BlackboardBase{ObjectInitializer} {
	// NodeName is the name shown in the Behavior Tree Editor
	NodeName = TEXT("Increment Path Index");
}

EBTNodeResult::Type UCpp_BTTask_IncrementPathhIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	Super::ExecuteTask(OwnerComp, NodeMemory);

	// try to get npc's controller
	if (const auto* AiCont = Cast<ACpp_AiC_NPC>(OwnerComp.GetAIOwner())) {
		// Try to get the npc
		if (const auto* npc = Cast<ACpp_NPC>(AiCont->GetPawn())) {
			// Try to get blackboard 
			if (auto* BlackBoardComp = OwnerComp.GetBlackboardComponent()) {
				// Get num of patrol points 
				const auto NumOfPatrolPoints = npc->GetPatrolPath()->NumOfPoints();
				const int MinIndex = 0;
				const int MaxIndex = NumOfPatrolPoints - 1;
				int Index = BlackBoardComp->GetValueAsInt(GetSelectedBlackboardKey());

				// Change Direction if at first or last index and bi-directional
				if (bBiDirectional) {
					if (Index >= MaxIndex && Direction == EDirectionType::Forward) {
						Direction = EDirectionType::Reverse;
					}
					else if (Index <= MinIndex && Direction == EDirectionType::Reverse) {
						Direction = EDirectionType::Forward;
					}
				}

				// set new index, % NumOfPatrolPoints to wrap around if needed
				BlackBoardComp->SetValueAsInt(GetSelectedBlackboardKey(), 
											  (Direction == EDirectionType::Forward ? Index+1 : Index-1) % NumOfPatrolPoints);

				// Finish with success
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}
