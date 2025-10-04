
#include "Characters/AuraBaseCharacter.h"

#include "AbilitySystemComponent.h"

AAuraBaseCharacter::AAuraBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AAuraBaseCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void AAuraBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AAuraBaseCharacter::InitAbilityActorInfo()
{
	
}

void AAuraBaseCharacter::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	if (GetAbilitySystemComponent() && GameplayEffectClass)
	{
		FGameplayEffectContextHandle EffectContext = GetAbilitySystemComponent()->MakeEffectContext();
		EffectContext.AddSourceObject(this);
		const FGameplayEffectSpecHandle EffectSpec = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, 1, EffectContext);
		GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*EffectSpec.Data.Get(), GetAbilitySystemComponent());
	}
}

void AAuraBaseCharacter::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1);
	ApplyEffectToSelf(DefaultVitalAttributes, 1);
}


