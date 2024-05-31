// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Cpp_ANS_Attack.generated.h"

/**
 * 
 */
UCLASS()
class CPP_3DAISYSTEM_API UCpp_ANS_Attack : public UAnimNotifyState
{
	GENERATED_BODY()
	
private:

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
