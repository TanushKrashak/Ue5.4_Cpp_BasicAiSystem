// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/Cpp_AiCharacter_Master.h"
#include "Components/WidgetComponent.h"

ACpp_AiCharacter_Master::ACpp_AiCharacter_Master()
{
	PrimaryActorTick.bCanEverTick = true;

	WidgetComponent{CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthValue"))};
	Health{MaxHealth};

	if (WidgetComponent) {
		WidgetComponent->SetupAttachment(RootComponent);
		WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
		WidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 95.0f));

		static ConstructorHelpers::FClassFinder<UUserWidget> HealthWidgetClassFinder(TEXT("UI/Cpp_WGT_HealthBar"));

		if (HealthWidgetClassFinder.Succeeded()) {
			WidgetComponent->SetWidgetClass(HealthWidgetClassFinder.Class);
		}
	}

}

void ACpp_AiCharacter_Master::BeginPlay()
{
	Super::BeginPlay();
	
}
void ACpp_AiCharacter_Master::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ACpp_AiCharacter_Master::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ACpp_AiCharacter_Master::GetHealth() const {

}

float ACpp_AiCharacter_Master::GetMaxHealth() const {

}

void ACpp_AiCharacter_Master::SetHealth(const float newHealth) {

}
