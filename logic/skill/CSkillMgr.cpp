#include "CSkillMgr.h"
#include "Process_error.h"
namespace SKILLEDITOR
{
	CSkillMgr::CSkillMgr()
	{
		m_pEntrys = NULL;
	}

	CSkillMgr::~CSkillMgr()
	{
		clear();
	}

	bool CSkillMgr::load(const char* filePath)
	{
		BSLib::stringc fileName = "skill_template.xml";
		if (filePath != NULL)
		{
			fileName = filePath;
		}
		BSLib::CXmlExcel xmlExcel;
		bool bRet = xmlExcel.loadFile(fileName);
		LOG_PROCESS_ERROR(bRet);


		return _postLoad(xmlExcel);
Exit0:
		return false;
	}
	bool CSkillMgr::save(const char* filePath)
	{
		return true;
	}

	bool CSkillMgr::_postLoad(BSLib::CXmlExcel& xmlExcel)
	{
		BSLib::CExcelTable * xmlTable = xmlExcel.getTable(0);
		LOG_PROCESS_ERROR(xmlTable);

		BSLib::s32 skipRowCnt = 3;
		BSLib::s32 rowCount = xmlTable->rowSize();

		LOG_PROCESS_ERROR(rowCount > skipRowCnt);
		m_pEntrys = new CSkillEntry[rowCount - skipRowCnt];
		LOG_PROCESS_ERROR(m_pEntrys);


		CSkillEntry *pSkillEntry = NULL;
		for(BSLib::s32 i = skipRowCnt; i < rowCount; i++)
		{
			pSkillEntry = m_pEntrys + i - skipRowCnt;

			BSLib::s32 sillID = 0, skillLevel = 0;
			xmlTable->getColumnValue(i, "SkillID", pSkillEntry->m_intData[ESkillIntVar_ID]);
			xmlTable->getColumnValue(i, "SkillLevel",  pSkillEntry->m_intData[ESkillIntVar_Level]);

			xmlTable->getColumnValue(i, "ScenarioType", pSkillEntry->m_intData[ESkillIntVar_ScenarioType]);
			xmlTable->getColumnValue(i, "SeqAfterLearn",  pSkillEntry->m_intData[ESkillIntVar_AtLearnSeqs]);
			xmlTable->getColumnValue(i, "SeqAfterEquip", pSkillEntry->m_intData[ESkillIntVar_AtEquipSeqs]);
			xmlTable->getColumnValue(i, "LoopFx",  pSkillEntry->m_strData[ESkillStrVar_LoopFX]);
			xmlTable->getColumnValue(i, "ChiLevel", pSkillEntry->m_intData[ESkillIntVar_ChargeLevel]);
			xmlTable->getColumnValue(i, "IsElite",  pSkillEntry->m_intData[ESkillIntVar_IsElite]);
			xmlTable->getColumnValue(i, "IsEmblem",  pSkillEntry->m_intData[ESkillIntVar_IsEmblem]);
			xmlTable->getColumnValue(i, "IsIgnoreHard",  pSkillEntry->m_intData[ESkillIntVar_IsIgnoreHard]);
			xmlTable->getColumnValue(i, "SkillPattern",  pSkillEntry->m_intData[ESkillIntVar_Pattern]);
			xmlTable->getColumnValue(i, "SkillBaseType",  pSkillEntry->m_intData[ESkillIntVar_BaseType]);

			{
				//xmlTable->getColumnValue(i, "RequireNotInCommonState",  pSkillEntry->m_intData[ESkillIntVar_]);
				//xmlTable->getColumnValue(i, "RequireMoveCheck",  pSkillEntry->m_intData[ESkillIntVar_IsElite]);
			}
			
			xmlTable->getColumnValue(i, "CoolDownTime", pSkillEntry->m_intData[ESkillIntVar_CoolDownTime]);
			xmlTable->getColumnValue(i, "CoolDownGroup",  pSkillEntry->m_intData[ESkillIntVar_GlobalCDType]);
			xmlTable->getColumnValue(i, "CategoryType", pSkillEntry->m_intData[ESkillIntVar_CategoryType]);
			xmlTable->getColumnValue(i, "CategoryVariable",  pSkillEntry->m_strData[ESkillIntVar_CategoryVar]);
			xmlTable->getColumnValue(i, "IsAutoFaceTarget", pSkillEntry->m_intData[ESkillIntVar_IsAutoFaceTarget]);

			xmlTable->getColumnValue(i, "CastTime",  pSkillEntry->m_intData[ESkillIntVar_CatingTime]);
			xmlTable->getColumnValue(i, "CastTake",  pSkillEntry->m_strData[ESkillStrVar_CastingPose]);
			{
				//add cast enhancement
			}

			xmlTable->getColumnValue(i, "AttackTime",  pSkillEntry->m_intData[ESkillIntVar_AttackingTime]);
			xmlTable->getColumnValue(i, "AttackSTake",  pSkillEntry->m_strData[ESkillStrVar_AttackingPos]);
			{
				//add cast enhancement
			}

			xmlTable->getColumnValue(i, "CloseAttackTime",  pSkillEntry->m_intData[ESkillIntVar_CloseAttackTime]);
			xmlTable->getColumnValue(i, "CloseAttackSTake",  pSkillEntry->m_strData[ESkillStrVar_CloseAttackPos]);
			{
				//add cast enhancement
			}

			xmlTable->getColumnValue(i, "IsIgnoreHard",  pSkillEntry->m_intData[ESkillIntVar_IsIgnoreHard]);
			xmlTable->getColumnValue(i, "SkillPattern",  pSkillEntry->m_intData[ESkillIntVar_Pattern]);
			xmlTable->getColumnValue(i, "SkillBaseType",  pSkillEntry->m_intData[ESkillIntVar_BaseType]);

			i++;
		}
		return true;
Exit0:
		return false;
	}
	bool CSkillMgr::_postSave(BSLib::CXmlExcel& xmlExcel)
	{
		return true;
	}
	bool CSkillMgr::clear()
	{
		/*TSKILLMAP::iterator begIter = m_skillMgrMap.begin();

		while(begIter != m_skillMgrMap.end())
		{
			delete begIter->second;
		}*/
		SAFE_DELETE_ARRAY(m_pEntrys);
		m_skillMgrMap.clear();
		return true;
	}
	
}