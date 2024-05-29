// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Cpp_AiC_NPC.generated.h"

class UAISenseConfig_Sight;
class AActor;


UCLASS()
class CPP_3DAISYSTEM_API ACpp_AiC_NPC : public AAIController
{
	GENERATED_BODY()

public:
	explicit ACpp_AiC_NPC(FObjectInitializer const& ObjectInitializer);


protected:
	virtual void OnPossess(APawn* InPawn) override;


private:
	class UAISenseConfig_Sight* SightConfig;

	void SetupPerceptionSystem();

	UFUNCTION()
	void OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus);
};
