#include "attrFunc.h"
#include "Process_error.h"
#include "ModifierFunc.h"
#include "EntityFunc.h"
#include "BulletFunc.h"
#include "EotFunc.h"
#include "SkillFunc.h"
#include "AuraFunc.h"
#include "../skill/evtDef.h"


namespace SKILLEDITOR
{

	extern TGetAttr GetCharAttrFunc[EGetCharAttrFunc_COUNT];
	extern TGetAttr GetSkillAttrFunc[EGetSkillAttrFunc_COUNT];
	extern TGetAttr GetBulletAttrFunc[EGetBulletAttrFunc_COUNT];
	extern TGetAttr GetEotAttrFunc[EGetEotAttrFunc_COUNT];
	extern TGetAttr GetAuraAttrFunc[EGetAuraAttrFunc_COUNT];

	TGetAttr * GetAttrFuncs[EAttrModifyType_Count] = 
	{
		GetCharAttrFunc,
		GetSkillAttrFunc,
		GetBulletAttrFunc,
		GetEotAttrFunc,
		GetAuraAttrFunc
	};

	BSLib::s32 GetAttrFuncCount[EAttrModifyType_Count] = 
	{
		EGetCharAttrFunc_COUNT,
		EGetSkillAttrFunc_COUNT,
		EGetBulletAttrFunc_COUNT,
		EGetEotAttrFunc_COUNT,
		EGetAuraAttrFunc_COUNT
	};
	TGetAttr GetAttrFunc(BSLib::s32 funcType, BSLib::s32 key)
	{
		TGetAttr *getAttrFunc = 0;

		if (funcType <= EAttrModifyType_Invalid || funcType >= EAttrModifyType_Count)
		{
			return NULL;
		}

		getAttrFunc = GetAttrFuncs[funcType];

		if (key < 0 || key >= GetAttrFuncCount[funcType])
		{
			return NULL;
		}
		return getAttrFunc[key];
Exit0:
		return 0;
	}
}