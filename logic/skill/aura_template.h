#ifndef __LOGIC_SKILL_AURATEMPLATE_H__
#define __LOGIC_SKILL_AURATEMPLATE_H__

#include "evtDef.h"
#include "aura_def.h"
//#include <unordered_map>
#include <map>
namespace SKILLEDITOR
{
	struct AuraTemplate
	{
		AuraTemplate()
		{
			m_iscpy = false;
			memset(m_dwSeq, 0, sizeof(m_dwSeq));
		}
		bool m_iscpy;
		AuraEntry	m_data;
		BSLib::u32	m_dwSeq[EMODIFY_EOT_TIMECOUNT][MAX_SEQ];
	};

	class CAuraMgr
	{
	public:
	private:
		//typedef std::tr1::unordered_map<BSLib::u64, AuraTemplate *> TAuraTemplateMap;
		typedef std::map<BSLib::u64, AuraTemplate *> TAuraTemplateMap;
		TAuraTemplateMap m_auraTemplateMap;

		typedef std::map<BSLib::u64, AuraEntryEx *> TAuraEntryExMap;
		TAuraEntryExMap	m_auraEntryExMap;
	};
}
#endif