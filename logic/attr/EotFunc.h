#ifndef __LOGIC_ATTR_EOTFUNC_H__
#define __LOGIC_ATTR_EOTFUNC_H__
#include "basedef.h"
namespace SKILLEDITOR
{
	enum EGetEotAttrFunc
	{
		EGetEotAttrFunc_INVALID = 0,
		EGetEotAttrFunc_GetEotIsGood,				//0X00040001  GetEotIsGood		��ȡEot����,hot/dot
		EGetEotAttrFunc_GetEotAttribute,			//0x00040002  GetEotAttribute	��ȡEOT�˺����ԣ����ڱ�˪�����е�һ��
		EGetEotAttrFunc_GetEotType,				//0x00040003  GetEotType		��ȡeot״̬���1=ħ����2=���䣬3=�ж���4=������5=�����޷������������HOT������EOT��1=������ǿ��2=���ؼ�ǿ��3=������ս��ǿ��4=������ǿ�е�һ��
		EGetEotAttrFunc_COUNT
	};
}
#endif