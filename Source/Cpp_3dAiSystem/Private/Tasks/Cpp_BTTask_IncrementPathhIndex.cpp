// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/Cpp_BTTask_IncrementPathhIndex.h"

UCpp_BTTask_IncrementPathhIndex::UCpp_BTTask_IncrementPathhIndex(const FObjectInitializer& ObjectInitializer) : UBTTask_BlackboardBase{ObjectInitializer} {
	// NodeName is the name shown in the Behavior Tree Editor
	NodeName = TEXT("Increment Path Index");
}

EBTNodeResult::Type UCpp_BTTask_IncrementPathhIndex::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	Super::ExecuteTask(OwnerComp, NodeMemory);
}
