#include "basedef.h"
#include "auraFunc.h"
#include "attrFunc.h"
class IFighter;
namespace SKILLEDITOR
{
	BSLib::s32 GetAuraIsGood(IFighter *target, BSLib::s32 arg)
	{
		return 0;
	}
	BSLib::s32 GetAuraType(IFighter *target, BSLib::s32 arg)
	{
		return 0;
	}
	BSLib::s32 GetAuraResult(IFighter *target, BSLib::s32 arg)
	{
		return 0;
	}
	BSLib::s32 GetAuraFixTime(IFighter *target, BSLib::s32 arg)
	{
		return 0;
	}

	TGetAttr GetAttrAuraFunc[EGAFAura_COUNT] = 
	{
		NULL,
		GetAuraIsGood,
		GetAuraType,
		GetAuraResult,
		GetAuraFixTime,
		
	};
}