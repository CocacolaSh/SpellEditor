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

	class IFighter;
	typedef BSLib::s32 (* TGetAttr)(IFighter* ,BSLib::s32);
	TGetAttr GetAttrFunc(BSLib::s32 funcType, BSLib::s32 key)
	{
		TGetAttr *getAttrFunc = 0;
Exit0:
		return 0;
	}
	enum EAttrModifyKeyChar
	{
		EAMKCHAR_INVALID = -1,  
		EAMKCHAR_NULL,
		EAMKCHAR_RegisterEvtAddDebuf,					//0x00000001 register events add debuf
		EAMKCHAR_RegisterEvtBulletHurt,				//0x00000002 register events bullet hurt
		EAMKCHAR_RegisterEvtChara,						//0x00000003 注册使用技能是调用的人物修改器序列
		EAMKCHAR_RegisterEvtBulletExploded,			//0x00000004 注册生成子弹时调用的子弹修改器序列 
		EAMKCHAR_RegisterEvtBulletBeHit,				//0x00000005 注册被命中时调用的子弹修改器序列 
		EAMKCHAR_RegisterEvtBulletBeHurt,				//0x00000006 注册伤害计算后调用的子弹修改器序列
		EAMKCHAR_SetAuraLastTime,						//0x00000007 改变人物身上aura/eot持续时间 
		EAMKCHAR_AddAuraLastTime,						//0x00000008 增加人物身上aura/eot持续时间 
		EAMKCHAR_SelfSpurt,							//0x00000009 自身位移 
		EAMKCHAR_ChangeFlag,							//0x0000000A 修改人物标记位 
		EAMKCHAR_ChangeSpeFlag,						//0x0000000B 修改人物特殊二级属性位 
		EAMKCHAR_ChangeEmblem,							//0x0000000C 修改人物装备技能列表中的文章技能计数
		EAMKCHAR_ChangeEotPower,						//0x0000000D 修改人物身上EOT效果的每一跳数值
		EAMKCHAR_ChangeAttributeA,						//0x0000000E 修改人物属性A值
		EAMKCHAR_ChangeAttributeB,						//0x0000000F 修改人物属性B值
		EAMKCHAR_ChangeAttributeC,						//0x00000010 修改人物属性C值
		EAMKCHAR_ChangeAttributeD,						//0x00000011 修改人物属性D值
		EAMKCHAR_ChangeAttributeE,						//0x00000012 修改人物属性E值
		EAMKCHAR_SetSpeAuraLastTime,					//0x00000013 修改人物指定ID aura持续时间
		EAMKCHAR_ChangeSpeEmblem,						//0x00000014 修改人物装备技能类表中指定文章技能计数 
		EAMKCHAR_AddAttributePercent,					//0x00000015 增加人物hp,mp百分比
		EAMKCHAR_AddAuraToChar,						//0x00000016 给人物添加指定Aura
		EAMKCHAR_AddEotToChar,							//0x00000017 给人物添加指定EOT
		EAMKCHAR_CharacterIfAction,					//0x00000018 完成人物身上的条件判断执行 
		EAMKCHAR_Count

	};

	enum EAttrModifyKeySkill
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
	};

	
}
#endif