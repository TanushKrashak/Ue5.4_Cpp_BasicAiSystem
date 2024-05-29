// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Cpp_BTTask_FindRandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class CPP_3DAISYSTEM_API UCpp_BTTask_FindRandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
