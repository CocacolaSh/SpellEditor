#include "ModifierFunc.h"

namespace SKILLEDITOR
{
	extern TAttrModifierFunc AttrCharModifierFunc[EMAKCHAR_Count];
	extern TAttrModifierFunc AttrSkillModifierFunc[];
	extern TAttrModifierFunc AttrBullectModifierFunc[];
	extern TAttrModifierFunc AttrEotModifierFunc[];
	extern TAttrModifierFunc AttrAuraModifierFunc[];

	TAttrModifierFunc *AttrModifiers[EATTR_MODIFY_TYPE_COUNT] = 
	{
		AttrCharModifierFunc,
		AttrSkillModifierFunc,
		AttrBullectModifierFunc,
		AttrEotModifierFunc,
		AttrAuraModifierFunc
	}

	BSLib::s32 AttrModifierCount[EATTR_MODIFY_TYPE_COUNT] = 
	{
		EMAKCHAR_Count,
	}
}