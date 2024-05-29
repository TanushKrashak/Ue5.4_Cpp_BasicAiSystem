// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Cpp_NPC.generated.h"

class UBehaviorTree;

UCLASS()
class CPP_3DAISYSTEM_API ACpp_NPC : public ACharacter
{
	GENERATED_BODY()

protected:
	//===================================================================================================
	// PROPERTIES & VARIABLES
	//===================================================================================================
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ai", meta = (AllowPrivateAccess = true))
	UBehaviorTree* BT_Brain;

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

};
