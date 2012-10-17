#include "EntityFunc.h"
#include "attrFunc.h"
#include "CCharacterEntity.h"
namespace SKILLEDITOR
{

	inline BSLib::s32 getCurrentHPPercent(void *target, BSLib::s32 arg)
	{
		//CAttrList *list = ((IFighter*)target)->getAttrList();
		BSLib::s32 retValue = 0;
		//retValue =  ((IFighter*)target)->getFtAttribute()->getHP()*SPELL_RATE_MAX / list->getExtendAttribute(atHpMax);
		return retValue;
	}

	inline BSLib::s32 getCurrentMPPercent(void *target, BSLib::s32 arg)
	{
		//CAttrList *list = ((IFighter*)target)->getAttrList();
		BSLib::s32 retValue = 0;
		//retValue =  ((IFighter*)target)->getFtAttribute()->getMP()*SPELL_RATE_MAX / list->getExtendAttribute(atMpMax);
		return retValue;
	}

	inline BSLib::s32 getMoveSpeed(void *target, BSLib::s32 arg)
	{
		//IFighter* obj = ((IFighter*)target);
		BSLib::s32 retValue = 0;
		//retValue = obj->getAttrList()->getExtendAttribute(atMoveSpeed);
		return retValue;
	}
	BSLib::s32 GetDebuffNo(void* target, BSLib::s32 arg)
	{
//		IFighter *pFighter = (IFighter *)target;
//		LOG_PROCESS_ERROR(pFighter);
//
//		return pFighter->getEffectCount(false);
//Exit0:
		return 0;
	}

	BSLib::s32 GetFlag(void* target, BSLib::s32 arg)
	{
//		IFighter *pFighter = (IFighter *)target;
//		LOG_PROCESS_ERROR(pFighter);
//
//		return pFighter->getFlag(arg) ? 1 : 0;
//Exit0:
		return 0;
	}

	BSLib::s32 GetMoveCondition(void* target, BSLib::s32 arg)
	{
//		IFighter *pFighter = (IFighter *)target;
//		LOG_PROCESS_ERROR(pFighter);
//
//		return pFighter->getMoveCondition();
//Exit0:
		return 0;
	}

	BSLib::s32 GetAttrPercent(void* target, BSLib::s32 arg)
	{
//		IFighter *pFighter = (IFighter *)target;
//		LOG_PROCESS_ERROR(pFighter);
//
//		switch (arg)
//		{
//		case eapt_hppercent:
//			return getCurrentHPPercent(target, arg);
//		case eapt_mppercent:
//			return getCurrentMPPercent(target, arg);
//		default:
//			break;
//		}
//Exit0:
		return 0;
	}

	BSLib::s32 GetBuffNo(void* target, BSLib::s32 arg)
	{
//		IFighter *pFighter = (IFighter *)target;
//		LOG_PROCESS_ERROR(pFighter);
//
//		return pFighter->getEffectCount(true);
//Exit0:
		return 0;
	}

	BSLib::s32 GetAttributeA(void* target, BSLib::s32 arg)
	{
		/*CAttrList *attrList = ((IFighter*)target)->getAttrList();
		BSLib::s32 nOutIndex = 0, nOutType = 0;

		bool bRet = getEnumAttrTypeAndIndex(arg, nOutType, nOutIndex);
		if (bRet)
		{
			switch(nOutType)
			{
			case eatype_base:
				return attrList->getBaseAttributeA(nOutIndex);
			case eatype_extend:
				return attrList->getExtendAttributeA(nOutIndex);
			case eatype_other:
				return attrList->getOtherAttribute(nOutIndex);
			case eatype_factor:
				return attrList->getFactor(nOutIndex);
			case eatype_custom:
				return attrList->getCustomAttribute(nOutIndex);
			default:
				break;
			}
		}*/
		return 0;
	}
	BSLib::s32 GetAttributeB(void* target, BSLib::s32 arg)
	{
		/*CAttrList *attrList = ((IFighter*)target)->getAttrList();
		BSLib::s32 nOutIndex = 0, nOutType = 0;

		bool bRet = getEnumAttrTypeAndIndex(arg, nOutType, nOutIndex);
		if (bRet)
		{
			switch(nOutType)
			{
			case eatype_base:
				return attrList->getBaseAttributeB(nOutIndex);
			case eatype_extend:
				return attrList->getExtendAttributeB(nOutIndex);
			default:
				break;
			}
		}*/
		return 0;
	}
	BSLib::s32 GetAttributeC(void* target, BSLib::s32 arg)
	{
		/*CAttrList *attrList = ((IFighter*)target)->getAttrList();
		BSLib::s32 nOutIndex = 0, nOutType = 0;

		bool bRet = getEnumAttrTypeAndIndex(arg, nOutType, nOutIndex);
		if (bRet)
		{
			switch(nOutType)
			{
			case eatype_base:
				return attrList->getBaseAttributeC(nOutIndex);
			case eatype_extend:
				return attrList->getExtendAttributeC(nOutIndex);
			default:
				break;
			}
		}*/
		return 0;
	}
	BSLib::s32 GetAttributeD(void* target, BSLib::s32 arg)
	{
		/*CAttrList *attrList = ((IFighter*)target)->getAttrList();
		BSLib::s32 nOutIndex = 0, nOutType = 0;

		bool bRet = getEnumAttrTypeAndIndex(arg, nOutType, nOutIndex);
		if (bRet)
		{
			return attrList->getExtendAttributeD(nOutIndex);
		}*/
		return 0;
	}
	BSLib::s32 GetAttributeE(void* target, BSLib::s32 arg)
	{
		/*CAttrList *attrList = ((IFighter*)target)->getAttrList();
		BSLib::s32 nOutIndex = 0, nOutType = 0;

		bool bRet = getEnumAttrTypeAndIndex(arg, nOutType, nOutIndex);
		if (bRet)
		{
			return attrList->getExtendAttributeE(nOutIndex);
		}*/
		return 0;
	}
	BSLib::s32 GetIsAttr(void* target, BSLib::s32 arg)
	{
		//IFighter *pFighter = (IFighter*)target;
		//if (!pFighter)
		//{
		//	return 0;
		//}
		//return pFighter->isAttack() ? 1 : 0;
		return 0;
	}
	TGetAttr GetCharAttrFunc[EGetCharAttrFunc_COUNT] = 
	{
		NULL,
		NULL,
		NULL,
		GetDebuffNo,
		GetFlag,
		GetMoveCondition,
		GetAttrPercent,
		GetBuffNo,
		GetAttributeA,
		GetAttributeB,
		GetAttributeC,
		GetAttributeD,
		GetAttributeE,
		GetIsAttr,
	};
}