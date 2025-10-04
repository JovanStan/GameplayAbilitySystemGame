
#pragma once

#include "CoreMinimal.h"
#include "AuraBaseCharacter.h"
#include "AuraCharacter.generated.h"


UCLASS()
class AURA_API AAuraCharacter : public AAuraBaseCharacter
{
	GENERATED_BODY()

public:
	AAuraCharacter();
	virtual void InitAbilityActorInfo() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	virtual int32 GetPlayerLevel() override;
};
