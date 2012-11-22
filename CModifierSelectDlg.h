#ifndef __CMODIFIERSELECTDLG_H__
#define __CMODIFIERSELECTDLG_H__
#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/combobox.h"
#include "wx/listbox.h"
#include "basedef.h"
#endif

enum 
{
	CModifierSelectDlg_ComboBoxID = 1,
	CModifierSelectDlg_ListBoxID
};

class CModifierSelectDlg : public wxDialog
{
public:
	CModifierSelectDlg();
	CModifierSelectDlg(wxWindow *parent,
		const wxString& message,
		const wxString& caption,
		wxString& value,
		long style = wxDEFAULT_DIALOG_STYLE,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& sz = wxDefaultSize );

	virtual ~CModifierSelectDlg ();
	void Init();

	bool Create(wxWindow *parent,
		const wxString& message,
		const wxString& caption,
		wxString& value,
		long style = wxDEFAULT_DIALOG_STYLE,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& sz = wxDefaultSize );

	// Generates cache for displayed text
	//virtual void GenerateValueAsString ( wxString& target, int prec, bool removeZeroes ) const;

private:
	wxComboBox *m_modifierComboBox;
	wxListBox *m_modifierLB;


private:
	DECLARE_DYNAMIC_CLASS_NO_COPY(CModifierSelectDlg)
	DECLARE_EVENT_TABLE()
};


#endif