#include "CModifyMgr.h"
#include "Process_error.h"
#include "../attr/ModifierFunc.h"
#include "evtDef.h"
namespace SKILLEDITOR
{
	AttrModifierList::AttrModifierList()
	{
		m_head = m_tail = NULL;
		m_type = EAttrModifyType_Invalid;
	}
	bool AttrModifierList::addNode(AttrModifierNode *node)
	{
		LOG_PROCESS_ERROR(node);
		LOG_PROCESS_ERROR(node->m_node.type == m_type);

		if (m_head == NULL)
		{
			m_head = node;
			m_tail = node;
			return true;
		}
		m_tail->m_next = node;
		m_tail = m_tail->m_next;
		return true;
Exit0:
		return false;
	}
	bool AttrModifierList::delAllNode()
	{
		if (m_head == NULL)
		{
			return false;
		}

		while (m_head)
		{
			AttrModifierNode *temp = m_head;
			m_head = m_head->m_next;
			delete temp;
			temp = NULL;
		}
		m_head = m_tail = NULL;
		return true;
	}

	bool AttrModifierList::applyAll(CCharacterEntity *src, void *dst)
	{
		AttrModifierNode *temp = m_head;
		bool bRet = true;

		while(temp != NULL)
		{
			TAttrModifierFunc func = GetModifierFunc(temp->m_node.type, temp->m_node.key);
			if (func == NULL)
			{
				temp = temp->m_next;
				continue;
			}

			if (!func (src, dst, temp->m_node.key, temp->m_node.args[0], temp->m_node.args[1], temp->m_node.args[2]))
			{
				//
				bRet = false;
			}
			temp = temp->m_next;
		}
		return bRet;
	}
	bool AttrModifierList::unapplyAll(CCharacterEntity *src, void *dst)
	{
		AttrModifierNode *temp = m_head;
		bool bRet = true;

		while(temp != NULL)
		{
			TAttrModifierFunc func = GetModifierFunc(temp->m_node.type, temp->m_node.key);
			if (func == NULL)
			{
				temp = temp->m_next;
				continue;
			}

			if (!func (src, dst, temp->m_node.key, -temp->m_node.args[0], -temp->m_node.args[1], -temp->m_node.args[2]))
			{
				//
				bRet = false;
			}
			temp = temp->m_next;
		}
		return bRet;
	}

	CModifyMgr::CModifyMgr(){}
	CModifyMgr::~CModifyMgr(){}
	AttrModifierList *CModifyMgr::findModifierList(BSLib::u32 seqID)
	{
		TModifierList::iterator iter = m_modifierList.find(seqID);
		if (iter == m_modifierList.end())
		{
			return NULL;
		}
		return iter->second;
	}
	bool CModifyMgr::addNode(BSLib::u32 seqID, AttrModifierNode *node)
	{
		bool bRet = true;
		AttrModifierList *list = findModifierList(seqID);
		if (list != NULL)
		{
			return list->addNode(node);
		}
		BSLib::s32 type = 0, idx;
		SplitSeqKey(seqID, type, idx);

		list = new AttrModifierList();
		list->setType(type);

		if (list->addNode(node) == false)
		{
			return false;
		}
		m_modifierList[seqID] = list;
	}

	bool CModifyMgr::applySeq(BSLib::s32 seqID, CCharacterEntity *src, BSLib::s32 type, void *dst)
	{
		AttrModifierList *list = findModifierList(seqID);
		LOG_PROCESS_ERROR(list);

		BSLib::s32 seq_type = 0, idx;
		SplitSeqKey(seqID, seq_type, idx);

		LOG_PROCESS_ERROR(seq_type == type);

		return list->applyAll(src, dst);
Exit0:
		return false;
	}
	bool CModifyMgr::rollbackSeq(BSLib::s32 seqID, CCharacterEntity *src, BSLib::s32 type, void *dst)
	{
		AttrModifierList *list = findModifierList(seqID);
		LOG_PROCESS_ERROR(list);

		BSLib::s32 seq_type = 0, idx;
		SplitSeqKey(seqID, seq_type, idx);

		LOG_PROCESS_ERROR(seq_type == type);

		return list->unapplyAll(src, dst);
Exit0:
		return false;
	}

	bool CModifyMgr::load(const char* filePath = NULL)
	{
		//
Exit0:
		return false;
	}
}