#include "attrList.h"

namespace SKILLEDITOR
{
	CAttrList::CAttrList()
	{
		reset();
	}
	CAttrList::~CAttrList()
	{
		;
	}

	bool GetEumAttrTypeAndIndex(BSLib::s32 inIndex, BSLib::s32 &type, BSLib::s32 &index)
	{
		if (inIndex < EAttrEntityType_BaseAttrMax)
		{
			type = EEnumAttrType_Base;
			index = inIndex - EAttrType_BaseAttributeBegin;
			return true;
		}
		else if (inIndex < EAttrEntityType_ExtendAttrMax)
		{
			type = EEnumAttrType_Extend;
			index = inIndex - EAttrEntityType_BaseAttrMax;
			return true;
		}
		else if (inIndex < EAttrEntityType_OtherAttrMax)
		{
			type = EEnumAttrType_Other;
			index = inIndex - EAttrEntityType_ExtendAttrMax;
			return true;
		}
		else if (inIndex < EAttrEntityType_FactorMax)
		{
			type = EEnumAttrType_Factor;
			index = inIndex - EAttrEntityType_OtherAttrMax;
			return true;
		}
		else 
		{
			type = EEnumAttrType_Custom;
			index = inIndex - EAttrEntityType_FactorMax;
			return true;
		}
	}
}