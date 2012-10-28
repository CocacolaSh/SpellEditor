#ifndef __LOGIC_SKILL_CONDITIONMGR_H__
#define __LOGIC_SKILL_CONDITIONMGR_H__

namespace SKILLEDITOR
{
	enum EConditionType
	{
		EConditionType_Invalid = -1,
		EConditionType_Item,
		EConditionType_Move,
		EConditionType_State,
		EConditionType_HPMPPct,
		EConditionType_Seq,
		EConditionType_Count
	};
	struct SCondition 
	{
		EConditionType			m_conditionType;
		BSLib::u32				m_conditionParameter1;
		BSLib::u32				m_conditionParameter2;
		BSLib::u32				m_conditionParameter3;
	};
}
#endif