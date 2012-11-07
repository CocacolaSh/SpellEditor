#include "CListView.h"
#include "./logic/skill/CSkillMgr.h"
#include "Process_error.h"
//#include "wx/richtext/richtextctrl.h"


BSLib::u16 CListView::sm_nameItemWidth = 250;

BEGIN_EVENT_TABLE(CListView, wxGrid)
EVT_SIZE(		CListView::OnSize)
EVT_GRID_CELL_LEFT_CLICK(CListView::OnCellLeftClick )
END_EVENT_TABLE()



CListView::CListView(wxWindow *parent, const wxWindowID id,
					 const wxPoint& pos, const wxSize& size,
					 long style)
					 : wxGrid(parent, id, pos, size, style), m_selTemp(NULL)
					 //m_attr(*wxBLUE, *wxLIGHT_GREY, wxNullFont)
{
	SetRowLabelSize(0);
}


void CListView::OnSize(wxSizeEvent& event)
{
	//this->SetColumnWidth(1, GetSize().GetWidth() - sm_nameItemWidth);
	event.Skip();
}
void CListView::OnCellLeftClick(wxGridEvent& ev)
{
	// This forces the cell to go into edit mode directly
	m_waitForSlowClick = TRUE;
	SetGridCursor(ev.GetRow(), ev.GetCol());
	// Store the click co-ordinates in the editor if possible
	// if an editor has created a ClientData area, we presume it's
	// a wxPoint and we store the click co-ordinates
	wxGridCellEditor* pEditor  = GetCellEditor(ev.GetRow(), ev.GetCol());
	wxPoint* pClickPoint = (wxPoint*)pEditor->GetClientData();
	if (pClickPoint)
	{
		*pClickPoint = ClientToScreen(ev.GetPosition());
#ifndef __WINDOWS__
		EnableCellEditControl(true);
#endif
	}
	// hack to prevent selection from being lost when click combobox
	if (ev.GetCol() == 0 && IsInSelection(ev.GetRow(), ev.GetCol()))
	{
		m_selTemp = m_selection;
		m_selection = NULL;
	}
	pEditor->DecRef();
	ev.Skip();
}
void CListView::initWithReportItems()
{
	//
	DisableDragColSize();
	DisableDragColMove();
	DisableDragRowSize();
	DisableDragGridSize();
	CreateGrid(0, 2, wxGridSelectRows);
	SetColLabelValue(0, wxT("Ãû³Æ"));
	SetColLabelValue(1, wxT("Öµ"));

	wxGridSizesInfo info;
	info.m_sizeDefault = 20;
	SetRowSizes(info);

	wxGridCellAttr *attrRO = new wxGridCellAttr;
	attrRO->SetReadOnly();
	SetColAttr(0, attrRO);

	registerItemWindow();

}
bool CListView::_createItemSkill()
{
	std::vector <SKILLEDITOR::SListItemShowData> showDataVec = SKILLEDITOR::sSkillMgr.getShowData();
	BSLib::s32 rowSize = showDataVec.size();
	InsertRows(0, rowSize);
	for (BSLib::s32 i = 0; i < rowSize; ++i)
	{
		wxString column1Str = wxString(wxConvUTF8.cMB2WC(showDataVec[i].showName.c_str()), *wxConvCurrent);
		SetCellValue(i, 0, column1Str);

		if (m_skillItemWindow[showDataVec[i].indexName])
		{
			SetAttr(i, 1, m_skillItemWindow[showDataVec[i].indexName]->m_cellAttr);
			//SetCellRenderer(i, 1, m_skillItemWindow[showDataVec[i].indexName]->m_cellRenderer);
		}
		
		//BSLib::s64 index = this->InsertItem(i, column1Str, -1);
		//wxRect rect;
		//GetSubItemRect(index, 0, rect);

		//BSLib::s32 width = GetColumnWidth(1);
		//CListViewItem lvItem;
		//lvItem.init(m_skillItemWindow, showDataVec[i].indexName, column1Str, rect.GetRightTop(), rect);
		////SetItem()
		//this->InsertItem(i, lvItem);
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