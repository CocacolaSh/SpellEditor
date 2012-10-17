#ifndef __LOGIC_ATTR_ATTRLIST_H__
#define __LOGIC_ATTR_ATTRLIST_H__
#include "basedef.h"
#include "attrTypes.h"
#include "Process_error.h"
#include <string.h>
namespace SKILLEDITOR
{
	class CAttrList
	{
	public:
		CAttrList();
		virtual ~CAttrList();

		inline void reset();
		inline BSLib::s32 getBaseAttribute(BSLib::s32 nIndex);
		inline bool setBaseAttribute(BSLib::s32 nIndex, BSLib::s32 nValue);
		inline BSLib::s32 calcBaseAttribute(BSLib::s32 index);

		inline BSLib::s32 getBaseAttributeA(BSLib::s32 nIndex);
		inline bool setBaseAttributeA(BSLib::s32 nIndex, BSLib::s32 nValue);
		inline BSLib::s32 getBaseAttributeB(BSLib::s32 nIndex);
		inline bool setBaseAttributeB(BSLib::s32 nIndex, BSLib::s32 nValue);
		inline BSLib::s32 getBaseAttributeC(BSLib::s32 nIndex);
		inline bool setBaseAttributeC(BSLib::s32 nIndex, BSLib::s32 nValue);

		inline BSLib::s32 calcExtendAttribute(BSLib::s32 index);
		inline BSLib::s32 getExtendAttribute(BSLib::s32 index);
		inline bool setExtendAttribute(BSLib::s32 index, BSLib::s32 value);

		inline BSLib::s32 getExtendAttributeA(BSLib::s32 index);
		inline bool setExtendAttributeA(BSLib::s32 index, BSLib::s32 value);
		inline BSLib::s32 getExtendAttributeB(BSLib::s32 index);
		inline bool setExtendAttributeB(BSLib::s32 index, BSLib::s32 value);
		inline BSLib::s32 getExtendAttributeC(BSLib::s32 index);
		inline bool setExtendAttributeC(BSLib::s32 index, BSLib::s32 value);
		inline BSLib::s32 getExtendAttributeD(BSLib::s32 index);
		inline bool setExtendAttributeD(BSLib::s32 index, BSLib::s32 value);
		inline BSLib::s32 getExtendAttributeE(BSLib::s32 index);
		inline bool setExtendAttributeE(BSLib::s32 index, BSLib::s32 value);

		inline BSLib::s32 getOtherAttribute(BSLib::s32 index);
		inline bool setOtherAttribute(BSLib::s32 index, BSLib::s32 value);

		inline BSLib::s32 getFactorAttribute(BSLib::s32 index);
		inline bool setFactorAttribute(BSLib::s32 index, BSLib::s32 value);

		inline BSLib::s32 getCustomAttribute(BSLib::s32 index);
		inline bool setCustomAttribute(BSLib::s32 index, BSLib::s32 value);

		inline void clone(CAttrList &attrList);
		inline void resetChange(){m_bNeedSync = false;}
		inline bool needSync(){return m_bNeedSync;}

	private:
		BSLib::s32 m_baseAttrListA[EAttrType_BaseAttributeEnd];
		BSLib::s32 m_baseAttrListB[EAttrType_BaseAttributeEnd];
		BSLib::s32 m_baseAttrListC[EAttrType_BaseAttributeEnd];
		BSLib::s32 m_baseAttrList[EAttrType_BaseAttributeEnd];

		BSLib::s32 m_exAttrListA[EExAttrType_AttributeEnd];
		BSLib::s32 m_exAttrListB[EExAttrType_AttributeEnd];
		BSLib::s32 m_exAttrListC[EExAttrType_AttributeEnd];
		BSLib::s32 m_exAttrListD[EExAttrType_AttributeEnd];
		BSLib::s32 m_exAttrListE[EExAttrType_AttributeEnd];
		BSLib::s32 m_exAttrList[EExAttrType_AttributeEnd];

		BSLib::s32 m_otherAttrList[EOtherAttrType_AttributeEnd];
		BSLib::s32 m_factorList[EFactorType_End];
		BSLib::s32 m_customList[ECustomAttrType_End];

		bool m_bNeedSync;
	};

