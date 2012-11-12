#include "CMainPropGrid.h"

static const wxString severities[] =
{
	wxT("wishlist"),
	wxT("minor"),
	wxT("normal"),
	wxT("major"),
	wxT("critical"),
};

static const wxString ScenarioTypeArr[] =
{
	wxT("PVP"),
	wxT("PVE"),
	wxT("Ignore"),
};

bool CMainPropCtrl::registerSkillProp()
{
	stdext::hash_map<BSLib::stringc, wxString> skillNameMap;
	std::vector <SKILLEDITOR::SListItemShowData> showDataVec = SKILLEDITOR::sSkillMgr.getShowData();
	BSLib::s32 rowSize = showDataVec.size();
	for (BSLib::s32 i = 0; i < rowSize; ++i)
	{
		wxString column1Str = wxString(wxConvUTF8.cMB2WC(showDataVec[i].showName.c_str()), *wxConvCurrent);
		skillNameMap[showDataVec[i].indexName] = column1Str;
	}

	m_skillItemWindow["ID"] = new wxIntProperty(skillNameMap["ID"], wxPG_LABEL, 0);
	m_skillItemWindow["SkillID"] = new wxIntProperty(skillNameMap["SkillID"], wxPG_LABEL, 0);
	m_skillItemWindow["SkillName"] = new wxIntProperty(skillNameMap["SkillName"], wxPG_LABEL, 0);
	m_skillItemWindow["SkillIcon"] = new wxIntProperty(skillNameMap["SkillIcon"], wxPG_LABEL, 0);
	m_skillItemWindow["SkillDescription"] = new wxIntProperty(skillNameMap["SkillDescription"], wxPG_LABEL, 0);
	m_skillItemWindow["SkillLevel"] = new wxIntProperty(skillNameMap["SkillLevel"], wxPG_LABEL, 0);
	m_skillItemWindow["ScenarioType"] = new wxIntProperty(skillNameMap["ScenarioType"], wxPG_LABEL, 0);
	m_skillItemWindow["SeqAfterLearn"] = new wxIntProperty(skillNameMap["SeqAfterLearn"], wxPG_LABEL, 0);
	m_skillItemWindow["SeqAfterEquip"] = new wxIntProperty(skillNameMap["SeqAfterEquip"], wxPG_LABEL, 0);
	m_skillItemWindow["LoopFx"] = new wxIntProperty(skillNameMap["LoopFx"], wxPG_LABEL, 0);

	m_skillItemWindow["ChiLevel"] = new wxIntProperty(skillNameMap["ChiLevel"], wxPG_LABEL, 0);
	m_skillItemWindow["IsElite"] = new wxIntProperty(skillNameMap["IsElite"], wxPG_LABEL, 0);
	m_skillItemWindow["IsEmblem"] = new wxIntProperty(skillNameMap["IsEmblem"], wxPG_LABEL, 0);
	m_skillItemWindow["IsIgnoreHard"] = new wxIntProperty(skillNameMap["IsIgnoreHard"], wxPG_LABEL, 0);
	m_skillItemWindow["SkillPattern"] = new wxIntProperty(skillNameMap["SkillPattern"], wxPG_LABEL, 0);
	m_skillItemWindow["SkillBaseType"] = new wxIntProperty(skillNameMap["SkillBaseType"], wxPG_LABEL, 0);
	m_skillItemWindow["RequireNotInCommonState"] = new wxIntProperty(skillNameMap["RequireNotInCommonState"], wxPG_LABEL, 0);
	m_skillItemWindow["RequireMoveCheck"] = new wxIntProperty(skillNameMap["RequireMoveCheck"], wxPG_LABEL, 0);
	m_skillItemWindow["RequireSeq"] = new wxIntProperty(skillNameMap["RequireSeq"], wxPG_LABEL, 0);
	m_skillItemWindow["CostPercentMP"] = new wxIntProperty(skillNameMap["CostPercentMP"], wxPG_LABEL, 0);

	m_skillItemWindow["CostPercentHP"] = new wxIntProperty(skillNameMap["CostPercentHP"], wxPG_LABEL, 0);
	m_skillItemWindow["CostItemID"] = new wxIntProperty(skillNameMap["CostItemID"], wxPG_LABEL, 0);
	m_skillItemWindow["CostItemNum"] = new wxIntProperty(skillNameMap["CostItemNum"], wxPG_LABEL, 0);
	m_skillItemWindow["CoolDownTime"] = new wxIntProperty(skillNameMap["CoolDownTime"], wxPG_LABEL, 0);
	m_skillItemWindow["CoolDownGroup"] = new wxIntProperty(skillNameMap["CoolDownGroup"], wxPG_LABEL, 0);
	m_skillItemWindow["CategoryType"] = new wxIntProperty(skillNameMap["CategoryType"], wxPG_LABEL, 0);
	m_skillItemWindow["CategoryVariable"] = new wxIntProperty(skillNameMap["CategoryVariable"], wxPG_LABEL, 0);
	m_skillItemWindow["IsAutoFaceTarget"] = new wxIntProperty(skillNameMap["IsAutoFaceTarget"], wxPG_LABEL, 0);
	m_skillItemWindow["CastTime"] = new wxIntProperty(skillNameMap["CastTime"], wxPG_LABEL, 0);
	m_skillItemWindow["CastTake"] = new wxIntProperty(skillNameMap["CastTake"], wxPG_LABEL, 0);

	m_skillItemWindow["CastEnhancement"] = new wxIntProperty(skillNameMap["CastEnhancement"], wxPG_LABEL, 0);
	m_skillItemWindow["CastArmor"] = new wxIntProperty(skillNameMap["CastArmor"], wxPG_LABEL, 0);
	m_skillItemWindow["AttackTime"] = new wxIntProperty(skillNameMap["AttackTime"], wxPG_LABEL, 0);
	m_skillItemWindow["AttackSTake"] = new wxIntProperty(skillNameMap["AttackSTake"], wxPG_LABEL, 0);
	m_skillItemWindow["AttackTargetType"] = new wxIntProperty(skillNameMap["AttackTargetType"], wxPG_LABEL, 0);
	m_skillItemWindow["AttackEnhancement"] = new wxIntProperty(skillNameMap["AttackEnhancement"], wxPG_LABEL, 0);
	m_skillItemWindow["FloatingTimeStart"] = new wxIntProperty(skillNameMap["FloatingTimeStart"], wxPG_LABEL, 0);
	m_skillItemWindow["FloatTimeSpan"] = new wxIntProperty(skillNameMap["FloatTimeSpan"], wxPG_LABEL, 0);
	m_skillItemWindow["AttackEventTime"] = new wxIntProperty(skillNameMap["AttackEventTime"], wxPG_LABEL, 0);
	m_skillItemWindow["AttackEvent"] = new wxIntProperty(skillNameMap["AttackEvent"], wxPG_LABEL, 0);

	m_skillItemWindow["SpurtStartTime"] = new wxIntProperty(skillNameMap["SpurtStartTime"], wxPG_LABEL, 0);
	m_skillItemWindow["SpurtTimeSpan"] = new wxIntProperty(skillNameMap["SpurtTimeSpan"], wxPG_LABEL, 0);
	m_skillItemWindow["SpurtDistanceX"] = new wxIntProperty(skillNameMap["SpurtDistanceX"], wxPG_LABEL, 0);
	m_skillItemWindow["SpurtDistanceY"] = new wxIntProperty(skillNameMap["SpurtDistanceY"], wxPG_LABEL, 0);
	m_skillItemWindow["SpurtDistanceZ"] = new wxIntProperty(skillNameMap["SpurtDistanceZ"], wxPG_LABEL, 0);
	m_skillItemWindow["SpurtNoStepDown"] = new wxIntProperty(skillNameMap["SpurtNoStepDown"], wxPG_LABEL, 0);
	m_skillItemWindow["FireTime"] = new wxIntProperty(skillNameMap["FireTime"], wxPG_LABEL, 0);
	m_skillItemWindow["FireType"] = new wxIntProperty(skillNameMap["FireType"], wxPG_LABEL, 0);
	m_skillItemWindow["sFireMissileID"] = new wxIntProperty(skillNameMap["sFireMissileID"], wxPG_LABEL, 0);
	
	m_skillItemWindow["AttackBoxGroupID1"] = new wxIntProperty(skillNameMap["AttackBoxGroupID1"], wxPG_LABEL, 0);
	m_skillItemWindow["HitSeq1"] = new wxIntProperty(skillNameMap["HitSeq1"], wxPG_LABEL, 0);
	m_skillItemWindow["HitBreakArmor1"] = new wxIntProperty(skillNameMap["HitBreakArmor1"], wxPG_LABEL, 0);
	m_skillItemWindow["HitAttackInfo1"] = new wxIntProperty(skillNameMap["HitAttackInfo1"], wxPG_LABEL, 0);
	m_skillItemWindow["AttackBoxGroupID2"] = new wxIntProperty(skillNameMap["AttackBoxGroupID2"], wxPG_LABEL, 0);
	m_skillItemWindow["HitSeq2"] = new wxIntProperty(skillNameMap["HitSeq2"], wxPG_LABEL, 0);
	m_skillItemWindow["HitBreakArmor2"] = new wxIntProperty(skillNameMap["HitBreakArmor2"], wxPG_LABEL, 0);
	m_skillItemWindow["HitAttackInfo2"] = new wxIntProperty(skillNameMap["HitAttackInfo2"], wxPG_LABEL, 0);
	m_skillItemWindow["AttackBoxGroupID3"] = new wxIntProperty(skillNameMap["AttackBoxGroupID3"], wxPG_LABEL, 0);
	m_skillItemWindow["HitSeq3"] = new wxIntProperty(skillNameMap["HitSeq3"], wxPG_LABEL, 0);
	m_skillItemWindow["HitBreakArmor3"] = new wxIntProperty(skillNameMap["HitBreakArmor3"], wxPG_LABEL, 0);
	m_skillItemWindow["HitAttackInfo3"] = new wxIntProperty(skillNameMap["HitAttackInfo3"], wxPG_LABEL, 0);

	m_skillItemWindow["CloseAttackTime"] = new wxIntProperty(skillNameMap["CloseAttackTime"], wxPG_LABEL, 0);
	m_skillItemWindow["CloseAttackSTake"] = new wxIntProperty(skillNameMap["CloseAttackSTake"], wxPG_LABEL, 0);
	m_skillItemWindow["seAttackEnhancement"] = new wxIntProperty(skillNameMap["seAttackEnhancement"], wxPG_LABEL, 0);
	m_skillItemWindow["CloseAttackEventTime"] = new wxIntProperty(skillNameMap["CloseAttackEventTime"], wxPG_LABEL, 0);
	m_skillItemWindow["CloseAttackEvent"] = new wxIntProperty(skillNameMap["CloseAttackEvent"], wxPG_LABEL, 0);

	return true;
}