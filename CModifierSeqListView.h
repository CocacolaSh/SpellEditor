#ifndef __CMODIFIERSEQLISTVIEW_H__
#define __CMODIFIERSEQLISTVIEW_H__
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

//#include "wx/dataview.h"
#include "wx/grid.h"
#include "wx/laywin.h"
#include "MainFrame.h"
#include "basedef.h"

class CModifierSeqListView : public wxGrid
{
public:
	CModifierSeqListView(wxWindow *parent, const wxWindowID id,
		const wxPoint& pos, const wxSize& size,
		long style);

	void initWithReportItems();

	void OnCellLeftClick(wxGridEvent& event);
	void OnSize(wxSizeEvent& event);
private:

	DECLARE_EVENT_TABLE()
};
#endif