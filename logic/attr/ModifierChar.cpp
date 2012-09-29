#include "ModifierChar.h"
#include "basedef.h"
#include "CCharacterEntity.h"
#include "ModifierFunc.h"
namespace SKILLEDITOR
{
	//
	bool RegisterEvtAddDebuf(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool RegisterEvtBulletHurt(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool RegisterEvtChara(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool RegisterEvtBulletExploded(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool RegisterEvtBulletBeHit(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool RegisterEvtBulletBeHurt(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool SetAuraLastTime(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool AddAuraLastTime(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}

	bool SelfSpurt(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeFlag(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeSpeFlag(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeEmblem(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeEotPower(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeAttributeA(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeAttributeB(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeAttributeC(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeAttributeD(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeAttributeE(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool SetSpeAuraLastTime(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeSpeEmblem(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool AddAttributePercent(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool AddAuraToChar(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool AddEotToChar(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool CharacterIfAction(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	TAttrModifierFunc AttrCharModifierFunc[EAMKCHAR_Count] = 
	{
		NULL,
		RegisterEvtAddDebuf,					//0x00000001 register events add debuf
		RegisterEvtBulletHurt,				//0x00000002 register events bullet hurt
		RegisterEvtChara,						//0x00000003 注册使用技能是调用的人物修改器序列
		RegisterEvtBulletExploded,			//0x00000004 注册生成子弹时调用的子弹修改器序列 
		RegisterEvtBulletBeHit,				//0x00000005 注册被命中时调用的子弹修改器序列 
		RegisterEvtBulletBeHurt,				//0x00000006 注册伤害计算后调用的子弹修改器序列
		SetAuraLastTime,						//0x00000007 改变人物身上aura/eot持续时间 
		AddAuraLastTime,						//0x00000008 增加人物身上aura/eot持续时间 
		SelfSpurt,							//0x00000009 自身位移 
		ChangeFlag,							//0x0000000A 修改人物标记位 
		ChangeSpeFlag,						//0x0000000B 修改人物特殊二级属性位 
		ChangeEmblem,							//0x0000000C 修改人物装备技能列表中的文章技能计数
		ChangeEotPower,						//0x0000000D 修改人物身上EOT效果的每一跳数值
		ChangeAttributeA,						//0x0000000E 修改人物属性A值
		ChangeAttributeB,						//0x0000000F 修改人物属性B值
		ChangeAttributeC,						//0x00000010 修改人物属性C值
		ChangeAttributeD,						//0x00000011 修改人物属性D值
		ChangeAttributeE,						//0x00000012 修改人物属性E值
		SetSpeAuraLastTime,					//0x00000013 修改人物指定ID aura持续时间
		ChangeSpeEmblem,						//0x00000014 修改人物装备技能类表中指定文章技能计数 
		AddAttributePercent,					//0x00000015 增加人物hp,mp百分比
		AddAuraToChar,						//0x00000016 给人物添加指定Aura
		AddEotToChar,							//0x00000017 给人物添加指定EOT
		CharacterIfAction,					//0x00000018 完成人物身上的条件判断执行 
	};
}