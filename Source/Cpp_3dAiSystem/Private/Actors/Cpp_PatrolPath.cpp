// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Cpp_PatrolPath.h"

// Sets default values
ACpp_PatrolPath::ACpp_PatrolPath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

FVector ACpp_PatrolPath::GetPatrolPoint(const int PointIndex) const {
	return PatrolPoints[PointIndex];
}

int ACpp_PatrolPath::NumOfPoints() const {
	return PatrolPoints.Num();
}