	void CAttrList::reset()
	{
		memset(m_baseAttrListA, 0, sizeof(m_baseAttrListA));
		memset(m_baseAttrListB, 0, sizeof(m_baseAttrListB));
		memset(m_baseAttrListC, 0, sizeof(m_baseAttrListC));
		memset(m_baseAttrList, 0, sizeof(m_baseAttrList));

		memset(m_exAttrListA, 0, sizeof(m_exAttrListA));
		memset(m_exAttrListB, 0, sizeof(m_exAttrListB));
		memset(m_exAttrListC, 0, sizeof(m_exAttrListC));
		memset(m_exAttrListD, 0, sizeof(m_exAttrListD));
		memset(m_exAttrListE, 0, sizeof(m_exAttrListE));
		memset(m_exAttrList, 0, sizeof(m_exAttrList));

		memset(m_otherAttrList, 0, sizeof(m_otherAttrList));
		memset(m_factorList, 0, sizeof(m_factorList));
		memset(m_customList, 0, sizeof(m_customList));
		m_bNeedSync = false;
	}
	BSLib::s32 CAttrList::getBaseAttribute(BSLib::s32 nIndex)
	{
		LOG_PROCESS_ERROR(nIndex > EAttrType_INVALID&& nIndex < EAttrType_BaseAttributeEnd);
		return m_baseAttrList[nIndex];
Exit0:
		return -1;
	}
	bool CAttrList::setBaseAttribute(BSLib::s32 nIndex, BSLib::s32 nValue)
	{
		LOG_PROCESS_ERROR(nIndex > EAttrType_INVALID&& nIndex < EAttrType_BaseAttributeEnd);
		m_baseAttrList[nIndex] = nValue;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}
	BSLib::s32 CAttrList::calcBaseAttribute(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index > EAttrType_INVALID&& index < EAttrType_BaseAttributeEnd);
		return ((m_baseAttrListA[index]*(SPELL_RATE_MAX + m_baseAttrListB[index]) + m_baseAttrListC[index] * SPELL_RATE_MAX) / SPELL_RATE_MAX);
Exit0:
		return -1;
	}

	BSLib::s32 CAttrList::getBaseAttributeA(BSLib::s32 nIndex)
	{
		LOG_PROCESS_ERROR(nIndex > EAttrType_INVALID&& nIndex < EAttrType_BaseAttributeEnd);
		return m_baseAttrListA[nIndex];
Exit0:
		return -1;
	}
	bool CAttrList::setBaseAttributeA(BSLib::s32 nIndex, BSLib::s32 nValue)
	{
		LOG_PROCESS_ERROR(nIndex > EAttrType_INVALID&& nIndex < EAttrType_BaseAttributeEnd);
		m_baseAttrListA[nIndex] = nValue;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}
	BSLib::s32 CAttrList::getBaseAttributeB(BSLib::s32 nIndex)
	{
		LOG_PROCESS_ERROR(nIndex > EAttrType_INVALID&& nIndex < EAttrType_BaseAttributeEnd);
		return m_baseAttrListB[nIndex];
Exit0:
		return -1;
	}
	bool CAttrList::setBaseAttributeB(BSLib::s32 nIndex, BSLib::s32 nValue)
	{
		LOG_PROCESS_ERROR(nIndex > EAttrType_INVALID&& nIndex < EAttrType_BaseAttributeEnd);
		m_baseAttrListB[nIndex] = nValue;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}
	BSLib::s32 CAttrList::getBaseAttributeC(BSLib::s32 nIndex)
	{
		LOG_PROCESS_ERROR(nIndex > EAttrType_INVALID&& nIndex < EAttrType_BaseAttributeEnd);
		return m_baseAttrListC[nIndex];
Exit0:
		return -1;
	}
	bool CAttrList::setBaseAttributeC(BSLib::s32 nIndex, BSLib::s32 nValue)
	{
		LOG_PROCESS_ERROR(nIndex > EAttrType_INVALID && nIndex < EAttrType_BaseAttributeEnd);
		m_baseAttrListC[nIndex] = nValue;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}
	BSLib::s32 CAttrList::calcExtendAttribute(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID && index < EExAttrType_AttributeEnd);
		BSLib::s32 tmp = 0;
		tmp = (m_exAttrListA[index]*(SPELL_RATE_MAX + m_exAttrListB[index]) + m_exAttrListC[index] * SPELL_RATE_MAX) / SPELL_RATE_MAX;
		return (tmp *(SPELL_RATE_MAX + m_exAttrListD[index]) + m_exAttrListE[index])/SPELL_RATE_MAX;
Exit0:
		return -1;
	}
	BSLib::s32 CAttrList::getExtendAttribute(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID && index < EExAttrType_AttributeEnd);
		return m_exAttrList[index];
Exit0:
		return -1;
	}
	bool CAttrList::setExtendAttribute(BSLib::s32 index, BSLib::s32 value)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID&& index < EExAttrType_AttributeEnd);
		m_exAttrList[index] = value;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}

	BSLib::s32 CAttrList::getExtendAttributeA(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID&& index < EExAttrType_AttributeEnd);
		return m_exAttrListA[index];
