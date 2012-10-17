#ifndef __LOGIC_ATTR_BULLETFUNC_H__
#define __LOGIC_ATTR_BULLETFUNC_H__
#include "basedef.h"
namespace SKILLEDITOR
{
	enum EGetBulletAttrFunc
	{
		EGetBulletAttrFunc_INVALID = 0,
		EGetBulletAttrFunc_GetRelation = 2,
		EGetBulletAttrFunc_GetTarDebufNo,
		EGetBulletAttrFunc_GetSrcDebufNo,
		EGetBulletAttrFunc_GetTarFlag,
		EGetBulletAttrFunc_GetSrcFlag,
		EGetBulletAttrFunc_GetTarMoveCondition,
		EGetBulletAttrFunc_GetSrcMoveCondition,
		EGetBulletAttrFunc_GetTarAttrPercent,
		EGetBulletAttrFunc_GetSrcAttrPercent,
		EGetBulletAttrFunc_GetTarBuffNo,
		EGetBulletAttrFunc_GetSrcBuffNo,
		EGetBulletAttrFunc_GetSkillAttribute,
		EGetBulletAttrFunc_GetBulletVar,
		EGetBulletAttrFunc_GetTarAttributeA,
		EGetBulletAttrFunc_GetTarAttributeB,
		EGetBulletAttrFunc_GetTarAttributeC,
		EGetBulletAttrFunc_GetTarAttributeD,
		EGetBulletAttrFunc_GetTarAttributeE,
		EGetBulletAttrFunc_GetSrcAttributeA,
		EGetBulletAttrFunc_GetSrcAttributeB,
		EGetBulletAttrFunc_GetSrcAttributeC,
		EGetBulletAttrFunc_GetSrcAttributeD,
		EGetBulletAttrFunc_GetSrcAttributeE,
		EGetBulletAttrFunc_GetTarIsAtt,
		EGetBulletAttrFunc_GetSrcIsAtt,
		EGetBulletAttrFunc_GetIsCritical,
		EGetBulletAttrFunc_GetDistance,
		EGetBulletAttrFunc_GetTarNPCRank,
		EGetBulletAttrFunc_GetSrcNPCRank,
		EGetBulletAttrFunc_COUNT
	};
}
#endif