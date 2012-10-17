#include "ModifierChar.h"
#include "basedef.h"
#include "CCharacterEntity.h"
#include "ModifierFunc.h"
#include "attrFunc.h"
#include "attrTypes.h"
namespace SKILLEDITOR
{
	template <class T>
	T GetMinValue(T inValue, T min)
	{
		return inValue < min ? inValue : min;
	}
	template <class T>
	T GetMaxValue(T inValue, T max)
	{
		return inValue > max ? inValue : max;
	}
	template <class T>
	T GetRangeValue(T inValue, T deltaValue, T min, T max)
	{
		T temp = inValue + deltaValue;
		if (deltaValue < 0)
		{
			temp = GetMaxValue(temp, min);
		}
		else
		{
			temp = GetMinValue(temp, max);
		}
		return temp;
	}

	bool ChangeBaseAttributeA(BSLib::s32 attrType, CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		LOG_PROCESS_ERROR(dst && attrType < EAttrType_BaseAttributeEnd);
//
//		CCharacterEntity *pObj = (CCharacterEntity *)dst;
//		CAttrList *attr_list = pObj->getFighterImp()->getAttrList();
//		BSLib::s32 value = attr_list->getBaseAttributeA(attrType);
//
//		value = GetRangeValue(value, arg1, 0, 0x7fffffff);
//		attr_list->setBaseAttributeA(attrType, value);
//		attr_list->setBaseAttribute(attrType, attr_list->calcBaseAttribute(attrType));
//
//		BSLib::s32 class = pObj->isPlayer() ? pObj->getDBEntityClass() : pObj->getEntityClass();
//		return CAttrConfig::getInstance().getModifierList(class, attrType).updateAffectedExAttr(src, pObj, arg1);
//Exit0:
		return false;
	}
	bool ChangeBaseAttributeB(BSLib::s32 attrType, CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		LOG_PROCESS_ERROR(dst && attrType < EAttrType_BaseAttributeEnd);
//
//		CCharacterEntity *pObj = (CCharacterEntity *)dst;
//		CAttrList *attr_list = pObj->getFighterImp()->getAttrList();
//		BSLib::s32 value = attr_list->getBaseAttributeA(attrType);
//
//		value = GetRangeValue(value, arg1, 0, 0x7fffffff);
//		attr_list->setBaseAttributeB(attrType, value);
//		attr_list->setBaseAttribute(attrType, attr_list->calcBaseAttribute(attrType));
//
//		BSLib::s32 class = pObj->isPlayer() ? pObj->getDBEntityClass() : pObj->getEntityClass();
//		return CAttrConfig::getInstance().getModifierList(class, attrType).updateAffectedExAttr(src, pObj, arg1);
//Exit0:
		return false;
	}
	bool ChangeBaseAttributeC(BSLib::s32 attrType, CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		LOG_PROCESS_ERROR(dst && attrType < EAttrType_BaseAttributeEnd);
//
//		CCharacterEntity *pObj = (CCharacterEntity *)dst;
//		CAttrList *attr_list = pObj->getFighterImp()->getAttrList();
//		BSLib::s32 value = attr_list->getBaseAttributeA(attrType);
//
//		value = GetRangeValue(value, arg1, 0, 0x7fffffff);
//		attr_list->setBaseAttributeC(attrType, value);
//		attr_list->setBaseAttribute(attrType, attr_list->calcBaseAttribute(attrType));
//
//		BSLib::s32 class = pObj->isPlayer() ? pObj->getDBEntityClass() : pObj->getEntityClass();
//		return CAttrConfig::getInstance().getModifierList(class, attrType).updateAffectedExAttr(src, pObj, arg1);
//Exit0:
		return false;
	}
	bool ChangeExtendAttributeA(BSLib::s32 attrType, CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		LOG_PROCESS_ERROR(dst && attrType < EExAttrType_AttributeEnd);
//
//		CCharacterEntity *pObj = (CCharacterEntity *)dst;
//		CAttrList *attr_list = pObj->getFighterImp()->getAttrList();
//		BSLib::s32 value = attr_list->getExtendAttributeA(attrType);
//
//		value = GetRangeValue(value, arg1, 0, 0x7fffffff);
//		attr_list->getExtendAttributeA(attrType, value);
//		attr_list->setExtendAttribute(attrType, attr_list->calcExtendAttribute(attrType));
//
//		return true;
//Exit0:
		return false;
	}
	bool ChangeExtendAttributeB(BSLib::s32 attrType, CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		LOG_PROCESS_ERROR(dst && attrType < EExAttrType_AttributeEnd);
//
//		CCharacterEntity *pObj = (CCharacterEntity *)dst;
//		CAttrList *attr_list = pObj->getFighterImp()->getAttrList();
//		BSLib::s32 value = attr_list->getExtendAttributeB(attrType);
//
//		BSLib::s32 basePoint = 1;
//		if (arg2 < 0)
//		{
//			//来自于职业修改
//			basePoint = arg2 & ~0x80000000;
//			value = value * basePoint / SPELL_RATE_MAX;
//		}
//		value = GetRangeValue(value, arg1, -SPELL_RATE_MAX, 0x7fffffff);
//
//		attr_list->getExtendAttributeB(attrType, value);
//		attr_list->setExtendAttribute(attrType, attr_list->calcExtendAttribute(attrType));
//
//		return true;
//Exit0:
		return false;
	}
	bool ChangeExtendAttributeC(BSLib::s32 attrType, CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		LOG_PROCESS_ERROR(dst && attrType < EExAttrType_AttributeEnd);
//
//		CCharacterEntity *pObj = (CCharacterEntity *)dst;
//		CAttrList *attr_list = pObj->getFighterImp()->getAttrList();
//		BSLib::s32 value = attr_list->getExtendAttributeC(attrType);
//		
//		BSLib::s32 basePoint = 1;
//		if (arg2 < 0)
//		{
//			//来自于职业修改
//			basePoint = arg2 & ~0x80000000;
//			value = value * basePoint / SPELL_RATE_MAX;
//		}
//		value = GetRangeValue(value, arg1, 0, 0x7fffffff);
//
//		attr_list->getExtendAttributeC(attrType, value);
//		attr_list->setExtendAttribute(attrType, attr_list->calcExtendAttribute(attrType));
//
//		return true;
//Exit0:
		return false;
	}
	bool ChangeExtendAttributeD(BSLib::s32 attrType, CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		LOG_PROCESS_ERROR(dst && attrType < EExAttrType_AttributeEnd);
//
//		CCharacterEntity *pObj = (CCharacterEntity *)dst;
//		CAttrList *attr_list = pObj->getFighterImp()->getAttrList();
//		BSLib::s32 value = attr_list->getExtendAttributeD(attrType);
//
//		BSLib::s32 basePoint = 1;
//		if (arg2 < 0)
//		{
//			//来自于职业修改
//			basePoint = arg2 & ~0x80000000;
//			value = value * basePoint / SPELL_RATE_MAX;
//		}
//		value = GetRangeValue(value, arg1, -SPELL_RATE_MAX, 0x7fffffff);
//		attr_list->getExtendAttributeD(attrType, value);
//		attr_list->setExtendAttribute(attrType, attr_list->calcExtendAttribute(attrType));
//
//		return true;
//Exit0:
		return false;
	}
	bool ChangeExtendAttributeE(BSLib::s32 attrType, CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		LOG_PROCESS_ERROR(dst && attrType < EExAttrType_AttributeEnd);
//
//		CCharacterEntity *pObj = (CCharacterEntity *)dst;
//		CAttrList *attr_list = pObj->getFighterImp()->getAttrList();
//		BSLib::s32 value = attr_list->getExtendAttributeE(attrType);
//
//		BSLib::s32 basePoint = 1;
//		if (arg2 < 0)
//		{
//			//来自于职业修改
//			basePoint = arg2 & ~0x80000000;
//			value = value * basePoint / SPELL_RATE_MAX;
//		}
//		value = GetRangeValue(value, arg1, 0, 0x7fffffff);
//
//		attr_list->getExtendAttributeE(attrType, value);
//		attr_list->setExtendAttribute(attrType, attr_list->calcExtendAttribute(attrType));
//
//		return true;
//Exit0:
		return false;
	}
	bool ChangeFactor(BSLib::s32 attrType, CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		LOG_PROCESS_ERROR(dst && attrType < EFactorType_End);
//
//		CCharacterEntity *pObj = (CCharacterEntity *)dst;
//		CAttrList *attr_list = pObj->getFighterImp()->getAttrList();
//		BSLib::s32 value = attr_list->getFactorAttribute(attrType);
//
//		value = GetRangeValue(value, arg1, 0, 0x7fffffff);
//
//		attr_list->setFactorAttribute(attrType, value);
//		return true;
//Exit0:
		return false;
	}
	bool ChangeOtherAttr(BSLib::s32 attrType, CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		LOG_PROCESS_ERROR(dst && attrType < EOtherAttrType_AttributeEnd);
//
//		CCharacterEntity *pObj = (CCharacterEntity *)dst;
//		CAttrList *attr_list = pObj->getFighterImp()->getAttrList();
//		BSLib::s32 value = attr_list->getOtherAttribute(attrType);
//
//		value = GetRangeValue(value, arg1, 0, 0x7fffffff);
//
//		attr_list->setOtherAttribute(attrType, value);
//		return true;
//Exit0:
		return false;
	}
	bool ChangeCustomAttr(BSLib::s32 attrType, CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		LOG_PROCESS_ERROR(dst && attrType < ECustomAttrType_End);
//
//		CCharacterEntity *pObj = (CCharacterEntity *)dst;
//		CAttrList *attr_list = pObj->getFighterImp()->getAttrList();
//		BSLib::s32 value = attr_list->getCustomAttribute(attrType);
//
//		switch(attrType)
//		{
//		case ECustomAttrType_CurHP:
//			{
//				BSLib::s32 maxValue  = attr_list->getExtendAttribute(EExAttrType_HpMax);
//				value = GetRangeValue(value, arg1, 0, maxValue);
//			}
//			break;
//		case ECustomAttrType_CurMP:
//			{
//				BSLib::s32 maxValue  = attr_list->getExtendAttribute(EExAttrType_MpMax);
//				value = GetRangeValue(value, arg1, 0, maxValue);
//			}
//			break;
//		case ECustomAttrType_CurSP:
//			{
//				BSLib::s32 maxValue  = attr_list->getOtherAttribute(EOtherAttrType_SPMax);
//				value = GetRangeValue(value, arg1, 0, maxValue);
//			}
//			break;
//		case ECustomAttrType_CurBT:
//			{
//				value = GetRangeValue(value, arg1, 0, 10000);
//			}
//			break;
//		case ECustomAttrType_FloatAtk:
//			{
//				value = GetRangeValue(value, arg1, 0, 200);
//			}
//			break;
//		case ECustomAttrType_Broke:
//			{
//				value = GetRangeValue(value, arg1, 0, 0x7fffffff);
//			}
//			break;
//		default:
//			LOG_PROCESS_ERROR(false);
//		}
//
//		return attr_list->setCustomAttribute(attrType, value);
//Exit0:
		return false;
	}
	//
	bool RegisterEvtAddDebuf(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		if (arg1 > 0)
//		{
//			return pTarget->getFighterImp()->regEvt(seAddDebuf, arg1);
//		}else
//		{
//			return pTarget->getFighterImp()->unRegEvt(seAddDebuf, -arg1);
//		}
//Exit0:
		return false;
	}
	bool RegisterEvtBulletHurt(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		if (arg1 > 0)
//		{
//			return pTarget->getFighterImp()->regEvt(seHurtBeforeDamage, arg1);
//		}else
//		{
//			return pTarget->getFighterImp()->unRegEvt(seHurtBeforeDamage, -arg1);
//		}
//Exit0:
		return false;
	}
	bool RegisterEvtChara(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		if (arg1 > 0)
//		{
//			return pTarget->getFighterImp()->regEvt(seCastingStart, arg1);
//		}else
//		{
//			return pTarget->getFighterImp()->unRegEvt(seCastingStart, -arg1);
//		}
//Exit0:
		return false;
	}
	bool RegisterEvtBulletExploded(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		if (arg1 > 0)
//		{
//			return pTarget->getFighterImp()->regEvt(seAfterExploded, arg1);
//		}else
//		{
//			return pTarget->getFighterImp()->unRegEvt(seAfterExploded, -arg1);
//		}
//Exit0:
		return false;
	}
	bool RegisterEvtBulletBeHit(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		if (arg1 > 0)
//		{
//			return pTarget->getFighterImp()->regEvt(seBeHit, arg1);
//		}else
//		{
//			return pTarget->getFighterImp()->unRegEvt(seBeHit, -arg1);
//		}
//Exit0:
		return false;
	}
	bool RegisterEvtBulletBeHurt(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		if (arg1 > 0)
//		{
//			return pTarget->getFighterImp()->regEvt(seBeHurtAfterDamage, arg1);
//		}else
//		{
//			return pTarget->getFighterImp()->unRegEvt(seBeHurtAfterDamage, -arg1);
//		}
//Exit0:
		return false;
	}
	bool SetAuraLastTime(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		CPrdEftList *pPrdEftList = (arg1 == 0) ? pTarget->getFighterImp()->getGoodPeList() : pTarget->getFighterImp()->getBadPeList();
//		LOG_PROCESS_ERROR(pPrdEftList);

//		pPrdEftList->resetRemainTime(arg2);
//Exit0:
		return false;
	}
	bool AddAuraLastTime(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		CPrdEftList *pPrdEftList = (arg1 == 0) ? pTarget->getFighterImp()->getGoodPeList() : pTarget->getFighterImp()->getBadPeList();
//		LOG_PROCESS_ERROR(pPrdEftList);
//
//		pPrdEftList->addRemainTime(arg2);
//Exit0:
		return false;
	}

