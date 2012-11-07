#include "MainFrame.h"
#include "MainSplitterWindow.h"
#include "CListView.h"
#include "basedef.h"
#include "Process_error.h"
#include "wx/display.h"

#define MENU_LINK(name) EVT_MENU(CTreeView_##name, CMainFrame::On##name)
BEGIN_EVENT_TABLE(CMainFrame, wxFrame)
	EVT_MENU(wxID_ABOUT, CMainFrame::OnAbout)
	EVT_MENU(wxID_EXIT, CMainFrame::OnQuit)
	EVT_MENU(wxID_OPEN, CMainFrame::OnOpenFile)
	EVT_SIZE(			CMainFrame::OnSize)
	EVT_BUTTON(wxID_OK, CMainFrame::OnButtonOk)
	MENU_LINK(CreateItemOnListView)
END_EVENT_TABLE()
BSLib::f32 CMainFrame::m_spliterPosPct = 0.2f;

void CMainFrame::OnAbout( wxCommandEvent& event)
{
	wxString aboutStr;
	aboutStr.Printf(wxT("This version is %s"), wxVERSION_STRING);
	wxMessageBox(aboutStr, wxT("About"), wxOK, this);
}

void CMainFrame::OnQuit( wxCommandEvent& event)
{
	Close();
}

void CMainFrame::OnOpenFile(wxCommandEvent& event)
{
	wxString msg;
	msg.Printf(wxT("openFile"));
	wxMessageBox(msg, wxT("Open"), wxOK, this);
}
void CMainFrame::OnCreateItemOnListView(wxCommandEvent& event)
{
	wxString selText = wxT("");
	LOG_PROCESS_ERROR (m_leftWindow && m_rightWindow);

	wxTreeItemId selItem = m_leftWindow->GetSelection();

	LOG_PROCESS_ERROR (selItem.IsOk());

	if (selItem == m_leftWindow->getSkillRootID())
	{
		m_rightWindow->CreateItem(ECreateItemType_Skill);
	}else if (selItem == m_leftWindow->getAuraRootID())
	{
		m_rightWindow->CreateItem(ECreateItemType_Aura);
	}else if (selItem == m_leftWindow->getEotRootID())
	{
		m_rightWindow->CreateItem(ECreateItemType_Eot);
	}

	selText = m_leftWindow->GetItemText(selItem);
	wxLogMessage(selText);
	return;
Exit0:
	return;
}
void CMainFrame::OnSize(wxSizeEvent& event)
{
	wxSize size = GetClientSize();

	m_panel->SetSize(size);
	m_splitterWindow->SetSize(size);
	/*m_leftWindow->SetSize(0, 0, size.x * m_spliterPosPct, size.y);
	m_rightWindow->SetSize(size.x * m_spliterPosPct, 0, size.x * (1 - m_spliterPosPct) , size.y);*/

	event.Skip();
}
void CMainFrame::OnButtonOk(wxCommandEvent &event)
{
	//
}

bool CMainFrame::initPanel()
{
	BSLib::s32 width = 0;

	wxSize clientSize = GetClientSize();
	width = clientSize.GetWidth();

	m_panel = new wxPanel(this,wxID_ANY, wxDefaultPosition, clientSize, wxSIMPLE_BORDER, wxT("MainPanel"));
	LOG_PROCESS_ERROR(m_panel);

	m_splitterWindow = new CMainSplitterWindow(m_panel);
	LOG_PROCESS_ERROR(m_splitterWindow != NULL);

	m_splitterWindow->SetSize(clientSize);
	//m_splitterWindow->SetSashGravity(1.0);

	m_leftWindow = new CTreeView(m_splitterWindow, ESPELL_TREE_CTRL_ID,  wxDefaultPosition, wxDefaultSize,
		wxTR_HIDE_ROOT | wxTR_DEFAULT_STYLE | wxTR_HAS_BUTTONS | wxTR_SINGLE);
	m_leftWindow->initTreeView();

	m_rightWindow = new CListView(m_splitterWindow, ESPELL_LIST_CTRL_ID, wxDefaultPosition, wxDefaultSize,wxLC_REPORT | wxLC_VRULES | wxLC_HRULES);
	m_rightWindow->initWithReportItems();

	m_splitterWindow->SplitVertically(m_leftWindow, m_rightWindow, width * m_spliterPosPct);

Exit0:
	return false;
}

CMainFrame::CMainFrame(const wxString& title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize)
{
	//wxDisplay Screen;
	//wxRect ClientRect = Screen.GetClientArea();

	//this->SetSize(ClientRect);

	m_panel = new wxPanel(this);
	initPanel();

	wxMenu *fileMenu = new wxMenu();
	wxMenu *helpMenu = new wxMenu();

	helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"),
		wxT("Show about dialog"));
	fileMenu->Append(wxID_OPEN, wxT("&Open..."), wxT("Open Spell File"));
	fileMenu->Append(wxID_EXIT, wxT("&Quit...\tF2"),
		wxT("Quit App"));
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, wxT("&File"));
	menuBar->Append(helpMenu, wxT("&Help"));
	SetMenuBar(menuBar);

	CreateStatusBar(2);
	SetStatusText(wxT("Welcome to use spelleditor!"));
}