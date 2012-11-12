#ifndef __MAIN_CMAINPROPGRID_H__
#define __MAIN_CMAINPROPGRID_H__
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

// Main propertygrid header.
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/propgrid/manager.h>

#include "./logic/skill/CSkillMgr.h"
#include "MainFrame.h"
#include "basedef.h"
#include "colaString.h"
#include <hash_map>

//enum ESkillLVItemType
//{
//	ESkillLVItemType_Invalid = -1,
//	ESkillLVItemType_ID,
//	ESkillLVItemType_Level,
//	ESkillLVItemType_Name,
//	ESkillLVItemType_Icon,
//	ESkillLVItemType_Descript,
//	ESkillLVItemType_Count,
//};


typedef stdext::hash_map<BSLib::stringc, wxPGProperty*> PropViewItemMap;


class CMainPropCtrl : public wxControl//wxPropertyGridManager
{
public:
	CMainPropCtrl(wxWindow *parent, const wxWindowID id,
		const wxPoint& pos, const wxSize& size,
		long style);
	bool createPropGrid();
	bool init();

	void OnSize(wxSizeEvent& event);
	void OnPropertyGridColBeginDrag( wxPropertyGridEvent& event );
	void OnPropertyGridColDragging( wxPropertyGridEvent& event );
	void OnPropertyGridColEndDrag( wxPropertyGridEvent& event );

	//ListViewItemMap *getSkillItemMap(){return &m_skillItemWindow;}
	//ListViewItemMap *getEotItemMap(){return &m_eotItemWindow;}
	//ListViewItemMap *getAuraItemMap(){return &m_auraItemWindow;}

	bool showGridPage(ECreateItemType _type, bool show = true);
	void finalizePanel( bool wasCreated = true);

private:
	bool _appendSkillProp();

	bool registerSkillProp();

private:
	//grid ui
	wxPropertyGridManager *m_pPropManager;
	wxPanel* m_panel;
	wxBoxSizer* m_topSizer;
	wxPropertyGrid			*m_pPropGrid;
	wxPropertyGridPage *m_propGridPages[ECreateItemType_Count];

	wxTextCtrl *m_propItemDesc;
private:
	PropViewItemMap m_skillItemWindow;
	PropViewItemMap m_eotItemWindow;
	PropViewItemMap m_auraItemWindow;
	//wxGridSelection *m_selTemp;

	//static BSLib::u16	sm_nameItemWidth;
	DECLARE_EVENT_TABLE()
};
#endif