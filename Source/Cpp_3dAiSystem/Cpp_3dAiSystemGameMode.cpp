// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cpp_3dAiSystemGameMode.h"
#include "Cpp_3dAiSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACpp_3dAiSystemGameMode::ACpp_3dAiSystemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
