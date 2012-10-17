#include "ModifierBullet.h"
#include "ModifierFunc.h"

namespace SKILLEDITOR
{
	bool MFBullet_AtkPlusByAttribute(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet *)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		BSLib::s32 atkPowerToAdd = 0;
//		CFighterImp *pFighter = src=>getFighterImp();
//		switch(arg1)
//		{
//		case 1:
//			{
//				atkPowerToAdd = pFighter->getAttrList()->getExtendAttribute(EExAttrType_PhyAtk);
//				break;
//			}
//		case 2:
//			{
//				atkPowerToAdd = pFighter->getAttrList()->getExtendAttribute(EExAttrType_MagAtk);
//				break;
//			}
//		case 3:
//			{
//				BSLib::s32 phyAtk = pFighter->getAttrList()->getExtendAttribute(EExAttrType_PhyAtk);
//				BSLib::s32 magAtk = pFighter->getAttrList()->getExtendAttribute(EExAttrType_MagAtk);
//				atkPowerToAdd = phyAtk >= magAtk ? phyAtk : magAtk;
//				break;
//			}
//		default:
//			LOG_PROCESS_ERROR(false);
//			break;
//
//		}
//
//		BSLib::s32 tempValue = pBullet->getTempValue(arg3);
//		atkPowerToAdd = atkPowerToAdd * (arg2 + tempValue) / SPELL_RATE_MAX;
//		pBullet->setAttackPower(pBullet->getAttackPower() + atkPowerToAdd);
//		return true;
//Exit0:
		return false;
	}
	bool MFBullet_AtbPlusBySkill(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		BSLib::s32 tempValue = pBullet->getTempValue(arg3);
//		pBullet->setAttackPower(pBullet->getAttackPower() + arg1 + tempValue);
//		return true;
//Exit0:
		return false;
	}
	bool MFBullet_PlusAura(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		AuraTemplate *pAuraTemplate = CAuraConfig::getInstance()->findTemplate(arg1, arg2);
//		LOG_PROCESS_ERROR(pAuraTemplate);
//
//		CAura *pAura = createAuraInstance(pAuraTemplate, src);
//		LOG_PROCESS_ERROR(pAura);
//
//		return pBullet->getTarget()->getFighterImp()->addPeriodEffect(src, pAura);
//Exit0:
		return false;
	}
	bool MFBullet_PlusEot(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		EotTemplate *pEotTemplate = CEotConfig::getInstance()->findTemplate(arg1, arg2);
//		LOG_PROCESS_ERROR(pEotTemplate);
//
//		CEot *pEot = createAuraInstance(pEotTemplate, src);
//		LOG_PROCESS_ERROR(pEot);
//
//		return pBullet->getTarget()->getFighterImp()->addPeriodEffect(src, pEot);
//Exit0:
		return false;
	}
	bool MFBullet_EotPlus(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		return true;
	}
	bool MFBullet_AtkSpecialMod(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		if (!GlobalCheckers::getInstance()->checkSeq(arg1, EATTR_MODIFY_TYPE_BULLET, dst))
//		{
//			return false;
//		}
//
//		BSLib::s32 tempValue = pBullet->getTempValue(arg3);
//
//		pBullet->setAttackPower(pBullet->getAttackPower()*(SPELL_RATE_MAX + arg2 + tempValue) / SPELL_RATE_MAX);
//		return true;
//Exit0:
		return false;
	}
	bool MFBullet_CriSpecialMod(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		/*CBullet *pBullet = (CBullet*)dst;
		LOG_PROCESS_ERROR(pBullet);

		if (!GlobalCheckers::getInstance()->checkSeq(arg1, EATTR_MODIFY_TYPE_BULLET, dst))
		{
			return false;
		}

		if (NULL == pBullet->getSrcAttrList())
		{
			return false;
		}
		BSLib::s32 tempValue = pBullet->getTempValue(arg3);

		BSLib::s32 criRate = pBullet->getSrcAttrList()->getOtherAttribute(EOtherAttrType_CriticalRate);

		pBullet->getSrcAttrList()->setOtherAttribute(EOtherAttrType_CriticalRate, criRate + arg2 + tempValue);
		return true;
Exit0:*/
		return false;
	}
	bool MFBullet_ApplyTargetSeq(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		if (!GlobalCheckers::getInstance()->checkSeq(arg1, EATTR_MODIFY_TYPE_BULLET, dst))
//		{
//			return false;
//		}
//
//		return CGlobalModifiers::getInstance()->applySeq(arg2, src, EATTR_MODIFY_TYPE_CHAR, pBullet->getTarget());
//Exit0:
		return false;
	}
	bool MFBullet_ApplySrcSeq(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		if (!GlobalCheckers::getInstance()->checkSeq(arg1, EATTR_MODIFY_TYPE_BULLET, dst))
//		{
//			return false;
//		}
//
//		return CGlobalModifiers::getInstance()->applySeq(arg2, src, EATTR_MODIFY_TYPE_CHAR, pBullet->getSource());
//Exit0:
		return false;
	}
	bool MFBullet_HalveHP(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		CCharacterEntity *pDst = pBullet->getTarget();
//		LOG_PROCESS_ERROR(src && pDst);
//
//		BSLib::s32 hpAvg = (src->getFighterImp()->getCurrentHP() + pDst->getFighterImp()->getCurrentHP()) / 2;
//
//		src->getFighterImp()->setCurrentHP(hpAvg);
//		pDst->getFighterImp()->setCurrentHP(hpAvg);
//
//		return true;
//Exit0:
		return false;
	}
	bool MFBullet_CloneEura(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		CCharacterEntity *pBulletDst = pBullet->getTarget();
//		LOG_PROCESS_ERROR(src && pBulletDst);
//
//		CCharacterEntity *pSrc = (arg1 == 0 ? src : pBulletDst);
//		CCharacterEntity *pDst = (arg1 == 0 ? pBulletDst : src);
//
//		CPrcEftList *pEftList = (arg2 == 0 ? pSrc->getFighterImp()->getGoodPeList() : pSrc->getFighterImp()->getBadPeList());
//		LOG_PROCESS_ERROR(pEftList);
//
//		CPeriodEffect *pEft = NULL;
//		pEftList->begin();
//
//		while((pEft = pEftList->next()) != NULL)
//		{
//			CPeriodEffect *pCloneEft = pEft->clone();
//			LOG_PROCESS_ERROR(pCloneEft);
//
//			pDst->getFighterImp()->addPeriodEffect(pSrc, pCloneEft);
//		}
//
//		return true;
//Exit0:
		return false;
	}
	bool MFBullet_ReflectDamage(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		CCharacterEntity *pSrc = pBullet->getSource();
//		LOG_PROCESS_ERROR(pSrc);
//
//		BSLib::s32 tempValue = pBullet->getTempValue(arg3);
//
//		pSrc->getFighterImp()->setCurrentHP(pSrc->getFighterImp()->getCurrentHP() - (BSLib::s32)(pBullet->getDamage()*(arg1 + tempValue) / SPELL_RATE_MAX));
//		return true;
//Exit0:
		return false;
	}
	bool MFBullet_VamDamage(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		CCharacterEntity *pSrc = pBullet->getSource();
//		LOG_PROCESS_ERROR(pSrc);
//
//		BSLib::s32 tempValue = pBullet->getTempValue(arg3);
//
//		pSrc->getFighterImp()->setCurrentHP(pSrc->getFighterImp()->getCurrentHP() + (BSLib::s32)(pBullet->getDamage()*(arg1 + tempValue) / SPELL_RATE_MAX));
//		return true;
//Exit0:
		return false;
	}
	bool MFBullet_FarOff(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
		//CBullet *pBullet = (CBullet*)dst;
		//LOG_PROCESS_ERROR(pBullet);

//		CCharacterEntity *pBulletDst = pBullet->getTarget();
//		LOG_PROCESS_ERROR(src && pBulletDst);
//
//		CCharacterEntity *pSrc = (arg1 > 0 ? src : pBulletDst);
//		CCharacterEntity *pDst = (arg1 > 0 ? pBulletDst : src);
//		LOG_PROCESS_ERROR(pSrc && pDst && pSrc != pDst);
//
//		BSLib::f32 dist = (pSrc->getPosition()- pDst->getPosition()).length();
//		dist = (dist <= abs(arg1) ? dist : abs(arg1));
//		
//		BSLib::Math::CVector3 vMoveDir = pSrc->getPosition()- pDst->getPosition();
//		BSLib::Math::Normalize(vMoveDir);
//
//		BSLib::Math::CVector3 vPosFm = pDst->getPosition();
//		BSLib::Math::CVector3 vPosTo = vPosFm + vMoveDir * dist;
//
//		LOG_PROCESS_ERROR(pDst->getScene() && pDst->getScene()->isLoaded());
//
//		float fTerrHeight = pDst->getScene()->getTerrainHeight(vPosTo);
//		if (vPosTo.z < fTerrHeight)
//		{
//			vPosTo.z = fTerrHeight;
//		}
//
//		pDst->teleportPosition(vPosTo);
//		return true;
//Exit0:
		return false;
	}
	bool MFBullet_BulletIfAction(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		if (!GlobalCheckers::getInstance()->checkSeq(arg1, EATTR_MODIFY_TYPE_BULLET, dst))
//		{
//			return false;
//		}
//
//		return CGlobalModifiers::getInstance()->applySeq(arg2, src, EATTR_MODIFY_TYPE_BULLET, pBullet->getSource());
//Exit0:
		return false;
	}
	bool MFBullet_ApplyHPChange(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		CCharacterEntity *pSrc = pBullet->getSource();
//		CCharacterEntity *pDst = pBullet->getTarget();
//		LOG_PROCESS_ERROR(pSrc && pDst);
//
//		pSrc->getFighterImp()->fireEvt(pSrc, seHurtBeforeDamage, EATTR_MODIFY_TYPE_BULLET, pBullet);
//
//		CAttrList *pSrcAttrList = pBullet->getSrcAttrList();
//		CAttrList *pDstAttrList = pBullet->getDstAttrList();
//		LOG_PROCESS_ERROR(pSrcAttrList && pDstAttrList);
//
//		bool bIsPVP = false;
//
//		CSkillTemplate *pSkillTemplate = pBullet->getSkillTemplate();
//		LOG_PROCESS_ERROR(pSkillTemplate);
//
//		BSLib::f64 llSrcBroke = pSrcAttrList->getCustomAttribute(ECustomAttrType_Broke);
//		llSrcBroke += pSkillTemplate->getVar(pBullet->getHitIndex(), pBullet->getSkillBaseIndex());
//
//		BSLib::f64 atkPower = pBullet->getAtkPower();
//		BSLib::f64 srcCriRate = pSrcAttrList->getOtherAttribute(EOtherAttrType_CriticalRate);
//		BSLib::f64 srcCri = pSrcAttrList->getOtherAttribute(EOtherAttrType_CriticalValue);
//
//		BSLib::f64 desCriRes = pDstAttrList->getOtherAttribute(EOtherAttrType_AntiCriticalValue);
//		BSLib::f64 desCriResRate = pDstAttrList->getOtherAttribute(EOtherAttrType_AntiCriticalRate);
//
//		BSLib::f64 srcCriFactor = pSrcAttrList->getFactorAttribute(EFactorType_Critical);
//		BSLib::f64 brokeFactor = pSrcAttrList->getFactorAttribute(EFactorType_Broke);
//
//		BSLib::s32 desBT = pDstAttrList->getCustomAttribute(ECustomAttrType_CurBT);
//
//		CLevelParam * pSrcLP = (CLevelParam *)(CLevelParamCfg::getInstance().getLevelParam(pSrc->getEntityLevel()));
//		CLevelParam * pDstLP = (CLevelParam *)(CLevelParamCfg::getInstance().getLevelParam(pDst->getEntityLevel()));
//		LOG_PROCESS_ERROR(pSrcLP && pDstLP);
//
//		bool bPhyAttack = pSkillTemplate->getVar(siiBaseType, NULL) & sitPhy;
//		BSLib::s32 srcAttackPierce = bPhyAttack ? pSrcAttrList->getOtherAttribute(EOtherAttrType_PhyPierce) : pSrcAttrList->getOtherAttribute(EOtherAttrType_MagPierce);
//		BSLib::s32 desAttackDef = bPhyAttack ? pDstAttrList->getExtendAttribute(EExAttrType_PhyDef) : pDstAttrList->getExtendAttribute(EExAttrType_MagDef);
//
//		BSLib::f64 srcLevP1 = pSrcLP->p[0];
//		BSLib::f64 srcLevP2 = pSrcLP->p[1];
//		BSLib::f64 srcDamT1 = CDamanageParamCfg::getInstance().m_nDamageParam[0];
//		BSLib::f64 srcDamT2 = CDamanageParamCfg::getInstance().m_nDamageParam[1];
//
//		BSLib::f64 desLevP1 = pDstLP->p[0];
//		BSLib::f64 desLevP2 = pDstLP->p[1];
//		BSLib::f64 desDamT1 = CDamanageParamCfg::getInstance().m_nDamageParam[2];
//
//		BSLib::f64 srcCriRateTotal = 0, desCriResRateTotal = 0, criRateTotal = 0;
//
//		if (bIsPVP)
//		{
//			srcCriRateTotal = srcCri / (srcLevP1*srcDamT2/SPELL_RATE_MAX) + srcCriRate/SPELL_RATE_MAX;
//			desCriResRateTotal = desCriRes / (desLevP1*desDamT1/SPELL_RATE_MAX) + desCriResRate / SPELL_RATE_MAX;
//			criRateTotal = srcCriRateTotal - desCriResRateTotal;
//		}else
//		{
//			srcCriRateTotal = srcCri / (desLevP1*srcDamT2/SPELL_RATE_MAX) + srcCriRate/SPELL_RATE_MAX;
//			desCriResRateTotal = desCriRes / (srcLevP1*desDamT1/SPELL_RATE_MAX) + desCriResRate / SPELL_RATE_MAX;
//			criRateTotal = srcCriRateTotal - desCriResRateTotal;
//		}
//
//		//暴击加成
//		if (rand(0, SPELL_RATE_MAX) < criRateTotal * SPELL_RATE_MAX)
//		{
//			pBullet->setCritical(true);
//			atkPower = atkPower *(1.5f + (srcCriFactor/SPELL_RATE_MAX));
//		}
//		//破招加成
//		if (llSrcBroke > desBT && pDst->isAttack())
//		{
//			atkPower = atkPower *(1.25f + (brokeFactor/SPELL_RATE_MAX));
//		}
//
//		//减伤比
//		BSLib::f64 numerator = 0, decDamageRate = 0;
//		if (bIsPVP)
//		{
//			numerator = desAttackDef * srcLevP2 - srcAttackPierce * desLevP2;
//			decDamageRate = numerator / (abs(numerator) + srcLevP2*desLevP2*srcDamT1 / SPELL_RATE_MAX);
//		}else
//		{
//			numerator = desAttackDef - srcAttackPierce;
//			decDamageRate = numerator / (abs(numerator) + srcLevP2*srcDamT1 / SPELL_RATE_MAX);
//		}
//
//		//最终伤害
//		BSLib::s32 itemDmg = pSrcAttrList->getCustomAttribute(ECustomAttrType_FloatAtk);
//		BSLib::f64 itemDmgPct = rand(200 - itemDmg, 200 + itemDmg) / 200;
//		BSLib::s32 dmg = atkPower *(1.0f - decDamageRate) * itemDmgPct;
//		dmg = dmg > 0 ? dmg : 1;
//		pBullet->setDamage(dmg);
//		
//		pDst->getFighterImp()->fireEvt(pDst, seHurtAfterDamage, EATTR_MODIFY_TYPE_BULLET, pBullet);
//
//		dmg = pBullet->getDamage();
//		BSLib::f64 curHPPct = pDstAttrList->getCustomAttribute(ECustomAttrType_CurHP) * 100.f / pDstAttrList->getExtendAttribute(EExAttrType_HpMax);
//		if (curHPPct <= 25)
//		{
//			BSLib::f64 endangeredPct = dmg * 100.f / pDstAttrList->getExtendAttribute(EExAttrType_HpMax);
//			pDst->getFighterImp()->getEntityAttribute()->addSP(endangeredPct * 2.f);
//		}else
//		{
//			BSLib::f64 endangeredPct = dmg * 100.f / pDstAttrList->getExtendAttribute(EExAttrType_HpMax);
//			pDst->getFighterImp()->getEntityAttribute()->addSP(endangeredPct);
//		}
//
//		BSLib::s32 iPart = pBullet->getHitPart();
//		if (iPart >= 1 && iPart <= npcPartEnd && !pDst->getFighterImp()->getEntityAttribute()->m_bPlayableChara)
//		{
//			NPCPartsData *pPartData = (NPCPartsData *)(pDst->getFighterImp()->getEntityAttribute()->m_oNpcAttribute.m_pNPCPartsData[iPart]);
//			if (pPartData)
//			{
//				BSLib::s32 hurtRateRatePlus = pSkillTemplate->getVar() & bPhyAttack ? 
//					pPartData->baseData[phyhurtrate] : pPartData->baseData[maghurtrate];
//				dmg *= (1.f + hurtRateRatePlus / SPELL_RATE_MAX);
//			}
//		}
//
//		pDst->getFighterImp()->getEntityAttribute()->addHP(-dmg);
//		pSrc->addDamageTotal(dmg);
//		if (iPart != 0)
//		{
//			pDst->getFighterImp()->getEntityAttribute()->addHP(-dmg, iPart);
//		}
//
//		if (!bIsPVP && pSrc->getFighterImp()->getEntityAttribute()->m_bPlayableChara && pDst->isBig())
//		{
//			pSrc->getFighterImp()->getEntityAttribute()->m_oPcAttribute.m_damageOutPVE += dmg;
//			BSLib::u16 sceneTypeID = pSrc->getSceneID();
//			const CEctypeTableItem *pEcType = CEctypeTable::singleton().find(sceneTypeID, 1);
//			if (pEcType)
//			{
//				BSLib::s32 emblemBonus = pEcType->m_difficulyInfo.m_emblemBonus;
//				BSLib::s32 hpMax = pSrcAttrList->getExtendAttribute(EExAttrType_HpMax);
//				if (pSrc->getFighterImp()->getEntityAttribute()->m_oPcAttribute.m_damageOutPVE / hpMax >= emblemBonus/SPELL_RATE_MAX)
//				{
//					pSrc->getFighterImp()->enableEmblem(true, 0);
//					pSrc->getFighterImp()->getEntityAttribute()->m_oPcAttribute.m_damageOutPVE = 0;
//				}
//			}
//		}
//		return true;
//Exit0:
		return false;
	}
	bool MFBullet_IniBulletVar(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		return pBullet->regTempValue(arg1, arg2, arg3);
//Exit0:
		return false;
	}
	bool MFBullet_MulBulletVar(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		BSLib::s32 nV1 = pBullet->getTempValue(arg1);
//		BSLib::s32 nV2 = arg2;
//		BSLib::s32 nV3 = pBullet->getTempValue(arg3);
//
//		return pBullet->setTempValue(arg1, nV1 *((float)(nV2 + nV3) / SPELL_RATE_MAX));
//Exit0:
		return false;
	}
	bool MFBullet_AddBulletVar(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		BSLib::s32 nV1 = pBullet->getTempValue(arg1);
//		BSLib::s32 nV2 = arg2;
//		BSLib::s32 nV3 = pBullet->getTempValue(arg3);
//
//		return pBullet->setTempValue(arg1, nV1 + nV2 + nV3);
//Exit0:
		return false;
	}
	bool MFBullet_EndBullet(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		return pBullet->setIsInvalid(true);
//Exit0:
		return false;;
	}
	bool MFBullet_ReflectBullet(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		CCharacterEntity* pDest = pBullet->getTarget();
//		LOG_PROCESS_ERROR(pDest);
//		pBullet->setSource(pDest);
//
//		return true;
//Exit0:
		return false;
	}
	bool MFBullet_ChangeTarAByV(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		CCharacterEntity* pDest = pBullet->getTarget();
//		LOG_PROCESS_ERROR(pDest);
//		BSLib::s32 nV3 = pBullet->getTempValue(arg2);
//
//		TAttrModifierFunc func = GetModifierFunc(EATTR_MODIFY_TYPE_CHAR, EAMKCHAR_ChangeAttributeA);
//		LOG_PROCESS_ERROR(func);
//
//		return func(src, pDest, 0, arg1, nV3, 0)
//
//		return true;
//Exit0:
		return false;
	}
	bool MFBullet_ChangeSrcAByV(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		CCharacterEntity* pDest = pBullet->getTarget();
//		LOG_PROCESS_ERROR(pDest);
//		BSLib::s32 nV3 = pBullet->getTempValue(arg2);
//
//		TAttrModifierFunc func = GetModifierFunc(EATTR_MODIFY_TYPE_CHAR, EAMKCHAR_ChangeAttributeA);
//		LOG_PROCESS_ERROR(func);
//
//		return func(src, pDest, 0, arg1, nV3, 0);
//Exit0:
		return false;
	}
	bool MFBullet_DamageSpecialMod(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3)
	{
//		bool bRet = true;
//		CBullet *pBullet = (CBullet*)dst;
//		LOG_PROCESS_ERROR(pBullet);
//
//		bRet = CGlobalCheckers::getInstance().checkSeq(arg1, EATTR_MODIFY_TYPE_BULLET, pBullet);
//		LOG_PROCESS_ERROR(bRet);
//
//		BSLib::s32 bulletDamage = pBullet->getDamage();
//		BSLib::s32 nV3 = pBullet->getTempValue(arg3);
//		bulletDamage = bulletDamage *(SPELL_RATE_MAX + arg2 + nV3) / SPELL_RATE_MAX;
//		pBullet->setDamage(bulletDamage);
//
//		return bRet
//Exit0:
		return false;
	}
	TAttrModifierFunc AttrBulletModifierFunc[EAMKBullet_Count] = 
	{
		NULL,
		MFBullet_AtkPlusByAttribute,
		MFBullet_AtbPlusBySkill,
		MFBullet_PlusAura,
		MFBullet_PlusEot,
		MFBullet_EotPlus,
		MFBullet_AtkSpecialMod,
		MFBullet_CriSpecialMod,
		MFBullet_ApplyTargetSeq,
		MFBullet_ApplySrcSeq,
		MFBullet_HalveHP,
		MFBullet_CloneEura,
		MFBullet_ReflectDamage,
		MFBullet_VamDamage,
		MFBullet_FarOff,
		MFBullet_BulletIfAction,
		MFBullet_ApplyHPChange,
		MFBullet_IniBulletVar,
		MFBullet_MulBulletVar,
		MFBullet_AddBulletVar,
		MFBullet_EndBullet,
		MFBullet_ReflectBullet,
		MFBullet_ChangeTarAByV,
		MFBullet_ChangeSrcAByV,
		MFBullet_DamageSpecialMod,
	};
}