
#include "AbilitySystemData/CharacterClassInfo.h"

FCharacterClassDefaultInfo UCharacterClassInfo::GetClassDefaultInfo(const ECharacterClass CharacterClass) const
{
	return CharacterClassInfo.FindChecked(CharacterClass);
}
