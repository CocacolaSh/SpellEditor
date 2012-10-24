#ifndef __LOGIC_SKILL_CMODIFYMGR_H__
#define __LOGIC_SKILL_CMODIFYMGR_H__
#include "basedef.h"
#include <map>

namespace SKILLEDITOR
{

	class CCharacterEntity;
	struct AttrModifier
	{
		BSLib::s32 key;
		BSLib::s32 type;
		BSLib::s32 args[3];
	};

	struct AttrModifierNode
	{
		AttrModifierNode()
		{
			memset(&m_node, 0, sizeof(m_node));
		}
		AttrModifier		m_node;
		AttrModifierNode *	m_next;
	};

	class AttrModifierList
	{
	public:
		AttrModifierList();
		virtual ~AttrModifierList(){}

		bool addNode(AttrModifierNode *node);
		void setType(BSLib::s32 type){m_type = type;}
		bool delAllNode();

		bool applyAll(CCharacterEntity *src, void *dst);
		bool unapplyAll(CCharacterEntity *src, void *dst);

	private:
		BSLib::s32 m_type;
		AttrModifierNode *m_head;
		AttrModifierNode *m_tail;
	};

	class CModifyMgr
	{
		CModifyMgr();
		virtual ~CModifyMgr();
	public:
		static CModifyMgr& getInstance()
		{
			static CModifyMgr sModifyMgr;
			return sModifyMgr;
		}

		AttrModifierList *findModifierList(BSLib::u32 seqID);
		bool addNode(BSLib::u32 seqID, AttrModifierNode *node);

		bool applySeq(BSLib::s32 seqID, CCharacterEntity *src, BSLib::s32 type, void *dst);
		bool rollbackSeq(BSLib::s32 seqID, CCharacterEntity *src, BSLib::s32 type, void *dst);

		bool load(const char* filePath = NULL);
	private:
		typedef std::map<BSLib::u32, AttrModifierList *> TModifierList;
		TModifierList		m_modifierList;
	};

#define  sModifierMgr CModifyMgr::getInstance()
}
#endif