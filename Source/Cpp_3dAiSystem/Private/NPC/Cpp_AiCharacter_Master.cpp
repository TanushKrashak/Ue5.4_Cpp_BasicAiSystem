// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/Cpp_AiCharacter_Master.h"
#include "Components/WidgetComponent.h"
#include "UI/Cpp_WGT_HealthBar.h"
#include "Components/BoxComponent.h"
#include "NPC/Cpp_NPC.h"
#include "../Cpp_3dAiSystemCharacter.h"

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
	// Bind the overlap functions to the collision box, so that we can detect when the player is hit
	RightFistCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACpp_AiCharacter_Master::OnAttackBeginOverlap);
	RightFistCollisionBox->OnComponentEndOverlap.AddDynamic(this, &ACpp_AiCharacter_Master::OnAttackEndOverlap);
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

void ACpp_AiCharacter_Master::OnAttackBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
												   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
												   const FHitResult& SweepResult) {
	// Do nothing if the other actor is self
	if (OtherActor == this) {
		return;
	}
	// Check if the other actor is an NPC and damage it
	if (auto* Enemy = Cast<ACpp_NPC>(OtherActor)) {
		// Decrease enemy health by 10%
		Enemy->SetHealth(Enemy->GetHealth() - Enemy->GetMaxHealth()*0.1f);
	}
	// Check if the other actor is a player and damage it
	if (auto* Player = Cast<ACpp_3dAiSystemCharacter>(OtherActor)) {
		// Decrease player health by 5%
		Player->SetHealth(Player->GetHealth() - Player->GetMaxHealth() * 0.05f);
	}
}
void ACpp_AiCharacter_Master::OnAttackEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
												 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {

}

float ACpp_AiCharacter_Master::GetHealth() const {
	return Health;
}
float ACpp_AiCharacter_Master::GetMaxHealth() const {
	return MaxHealth;
}

void ACpp_AiCharacter_Master::SetHealth(const float newHealth) {
	Health = FMath::Clamp(newHealth, 0.0f, MaxHealth);
	// self died
	if (Health <= 0.0f) {
		// check if player died, if so, close the game
		if (Cast<ACpp_3dAiSystemCharacter>(this)) {
			UE_LOG(LogTemp, Error, TEXT("Player Died"));
			GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
		}
		// check if NPC died
		else if (Cast<ACpp_NPC>(this)) {
			UE_LOG(LogTemp, Warning, TEXT("NPC Died!"));
			Destroy();
		}
	}
}

void ACpp_AiCharacter_Master::AttackStart() {
	RightFistCollisionBox->SetCollisionProfileName("Fist");
	RightFistCollisionBox->SetNotifyRigidBodyCollision(true);
}
void ACpp_AiCharacter_Master::AttackEnd() {
	RightFistCollisionBox->SetCollisionProfileName("Fist");
	RightFistCollisionBox->SetNotifyRigidBodyCollision(false);
}

