// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cpp_PatrolPath.generated.h"

UCLASS()
class CPP_3DAISYSTEM_API ACpp_PatrolPath : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACpp_PatrolPath();

	FVector GetPatrolPoint(const int PointIndex) const;
	int NumOfPoints() const;

private:
	// Array of patrol points for the AI to follow
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ai", meta = (MakeEditWidget="true", AllowPrivateAccess="true"))
	TArray<FVector> PatrolPoints;


};
