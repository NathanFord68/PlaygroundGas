// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Attributes/PlayBaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PlayHealthAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class PLAYGROUNDGAS_API UPlayHealthAttributeSet : public UPlayBaseAttributeSet
{
	GENERATED_BODY()
	
public:

	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data);

	UPROPERTY()
	FPlayAttributeEvent OnHealthChanged;

	UPROPERTY()
	FGameplayAttributeData Health;
	PLAY_ATTRIBUTE_ACCESSORS(UPlayHealthAttributeSet, Health);
};
