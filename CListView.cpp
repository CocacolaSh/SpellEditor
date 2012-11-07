#include "CListView.h"
#include "./logic/skill/CSkillMgr.h"
#include "Process_error.h"
//#include "wx/richtext/richtextctrl.h"

bool CListViewItem::init(ListViewItemMap &lvMap, BSLib::stringc indexStr, wxString  keyStr, const wxPoint& pos, const wxRect& size)
{
	wxWindow *pWindow = lvMap[indexStr];
	LOG_PROCESS_ERROR(pWindow);

	m_keyStr = keyStr;
	m_subControl = pWindow;

	m_subControl->SetPosition(pos);
	//m_subControl->SetSize(size);
	m_subControl->Show(true);
	return true;
Exit0:
	return false;
}

BSLib::u16 CListView::sm_nameItemWidth = 250;
BEGIN_EVENT_TABLE(CListView, wxListCtrl)
EVT_SIZE(		CListView::OnSize)
END_EVENT_TABLE()



CListView::CListView(wxWindow *parent, const wxWindowID id,
					 const wxPoint& pos, const wxSize& size,
					 long style)
					 : wxListCtrl(parent, id, pos, size, style)
					 //m_attr(*wxBLUE, *wxLIGHT_GREY, wxNullFont)
{
	//
}


void CListView::OnSize(wxSizeEvent& event)
{
	this->SetColumnWidth(1, GetSize().GetWidth() - sm_nameItemWidth);
	event.Skip();
}
void CListView::initWithReportItems()
{
	//
	wxListItem itemCol;

	itemCol.SetText(wxT("Ãû³Æ"));
	itemCol.SetImage(-1);
	this->InsertColumn(0, itemCol);

	itemCol.SetText(wxT("Öµ"));
	itemCol.SetImage(-1);
	this->InsertColumn(1, itemCol);

	this->SetColumnWidth(0, sm_nameItemWidth);
	this->SetColumnWidth(1, GetSize().GetWidth() - sm_nameItemWidth);

	registerItemWindow();

}
bool CListView::_createItemSkill()
{
	std::vector <SKILLEDITOR::SListItemShowData> showDataVec = SKILLEDITOR::sSkillMgr.getShowData();
	for (BSLib::s32 i = 0; i < showDataVec.size(); ++i)
	{
		wxString column1Str = wxString(wxConvUTF8.cMB2WC(showDataVec[i].showName.c_str()), *wxConvCurrent);
		
		BSLib::s64 index = this->InsertItem(i, column1Str, -1);
		wxRect rect;
		GetSubItemRect(index, 0, rect);

		BSLib::s32 width = GetColumnWidth(1);
		CListViewItem lvItem;
		lvItem.init(m_skillItemWindow, showDataVec[i].indexName, column1Str, rect.GetRightTop(), rect);
		//SetItem()
		this->InsertItem(i, lvItem);
	}
	return true;
}
bool CListView::CreateItem(ECreateItemType _type)
{
	switch (_type)
	{
	case ECreateItemType_Skill:
		{
			_createItemSkill();
		}
		break;
	case ECreateItemType_Eot:
		break;
	case ECreateItemType_Aura:
		break;
	default:
		break;
	}
	return true;
}