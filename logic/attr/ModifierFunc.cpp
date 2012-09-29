#include "ModifierFunc.h"
#include "EntityFunc.h"
#include "../../Process_error.h"
#include "../skill/evtDef.h"
#include "ModifierEot.h"
#include "ModifierSkill.h"
#include "ModifierChar.h"
#include "ModifierSkill.h"
#include "ModifierBullet.h"
#include "ModifierAura.h"
//#include ""

namespace SKILLEDITOR
{
	extern TAttrModifierFunc AttrCharModifierFunc[EAMKCHAR_Count];
	extern TAttrModifierFunc AttrSkillModifierFunc[EAMKSkill_Count];
	extern TAttrModifierFunc AttrBullectModifierFunc[EAMKBullet_Count];
	extern TAttrModifierFunc AttrEotModifierFunc[EAMKEOT_Count];
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
		TAttrModifierFunc func;

		LOG_PROCESS_ERROR(funcType >= 0 || funcType < EATTR_MODIFY_TYPE_COUNT);

		BSLib::s32 keyCount = AttrModifierCount[funcType];
		LOG_PROCESS_ERROR(key >= 0 && key < keyCount );
		func = AttrModifiers[funcType][key];
		return func;
Exit0:
		return NULL;
	}
}