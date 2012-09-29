#ifndef __LOGIC_ATTR_ENTITYFUNC_H__
#define __LOGIC_ATTR_ENTITYFUNC_H__

namespace SKILLEDITOR
{
	enum EGetCharAttrFunc
	{
		EGCAF_INVALID = 0,
		EGCAF_DEBUFNO = 0x00000003,
		EGCAF_FLAG,
		EGCAF_MOVECONDITION,
		EGCAF_ATTRPERCENT,
		EGCAF_BUFFNO,
		EGCAF_ATTRIBUTEA,
		EGCAF_ATTRIBUTEB,
		EGCAF_ATTRIBUTEC,
		EGCAF_ATTRIBUTED,
		EGCAF_ATTRIBUTEE,
		EGCAF_GETISATT,
		EGCAF_COUNT
	};

	enum EGetSkillAttrFunc
	{
		EGSAF_INVALID = 0,
		EGSAF_COUNT
	};
	enum EGetBulletAttrFunc
	{
		EGBAF_INVALID = 0,
		EGBAF_COUNT
	};
	enum EGetEotAttrFunc
	{
		EGEAF_INVALID = 0,
		EGEAF_COUNT
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