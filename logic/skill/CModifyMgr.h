#ifndef __LOGIC_SKILL_CMODIFYMGR_H__
#define __LOGIC_SKILL_CMODIFYMGR_H__

namespace SKILLEDITOR
{
	class CModifyMgr
	{
		CModifyMgr();
		virtual ~CModifyMgr();
	public:
		static CModifyMgr& getInstance(){return *this;}

		bool applySeq(BSLib::s32 seqID, void *dst);
		bool applySeq(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3);
		bool rollbackSeq(CCharacterEntity *src, void *dst, BSLib::s32 key, BSLib::s32 arg1, BSLib::s32 arg2, BSLib::s32 arg3);
	};

#define  sModifierMgr CModifyMgr::getInstance()
}
#endif