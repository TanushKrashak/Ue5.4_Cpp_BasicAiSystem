// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "Cpp_BTService_ChangeSpeed.generated.h"

/**
 * 
 */
UCLASS()
class CPP_3DAISYSTEM_API UCpp_BTService_ChangeSpeed : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UCpp_BTService_ChangeSpeed();
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ai", meta = (AllowPrivateAccess = true))
	float Speed = 600.0f;

};
