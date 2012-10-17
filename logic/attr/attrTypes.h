#ifndef __LOGIC_ATTR_ATTRTYPES_H__
#define __LOGIC_ATTR_ATTRTYPES_H__
#include "basedef.h"
namespace SKILLEDITOR
{
	enum EAttrType
	{
		EAttrType_INVALID = -1,
		EAttrType_BaseAttributeBegin,
		EAttrType_Strength = EAttrType_BaseAttributeBegin,
		EAttrType_Stamina,
		EAttrType_Intelli,
		EAttrType_Spirit,
		EAttrType_CoolDownReduceFactor,
		EAttrType_MPCostIncreaseFactor,
		EAttrType_GeneralResist,
		EAttrType_BaseAttributeEnd,
	};
	enum EExtendAttrType
	{
		EExAttrType_INVALID = -1,

		//有ABCDE的二级属性
		EExAttrType_AttributeBegin,
		EExAttrType_PhyAtk = EExAttrType_AttributeBegin,
		EExAttrType_MagAtk,
		EExAttrType_PhyDef,
		EExAttrType_MagDef,
		EExAttrType_HpMax,
		EExAttrType_MpMax,
		EExAttrType_MoveSpeed,
		EExAttrType_AttributeEnd,
	};

	enum EOtherAttrType
	{
		EOtherAttrType_INVALID = -1,
		EOtherAttrType_AttributeBegin,
		EOtherAttrType_SPMax = EOtherAttrType_AttributeBegin,
		EOtherAttrType_HPRecoveryPerMin,
		EOtherAttrType_MPRecoveryPerMin,
		EOtherAttrType_SPRecoveryPerMin,

		EOtherAttrType_PhyPierce,
		EOtherAttrType_MagPierce,

		EOtherAttrType_CriticalValue,
		EOtherAttrType_AntiCriticalValue,
		EOtherAttrType_CriticalRate,
		EOtherAttrType_AntiCriticalRate,
		EOtherAttrType_AntiStiff,
		EOtherAttrType_Stiff,

		EOtherAttrType_NullExtend,//save
		EOtherAttrType_AtkRangeParam,
		EOtherAttrType_FireEnhanced,
		EOtherAttrType_WaterEnhanced,
		EOtherAttrType_LightEnhanced,
		EOtherAttrType_ShadowEnhanced,

		EOtherAttrType_FireResist,
		EOtherAttrType_WaterResist,
		EOtherAttrType_LightResist,
		EOtherAttrType_ShadowResist,
		EOtherAttrType_AttributeEnd,
	};

	enum EFactorType
	{
		EFactorType_INVALID = -1,
		EFactorType_Begin,
		EFactorType_Critical = EFactorType_Begin,
		EFactorType_Broke,
		EFactorType_AtkSpeed,
		EFactorType_CastSpeed,

		EFactorType_NullExtend,
		EFactorType_PhyCoolDownReduce,
		EFactorType_MagCoolDownReduce,
		EFactorType_PhyMpCostIncrease,
		EFactorType_MagMpCostIncrease,
		EFactorType_MaxBaTiValue,
		EFactorType_BaTiRegenStartTime,
		EFactorType_BaTiRegenRate,
		EFactorType_BaTiRecoverAllTime,
		EFactorType_End,
	};

	enum ECustomAttrType
	{
		ECustomAttrType_INVALID = -1,
		ECustomAttrType_Begin,
		ECustomAttrType_CurHP = ECustomAttrType_Begin,
		ECustomAttrType_CurMP,
		ECustomAttrType_CurSP,
		ECustomAttrType_CurBT,
		ECustomAttrType_Broke,
		ECustomAttrType_FloatAtk,
		ECustomAttrType_End,
	};

	//属性编号定义
	enum EAttrEntityType
	{
		EAttrEntityType_INVALID = -1,
		EAttrEntityType_Null,
		EAttrEntityType_Begin,
		EAttrEntityType_BaseAttrMax = 31,
		EAttrEntityType_ExtendAttrMax = 51,
		EAttrEntityType_OtherAttrMax = 73,
		EAttrEntityType_FactorMax = 101,
		EAttrEntityType_CustomMax = 106,
		EAttrEntityType_Count,
		EAttrEntityType_End = EAttrEntityType_Count,
	};

	//属性中转类型
	enum EEnumAttrType
	{
		EEnumAttrType_INVALID = -1,
		EEnumAttrType_Begin,
		EEnumAttrType_Base = EEnumAttrType_Begin,
		EEnumAttrType_Extend,
		EEnumAttrType_Other,
		EEnumAttrType_Factor,
		EEnumAttrType_Custom,
		EEnumAttrType_Count,
	};

	const int SPELL_RATE_MAX = 10000;
}
#endif