#ifndef __LOGIC_SKILL_CSKILLMGR_H__
#define __LOGIC_SKILL_CSKILLMGR_H__
#include "basedef.h"
#include "../../io/CXmlExcel.h"
#include "CSkillTemplate.h"
#include <map>

namespace SKILLEDITOR
{
	class CSkillMgr
	{
	public:
		CSkillMgr();
		~CSkillMgr();

		bool clear();

		bool load(const char* filePath = NULL);
		bool save(const char* filePath = NULL);
	private:
		bool _postLoad(BSLib::CXmlExcel& xmlExcel);
		bool _postSave(BSLib::CXmlExcel& xmlExcel);
	private:
		typedef std::map<BSLib::s64, CSkillTemplate> TSKILLMAP;
		CSkillEntry*		m_pEntrys;
		TSKILLMAP m_skillMgrMap;
	};
}
#endif