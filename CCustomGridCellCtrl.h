#ifndef __MAIN_CCUSTOMGRIDCELLCTRL_H__
#define __MAIN_CCUSTOMGRIDCELLCTRL_H__
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
//#include "wx/dataview.h"
#include "wx/grid.h"
#include "wx/combo.h"
#include "wx/laywin.h"

class CGridCellChoiceRenderer : public wxGridCellStringRenderer
{
public:
	CGridCellChoiceRenderer(wxLayoutAlignment border = wxLAYOUT_NONE) : 
	  m_border(border) {}
	  virtual void Draw(wxGrid& grid,
		  wxGridCellAttr& attr,
		  wxDC& dc,
		  const wxRect& rect,
		  int row, int col,
		  bool isSelected);
	  virtual wxGridCellRenderer *Clone() const
	  { return new CGridCellChoiceRenderer; }
private:
	wxLayoutAlignment m_border;
};

class CGridCellNumberRenderer : public wxGridCellNumberRenderer
{
public:
	  virtual void Draw(wxGrid& grid,
		  wxGridCellAttr& attr,
		  wxDC& dc,
		  const wxRect& rect,
		  int row, int col,
		  bool isSelected);
	  virtual wxGridCellRenderer *Clone() const
	  { return new CGridCellNumberRenderer; }
};

class SComboBox;

class CFastComboEditor : public wxGridCellEditor
{
public:
	CFastComboEditor(size_t count = 0,
		const wxString choices[] = NULL,	bool allowOthers = FALSE);
	virtual void Create(wxWindow* parent,
		wxWindowID id,
		wxEvtHandler* evtHandler);
	virtual void PaintBackground(const wxRect& rectCell, wxGridCellAttr *attr);

	virtual void BeginEdit(int row, int col, wxGrid* grid);
	virtual bool EndEdit(int row, int col, const wxGrid* grid,
		const wxString& oldval, wxString *newval);
	virtual void ApplyEdit(int row, int col, wxGrid* grid);

	virtual void Reset();

	// parameters string format is "item1[,item2[...,itemN]]"
	virtual void SetParameters(const wxString& params);
	void SetParameters(size_t count, const wxString choices[]);
	virtual wxGridCellEditor *Clone() const;
	virtual wxString GetValue() const;
protected:
	wxPoint m_pointActivate;
	SComboBox *Combo() const { return (SComboBox*)m_control; }
	wxString        m_startValue;
	wxArrayString   m_choices;
	bool            m_allowOthers;
};

class SCheckComboBox;
class CCheckComboEditor : public wxGridCellEditor
{
public:
	CCheckComboEditor(size_t count = 0,
		const wxString choices[] = NULL,	bool allowOthers = FALSE);
	virtual void Create(wxWindow* parent,
		wxWindowID id,
		wxEvtHandler* evtHandler);
	virtual void PaintBackground(const wxRect& rectCell, wxGridCellAttr *attr);

	virtual void BeginEdit(int row, int col, wxGrid* grid);
	virtual bool EndEdit(int row, int col, const wxGrid* grid,
		const wxString& oldval, wxString *newval);
	virtual void ApplyEdit(int row, int col, wxGrid* grid);

	virtual void Reset();

	// parameters string format is "item1[,item2[...,itemN]]"
	virtual void SetParameters(const wxString& params);
	void SetParameters(size_t count, const wxString choices[]);
	virtual wxGridCellEditor *Clone() const;
	virtual wxString GetValue() const;
protected:
	wxPoint m_pointActivate;
	wxComboCtrl *Combo() const { return (wxComboCtrl*)m_control; }
	wxString   m_value;
	wxArrayString   m_choices;
	bool            m_allowOthers;
};


#endif