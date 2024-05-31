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

	void AttackStart();
	void AttackEnd();

protected:
	//===================================================================================================
	// PROPERTIES & VARIABLES	
	//===================================================================================================
	UPROPERTY()
	UWidgetComponent* WidgetComponent;

	const float MaxHealth = 100.0f;
	float Health;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision", meta = (AllowPrivateAccess = true))
	class UBoxComponent* RightFistCollisionBox;

	//===================================================================================================
	// FUNCTIONS	
	//===================================================================================================
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Overlap Begin & End Functions For Attacking
	UFUNCTION()
	void OnAttackBeginOverlap(UPrimitiveComponent* OverlappedComponent,
							  AActor* OtherActor, 
							  UPrimitiveComponent* OtherComp,
							  int32 OtherBodyIndex, 
							  bool bFromSweep, 
							  const FHitResult& SweepResult);
	UFUNCTION()
	void OnAttackEndOverlap(UPrimitiveComponent* OverlappedComponent,
							AActor* OtherActor,
							UPrimitiveComponent* OtherComp,
							int32 OtherBodyIndex);
};
