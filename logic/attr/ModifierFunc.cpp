#include "ModifierFunc.h"
#include "EntityFunc.h"
#include "../../Process_error.h"
#include "evtDef.h"

namespace SKILLEDITOR
{
	extern TAttrModifierFunc AttrCharModifierFunc[EAMKCHAR_Count];
	extern TAttrModifierFunc AttrSkillModifierFunc[EAMKSKILL_Count];
	extern TAttrModifierFunc AttrBullectModifierFunc[EAMKBullet_Count];
	extern TAttrModifierFunc AttrEotModifierFunc[EAMKEot_Count];
	extern TAttrModifierFunc AttrAuraModifierFunc[EAMKAura_Count];

	TAttrModifierFunc *AttrModifiers[EATTR_MODIFY_TYPE_COUNT] = 
	{
		AttrCharModifierFunc,
		AttrSkillModifierFunc,
		AttrBullectModifierFunc,
		AttrEotModifierFunc,
		AttrAuraModifierFunc
	};

	BSLib::s32 AttrModifierCount[EATTR_MODIFY_TYPE_COUNT] = 
	{
		EAMKCHAR_Count,
	};

	TAttrModifierFunc GetModifierFunc(BSLib::s32 funcType, BSLib::s32 key)
	{
		TAttrModifierFunc func = NULL;

		LOG_PROCESS_ERROR(funcType >= 0 || funcType < EATTR_MODIFY_TYPE_COUNT);

		BSLib::s32 keyCount = AttrModifierCount[funcType];
		LOG_PROCESS_ERROR(key >= 0 && key < keyCount );
		func = AttrModifiers[funcType][key];
		return func;
Exit0:
		return NULL;
	}
}