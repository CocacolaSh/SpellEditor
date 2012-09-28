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

	enum EModifyCharAttrKey
	{
		EMAKCHAR_INVALID = -1,  
		EMAKCHAR_NULL,
		EMAKCHAR_RegisterEvtAddDebuf,					//0x00000001 register events add debuf
		EMAKCHAR_RegisterEvtBulletHurt,				//0x00000002 register events bullet hurt
		EMAKCHAR_RegisterEvtChara,						//0x00000003 注册使用技能是调用的人物修改器序列
		EMAKCHAR_RegisterEvtBulletExploded,			//0x00000004 注册生成子弹时调用的子弹修改器序列 
		EMAKCHAR_RegisterEvtBulletBeHit,				//0x00000005 注册被命中时调用的子弹修改器序列 
		EMAKCHAR_RegisterEvtBulletBeHurt,				//0x00000006 注册伤害计算后调用的子弹修改器序列
		EMAKCHAR_SetAuraLastTime,						//0x00000007 改变人物身上aura/eot持续时间 
		EMAKCHAR_AddAuraLastTime,						//0x00000008 增加人物身上aura/eot持续时间 
		EMAKCHAR_SelfSpurt,							//0x00000009 自身位移 
		EMAKCHAR_ChangeFlag,							//0x0000000A 修改人物标记位 
		EMAKCHAR_ChangeSpeFlag,						//0x0000000B 修改人物特殊二级属性位 
		EMAKCHAR_ChangeEmblem,							//0x0000000C 修改人物装备技能列表中的文章技能计数
		EMAKCHAR_ChangeEotPower,						//0x0000000D 修改人物身上EOT效果的每一跳数值
		EMAKCHAR_ChangeAttributeA,						//0x0000000E 修改人物属性A值
		EMAKCHAR_ChangeAttributeB,						//0x0000000F 修改人物属性B值
		EMAKCHAR_ChangeAttributeC,						//0x00000010 修改人物属性C值
		EMAKCHAR_ChangeAttributeD,						//0x00000011 修改人物属性D值
		EMAKCHAR_ChangeAttributeE,						//0x00000012 修改人物属性E值
		EMAKCHAR_SetSpeAuraLastTime,					//0x00000013 修改人物指定ID aura持续时间
		EMAKCHAR_ChangeSpeEmblem,						//0x00000014 修改人物装备技能类表中指定文章技能计数 
		EMAKCHAR_AddAttributePercent,					//0x00000015 增加人物hp,mp百分比
		EMAKCHAR_AddAuraToChar,						//0x00000016 给人物添加指定Aura
		EMAKCHAR_AddEotToChar,							//0x00000017 给人物添加指定EOT
		EMAKCHAR_CharacterIfAction,					//0x00000018 完成人物身上的条件判断执行 
		EMAKCHAR_Count

	};
}
#endif