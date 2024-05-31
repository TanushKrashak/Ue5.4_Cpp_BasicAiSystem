// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/Cpp_AiCharacter_Master.h"
#include "Components/WidgetComponent.h"
#include "UI/Cpp_WGT_HealthBar.h"
#include "Components/BoxComponent.h"

ACpp_AiCharacter_Master::ACpp_AiCharacter_Master()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set up widget component
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	// Setup Right Fist Collision Box
	RightFistCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("RightFistCollisionBox"));
	Health = MaxHealth;

	// Initialize WidgetComponent
	if (WidgetComponent) {
		WidgetComponent->SetupAttachment(RootComponent);
		WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
		WidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 95.0f));		
		static ConstructorHelpers::FClassFinder<UUserWidget> HealthWidgetClassFinder(TEXT("/Game/UI/WBP_HealthBar"));

		if (HealthWidgetClassFinder.Succeeded()) {
			WidgetComponent->SetWidgetClass(HealthWidgetClassFinder.Class);
		}
	}

	// Initialize RightFistCollisionBox
	if (RightFistCollisionBox) {
		// Attaching with snap to target
		RightFistCollisionBox->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, 
											   FName("hand_rSocket"));
		RightFistCollisionBox->SetRelativeLocation(FVector(-7.0f, 0.0f, 0.0f));
		RightFistCollisionBox->SetCollisionProfileName("OverlapAll");
		RightFistCollisionBox->SetBoxExtent(FVector(5.0f, 5.0f, 5.0f));
	}
}

void ACpp_AiCharacter_Master::BeginPlay()
{
	Super::BeginPlay();
	
}
void ACpp_AiCharacter_Master::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (const auto widget = Cast<UCpp_WGT_HealthBar>(WidgetComponent->GetUserWidgetObject())) {
		widget->SetHealthBarPercentage(Health / MaxHealth);
	}

}
void ACpp_AiCharacter_Master::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ACpp_AiCharacter_Master::GetHealth() const {
	return Health;
}
float ACpp_AiCharacter_Master::GetMaxHealth() const {
	return MaxHealth;
}

void ACpp_AiCharacter_Master::SetHealth(const float newHealth) {
	Health = FMath::Clamp(newHealth, 0.0f, MaxHealth);
}

void ACpp_AiCharacter_Master::AttackStart() {
	RightFistCollisionBox->SetCollisionProfileName("Fist");
	RightFistCollisionBox->SetNotifyRigidBodyCollision(true);
}
void ACpp_AiCharacter_Master::AttackEnd() {
	RightFistCollisionBox->SetCollisionProfileName("Fist");
	//RightFistCollisionBox->SetNotifyRigidBodyCollision(false);
}

