#include "CSkillMgr.h"
#include "Process_error.h"
#include "SkillDef.h"
#include <string>
#include <sstream>
namespace SKILLEDITOR
{

	bool StrToUInt64Vector(std::string &enhancementStr, std::vector<BSLib::u64> &outputVector)
	{
		std::string::size_type curPos = std::string::npos;
		std::string::size_type lastPos = 0;

		do 
		{
			curPos = enhancementStr.find_first_of('|', lastPos);
			std::string subToken = enhancementStr.substr(lastPos, curPos);
			do 
			{
				std::string::size_type subCurPos = std::string::npos;
				std::string::size_type subLastPos = 0;

				subCurPos = subToken.find_first_of('-', subLastPos);

				BSLib::s32 id = 0, level = 0;
				if (subCurPos == std::string::npos)
				{
					std::stringstream ss;
					ss << subToken.substr(subLastPos, subCurPos);
					ss >> id;
					level = 1;
				}else
				{
					std::stringstream ss;
					ss << subToken.substr(subLastPos, subCurPos);
					ss >> id;

					ss.clear();
					ss << subToken.substr(subCurPos + 1);
					ss >> level;
				}
				outputVector.push_back(MakeSkillKey(id, level));
				subLastPos = subCurPos + 1;
			} while (false);

			lastPos = curPos + 1;
		} while (curPos != std::string::npos);
		return true;
	}
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

			char *stopStr = NULL;
			BSLib::s32 sillID = 0, skillLevel = 0;
			xmlTable->getColumnValue(i, "SkillID", pSkillEntry->m_intData[ESkillIntVar_ID]);
			xmlTable->getColumnValue(i, "SkillLevel",  pSkillEntry->m_intData[ESkillIntVar_Level]);

			xmlTable->getColumnValue(i, "ScenarioType", pSkillEntry->m_intData[ESkillIntVar_ScenarioType]);
			xmlTable->getColumnValue(i, "SeqAfterLearn",  pSkillEntry->m_intData[ESkillIntVar_AtLearnSeqs]);
			xmlTable->getColumnValue(i, "SeqAfterEquip", pSkillEntry->m_intData[ESkillIntVar_AtEquipSeqs]);
			//xmlTable->getColumnValue(i, "LoopFx",  pSkillEntry->m_strData[ESkillStrVar_LoopFX]);
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
			//xmlTable->getColumnValue(i, "CategoryVariable",  pSkillEntry->m_strData[ESkillIntVar_CategoryVar]);
			xmlTable->getColumnValue(i, "IsAutoFaceTarget", pSkillEntry->m_intData[ESkillIntVar_IsAutoFaceTarget]);

			{
				std::string requireNotInCommonState = "";
				//xmlTable->getColumnValue(i, "RequireNotInCommonState", requireNotInCommonState);
				if (requireNotInCommonState != "")
				{
					std::string::size_type lastPos = 0;
					std::string::size_type splitPos = requireNotInCommonState.find_first_of(';', lastPos);
					while(splitPos != std::string::npos)
					{
						std::string stateStr = requireNotInCommonState.substr(lastPos, splitPos);

						BSLib::s32 stateInt = 0;
						std::stringstream ss;
						ss<< stateStr;
						ss >> stateInt;

						if (stateInt >= 0 && stateInt < 96)
						{
							if (stateInt < 32)
							{
								pSkillEntry->m_conditionChecker[EConditionType_State].m_conditionParameter1 |=
									(0x01 << (stateInt % 32));
							}
							else if (stateInt < 64)
							{
								pSkillEntry->m_conditionChecker[EConditionType_State].m_conditionParameter2 |=
									(0x01 << (stateInt % 32));
							}
							else
							{
								pSkillEntry->m_conditionChecker[EConditionType_State].m_conditionParameter3 |=
									(0x01 << (stateInt % 32));
							}
						}
					}
				}
			}
			xmlTable->getColumnValue(i, "CastTime",  pSkillEntry->m_intData[ESkillIntVar_CatingTime]);
			//xmlTable->getColumnValue(i, "CastTake",  pSkillEntry->m_strData[ESkillStrVar_CastingPose]);
			{
				//add cast enhancement
				std::string enhancementStr = "";
				//xmlTable->getColumnValue(i, "CastEnhancement", enhancementStr);
				StrToUInt64Vector(enhancementStr, pSkillEntry->m_castEnhancement);
			}

			xmlTable->getColumnValue(i, "AttackTime",  pSkillEntry->m_intData[ESkillIntVar_AttackingTime]);
			xmlTable->getColumnValue(i, "AttackSTake",  pSkillEntry->m_strData[ESkillStrVar_AttackingPos]);
			{
				std::string enhancementStr = "";
				//xmlTable->getColumnValue(i, "AttackEnhancement", enhancementStr);
				StrToUInt64Vector(enhancementStr, pSkillEntry->m_attackEnhancement);
			}

