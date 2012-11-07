#ifndef __MAIN_SPLITTER_WINDOW_H__
#define __MAIN_SPLITTER_WINDOW_H__
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/splitter.h"
#include "wx/treectrl.h"
#include "MainFrame.h"
#include "basedef.h"

class CMainSplitterWindow : public wxSplitterWindow
{
public:
	CMainSplitterWindow(wxWindow* parent);

	// event handlers
	void OnPositionChanged(wxSplitterEvent& event);
	void OnPositionChanging(wxSplitterEvent& event);
	void OnDClick(wxSplitterEvent& event);
	void OnUnsplitEvent(wxSplitterEvent& event);

private:
	DECLARE_EVENT_TABLE()
	wxDECLARE_NO_COPY_CLASS(CMainSplitterWindow);
private:
	wxWindow*	m_parentFrame;
};

class TreeItemData : public wxTreeItemData
{
public:
	TreeItemData(const wxString& desc) : m_desc(desc) { }

	void ShowInfo(wxTreeCtrl *tree);
	const wxChar *GetDesc() const { return m_desc.c_str(); }

private:
	wxString m_desc;
};


class CTreeView : public wxTreeCtrl
{
public:
	enum
	{
		TreeCtrlIcon_File,
		TreeCtrlIcon_FileSelected,
		TreeCtrlIcon_Folder,
		TreeCtrlIcon_FolderSelected,
		TreeCtrlIcon_FolderOpened
	};

public:
	CTreeView(wxWindow *parent, const wxWindowID id,
		const wxPoint& pos, const wxSize& size,
		long style);
	virtual ~CTreeView()
	{
		//
	}

	void initTreeView();
	void createImageSet(BSLib::u16 size = 16);

	void OnItemExpanded(wxTreeEvent& event);
	void OnItemExpanding(wxTreeEvent& event);
	void OnTreeRightClick(wxTreeEvent& event);
	void OnItemRightClicked(wxTreeEvent& event);
	

	void ShowMenu(wxTreeItemId id, const wxPoint& pt);

	wxTreeItemId getSkillRootID(){return skillRootId;}
	wxTreeItemId getAuraRootID(){return auraRootId;}
	wxTreeItemId getEotRootID(){return eotRootId;}
private:
	BSLib::u16		m_imageSize;

	wxTreeItemId eotRootId;
	wxTreeItemId auraRootId;
	wxTreeItemId skillRootId;
private:
	DECLARE_EVENT_TABLE()
};


#endif