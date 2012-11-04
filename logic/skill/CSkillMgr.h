#ifndef __LOGIC_SKILL_CSKILLMGR_H__
#define __LOGIC_SKILL_CSKILLMGR_H__
#include "basedef.h"
#include "../../io/CXmlExcel.h"
#include "CSkillTemplate.h"
#include <map>
#include <vector>

namespace SKILLEDITOR
{
	typedef struct _SListItemShowData
	{
		BSLib::stringc showName;
		void *reserved;
	}SListItemShowData;

	class CSkillMgr
	{
	
		CSkillMgr();
		~CSkillMgr();
	public:
		static CSkillMgr& getInstance()
		{
			static CSkillMgr _sSkillMgr;
			return _sSkillMgr;
		}
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

		std::vector <SListItemShowData> m_showData;
	public:
		std::vector <SListItemShowData> &getShowData(){return m_showData;}
	};
	#define  sSkillMgr CSkillMgr::getInstance()
}
#endif