// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks/Cpp_BTTask_FindPlayerLocation.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "GameFramework/Character.h"


UCpp_BTTask_FindPlayerLocation::UCpp_BTTask_FindPlayerLocation(FObjectInitializer const& ObjectInitializer) {
	// NodeName is the name of the task that will be displayed in the Behavior Tree Editor
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UCpp_BTTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	// Get Player Character
	if (const auto* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)) {
		// Get the player's location
		const auto PlayerLocation = Player->GetActorLocation();
		if (bRandLocAroundPlayer) {
			FNavLocation NavLocation;
			// Get the navigation system and generate a random location around the player
			if (const auto* NavSys = UNavigationSystemV1::GetCurrent(GetWorld())) {
				// Try to get a random point in the navigable radius around the player
				if (NavSys->GetRandomPointInNavigableRadius(PlayerLocation, SearchRadius, NavLocation)) {
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), NavLocation.Location);
				}
			}
		}
		else {
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerLocation);			
		}
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	
	return EBTNodeResult::Failed;	
}
