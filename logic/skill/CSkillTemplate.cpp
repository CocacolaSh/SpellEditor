#include "CSkillTemplate.h"
#include "Process_error.h"


namespace SKILLEDITOR
{
	CSkillEntry::CSkillEntry()
	{
		memset(m_intData, 0, sizeof(m_intData));
		memset(m_conditionChecker, 0, sizeof(m_conditionChecker));
		memset(m_seq, 0, sizeof(m_seq));
		memset(m_attackEffect, NULL, sizeof(m_attackEffect));
	}

	CSkillEntry::~CSkillEntry()
	{
		clear();
	}

	bool CSkillEntry::clear()
	{
		m_castEnhancement.clear();
		m_attackEnhancement.clear();
		for (BSLib::s32 i = 0; i < ESkillAttackEffect_Count; i++)
		{
			SAFE_DELETE(m_attackEffect[i]);
		}
		return true;
	}
	CSkillTemplate::CSkillTemplate()
	{
		memset(m_skillEntrys, NULL, sizeof(m_skillEntrys));
	}
	CSkillTemplate::~CSkillTemplate()
	{
		//
	}

	bool CSkillTemplate::addSkillEntry(CSkillEntry *pSkillEntry)
	{
		LOG_PROCESS_ERROR(pSkillEntry);
		BSLib::s32 chargeLevel = pSkillEntry->m_intData[ESkillIntVar_ChargeLevel];

		LOG_PROCESS_ERROR(chargeLevel>= ESkillChargeLevel_Level0 || chargeLevel < ESkillChargeLevel_Count);

		BSLib::s32 scenarioType = pSkillEntry->m_intData[ESkillIntVar_ScenarioType];
		LOG_PROCESS_ERROR(scenarioType>= ESkillScenarioType_Ignore && scenarioType < ESkillScenarioType_Count);

		m_skillEntrys[chargeLevel][scenarioType] = pSkillEntry;
		return true;
Exit0:
		return false;
	}
	CSkillEntry* CSkillTemplate::getSkillEntry(const ::GSLib::SSkillEntryParameter& skillParameter)const
	{
		BSLib::s32 chargeLevel = skillParameter.m_chargeLevel;
		BSLib::s32 scenarioType = skillParameter.m_scenarioType;

		LOG_PROCESS_ERROR(chargeLevel>= ESkillChargeLevel_Level0 || chargeLevel < ESkillChargeLevel_Count);
		LOG_PROCESS_ERROR(scenarioType>= ESkillScenarioType_Ignore && scenarioType < ESkillScenarioType_Count);

		CSkillEntry* pSkillEntry = m_skillEntrys[chargeLevel][scenarioType];
		if (pSkillEntry == NULL && scenarioType != ESkillScenarioType_Ignore)
		{
			pSkillEntry = m_skillEntrys[chargeLevel][ESkillScenarioType_Ignore];
		}
		return pSkillEntry;
Exit0:
		return NULL;
	}
}