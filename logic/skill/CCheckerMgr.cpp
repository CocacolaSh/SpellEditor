#include "CCheckerMgr.h"
#include "Process_error.h"
#include "../attr/CheckerFunc.h"

namespace SKILLEDITOR
{
	CAttrCheckerList::CAttrCheckerList()
	{
		m_type = 0;
		m_pHeader = m_pTail = NULL;
	}
	CAttrCheckerList::~CAttrCheckerList()
	{
		//
	}

	bool CAttrCheckerList::addNode(CheckerNode *node)
	{
		LOG_PROCESS_ERROR(node);
		LOG_PROCESS_ERROR(m_type == node->node.type);
		if (m_pTail == NULL)
		{
			m_pHeader = m_pTail = node;
		}else
		{
			m_pTail->next = node;
			m_pTail = node;
		}
Exit0:
		return false;
	}

	bool CAttrCheckerList::checkAll(void *dst)
	{
		CheckerNode *node = m_pHeader;

		while(node != NULL)
		{
			TAttrCheckerFunc func = GetCheckerFunc(node->node.key);
			LOG_PROCESS_ERROR(func);

			if (!func(dst, node->node.type, node->node.func_id1, node->node.arg1, node->node.func_id2, node->node.arg2))
			{
				LOG_PROCESS_ERROR(false);
			}
			node = node->next;
		}
		return true;
Exit0:
		return false;
	}
}