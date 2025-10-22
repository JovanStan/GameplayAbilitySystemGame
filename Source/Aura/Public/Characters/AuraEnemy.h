
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemData/CharacterClassInfo.h"
#include "Characters/AuraBaseCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetControllers/OverlayWidgetController.h"
#include "AuraEnemy.generated.h"

enum class ECharacterClass : uint8;
class UWidgetComponent;

UCLASS()
class AURA_API AAuraEnemy : public AAuraBaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	virtual int32 GetPlayerLevel() override;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	virtual void InitializeDefaultAttributes() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ECharacterClass CharacterClass = ECharacterClass::Warrior;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
