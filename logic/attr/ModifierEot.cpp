#include "basedef.h"
#include "ModifierEot.h"
#include "ModifierFunc.h"

namespace SKILLEDITOR
{
	class CCharacterEntity;
	bool ChangeEotAtkPower(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}

	TAttrModifierFunc AttrEotModifierFunc[EAMKEOT_Count] = 
	{
		NULL,
		ChangeEotAtkPower
	};
}