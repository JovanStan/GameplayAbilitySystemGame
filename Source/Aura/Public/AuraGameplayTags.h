
#pragma once
#include "GameplayTagContainer.h"

struct FGameplayTag;

struct FAuraGameplayTags
{
	static const FAuraGameplayTags& Get() { return GameplayTags;}
	static void InitializeNativeGameplayTags();


	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;

private:
	static FAuraGameplayTags GameplayTags;
};

