// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Cpp_BTTask_MeleeAttack.generated.h"

/**
 * 
 */
UCLASS()
class CPP_3DAISYSTEM_API UCpp_BTTask_MeleeAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UCpp_BTTask_MeleeAttack();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	bool MontageHasFinished(const ACpp_NPC* npc);
};
