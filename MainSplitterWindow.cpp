#include "MainSplitterWindow.h"
#include "icon1.xpm"
#include "icon2.xpm"
#include "unchecked.xpm"
#include "checked.xpm"

BEGIN_EVENT_TABLE(CMainSplitterWindow, wxSplitterWindow)
	EVT_SPLITTER_SASH_POS_CHANGED(wxID_ANY, CMainSplitterWindow::OnPositionChanged)
	EVT_SPLITTER_SASH_POS_CHANGING(wxID_ANY, CMainSplitterWindow::OnPositionChanging)

	EVT_SPLITTER_DCLICK(wxID_ANY, CMainSplitterWindow::OnDClick)

	EVT_SPLITTER_UNSPLIT(wxID_ANY, CMainSplitterWindow::OnUnsplitEvent)
END_EVENT_TABLE()


CMainSplitterWindow::CMainSplitterWindow(wxWindow * parent)
	:wxSplitterWindow(parent,wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3DSASH, wxT("Splitter")),
	m_parentFrame(parent)
{
	//
}

void CMainSplitterWindow::OnPositionChanged(wxSplitterEvent& event)
{
	//
}
void CMainSplitterWindow::OnPositionChanging(wxSplitterEvent& event)
{
	//
}
void CMainSplitterWindow::OnDClick(wxSplitterEvent& event)
{
	//
}
void CMainSplitterWindow::OnUnsplitEvent(wxSplitterEvent& event)
{
	//
}

BEGIN_EVENT_TABLE(CTreeView, wxTreeCtrl)
	EVT_TREE_ITEM_EXPANDED(ESPELL_TREE_CTRL_ID, CTreeView::OnItemExpanded)
	EVT_TREE_ITEM_EXPANDING(ESPELL_TREE_CTRL_ID, CTreeView::OnItemExpanding)
	EVT_TREE_ITEM_MENU(ESPELL_TREE_CTRL_ID, CTreeView::OnItemMenu)
END_EVENT_TABLE()
void CTreeView::OnItemExpanded(wxTreeEvent& event)
{
	event.Skip();
}
void CTreeView::OnItemExpanding(wxTreeEvent& event)
{
	event.Skip();
}
void CTreeView::OnItemMenu(wxTreeEvent& event)
{
	wxTreeItemId itemId = event.GetItem();
	wxCHECK_RET( itemId.IsOk(), "should have a valid item" );

	TreeItemData *item = (TreeItemData *)GetItemData(itemId);
	wxPoint clientpt = event.GetPoint();
	wxPoint screenpt = ClientToScreen(clientpt);

	wxLogMessage(wxT("OnItemMenu for item \"%s\" at screen coords (%i, %i)"),
		item->GetDesc(), screenpt.x, screenpt.y);

	//ShowMenu(itemId, clientpt);
	event.Skip();
}
CTreeView::CTreeView(wxWindow *parent, const wxWindowID id,
							 const wxPoint& pos, const wxSize& size,
							 long style)
							 : wxTreeCtrl(parent, id, pos, size, style)
{
	//
}

void CTreeView::initTreeView()
{
	//
	createImageSet();
}
void CTreeView::createImageSet(BSLib::u16 size)
{
	//if (size == -1)
	//{
	//	SetImageList(NULL);
	//	return;
	//}
	//if ( size == 0 )
	//	size = m_imageSize;
	//else
	//	m_imageSize = size;

	//// should correspond to TreeCtrlIcon_xxx enum
	wxIcon icons[2];
	icons[0] = wxIcon(icon1_xpm);
	icons[1] = wxIcon(icon2_xpm);

	// Make an image list containing small icons
	wxImageList *images = new wxImageList(size, size, true);
	for ( size_t i = 0; i < WXSIZEOF(icons); i++ )
	{
		int sizeOrig = icons[0].GetWidth();
		if ( size == sizeOrig )
		{
			images->Add(icons[i]);
		}
		else
		{
			images->Add(wxBitmap(wxBitmap(icons[i]).ConvertToImage().Rescale(size, size)));
		}
	}

	//AssignImageList(images);

	//wxImageList *states;

	////if (m_alternateStates)
	////{
	////	wxIcon icons[5];
	////	icons[0] = wxIcon(state1_xpm);  // yellow
	////	icons[1] = wxIcon(state2_xpm);  // green
	////	icons[2] = wxIcon(state3_xpm);  // red
	////	icons[3] = wxIcon(state4_xpm);  // blue
	////	icons[4] = wxIcon(state5_xpm);  // black

	////	int width  = icons[0].GetWidth(),
	////		height = icons[0].GetHeight();

	////	// Make an state image list containing small icons
	////	states = new wxImageList(width, height, true);

	////	for ( size_t i = 0; i < WXSIZEOF(icons); i++ )
	////		states->Add(icons[i]);
	////}
	////else
	//{
	//	wxIcon icons[2];
	//	icons[0] = wxIcon(unchecked_xpm);
	//	icons[1] = wxIcon(checked_xpm);

	//	int width  = icons[0].GetWidth(),
	//		height = icons[0].GetHeight();

	//	// Make an state image list containing small icons
	//	states = new wxImageList(width, height, true);

	//	for ( size_t i = 0; i < WXSIZEOF(icons); i++ )
	//		states->Add(icons[i]);
	//}

	//AssignStateImageList(states);

	int image = 0;// CTreeView::TreeCtrlIcon_Folder;
	wxTreeItemId rootId = AddRoot(wxT("Root"), image, image, new TreeItemData(wxT("Root item")));
	//AddRoot(wxT("Root1"), image, image, new TreeItemData(wxT("Root item")));
	wxTreeItemId id = AppendItem(rootId, wxT("Child"), image, image, new TreeItemData(wxT("Child item1")));
	AppendItem(rootId, wxT("Child2"), image, image, new TreeItemData(wxT("Child item2")));
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

}