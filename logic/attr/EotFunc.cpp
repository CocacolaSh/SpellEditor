#include "EotFunc.h"
#include "attrFunc.h"
#include "../skill/eot_template.h"
namespace SKILLEDITOR
{
	BSLib::s32 GetEotIsGood(void *target, BSLib::s32 arg)
	{
		EotTemplate *eot = (EotTemplate*)target;
		return eot->m_data.m_isHot;
	}

	BSLib::s32 GetEotAttribute(void *target, BSLib::s32 arg)
	{
		EotTemplate *eot = (EotTemplate*)target;
		return eot->m_data.m_targetAttrID;
	}

	BSLib::s32 GetEotType(void *target, BSLib::s32 arg)
	{
		return 0;
	}
	TGetAttr GetEotAttrFunc[EGetEotAttrFunc_COUNT] = 
	{
		NULL,
		GetEotIsGood,				//0X00040001  GetEotIsGood		获取Eot类型,hot/dot
		GetEotAttribute,			//0x00040002  GetEotAttribute	获取EOT伤害属性，属于冰霜火焰中的一种
		GetEotType,
	};
}