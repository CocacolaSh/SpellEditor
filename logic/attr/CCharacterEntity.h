#ifndef __LOGIC_ATTR_CCHARACTERENTITY_H__
#define __LOGIC_ATTR_CCHARACTERENTITY_H__
#include "basedef.h"
namespace SKILLEDITOR
{
	class IFighter;
	class CCharacterEntity
	{
	public:
		CCharacterEntity(){}
		virtual ~CCharacterEntity(){}

		IFighter *getFighterImp(){return NULL;}
		BSLib::u64 getEntityID(){return 0;}
	};
}
#endif