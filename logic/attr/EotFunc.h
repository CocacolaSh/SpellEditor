#ifndef __LOGIC_ATTR_EOTFUNC_H__
#define __LOGIC_ATTR_EOTFUNC_H__
#include "basedef.h"
namespace SKILLEDITOR
{
	enum EGetEotAttrFunc
	{
		EGetEotAttrFunc_INVALID = 0,
		EGetEotAttrFunc_GetEotIsGood,				//0X00040001  GetEotIsGood		获取Eot类型,hot/dot
		EGetEotAttrFunc_GetEotAttribute,			//0x00040002  GetEotAttribute	获取EOT伤害属性，属于冰霜火焰中的一种
		EGetEotAttrFunc_GetEotType,				//0x00040003  GetEotType		获取eot状态类别，1=魔法，2=诅咒，3=中毒，4=疾病，5=特殊无法反抗，如果是HOT等正面EOT，1=攻击加强，2=防守加强，3=持续作战加强，4=辅助加强中的一种
		EGetEotAttrFunc_COUNT
	};
}
#endif