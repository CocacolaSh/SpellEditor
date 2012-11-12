#ifndef __MAIN_FRAME_H__
#define __MAIN_FRAME_H__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/treectrl.h"
#include "wx/listctrl.h"
#include "basedef.h"

class CMainSplitterWindow;
class CListView;
class CTreeView;
class CMainPropCtrl;

enum 
{
	ESPELL_TREE_CTRL_ID = 1,
	ESPELL_LIST_CTRL_ID,
};

enum ECreateItemType
{
	ECreateItemType_Skill = 0,
	ECreateItemType_Aura,
	ECreateItemType_Eot,
	ECreateItemType_Count,
};

enum ETreeViewID
{
	CTreeView_CreateItemOnListView = 100,
	PGID
};
class CMainFrame : public wxFrame
{
public:
	CMainFrame(const wxString& title);

	bool initPanel();

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnOpenFile(wxCommandEvent& event);
	void OnButtonOk(wxCommandEvent& event);

	void OnSize(wxSizeEvent& event);
	void OnGridSize(wxSizeEvent& event);

	void OnCreateItemOnListView(wxCommandEvent& event);
private:
	DECLARE_EVENT_TABLE()

private:
	static BSLib::f32	m_spliterPosPct;
	CMainSplitterWindow	*m_splitterWindow;
	CTreeView *m_leftWindow;
	CMainPropCtrl *m_rightWindow;

	wxPanel*		m_panel;
};
#endif