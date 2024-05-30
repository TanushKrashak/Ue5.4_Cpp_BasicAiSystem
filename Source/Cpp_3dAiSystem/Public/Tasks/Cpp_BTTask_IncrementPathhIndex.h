// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Cpp_BTTask_IncrementPathhIndex.generated.h"

/**
 * 
 */
UCLASS()
class CPP_3DAISYSTEM_API UCpp_BTTask_IncrementPathhIndex : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	explicit UCpp_BTTask_IncrementPathhIndex(const FObjectInitializer& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	enum class EDirectionType {
		Forward,	
		Reverse
	};

	EDirectionType Direction = EDirectionType::Forward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ai", meta = (AllowPrivateAccess = true))
	bool bBiDirectional = false;
};
