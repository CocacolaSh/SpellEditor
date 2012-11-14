#include "CMainPropGrid.h"
#include "./logic/skill/CSkillTemplate.h"

using namespace SKILLEDITOR;
static const wxChar* severities[] =
{
	wxT("wishlist"),
	wxT("minor"),
	wxT("normal"),
	wxT("major"),
	wxT("critical"),
};

static const wxChar* ScenarioTypeArrLabels[] =
{
	wxT("PVP"),
	wxT("PVE"),
	wxT("ºöÂÔ"),
	NULL
};
static long ScenarioTypeArrValues[] = 
{ 
	ESkillScenarioType_PVP, 
	ESkillScenarioType_PVE, 
	ESkillScenarioType_Ignore,
	-1
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
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["ID"]);
	m_skillItemWindow["SkillID"] = new wxIntProperty(skillNameMap["SkillID"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["SkillID"]);
	m_skillItemWindow["SkillName"] = new wxIntProperty(skillNameMap["SkillName"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["SkillName"]);
	m_skillItemWindow["SkillIcon"] = new wxIntProperty(skillNameMap["SkillIcon"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["SkillIcon"]);
	m_skillItemWindow["SkillDescription"] = new wxIntProperty(skillNameMap["SkillDescription"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["SkillDescription"]);
	m_skillItemWindow["SkillLevel"] = new wxIntProperty(skillNameMap["SkillLevel"], wxPG_LABEL, 0);
	m_skillItemWindow["SkillLevel"]->SetEditor(wxPGEditor_SpinCtrl);
	m_skillItemWindow["SkillLevel"]->SetAttribute(wxPG_ATTR_MIN, (long)0);
	m_skillItemWindow["SkillLevel"]->SetAttribute(wxPG_ATTR_MAX, (long)10);
	m_skillItemWindow["SkillLevel"]->SetAttribute(wxT("Step"), (long)1);
	m_skillItemWindow["SkillLevel"]->SetAttribute(wxT("MotionSpin"), true);
	//pg->SetPropertyEditor( wxT("SpinCtrl"), wxPGEditor_SpinCtrl );
	//pg->SetPropertyAttribute( wxT("SpinCtrl"), wxPG_ATTR_MIN, (long)-10 );  // Use constants instead of string
	//pg->SetPropertyAttribute( wxT("SpinCtrl"), wxPG_ATTR_MAX, (long)16384 );   // for reduced binary size.
	//pg->SetPropertyAttribute( wxT("SpinCtrl"), wxT("Step"), (long)2 );
	//pg->SetPropertyAttribute( wxT("SpinCtrl"), wxT("MotionSpin"), true );
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["SkillLevel"]);
	m_skillItemWindow["ScenarioType"] = new wxEnumProperty(skillNameMap["ScenarioType"], wxPG_LABEL,
		ScenarioTypeArrLabels, ScenarioTypeArrValues, ESkillScenarioType_Ignore);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["ScenarioType"]);
	m_skillItemWindow["SeqAfterLearn"] = new wxIntProperty(skillNameMap["SeqAfterLearn"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["SeqAfterLearn"]);
	m_skillItemWindow["SeqAfterEquip"] = new wxIntProperty(skillNameMap["SeqAfterEquip"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["SeqAfterEquip"]);
	m_skillItemWindow["LoopFx"] = new wxIntProperty(skillNameMap["LoopFx"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["LoopFx"]);

	m_skillItemWindow["ChiLevel"] = new wxIntProperty(skillNameMap["ChiLevel"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["ChiLevel"]);
	m_skillItemWindow["IsElite"] =  new wxBoolProperty(skillNameMap["IsElite"], wxPG_LABEL, 0);
	m_skillItemWindow["IsElite"]->SetAttribute(wxPG_BOOL_USE_CHECKBOX, true);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["IsElite"]);
	m_skillItemWindow["IsEmblem"] =  new wxBoolProperty(skillNameMap["IsEmblem"], wxPG_LABEL, 0);
	m_skillItemWindow["IsEmblem"]->SetAttribute(wxPG_BOOL_USE_CHECKBOX, true);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["IsEmblem"]);
	m_skillItemWindow["IsIgnoreHard"] =  new wxBoolProperty(skillNameMap["IsIgnoreHard"], wxPG_LABEL, 0);
	m_skillItemWindow["IsIgnoreHard"]->SetAttribute(wxPG_BOOL_USE_CHECKBOX, true);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["IsIgnoreHard"]);
	m_skillItemWindow["SkillPattern"] = new wxIntProperty(skillNameMap["SkillPattern"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["SkillPattern"]);
	m_skillItemWindow["SkillBaseType"] = new wxIntProperty(skillNameMap["SkillBaseType"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["SkillBaseType"]);
	m_skillItemWindow["RequireNotInCommonState"] = new wxIntProperty(skillNameMap["RequireNotInCommonState"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["RequireNotInCommonState"]);
	m_skillItemWindow["RequireMoveCheck"] = new wxIntProperty(skillNameMap["RequireMoveCheck"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["RequireMoveCheck"]);
	m_skillItemWindow["RequireSeq"] = new wxIntProperty(skillNameMap["RequireSeq"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["RequireSeq"]);
	m_skillItemWindow["CostPercentMP"] = new wxIntProperty(skillNameMap["CostPercentMP"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["CostPercentMP"]);

	m_skillItemWindow["CostPercentHP"] = new wxIntProperty(skillNameMap["CostPercentHP"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["CostPercentHP"]);
	m_skillItemWindow["CostItemID"] = new wxIntProperty(skillNameMap["CostItemID"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["CostItemID"]);
	m_skillItemWindow["CostItemNum"] = new wxIntProperty(skillNameMap["CostItemNum"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["CostItemNum"]);
	m_skillItemWindow["CoolDownTime"] = new wxIntProperty(skillNameMap["CoolDownTime"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["CoolDownTime"]);
	m_skillItemWindow["CoolDownGroup"] = new wxIntProperty(skillNameMap["CoolDownGroup"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["CoolDownGroup"]);
	m_skillItemWindow["CategoryType"] = new wxIntProperty(skillNameMap["CategoryType"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["CategoryType"]);
	m_skillItemWindow["CategoryVariable"] = new wxIntProperty(skillNameMap["CategoryVariable"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["CategoryVariable"]);
	m_skillItemWindow["IsAutoFaceTarget"] = new wxBoolProperty(skillNameMap["IsAutoFaceTarget"], wxPG_LABEL, 0);
	m_skillItemWindow["IsAutoFaceTarget"]->SetAttribute(wxPG_BOOL_USE_CHECKBOX, true);
	m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow["IsAutoFaceTarget"]);

	wxPGProperty* topCastId = m_propGridPages[ECreateItemType_Skill]->Append(new wxStringProperty(wxT("ÆðÊÖ½×¶Î"), wxPG_LABEL, wxT("<composed>")) );
	m_skillItemWindow["CastTime"] = new wxFloatProperty(skillNameMap["CastTime"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topCastId, m_skillItemWindow["CastTime"]);
	m_skillItemWindow["CastTake"] = new wxIntProperty(skillNameMap["CastTake"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topCastId, m_skillItemWindow["CastTake"]);
	m_skillItemWindow["CastEnhancement"] = new wxIntProperty(skillNameMap["CastEnhancement"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topCastId, m_skillItemWindow["CastEnhancement"]);
	m_skillItemWindow["CastArmor"] = new wxIntProperty(skillNameMap["CastArmor"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topCastId, m_skillItemWindow["CastArmor"]);

	wxPGProperty* topAttackId = m_propGridPages[ECreateItemType_Skill]->Append(new wxStringProperty(wxT("¹¥»÷½×¶Î"), wxPG_LABEL, wxT("<composed>")) );
	m_skillItemWindow["AttackTime"] = new wxFloatProperty(skillNameMap["AttackTime"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topAttackId, m_skillItemWindow["AttackTime"]);
	m_skillItemWindow["AttackSTake"] = new wxIntProperty(skillNameMap["AttackSTake"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topAttackId, m_skillItemWindow["AttackSTake"]);
	m_skillItemWindow["AttackTargetType"] = new wxIntProperty(skillNameMap["AttackTargetType"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topAttackId, m_skillItemWindow["AttackTargetType"]);
	m_skillItemWindow["AttackEnhancement"] = new wxIntProperty(skillNameMap["AttackEnhancement"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topAttackId, m_skillItemWindow["AttackEnhancement"]);

	wxPGProperty* topAttackEftId = m_propGridPages[ECreateItemType_Skill]->Append( new wxStringProperty(wxT("¹¥»÷Ð§¹û"), wxPG_LABEL, wxT("<composed>")) );
	wxPGProperty* floatEftId = m_propGridPages[ECreateItemType_Skill]->AppendIn(topAttackEftId, new wxStringProperty(wxT("¸¡¿Õ"), wxPG_LABEL, wxT("<composed>")) );
	wxPGProperty* modifyEftId = m_propGridPages[ECreateItemType_Skill]->AppendIn(topAttackEftId, new wxStringProperty(wxT("ÌØÊâÐÞ¸ÄÆ÷"), wxPG_LABEL, wxT("<composed>")) );
	m_skillItemWindow["FloatingTimeStart"] = new wxFloatProperty(skillNameMap["FloatingTimeStart"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(floatEftId, m_skillItemWindow["FloatingTimeStart"]);
	m_skillItemWindow["FloatTimeSpan"] = new wxFloatProperty(skillNameMap["FloatTimeSpan"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(floatEftId, m_skillItemWindow["FloatTimeSpan"]);
	m_skillItemWindow["AttackEventTime"] = new wxFloatProperty(skillNameMap["AttackEventTime"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(modifyEftId, m_skillItemWindow["AttackEventTime"]);
	m_skillItemWindow["AttackEvent"] = new wxIntProperty(skillNameMap["AttackEvent"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(modifyEftId, m_skillItemWindow["AttackEvent"]);

	wxPGProperty* topSpurtInfoId = m_propGridPages[ECreateItemType_Skill]->AppendIn(topAttackEftId, new wxStringProperty(wxT("ÌØÊâÎ»ÒÆ"), wxPG_LABEL, wxT("<composed>")) );
	m_skillItemWindow["SpurtStartTime"] = new wxIntProperty(skillNameMap["SpurtStartTime"], wxPG_LABEL, 0);
	m_skillItemWindow["SpurtTimeSpan"] = new wxIntProperty(skillNameMap["SpurtTimeSpan"], wxPG_LABEL, 0);
	m_skillItemWindow["SpurtDistanceX"] = new wxIntProperty(skillNameMap["SpurtDistanceX"], wxPG_LABEL, 0);
	m_skillItemWindow["SpurtDistanceY"] = new wxIntProperty(skillNameMap["SpurtDistanceY"], wxPG_LABEL, 0);
	m_skillItemWindow["SpurtDistanceZ"] = new wxIntProperty(skillNameMap["SpurtDistanceZ"], wxPG_LABEL, 0);
	m_skillItemWindow["SpurtNoStepDown"] = new wxBoolProperty(skillNameMap["SpurtNoStepDown"], wxPG_LABEL, 0);
	m_skillItemWindow["SpurtNoStepDown"]->SetAttribute(wxPG_BOOL_USE_CHECKBOX, true);
	m_skillItemWindow["FireTime"] = new wxFloatProperty(skillNameMap["FireTime"], wxPG_LABEL, 0);
	m_skillItemWindow["FireType"] = new wxIntProperty(skillNameMap["FireType"], wxPG_LABEL, 0);
	m_skillItemWindow["sFireMissileID"] = new wxIntProperty(skillNameMap["sFireMissileID"], wxPG_LABEL, 0);
	m_propGridPages[ECreateItemType_Skill]->AppendIn( topSpurtInfoId, m_skillItemWindow["SpurtStartTime"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( topSpurtInfoId, m_skillItemWindow["SpurtTimeSpan"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( topSpurtInfoId, m_skillItemWindow["SpurtDistanceX"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( topSpurtInfoId, m_skillItemWindow["SpurtDistanceY"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( topSpurtInfoId, m_skillItemWindow["SpurtDistanceZ"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( topSpurtInfoId, m_skillItemWindow["SpurtNoStepDown"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( topSpurtInfoId, m_skillItemWindow["FireTime"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( topSpurtInfoId, m_skillItemWindow["FireType"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( topSpurtInfoId, m_skillItemWindow["sFireMissileID"] );
	
	wxPGProperty* topAttackInfoId = m_propGridPages[ECreateItemType_Skill]->Append( new wxStringProperty(wxT("¹¥»÷ÐÅÏ¢"), wxPG_LABEL, wxT("<composed>")) );
	m_skillItemWindow["AttackBoxGroupID1"] = new wxIntProperty(skillNameMap["AttackBoxGroupID1"], wxPG_LABEL, 0);
	m_skillItemWindow["HitSeq1"] = new wxIntProperty(skillNameMap["HitSeq1"], wxPG_LABEL, 0);
	m_skillItemWindow["HitBreakArmor1"] = new wxIntProperty(skillNameMap["HitBreakArmor1"], wxPG_LABEL, 0);
	m_skillItemWindow["HitAttackInfo1"] = new wxIntProperty(skillNameMap["HitAttackInfo1"], wxPG_LABEL, 0);
	wxPGProperty* pid = m_propGridPages[ECreateItemType_Skill]->AppendIn( topAttackInfoId, new wxStringProperty(wxT("AttackInfo 1"), wxT("AttackInfo 1"), wxT("<composed>")) );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["AttackBoxGroupID1"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["HitSeq1"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["HitBreakArmor1"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["HitAttackInfo1"] );

	m_skillItemWindow["AttackBoxGroupID2"] = new wxIntProperty(skillNameMap["AttackBoxGroupID2"], wxPG_LABEL, 0);
	m_skillItemWindow["HitSeq2"] = new wxIntProperty(skillNameMap["HitSeq2"], wxPG_LABEL, 0);
	m_skillItemWindow["HitBreakArmor2"] = new wxIntProperty(skillNameMap["HitBreakArmor2"], wxPG_LABEL, 0);
	m_skillItemWindow["HitAttackInfo2"] = new wxIntProperty(skillNameMap["HitAttackInfo2"], wxPG_LABEL, 0);
	pid = m_propGridPages[ECreateItemType_Skill]->AppendIn( topAttackInfoId, new wxStringProperty(wxT("AttackInfo 2"), wxT("AttackInfo 2"), wxT("<composed>")) );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["AttackBoxGroupID2"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["HitSeq2"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["HitBreakArmor2"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["HitAttackInfo2"] );

	m_skillItemWindow["AttackBoxGroupID3"] = new wxIntProperty(skillNameMap["AttackBoxGroupID3"], wxPG_LABEL, 0);
	m_skillItemWindow["HitSeq3"] = new wxIntProperty(skillNameMap["HitSeq3"], wxPG_LABEL, 0);
	m_skillItemWindow["HitBreakArmor3"] = new wxIntProperty(skillNameMap["HitBreakArmor3"], wxPG_LABEL, 0);
	m_skillItemWindow["HitAttackInfo3"] = new wxIntProperty(skillNameMap["HitAttackInfo3"], wxPG_LABEL, 0);
	pid = m_propGridPages[ECreateItemType_Skill]->AppendIn( topAttackInfoId, new wxStringProperty(wxT("AttackInfo 3"), wxT("AttackInfo 3"), wxT("<composed>")) );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["AttackBoxGroupID3"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["HitSeq3"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["HitBreakArmor3"] );
	m_propGridPages[ECreateItemType_Skill]->AppendIn( pid, m_skillItemWindow["HitAttackInfo3"] );


	m_skillItemWindow["CloseAttackTime"] = new wxIntProperty(skillNameMap["CloseAttackTime"], wxPG_LABEL, 0);
	m_skillItemWindow["CloseAttackTime"]->SetAttribute(wxPG_ATTR_UNITS, wxT("Sec") );
	m_skillItemWindow["CloseAttackTime"]->SetAttribute(wxPG_ATTR_MIN, (long)0);
	m_skillItemWindow["CloseAttackSTake"] = new wxIntProperty(skillNameMap["CloseAttackSTake"], wxPG_LABEL, 0);
	m_skillItemWindow["seAttackEnhancement"] = new wxIntProperty(skillNameMap["seAttackEnhancement"], wxPG_LABEL, 0);
	m_skillItemWindow["CloseAttackEventTime"] = new wxFloatProperty(skillNameMap["CloseAttackEventTime"], wxPG_LABEL, 0);
	m_skillItemWindow["CloseAttackEventTime"]->SetAttribute(wxPG_ATTR_UNITS, wxT("Sec") );
	m_skillItemWindow["CloseAttackEventTime"]->SetAttribute(wxPG_ATTR_MIN, (long)0);
	m_skillItemWindow["CloseAttackEvent"] = new wxIntProperty(skillNameMap["CloseAttackEvent"], wxPG_LABEL, 0);
	wxPGProperty* topCloseAttackId = m_propGridPages[ECreateItemType_Skill]->Append( new wxStringProperty(wxT("ÊÕÕÐ½×¶Î"), wxPG_LABEL, wxT("<composed>")) );
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topCloseAttackId, m_skillItemWindow["CloseAttackTime"]);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topCloseAttackId, m_skillItemWindow["CloseAttackSTake"]);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topCloseAttackId, m_skillItemWindow["seAttackEnhancement"]);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topCloseAttackId, m_skillItemWindow["CloseAttackEventTime"]);
	m_propGridPages[ECreateItemType_Skill]->AppendIn(topCloseAttackId, m_skillItemWindow["CloseAttackEvent"]);



	//m_skillItemWindow["ID"] = new wxIntProperty(skillNameMap["ID"], wxPG_LABEL, 0);
	//m_skillItemWindow["SkillID"] = new wxIntProperty(skillNameMap["SkillID"], wxPG_LABEL, 0);
	//m_skillItemWindow["SkillName"] = new wxIntProperty(skillNameMap["SkillName"], wxPG_LABEL, 0);
	//m_skillItemWindow["SkillIcon"] = new wxIntProperty(skillNameMap["SkillIcon"], wxPG_LABEL, 0);
	//m_skillItemWindow["SkillDescription"] = new wxIntProperty(skillNameMap["SkillDescription"], wxPG_LABEL, 0);
	//m_skillItemWindow["SkillLevel"] = new wxIntProperty(skillNameMap["SkillLevel"], wxPG_LABEL, 0);
	//m_skillItemWindow["ScenarioType"] = new wxIntProperty(skillNameMap["ScenarioType"], wxPG_LABEL, 0);
	//m_skillItemWindow["SeqAfterLearn"] = new wxIntProperty(skillNameMap["SeqAfterLearn"], wxPG_LABEL, 0);
	//m_skillItemWindow["SeqAfterEquip"] = new wxIntProperty(skillNameMap["SeqAfterEquip"], wxPG_LABEL, 0);
	//m_skillItemWindow["LoopFx"] = new wxIntProperty(skillNameMap["LoopFx"], wxPG_LABEL, 0);

	//m_skillItemWindow["ChiLevel"] = new wxIntProperty(skillNameMap["ChiLevel"], wxPG_LABEL, 0);
	//m_skillItemWindow["IsElite"] =  new wxBoolProperty(skillNameMap["IsElite"], wxPG_LABEL, 0);
	//m_skillItemWindow["IsElite"]->SetAttribute(wxPG_BOOL_USE_CHECKBOX, true);
	//m_skillItemWindow["IsEmblem"] =  new wxBoolProperty(skillNameMap["IsEmblem"], wxPG_LABEL, 0);
	//m_skillItemWindow["IsEmblem"]->SetAttribute(wxPG_BOOL_USE_CHECKBOX, true);
	//m_skillItemWindow["IsIgnoreHard"] =  new wxBoolProperty(skillNameMap["IsIgnoreHard"], wxPG_LABEL, 0);
	//m_skillItemWindow["IsIgnoreHard"]->SetAttribute(wxPG_BOOL_USE_CHECKBOX, true);
	//m_skillItemWindow["SkillPattern"] = new wxIntProperty(skillNameMap["SkillPattern"], wxPG_LABEL, 0);
	//m_skillItemWindow["SkillBaseType"] = new wxIntProperty(skillNameMap["SkillBaseType"], wxPG_LABEL, 0);
	//m_skillItemWindow["RequireNotInCommonState"] = new wxIntProperty(skillNameMap["RequireNotInCommonState"], wxPG_LABEL, 0);
	//m_skillItemWindow["RequireMoveCheck"] = new wxIntProperty(skillNameMap["RequireMoveCheck"], wxPG_LABEL, 0);
	//m_skillItemWindow["RequireSeq"] = new wxIntProperty(skillNameMap["RequireSeq"], wxPG_LABEL, 0);
	//m_skillItemWindow["CostPercentMP"] = new wxIntProperty(skillNameMap["CostPercentMP"], wxPG_LABEL, 0);

	//m_skillItemWindow["CostPercentHP"] = new wxIntProperty(skillNameMap["CostPercentHP"], wxPG_LABEL, 0);
	//m_skillItemWindow["CostItemID"] = new wxIntProperty(skillNameMap["CostItemID"], wxPG_LABEL, 0);
	//m_skillItemWindow["CostItemNum"] = new wxIntProperty(skillNameMap["CostItemNum"], wxPG_LABEL, 0);
	//m_skillItemWindow["CoolDownTime"] = new wxIntProperty(skillNameMap["CoolDownTime"], wxPG_LABEL, 0);
	//m_skillItemWindow["CoolDownGroup"] = new wxIntProperty(skillNameMap["CoolDownGroup"], wxPG_LABEL, 0);
	//m_skillItemWindow["CategoryType"] = new wxIntProperty(skillNameMap["CategoryType"], wxPG_LABEL, 0);
	//m_skillItemWindow["CategoryVariable"] = new wxIntProperty(skillNameMap["CategoryVariable"], wxPG_LABEL, 0);
	//m_skillItemWindow["IsAutoFaceTarget"] = new wxIntProperty(skillNameMap["IsAutoFaceTarget"], wxPG_LABEL, 0);
	//m_skillItemWindow["IsAutoFaceTarget"]->SetAttribute(wxPG_BOOL_USE_CHECKBOX, true);
	//m_skillItemWindow["CastTime"] = new wxFloatProperty(skillNameMap["CastTime"], wxPG_LABEL, 0);
	//m_skillItemWindow["CastTake"] = new wxIntProperty(skillNameMap["CastTake"], wxPG_LABEL, 0);

	//m_skillItemWindow["CastEnhancement"] = new wxIntProperty(skillNameMap["CastEnhancement"], wxPG_LABEL, 0);
	//m_skillItemWindow["CastArmor"] = new wxIntProperty(skillNameMap["CastArmor"], wxPG_LABEL, 0);
	//m_skillItemWindow["AttackTime"] = new wxFloatProperty(skillNameMap["AttackTime"], wxPG_LABEL, 0);
	//m_skillItemWindow["AttackSTake"] = new wxIntProperty(skillNameMap["AttackSTake"], wxPG_LABEL, 0);
	//m_skillItemWindow["AttackTargetType"] = new wxIntProperty(skillNameMap["AttackTargetType"], wxPG_LABEL, 0);
	//m_skillItemWindow["AttackEnhancement"] = new wxIntProperty(skillNameMap["AttackEnhancement"], wxPG_LABEL, 0);
	//m_skillItemWindow["FloatingTimeStart"] = new wxFloatProperty(skillNameMap["FloatingTimeStart"], wxPG_LABEL, 0);
	//m_skillItemWindow["FloatTimeSpan"] = new wxFloatProperty(skillNameMap["FloatTimeSpan"], wxPG_LABEL, 0);
	//m_skillItemWindow["AttackEventTime"] = new wxFloatProperty(skillNameMap["AttackEventTime"], wxPG_LABEL, 0);
	//m_skillItemWindow["AttackEvent"] = new wxIntProperty(skillNameMap["AttackEvent"], wxPG_LABEL, 0);

	//m_skillItemWindow["SpurtStartTime"] = new wxIntProperty(skillNameMap["SpurtStartTime"], wxPG_LABEL, 0);
	//m_skillItemWindow["SpurtTimeSpan"] = new wxIntProperty(skillNameMap["SpurtTimeSpan"], wxPG_LABEL, 0);
	//m_skillItemWindow["SpurtDistanceX"] = new wxIntProperty(skillNameMap["SpurtDistanceX"], wxPG_LABEL, 0);
	//m_skillItemWindow["SpurtDistanceY"] = new wxIntProperty(skillNameMap["SpurtDistanceY"], wxPG_LABEL, 0);
	//m_skillItemWindow["SpurtDistanceZ"] = new wxIntProperty(skillNameMap["SpurtDistanceZ"], wxPG_LABEL, 0);
	//m_skillItemWindow["SpurtNoStepDown"] = new wxIntProperty(skillNameMap["SpurtNoStepDown"], wxPG_LABEL, 0);
	//m_skillItemWindow["FireTime"] = new wxIntProperty(skillNameMap["FireTime"], wxPG_LABEL, 0);
	//m_skillItemWindow["FireType"] = new wxIntProperty(skillNameMap["FireType"], wxPG_LABEL, 0);
	//m_skillItemWindow["sFireMissileID"] = new wxIntProperty(skillNameMap["sFireMissileID"], wxPG_LABEL, 0);
	//
	//m_skillItemWindow["AttackBoxGroupID1"] = new wxIntProperty(skillNameMap["AttackBoxGroupID1"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitSeq1"] = new wxIntProperty(skillNameMap["HitSeq1"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitBreakArmor1"] = new wxIntProperty(skillNameMap["HitBreakArmor1"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitAttackInfo1"] = new wxIntProperty(skillNameMap["HitAttackInfo1"], wxPG_LABEL, 0);
	//m_skillItemWindow["AttackBoxGroupID2"] = new wxIntProperty(skillNameMap["AttackBoxGroupID2"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitSeq2"] = new wxIntProperty(skillNameMap["HitSeq2"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitBreakArmor2"] = new wxIntProperty(skillNameMap["HitBreakArmor2"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitAttackInfo2"] = new wxIntProperty(skillNameMap["HitAttackInfo2"], wxPG_LABEL, 0);
	//m_skillItemWindow["AttackBoxGroupID3"] = new wxIntProperty(skillNameMap["AttackBoxGroupID3"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitSeq3"] = new wxIntProperty(skillNameMap["HitSeq3"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitBreakArmor3"] = new wxIntProperty(skillNameMap["HitBreakArmor3"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitAttackInfo3"] = new wxIntProperty(skillNameMap["HitAttackInfo3"], wxPG_LABEL, 0);

	//wxPGProperty* topAttackId =new wxStringProperty(wxT("3D Object"), wxPG_LABEL, wxT("<composed>"));
	//pid = pg->AppendIn( topId, new wxStringProperty(wxT("Triangle 1"), wxT("Triangle 1"), wxT("<composed>")) );
	//pg->AppendIn( pid, new wxVectorProperty( wxT("A"), wxPG_LABEL ) );
	//pg->AppendIn( pid, new wxVectorProperty( wxT("B"), wxPG_LABEL ) );
	//pg->AppendIn( pid, new wxVectorProperty( wxT("C"), wxPG_LABEL ) );
	///*m_skillItemWindow["AttackBoxGroupID1"] = new wxIntProperty(skillNameMap["AttackBoxGroupID1"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitSeq1"] = new wxIntProperty(skillNameMap["HitSeq1"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitBreakArmor1"] = new wxIntProperty(skillNameMap["HitBreakArmor1"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitAttackInfo1"] = new wxIntProperty(skillNameMap["HitAttackInfo1"], wxPG_LABEL, 0);
	//m_skillItemWindow["AttackBoxGroupID2"] = new wxIntProperty(skillNameMap["AttackBoxGroupID2"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitSeq2"] = new wxIntProperty(skillNameMap["HitSeq2"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitBreakArmor2"] = new wxIntProperty(skillNameMap["HitBreakArmor2"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitAttackInfo2"] = new wxIntProperty(skillNameMap["HitAttackInfo2"], wxPG_LABEL, 0);
	//m_skillItemWindow["AttackBoxGroupID3"] = new wxIntProperty(skillNameMap["AttackBoxGroupID3"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitSeq3"] = new wxIntProperty(skillNameMap["HitSeq3"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitBreakArmor3"] = new wxIntProperty(skillNameMap["HitBreakArmor3"], wxPG_LABEL, 0);
	//m_skillItemWindow["HitAttackInfo3"] = new wxIntProperty(skillNameMap["HitAttackInfo3"], wxPG_LABEL, 0);*/

	//m_skillItemWindow["CloseAttackTime"] = new wxIntProperty(skillNameMap["CloseAttackTime"], wxPG_LABEL, 0);
	//m_skillItemWindow["CloseAttackSTake"] = new wxIntProperty(skillNameMap["CloseAttackSTake"], wxPG_LABEL, 0);
	//m_skillItemWindow["seAttackEnhancement"] = new wxIntProperty(skillNameMap["seAttackEnhancement"], wxPG_LABEL, 0);
	//m_skillItemWindow["CloseAttackEventTime"] = new wxIntProperty(skillNameMap["CloseAttackEventTime"], wxPG_LABEL, 0);
	//m_skillItemWindow["CloseAttackEvent"] = new wxIntProperty(skillNameMap["CloseAttackEvent"], wxPG_LABEL, 0);

	return true;
}