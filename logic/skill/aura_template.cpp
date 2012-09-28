#include "aura_template.h"

namespace SKILLEDITOR
{
	AuraEntry::AuraEntry(){}
	AuraEntry::~AuraEntry(){}

	BSLib::s32 AuraEntry::getID(){return m_id;}
	BSLib::s32 AuraEntry::getLevel(){return m_level;}
	bool AuraEntry::isGood(){return m_isGood != 0}
	bool AuraEntry::isUndispeled(){return m_isUnDispeled != 0;}

	void AuraEntry::reset()
	{
		m_id =0;
		m_level = 0;
		m_isGood =0;
		m_isUnDispeled = m_isDisapearAfterDead = 0;
		m_groupID = m_subGroupID = 0;
		m_targetAttrID = m_targetAttrType = 0;
		m_powerOfAura = m_powerUpperLimit = 0;
		m_fixTime = m_maxTime = 0 ;
		m_targetAttrID = 0;
	}
}