	bool SelfSpurt(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool ChangeFlag(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		if (arg2 == 1)
//		{
//			pTarget->getFighterImp()->setFlag(abs(arg1));
//		}else
//		{
//			pTarget->getFighterImp()->resetFlag(abs(arg1));
//		}
//		return true;
//Exit0:
		return false;
	}
	bool ChangeSpeFlag(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		switch(abs(arg1))
//		{
//		case 0://nohit
//		case 1://freeze
//		case 2://nomove
//		case 3://stun
//			{
//				if (arg2 == 1)
//				{
//					pTarget->getFighterImp()->setSpeFlag(abs(arg1));
//				}else
//				{
//					pTarget->getFighterImp()->resetSpeFlag(abs(arg1));
//				}
//			}
//		default:
//			return false;
//		}
//		
//		return true;
//Exit0:
		return false;
	}
	bool ChangeEmblem(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		pTarget->getFighterImp()->enableEmblem((arg1 == 1), 0);
//		return true;
//Exit0:
		return false;
	}
	bool ChangeEotPower(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		bool bRet = true;
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		BSLib::s32 attrType = arg1;
//		CPrdEftList *pPrdEftList = NULL;
//		if (attrType == 0)
//		{
//			pPrdEftList = pTarget->getFighterImp()->getGoodPeList();
//		}else
//		{
//			pPrdEftList = pTarget->getFighterImp()->getBadPeList();
//		}
//
//		BSLib::s32 atkPower = 0;
//		BSLib::s32 percent = arg2;
//		pPrdEftList->begin();
//		CPeriodEffect *pPE = pPrdEftList->next();
//		while(pPE)
//		{
//			if(pPE->getType() == peftEot)
//			{
//				CEot* pEot = (CEot*)pPE;
//				LOG_PROCESS_ERROR(pEot);
//
//				pEot->modifyMe();
//				LOG_PROCESS_ERROR(pEot->getInfo());
//				atkPower = pEot->getInfo()->m_data.m_iJumpPower;
//				atkPower = atkPower *((float)percent / SPELL_RATE_MAX);
//				pEot->getInfo()->m_data.m_iJumpPower = atkPower; 
//			}
//			pPE = pPrdEftList->next();
//		}
//
//		return bRet;
//Exit0:
		return false;
	}
	bool ChangeAttributeA(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		bool bRet = true;

		BSLib::s32 attrType = abs(arg1);
		BSLib::s32 outType = 0, outIndex = 0;
		bRet = GetEumAttrTypeAndIndex(attrType, outType, outIndex);
		if (bRet)
		{
			switch(outType)
			{
			case EEnumAttrType_Base:
				bRet = ChangeBaseAttributeA(outIndex, src, dst, key, arg2, arg3, 0);
				break;
			case EEnumAttrType_Extend:
				bRet = ChangeExtendAttributeA(outIndex, src, dst, key, arg2, arg3, 0);
				break;
			case EEnumAttrType_Other:
				bRet = ChangeOtherAttr(outIndex, src, dst, key, arg2, arg3, 0);
				break;
			case EEnumAttrType_Factor:
				bRet = ChangeFactor(outIndex, src, dst, key, arg2, arg3, 0);
				break;
			case EEnumAttrType_Custom:
				bRet = ChangeCustomAttr(outIndex, src, dst, key, arg2, arg3, 0);
				break;
			default:
				bRet = false;
				break;
			}
		}
		return bRet;
	}
	bool ChangeAttributeB(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		bool bRet = true;

		BSLib::s32 attrType = abs(arg1);
		BSLib::s32 outType = 0, outIndex = 0;
		bRet = GetEumAttrTypeAndIndex(attrType, outType, outIndex);
		if (bRet)
		{
			if(attrType >= EAttrEntityType_ExtendAttrMax)
				return false;
			switch(outType)
			{
			case EEnumAttrType_Base:
				bRet = ChangeBaseAttributeB(outIndex, src, dst, key, arg2, arg3, 0);
				break;
			case EEnumAttrType_Extend:
				bRet = ChangeExtendAttributeB(outIndex, src, dst, key, arg2, arg3, 0);
				break;
			default:
				bRet = false;
				break;
			}
		}
		return bRet;
	}
	bool ChangeAttributeC(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		bool bRet = true;

		BSLib::s32 attrType = abs(arg1);
		BSLib::s32 outType = 0, outIndex = 0;
		bRet = GetEumAttrTypeAndIndex(attrType, outType, outIndex);
		if (bRet)
		{
			if(attrType >= EAttrEntityType_ExtendAttrMax)
				return false;
			switch(outType)
			{
			case EEnumAttrType_Base:
				bRet = ChangeBaseAttributeC(outIndex, src, dst, key, arg2, arg3, 0);
				break;
			case EEnumAttrType_Extend:
				bRet = ChangeExtendAttributeC(outIndex, src, dst, key, arg2, arg3, 0);
				break;
			default:
				bRet = false;
				break;
			}
		}
		return bRet;
	}
	bool ChangeAttributeD(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		bool bRet = true;

		BSLib::s32 attrType = abs(arg1);
		BSLib::s32 outType = 0, outIndex = 0;
		bRet = GetEumAttrTypeAndIndex(attrType, outType, outIndex);
		if (bRet)
		{
			if(attrType >= EAttrEntityType_ExtendAttrMax || attrType < EAttrEntityType_BaseAttrMax)
				return false;
			bRet = ChangeExtendAttributeD(outIndex, src, dst, key, arg2, arg3, 0);
		}
		return bRet;
	}
	bool ChangeAttributeE(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		bool bRet = true;

		BSLib::s32 attrType = abs(arg1);
		BSLib::s32 outType = 0, outIndex = 0;
		bRet = GetEumAttrTypeAndIndex(attrType, outType, outIndex);
		if (bRet)
		{
			if(attrType >= EAttrEntityType_ExtendAttrMax || attrType < EAttrEntityType_BaseAttrMax)
				return false;
			bRet = ChangeExtendAttributeE(outIndex, src, dst, key, arg2, arg3, 0);
		}
		return bRet;
	}
	bool SetSpeAuraLastTime(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		bool bRet = true;
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		CPrdEftList *pPrdEftList = pTarget->getFighterImp()->getGoodPeList();
//		LOG_PROCESS_ERROR(pPrdEftList);
//		pPrdEftList->resetRemainTime(arg2, arg1);
//
//		CPrdEftList *pPrdEftList = pTarget->getFighterImp()->getBadPeList();
//		LOG_PROCESS_ERROR(pPrdEftList);
//		pPrdEftList->resetRemainTime(arg2, arg1);
//
//		return bRet;
//Exit0:
		return false;
	}
	bool ChangeSpeEmblem(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		pTarget->getFighterImp()->enableEmblem((arg1 == 1), abs(arg2));
//		return true;
//Exit0:
		return false;
	}
	bool AddAttributePercent(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		bool bRet = true;
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		BSLib::s32 newValue = 0, maxValue = 0, oldValue = 0, delValue = 0;
//		switch(arg1)
//		{
//		case 0://HP
//			{
//				oldValue = pTarget->getFighterImp()->getAttrList()->getCustomAttribute(ECustomAttrType_CurHP);
//				maxValue = pTarget->getFighterImp()->getAttrList()->getExtendAttribute(EExAttrType_HpMax);
//				delValue = maxValue *(arg2 / SPELL_RATE_MAX);
//				newValue = GetRangeValue(oldValue, delValue, 0, maxValue);
//
//				if (newValue > oldValue)
//				{
//					pTarget->getFighterImp()->getAttrList()->addHP(newValue-oldValue);
//				}else
//				{
//					pTarget->getFighterImp()->getAttrList()->useHP(oldValue - newValue);
//				}
//			}
//			break;
//		case 1://HP
//			{
//				oldValue = pTarget->getFighterImp()->getAttrList()->getCustomAttribute(ECustomAttrType_CurMP);
//				maxValue = pTarget->getFighterImp()->getAttrList()->getExtendAttribute(EExAttrType_MpMax);
//				delValue = maxValue *(arg2 / SPELL_RATE_MAX);
//				newValue = GetRangeValue(oldValue, delValue, 0, maxValue);
//
//				if (newValue > oldValue)
//				{
//					pTarget->getFighterImp()->getAttrList()->addMP(newValue-oldValue);
//				}else
//				{
//					pTarget->getFighterImp()->getAttrList()->useMP(oldValue - newValue);
//				}
//			}
//			break;
//		default:
//			bRet = false;
//			break;
//		}
//
//		return bRet;
//Exit0:
		return false;
	}
	bool AddAuraToChar(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		bool bRet = true;
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		bRet = pTarget->getFighterImp()->addPeriodEffect(arg1, arg2);
//
//		return bRet;
//Exit0:
		return false;
	}
	bool AddEotToChar(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		bool bRet = true;
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		bRet = pTarget->getFighterImp()->addPeriodEffect(arg1, arg2);
//
//		return bRet;
//Exit0:
		return false;
	}
	bool CharacterIfAction(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		bool bRet = true;
//		CCharacterEntity *pTarget = (CCharacterEntity *)dst;
//		LOG_PROCESS_ERROR(pTarget);
//
//		IFighter *pFighter = pTarget->getFighterImp();
//		LOG_PROCESS_ERROR(pFighter);
//
//		bRet = GlobalCheckers::getInstance()->checkSeq(arg1, EATTR_MODIFY_TYPE_CHAR, pFighter);
//		LOG_PROCESS_ERROR(bRet);
//
//		bRet = GlobalModifiers::getInstance()->applySeq(arg2, src,  EATTR_MODIFY_TYPE_CHAR, pTarget);
//		LOG_PROCESS_ERROR(bRet);
//
//		return bRet;
//Exit0:
		return false;
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