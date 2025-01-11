// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayCharacter.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/Attributes/PlayHealthAttributeSet.h"


// Sets default values
APlayCharacter::APlayCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	HealthAttributeSet = CreateDefaultSubobject<UPlayHealthAttributeSet>(TEXT("HealthAttributeSet"));
}

// Called when the game starts or when spawned
void APlayCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (HealthAttributeSet)
	{
		HealthAttributeSet->OnHealthChanged.AddDynamic(this, &APlayCharacter::HandleHealthChanged);
	}
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		AbilitySystemComponent->SetNumericAttributeBase(UPlayHealthAttributeSet::GetHealthAttribute(), InitialHealth);
	}
}

// Called every frame
void APlayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* APlayCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void APlayCharacter::HandleHealthChanged(float Magnitude, float NewHealth)
{
	if (NewHealth <= 0)
	{
		Destroy();
	}
}

