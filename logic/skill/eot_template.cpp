#include "eot_template.h"

namespace SKILLEDITOR
{
	EotEntry::EotEntry(){}
	EotEntry::~EotEntry(){}

	BSLib::s32 EotEntry::getID(){return m_id;}
	BSLib::s32 EotEntry::getLevel(){return m_level;}
	bool EotEntry::isGood(){return m_isHot != 0}
	bool EotEntry::isUndispeled(){return true;}

	void EotEntry::reset()
	{
		m_id =0;
		m_level = 0;
		m_isHot =0;
		m_jumpTime = m_jumpNumber = m_jumpPower = m_jumpMaxTime = 0;
		m_targetAttrID = 0;
	}
}