Exit0:
		return -1;
	}
	bool CAttrList::setExtendAttributeA(BSLib::s32 index, BSLib::s32 value)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID&& index < EExAttrType_AttributeEnd);
		m_exAttrListA[index] = value;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}
	BSLib::s32 CAttrList::getExtendAttributeB(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID&& index < EExAttrType_AttributeEnd);
		return m_exAttrListB[index];
Exit0:
		return -1;
	}
	bool CAttrList::setExtendAttributeB(BSLib::s32 index, BSLib::s32 value)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID&& index < EExAttrType_AttributeEnd);
		m_exAttrListB[index] = value;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}
	BSLib::s32 CAttrList::getExtendAttributeC(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID&& index < EExAttrType_AttributeEnd);
		return m_exAttrListC[index];
Exit0:
		return -1;
	}
	bool CAttrList::setExtendAttributeC(BSLib::s32 index, BSLib::s32 value)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID&& index < EExAttrType_AttributeEnd);
		m_exAttrListC[index] = value;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}
	BSLib::s32 CAttrList::getExtendAttributeD(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID&& index < EExAttrType_AttributeEnd);
		return m_exAttrListD[index];
Exit0:
		return -1;
	}
	bool CAttrList::setExtendAttributeD(BSLib::s32 index, BSLib::s32 value)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID&& index < EExAttrType_AttributeEnd);
		m_exAttrListD[index] = value;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}
	BSLib::s32 CAttrList::getExtendAttributeE(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID&& index < EExAttrType_AttributeEnd);
		return m_exAttrListE[index];
Exit0:
		return -1;
	}
	bool CAttrList::setExtendAttributeE(BSLib::s32 index, BSLib::s32 value)
	{
		LOG_PROCESS_ERROR(index > EExAttrType_INVALID&& index < EExAttrType_AttributeEnd);
		m_exAttrListE[index] = value;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}

	BSLib::s32 CAttrList::getOtherAttribute(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index > EOtherAttrType_INVALID&& index < EOtherAttrType_AttributeEnd);
		return m_otherAttrList[index];
Exit0:
		return -1;
	}
	bool CAttrList::setOtherAttribute(BSLib::s32 index, BSLib::s32 value)
	{
		LOG_PROCESS_ERROR(index > EOtherAttrType_INVALID&& index < EOtherAttrType_AttributeEnd);
		m_otherAttrList[index] = value;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}

	BSLib::s32 CAttrList::getFactorAttribute(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index > EFactorType_INVALID&& index < EFactorType_End);
		return m_factorList[index];
Exit0:
		return -1;
	}
	bool CAttrList::setFactorAttribute(BSLib::s32 index, BSLib::s32 value)
	{
		LOG_PROCESS_ERROR(index > EFactorType_INVALID&& index < EFactorType_End);
		m_factorList[index] = value;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}

	BSLib::s32 CAttrList::getCustomAttribute(BSLib::s32 index)
	{
		LOG_PROCESS_ERROR(index > ECustomAttrType_INVALID&& index < ECustomAttrType_End);
		return m_customList[index];
Exit0:
		return -1;
	}
	bool CAttrList::setCustomAttribute(BSLib::s32 index, BSLib::s32 value)
	{
		LOG_PROCESS_ERROR(index > ECustomAttrType_INVALID&& index < ECustomAttrType_End);
		m_customList[index] = value;
		m_bNeedSync = true;
		return true;
Exit0:
		return false;
	}

	inline void CAttrList::clone(CAttrList &attrList)
	{
		memcpy(attrList.m_baseAttrListA, m_baseAttrListA, sizeof(m_baseAttrListA));
		memcpy(attrList.m_baseAttrListB, m_baseAttrListB, sizeof(m_baseAttrListB));
		memcpy(attrList.m_baseAttrListC, m_baseAttrListC, sizeof(m_baseAttrListC));
		memcpy(attrList.m_baseAttrList, m_baseAttrList, sizeof(m_baseAttrList));

		memcpy(attrList.m_exAttrListA, m_exAttrListA, sizeof(m_exAttrListA));
		memcpy(attrList.m_exAttrListB, m_exAttrListB, sizeof(m_exAttrListB));
		memcpy(attrList.m_exAttrListC, m_exAttrListC, sizeof(m_exAttrListC));
		memcpy(attrList.m_exAttrListD, m_exAttrListD, sizeof(m_exAttrListD));
		memcpy(attrList.m_exAttrListE, m_exAttrListE, sizeof(m_exAttrListE));
		memcpy(attrList.m_exAttrList, m_exAttrList, sizeof(m_exAttrList));

		memcpy(attrList.m_otherAttrList, m_otherAttrList, sizeof(m_otherAttrList));
		memcpy(attrList.m_factorList, m_factorList, sizeof(m_factorList));
		memcpy(attrList.m_customList, m_customList, sizeof(m_customList));
		attrList.m_bNeedSync = m_bNeedSync;

	}
}
#endif