#ifndef __MAIN_CMODIFIEREDITOR_H__
#define __MAIN_CMODIFIEREDITOR_H__
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
//#include "wx/dataview.h"
#include "wx/grid.h"
#include "wx/laywin.h"

class CGridCellTextButtonRenderer : public wxGridCellStringRenderer
{
public:
	CGridCellTextButtonRenderer(wxLayoutAlignment border = wxLAYOUT_NONE) : 
	  m_border(border) {}
	  virtual void Draw(wxGrid& grid,
		  wxGridCellAttr& attr,
		  wxDC& dc,
		  const wxRect& rect,
		  int row, int col,
		  bool isSelected);
	  virtual wxGridCellRenderer *Clone() const
	  { return new CGridCellTextButtonRenderer; }
private:
	wxLayoutAlignment m_border;
};


#define wxTB_SUBID1                     2
#define wxTB_SUBID2                     3
class STextButton : public wxControl
{
public:
	STextButton(wxWindow *parent, wxWindowID id,
		const wxString& value = wxEmptyString,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = 0,
		const wxString& name = wxEmptyString);
	virtual ~STextButton()
	{
		delete m_textCtrl;
		delete m_button;
	}
	// Initialize member variables
	virtual void Init()
	{
		m_nRow = m_nCol = -1; 
		m_pGrid = NULL;
	}

	virtual wxWindow *GetControl() { return this; }
	void SetCellData(int nRow, int nCol, wxGrid* pGrid)
	{
		m_nRow = nRow;
		m_nCol = nCol;
		m_pGrid = pGrid;
	}

	wxString GetValue(){return m_textCtrl->GetValue();}
	void SetValue(wxString &valueStr){m_textCtrl->SetValue(valueStr);}
	void OnSize(wxSizeEvent& event);

	// On mouse left up, set the value and close the popup
	void OnMouseClick(wxMouseEvent& WXUNUSED(event))
	{
		//int checkItem = HitTest(event.GetPosition());

	}
	void OnButton(wxCommandEvent& (event));
	virtual wxSize DoGetBestSize() const {
		wxSize sz = m_textCtrl->GetBestSize();
		wxSize sz2 = m_button->GetBestSize();
		return wxSize( sz2.GetWidth() + sz.GetWidth() ,
			sz2.GetHeight() );
	}
private:
	DECLARE_EVENT_TABLE()
	int m_nRow;
	int m_nCol; 
	wxGrid* m_pGrid;
	wxTextCtrl *m_textCtrl;
	wxButton *m_button;
};
class CTextButtonEditor : public wxGridCellEditor
{
public:
	CTextButtonEditor(wxString buttonLabel, bool allowOthers = true);
	virtual void Create(wxWindow* parent,
		wxWindowID id,
		wxEvtHandler* evtHandler);
	virtual void PaintBackground(const wxRect& rectCell, wxGridCellAttr *attr);

	virtual void BeginEdit(int row, int col, wxGrid* grid);
	virtual bool EndEdit(int row, int col, const wxGrid* grid,
		const wxString& oldval, wxString *newval);
	virtual void ApplyEdit(int row, int col, wxGrid* grid);
	//virtual void 	SetSize (const wxRect &rect);

	virtual void Reset();
	//virtual void SetSize (const wxRect &rect);

	virtual wxGridCellEditor *Clone() const;
	virtual wxString GetValue() const;
protected:
	wxPoint m_pointActivate;
	STextButton *TextCtrl() const { return (STextButton*)m_control; }
	wxString   m_value;
	wxString   m_btnLabel;
	bool            m_allowOthers;
};
#endif