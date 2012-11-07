#ifndef __MAIN_LISTVIEW_WINDOW_H__
#define __MAIN_LISTVIEW_WINDOW_H__
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "wx/splitter.h"
#include "wx/listctrl.h"
#include "wx/dataview.h"
#include "MainFrame.h"
#include "basedef.h"
#include "colaString.h"
#include <hash_map>

enum ESkillLVItemType
{
	ESkillLVItemType_Invalid = -1,
	ESkillLVItemType_ID,
	ESkillLVItemType_Level,
	ESkillLVItemType_Name,
	ESkillLVItemType_Icon,
	ESkillLVItemType_Descript,
	ESkillLVItemType_Count,
};
typedef stdext::hash_map<BSLib::stringc, wxWindow*> ListViewItemMap;
class CListViewItem : public wxListItem
{
public:
	CListViewItem()
	{	}

	bool init(ListViewItemMap &lvMap, BSLib::stringc indexStr, wxString keyStr, const wxPoint& pos, const wxRect& size);
	~CListViewItem(){}
private:
	wxString  m_keyStr;
	wxWindow *m_subControl;
};

template<class T>
T* createWindow(wxWindow *parent, const wxWindowID id,
				const wxPoint& pos, const wxSize& size,
				long style)
{
	return new T(parent, id, pos, size, style);
}
class CListView : public wxDataViewCtrl
{
public:
	CListView(wxWindow *parent, const wxWindowID id,
		const wxPoint& pos, const wxSize& size,
		long style);

	void initWithReportItems();

	void OnSize(wxSizeEvent& event);

	bool CreateList();

	bool CreateItem(ECreateItemType _type);

	bool registerItemWindow();

	ListViewItemMap *getSkillItemMap(){return &m_skillItemWindow;}
	ListViewItemMap *getEotItemMap(){return &m_eotItemWindow;}
	ListViewItemMap *getAuraItemMap(){return &m_auraItemWindow;}
private:
	bool _createItemSkill();
private:
	ListViewItemMap m_skillItemWindow;
	ListViewItemMap m_eotItemWindow;
	ListViewItemMap m_auraItemWindow;

	static BSLib::u16	sm_nameItemWidth;
	DECLARE_EVENT_TABLE()
};
#endif