#include "MainSplitterWindow.h"
#include "FolderOpened.xpm"
#include "FolderClosed.xpm"
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
#define MENU_LINK(name) EVT_MENU(CTreeView_##name, CMainFrame::On##name)

BEGIN_EVENT_TABLE(CTreeView, wxTreeCtrl)
	EVT_TREE_ITEM_EXPANDED(ESPELL_TREE_CTRL_ID, CTreeView::OnItemExpanded)
	EVT_TREE_ITEM_EXPANDING(ESPELL_TREE_CTRL_ID, CTreeView::OnItemExpanding)
	EVT_TREE_ITEM_MENU(ESPELL_TREE_CTRL_ID, CTreeView::OnTreeRightClick)
	EVT_TREE_ITEM_RIGHT_CLICK(ESPELL_TREE_CTRL_ID, CTreeView::OnItemRightClicked)

	MENU_LINK(CreateItemOnListView)
END_EVENT_TABLE()
void CTreeView::OnItemExpanded(wxTreeEvent& event)
{
	event.Skip();
}
void CTreeView::OnItemRightClicked(wxTreeEvent& event)
{
	wxTreeItemId clickID = event.GetItem();
	wxPoint clientpt = event.GetPoint();
	wxPoint screenpt = /*ClientToScreen*/(clientpt);

	if (clickID == skillRootId ||
		clickID == eotRootId ||
		clickID == auraRootId)
	{
		ShowMenu(clickID, screenpt);
	}
	event.Skip();
}
void CTreeView::OnItemExpanding(wxTreeEvent& event)
{
	event.Skip();
}
void CTreeView::OnTreeRightClick(wxTreeEvent& event)
{
	if (event.GetItem().IsOk())
	{
		event.Skip();
		return;
	}
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

void CTreeView::ShowMenu(wxTreeItemId id, const wxPoint& pt)
{
	wxString title;
	if ( id.IsOk() )
	{
		title << wxT("Create ") << GetItemText(id);
	}
	else
	{
		title = wxT("Menu for no particular item");
	}

	wxMenu menu;
	menu.Append(CTreeView_CreateItemOnListView, title);
	//menu.AppendSeparator();
	//menu.Append(TreeTest_Highlight, wxT("&Highlight item"));
	//menu.Append(TreeTest_Dump, wxT("&Dump"));

	PopupMenu(&menu, pt);
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
	icons[0] = wxIcon(FolderClosed_xpm);
	icons[1] = wxIcon(FolderOpened_xpm);

	// Make an image list containing small icons
	wxImageList *images = new wxImageList(size, size, true);
	for ( size_t i = 0; i < WXSIZEOF(icons); i++ )
	{
		int sizeOrig = icons[i].GetWidth();
		//if ( size == sizeOrig )
		{
			images->Add(icons[i]);
		}
		/*else
		{
			wxBitmap bitMapIcon;
			bitMapIcon.CopyFromIcon(icons[i]);
			images->Add(wxBitmap(bitMapIcon.ConvertToImage().Rescale(size, size)));
		}*/
	}

	AssignImageList(images);

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

	wxTreeItemId rootID = AddRoot(wxT(""), image, image, NULL);
	skillRootId = AppendItem(rootID, wxT("技能"), image, image, new TreeItemData(wxT("Root item")));
	//AddRoot(wxT("Root1"), image, image, new TreeItemData(wxT("Root item")));
	wxTreeItemId id = AppendItem(skillRootId, wxT("Child"), image, image, new TreeItemData(wxT("Child item1")));
	AppendItem(skillRootId, wxT("Child2"), image, image, new TreeItemData(wxT("Child item2")));

	eotRootId = AppendItem(rootID, wxT("EOT"), image, image, new TreeItemData(wxT("Root item")));
	auraRootId = AppendItem(rootID, wxT("Aura"), image, image, new TreeItemData(wxT("Root item")));
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
	
	itemCol.SetText(wxT("名称"));
	itemCol.SetImage(-1);
	this->InsertColumn(0, itemCol);

	itemCol.SetText(wxT("值"));
	itemCol.SetImage(-1);
	this->InsertColumn(1, itemCol);

	this->SetColumnWidth(0, sm_nameItemWidth);
	this->SetColumnWidth(1, GetSize().GetWidth() - sm_nameItemWidth);

}