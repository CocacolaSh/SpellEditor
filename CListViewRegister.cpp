#include "CListView.h"
#include "CCustomGridCellCtrl.h"
#include "CModifierEditor.h"

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

bool CListView::registerItemWindow()
{
	m_skillItemWindow["ID"] = new SCustomLVItemInfo();
	m_skillItemWindow["ID"]->m_cellAttr = new wxGridCellAttr;
	m_skillItemWindow["ID"]->m_cellAttr ->SetReadOnly();

	/*m_skillItemWindow["SkillID"] = new wxGridCellAttr;
	m_skillItemWindow["SkillID"]->SetEditor(new wxGridCellTextEditor);*/

	m_skillItemWindow["SkillLevel"] =  new SCustomLVItemInfo();
	m_skillItemWindow["SkillLevel"]->m_cellAttr = new wxGridCellAttr;
	m_skillItemWindow["SkillLevel"]->m_cellAttr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
	m_skillItemWindow["SkillLevel"]->m_cellAttr->SetRenderer(new CGridCellNumberRenderer);//m_cellRenderer = new wxGridCellNumberRenderer;
	m_skillItemWindow["SkillLevel"]->m_cellAttr->SetEditor(new wxGridCellNumberEditor(1, 100));

	m_skillItemWindow["ScenarioType"] = new SCustomLVItemInfo();
	m_skillItemWindow["ScenarioType"]->m_cellAttr = new wxGridCellAttr;
	m_skillItemWindow["ScenarioType"]->m_cellAttr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
	m_skillItemWindow["ScenarioType"]->m_cellAttr->SetEditor( new CFastComboEditor(WXSIZEOF(ScenarioTypeArr),
		ScenarioTypeArr));
	m_skillItemWindow["ScenarioType"]->m_cellAttr->SetRenderer(new CGridCellChoiceRenderer);//m_cellRenderer = new wxGridCellStringRenderer;

	m_skillItemWindow["SkillName"] = new SCustomLVItemInfo();
	m_skillItemWindow["SkillName"]->m_cellAttr = new wxGridCellAttr;
	m_skillItemWindow["SkillName"]->m_cellAttr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
	m_skillItemWindow["SkillName"]->m_cellAttr->SetEditor(new CCheckComboEditor(WXSIZEOF(severities),
		severities));
	m_skillItemWindow["SkillName"]->m_cellAttr->SetRenderer(new CGridCellChoiceRenderer);//m_cellRenderer = new wxGridCellStringRenderer;

	m_skillItemWindow["IsElite"] = new SCustomLVItemInfo();
	m_skillItemWindow["IsElite"]->m_cellAttr = new wxGridCellAttr;
	m_skillItemWindow["IsElite"]->m_cellAttr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
	m_skillItemWindow["IsElite"]->m_cellAttr->SetEditor(new wxGridCellBoolEditor);
	m_skillItemWindow["IsElite"]->m_cellAttr->SetRenderer(new wxGridCellBoolRenderer);//m_cellRenderer = new wxGridCellBoolRenderer;

	m_skillItemWindow["IsEmblem"] = new SCustomLVItemInfo();
	m_skillItemWindow["IsEmblem"]->m_cellAttr = new wxGridCellAttr;
	m_skillItemWindow["IsEmblem"]->m_cellAttr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
	m_skillItemWindow["IsEmblem"]->m_cellAttr->SetEditor(new wxGridCellBoolEditor);
	m_skillItemWindow["IsEmblem"]->m_cellAttr->SetRenderer(new wxGridCellBoolRenderer);

	m_skillItemWindow["IsIgnoreHard"] = new SCustomLVItemInfo();
	m_skillItemWindow["IsIgnoreHard"]->m_cellAttr = new wxGridCellAttr;
	m_skillItemWindow["IsIgnoreHard"]->m_cellAttr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
	m_skillItemWindow["IsIgnoreHard"]->m_cellAttr->SetEditor(new wxGridCellBoolEditor);
	m_skillItemWindow["IsIgnoreHard"]->m_cellAttr->SetRenderer(new wxGridCellBoolRenderer);

	m_skillItemWindow["SkillPattern"] = new SCustomLVItemInfo();
	m_skillItemWindow["SkillPattern"]->m_cellAttr = new wxGridCellAttr;
	m_skillItemWindow["SkillPattern"]->m_cellAttr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
	m_skillItemWindow["SkillPattern"]->m_cellAttr->SetEditor(new wxGridCellEnumEditor(ScenarioTypeArr[1]));
	m_skillItemWindow["SkillPattern"]->m_cellAttr->SetRenderer(new wxGridCellStringRenderer);

	m_skillItemWindow["SeqAfterLearn"] = new SCustomLVItemInfo();
	m_skillItemWindow["SeqAfterLearn"]->m_cellAttr = new wxGridCellAttr;
	m_skillItemWindow["SeqAfterLearn"]->m_cellAttr->SetAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
	m_skillItemWindow["SeqAfterLearn"]->m_cellAttr->SetEditor(new CTextButtonEditor(wxT("±à¼­")));
	m_skillItemWindow["SeqAfterLearn"]->m_cellAttr->SetRenderer(new wxGridCellStringRenderer);
	return true;
}