
#include "CModifierSeqListView.h"
#include "CModifierEditor.h"

BEGIN_EVENT_TABLE(CModifierSeqListView, wxGrid)
	EVT_SIZE(		CModifierSeqListView::OnSize)
	//EVT_GRID_CELL_LEFT_CLICK(CModifierSeqListView::OnCellLeftClick )
END_EVENT_TABLE()



CModifierSeqListView::CModifierSeqListView(wxWindow *parent, const wxWindowID id,
					 const wxPoint& pos, const wxSize& size,
					 long style)
					 : wxGrid(parent, id, pos, size, style)
{
	SetRowLabelSize(0);
}

void CModifierSeqListView::initWithReportItems()
{
	DisableDragColSize();
	DisableDragColMove();
	DisableDragRowSize();
	DisableDragGridSize();

	CreateGrid(8, 4, wxGridSelectRows);
	SetColLabelValue(0, wxT("修改器ID"));
	SetColLabelValue(1, wxT("参数1"));
	SetColLabelValue(2, wxT("参数2"));
	SetColLabelValue(3, wxT("参数3"));
	
	wxGridCellAttr *pAttr = new wxGridCellAttr;
	
	pAttr->SetEditor(new CTextButtonEditor(wxT("编辑")));
	//pAttr->SetRenderer(new CGridCellTextButtonRenderer);
	SetColAttr(0, pAttr);

	wxGridSizesInfo info;
	info.m_sizeDefault = 30;
	SetRowSizes(info);
}


void CModifierSeqListView::OnSize(wxSizeEvent& event)
{
	BSLib::s32 wc = event.GetSize().GetWidth();
	BSLib::s32 colSize = wc * 0.25;
	SetColSize(0, colSize);
	SetColSize(1, colSize);
	SetColSize(2, colSize);
	SetColSize(3, colSize);
	DisableCellEditControl();
	event.Skip();
}
void CModifierSeqListView::OnCellLeftClick(wxGridEvent& ev)
{
//	// This forces the cell to go into edit mode directly
//	m_waitForSlowClick = TRUE;
//	SetGridCursor(ev.GetRow(), ev.GetCol());
//	// Store the click co-ordinates in the editor if possible
//	// if an editor has created a ClientData area, we presume it's
//	// a wxPoint and we store the click co-ordinates
//	wxGridCellEditor* pEditor  = GetCellEditor(ev.GetRow(), ev.GetCol());
//	wxPoint* pClickPoint = (wxPoint*)pEditor->GetClientData();
//	if (pClickPoint)
//	{
//		*pClickPoint = ClientToScreen(ev.GetPosition());
//#ifndef __WINDOWS__
//		EnableCellEditControl(true);
//#endif
//	}
//	// hack to prevent selection from being lost when click combobox
//	if (ev.GetCol() == 0 && IsInSelection(ev.GetRow(), ev.GetCol()))
//	{
//		//m_selTemp = m_selection;
//		m_selection = NULL;
//	}
//	pEditor->DecRef();
//	ev.Skip();
}