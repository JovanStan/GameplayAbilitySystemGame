
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"


class UAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<APlayerState> PlayerState;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAttributeSet> AttributeSet;
};
