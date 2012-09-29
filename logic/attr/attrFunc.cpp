#include "attrFunc.h"
#include "Process_error.h"
#include "ModifierFunc.h"
#include "EntityFunc.h"
#include "../skill/evtDef.h"
#include "auraFunc.h"

namespace SKILLEDITOR
{

	extern TGetAttr GetCharAttrFunc[EGCAF_COUNT];
	extern TGetAttr GetSkillAttrFunc[EGSAF_COUNT];
	extern TGetAttr GetBulletAttrFunc[EGBAF_COUNT];
	extern TGetAttr GetEotAttrFunc[EGEAF_COUNT];
	extern TGetAttr GetAuraAttrFunc[EGAFAura_COUNT];

	TGetAttr * GetAttrFuncs[EATTR_MODIFY_TYPE_COUNT] = 
	{
		GetCharAttrFunc,
		GetSkillAttrFunc,
		GetBulletAttrFunc,
		GetEotAttrFunc,
		GetAuraAttrFunc
	};

	BSLib::s32 GetAttrFuncCount[EATTR_MODIFY_TYPE_COUNT] = 
	{
		EGCAF_COUNT,
		EGSAF_COUNT,
		EGBAF_COUNT,
		EGEAF_COUNT,
		EGAFAura_COUNT
	};
	TGetAttr GetAttrFunc(BSLib::s32 funcType, BSLib::s32 key)
	{
		TGetAttr *getAttrFunc = 0;

		if (funcType <= EATTR_MODIFY_TYPE_INVALID || funcType >= EATTR_MODIFY_TYPE_COUNT)
		{
			return NULL;
		}

		getAttrFunc = GetAttrFuncs[funcType];

		if (key <0 || key >= GetAttrFuncCount[funcType])
		{
			return NULL;
		}
		return getAttrFunc[key];
Exit0:
		return 0;
	}
}