#include "CListView.h"
bool CListView::registerItemWindow()
{
	m_skillItemWindow["ID"] = new wxTextCtrl(this, ESkillLVItemType_ID , "", wxDefaultPosition, wxDefaultSize, wxTE_RICH);
	m_skillItemWindow["ID"]->Hide();

	m_skillItemWindow["Level"] = new wxTextCtrl(this, ESkillLVItemType_Level , "", wxDefaultPosition, wxDefaultSize, wxTE_RICH);
	m_skillItemWindow["Level"]->Hide();
	return true;
}