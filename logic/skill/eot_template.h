#ifndef __LOGIC_SKILL_EOTTEMPLATE_H__
#define __LOGIC_SKILL_EOTTEMPLATE_H__

#include "evtDef.h"
#include "eot_def.h"
namespace SKILLEDITOR
{
	struct EotTemplate
	{
		bool m_iscpy;
		EotEntry	m_data;
		BSLib::u32	m_dwSeq[EMODIFY_EOT_TIMECOUNT][MAX_SEQ];
	};

	class CEotMgr
	{
	public:
	};
}
#endif