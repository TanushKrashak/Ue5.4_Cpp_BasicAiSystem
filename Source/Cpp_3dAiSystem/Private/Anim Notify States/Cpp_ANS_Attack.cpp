// Fill out your copyright notice in the Description page of Project Settings.


#include "Anim Notify States/Cpp_ANS_Attack.h"
#include "NPC/Cpp_AiCharacter_Master.h"


void UCpp_ANS_Attack::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) {
	// Check if mesh and owner exist
	if (MeshComp && MeshComp->GetOwner()) {
		if (ACpp_AiCharacter_Master* inChar = Cast<ACpp_AiCharacter_Master>(MeshComp->GetOwner())) {
			inChar->AttackStart();
		}
	}
}

void UCpp_ANS_Attack::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) {
	// Check if mesh and owner exist
	if (MeshComp && MeshComp->GetOwner()) {
		if (ACpp_AiCharacter_Master* inChar = Cast<ACpp_AiCharacter_Master>(MeshComp->GetOwner())) {
			inChar->AttackEnd();
		}
	}
}
