#ifndef __LOGIC_SKILL_CCHECKERMGR_H__
#define __LOGIC_SKILL_CCHECKERMGR_H__
#include "basedef.h"
#include <map>
namespace SKILLEDITOR
{
	struct AttrChecker 
	{
		BSLib::s32 key;
		BSLib::s32 type;
		BSLib::s32 func_id1;
		BSLib::s32 arg1;
		BSLib::s32 func_id2;
		BSLib::s32 arg2;
	};

	struct CheckerNode
	{
		CheckerNode()
		{
			memset(&node, 0, sizeof(node));
			next = NULL;
		}
		AttrChecker node;
		CheckerNode *next;
	};

	class CAttrCheckerList
	{
	public:
		CAttrCheckerList();
		virtual ~CAttrCheckerList();

		bool addNode(CheckerNode *node);
		void setType(BSLib::s32 type){m_type = type;}

		bool checkAll(void *dst);
	private:
		BSLib::s32	m_type;
		CheckerNode* m_pHeader;
		CheckerNode* m_pTail;

	};
}
#endif