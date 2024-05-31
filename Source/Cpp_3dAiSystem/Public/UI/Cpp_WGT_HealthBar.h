// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Cpp_WGT_HealthBar.generated.h"

class UProgressBar;


UCLASS()
class CPP_3DAISYSTEM_API UCpp_WGT_HealthBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	void SetHealthBarPercentage(const float Percentage);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* PB_HealthBar;
};
