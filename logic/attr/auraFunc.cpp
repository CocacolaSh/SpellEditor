#include "basedef.h"
#include "AuraFunc.h"
#include "attrFunc.h"
#include "../skill/aura_template.h"

namespace SKILLEDITOR
{
	BSLib::s32 GetAuraIsGood(void *target, BSLib::s32 arg)
	{
		AuraTemplate *aura = (AuraTemplate*)target;
		return aura->m_data.m_isGood;
	}
	BSLib::s32 GetAuraType(void *target, BSLib::s32 arg)
	{
		return 0;
	}
	BSLib::s32 GetAuraResult(void *target, BSLib::s32 arg)
	{
		return 0;
	}
	BSLib::s32 GetAuraFixTime(void *target, BSLib::s32 arg)
	{
		AuraTemplate *aura = (AuraTemplate*)target;
		return aura->m_data.m_fixTime;
	}

	TGetAttr GetAuraAttrFunc[EGetAuraAttrFunc_COUNT] = 
	{
		NULL,
		GetAuraIsGood,
		GetAuraType,
		GetAuraResult,
		GetAuraFixTime,
		
	};
}