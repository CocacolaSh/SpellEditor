#ifndef __LOGIC_ATTR_ENTITYFUNC_H__
#define __LOGIC_ATTR_ENTITYFUNC_H__

#include "basedef.h"
namespace SKILLEDITOR
{
	enum EGetCharAttrFunc
	{
		EGetCharAttrFunc_INVALID = 0,
		EGetCharAttrFunc_DebuffNo = 0x00000003,
		EGetCharAttrFunc_Flag,
		EGetCharAttrFunc_MoveCondition,
		EGetCharAttrFunc_AttrPercent,
		EGetCharAttrFunc_BuffNo,
		EGetCharAttrFunc_GetAttributeA,
		EGetCharAttrFunc_GetAttributeB,
		EGetCharAttrFunc_GetAttributeC,
		EGetCharAttrFunc_GetAttributeD,
		EGetCharAttrFunc_GetAttributeE,
		EGetCharAttrFunc_GetIsAtt,
		EGetCharAttrFunc_COUNT
	};

	
	
	
	//enum EGetAuraAttrFunc
	//{
	//	EGAAF_INVALID = 0,
	//	EGAAF_COUNT
	//};
	
	

	/*enum EAttrModifyKeySkill
	{
		EAMKSKILL_Invalid = -1,
		EAMKSKILL_Count,
	};
	enum EAttrModifyKeyBullet
	{
		EAMKBullet_Invalid = -1,
		EAMKBullet_Count,
	};
	enum EAttrModifyKeyEot
	{
		EAMKEot_Invalid = -1,
		EAMKEot_Count,
	};
	enum EAttrModifyKeyAura
	{
		EAMKAura_Invalid = -1,
		EAMKAura_Count,
	};*/

	
}
#endif