			xmlTable->getColumnValue(i, "CloseAttackTime",  pSkillEntry->m_intData[ESkillIntVar_CloseAttackTime]);
			//xmlTable->getColumnValue(i, "CloseAttackSTake",  pSkillEntry->m_strData[ESkillStrVar_CloseAttackPos]);
			

			xmlTable->getColumnValue(i, "CastArmor",  pSkillEntry->m_intData[ESkillIntVar_CastArmor]);
			xmlTable->getColumnValue(i, "FloatingTimeStart",  pSkillEntry->m_intData[ESkillIntVar_FloatTimeStart]);
			xmlTable->getColumnValue(i, "FloatTimeSpan",  pSkillEntry->m_intData[ESkillIntVar_FloadTimeSpan]);

			{
				//attack effect
				BSLib::stringc attackEvent = "";
				xmlTable->getColumnValue(i, "AttackEvent",  attackEvent);
				if (attackEvent != "")
				{
					BSLib::s32 attackEventTime = 0;
					xmlTable->getColumnValue(i, "AttackEventTime",  attackEventTime);
					BSLib::u32 modifierSeq = 0;

					modifierSeq = strtol(attackEvent.c_str(), &stopStr, 0);

					pSkillEntry->m_attackEffect[ESkillAttackEffect_Modifier] = new CSkillAttackEffectModifier(attackEventTime / 1000.0f, modifierSeq);
				}
				
				BSLib::s32 spurtStartTime = 0, spurtTimeSpan = 0, spurtDistanceX = 0, spurtDistanceY = 0, spurtDistanceZ = 0;
				bool spurtStepDown = false;

				xmlTable->getColumnValue(i, "SpurtStartTime",  spurtStartTime);
				xmlTable->getColumnValue(i, "SpurtTimeSpan",  spurtTimeSpan);
				xmlTable->getColumnValue(i, "SpurtDistanceX",  spurtDistanceX);
				xmlTable->getColumnValue(i, "SpurtDistanceY",  spurtDistanceY);
				xmlTable->getColumnValue(i, "SpurtDistanceZ",  spurtDistanceZ);
				xmlTable->getColumnValue(i, "SpurtNoStepDown",  spurtStepDown);
				if (spurtStartTime >= 0 && spurtTimeSpan > 0 && (spurtDistanceX != 0 || spurtDistanceY != 0 || spurtDistanceZ != 0))
				{

					pSkillEntry->m_attackEffect[ESkillAttackEffect_Spurt] = new CSkillAttackEffectSpurt(spurtStartTime / 1000.0f,
						spurtTimeSpan/1000.0f, static_cast<BSLib::f32>(spurtDistanceX), static_cast<BSLib::f32>(spurtDistanceY), static_cast<BSLib::f32>(spurtDistanceZ), spurtStepDown);
				}

				BSLib::s32 fireTime = 0, fireType = 0;
				BSLib::stringc fireMissileID = "";
				xmlTable->getColumnValue(i, "FireTime",  fireTime);
				xmlTable->getColumnValue(i, "FireType",  fireType);
				xmlTable->getColumnValue(i, "FireMissileID",  fireMissileID);
				if (fireTime >=0 && fireMissileID != "")
				{
					pSkillEntry->m_attackEffect[ESkillAttackEffect_Fire] = new CSkillAttackEffectFire(fireTime / 1000.0f, fireType, fireMissileID, 
						pSkillEntry->m_intData[ESkillIntVar_ID], pSkillEntry->m_intData[ESkillIntVar_Level]);
				}
			}

			for (BSLib::s32 j = 0; j < EModifySkillTime_Count; ++j)
			{
				BSLib::s32 attackBoxGroupID = 0, breadArmor = 0;
				BSLib::stringc attackInfo = "";

				char colIndex = j + 1 + '0';
				BSLib::stringc columnStr = "AttackBoxGroupID";
				columnStr += colIndex;
				xmlTable->getColumnValue(i, columnStr,  attackBoxGroupID);
				columnStr = "HitBreadArmor";
				columnStr += colIndex;
				xmlTable->getColumnValue(i, columnStr,  breadArmor);

				columnStr = "HitAttackInfo";
				columnStr += colIndex;
				xmlTable->getColumnValue(i, columnStr,  attackInfo);

				pSkillEntry->m_attackPeriods[j].init(attackBoxGroupID, attackInfo, breadArmor);
				pSkillEntry->m_attackPeriods[j].setChargeLevel(pSkillEntry->m_intData[ESkillIntVar_ChargeLevel]);
				pSkillEntry->m_attackPeriods[j].setPeriodID(j);

				BSLib::stringc hitSeqStr = "";
				columnStr = "HitSeq";
				columnStr += colIndex;
				xmlTable->getColumnValue(i, columnStr,  hitSeqStr);

				pSkillEntry->m_seq[EModifySkillTime_OnHit1 + j] = strtol(hitSeqStr.c_str(), &stopStr, 0);

			}
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