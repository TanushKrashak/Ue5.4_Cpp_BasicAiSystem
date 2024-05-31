// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Cpp_AiCharacter_Master.generated.h"

// Forward Declarations
class UWidgetComponent;

UCLASS()
class CPP_3DAISYSTEM_API ACpp_AiCharacter_Master : public ACharacter
{
	GENERATED_BODY()

public:
	//===================================================================================================
	// PROPERTIES & VARIABLES	
	//===================================================================================================
	
	

	//===================================================================================================
	// FUNCTIONS	
	//===================================================================================================
	ACpp_AiCharacter_Master();

	// Getters
	float GetHealth() const;
	float GetMaxHealth() const;

	// Setters
	void SetHealth(const float newHealth);

protected:
	//===================================================================================================
	// PROPERTIES & VARIABLES	
	//===================================================================================================
	UPROPERTY()
	UWidgetComponent* WidgetComponent;
	const float MaxHealth = 100.0f;
	float Health;
			

	//===================================================================================================
	// FUNCTIONS	
	//===================================================================================================
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
