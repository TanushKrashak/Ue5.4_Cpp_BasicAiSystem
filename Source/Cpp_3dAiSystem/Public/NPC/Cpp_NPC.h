// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Cpp_NPC.generated.h"

// Forward Declarations
class UBehaviorTree;
class ACpp_PatrolPath;
class UAnimMontage;

UCLASS()
class CPP_3DAISYSTEM_API ACpp_NPC : public ACharacter, public ICpp_Interface_Combat
{
	GENERATED_BODY()

protected:
	//===================================================================================================
	// PROPERTIES & VARIABLES
	//===================================================================================================
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ai", meta = (AllowPrivateAccess = true))
	UBehaviorTree* BT_Brain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ai", meta = (AllowPrivateAccess = true))
	ACpp_PatrolPath* PatrolPath;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ai", meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;

	//===================================================================================================
	// FUNCTIONS
	//===================================================================================================
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;




public:	
	//===================================================================================================
	// PROPERTIES & VARIABLES
	//===================================================================================================


	//===================================================================================================
	// FUNCTIONS
	//===================================================================================================
	ACpp_NPC();

	UBehaviorTree* GetBehaviorTree() const;

	ACpp_PatrolPath* GetPatrolPath() const;

	UAnimMontage* GetAttackMontage() const;

};
