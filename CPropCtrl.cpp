#include "CPropCtrl.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/editlbox.h"
#include "wx/sizer.h"
#include "wx/listctrl.h"
#include "CModifierSeqListView.h"

static const char* const eledit_xpm[] = {
	"16 16 3 1",
	"   c None",
	".  c #000000",
	"+  c #00007F",
	"                ",
	"                ",
	"      .. ..     ",
	"        .       ",
	"        .       ",
	"  ++++  .  ++++ ",
	"     ++ . ++  ++",
	"  +++++ . ++++++",
	" ++  ++ . ++    ",
	" ++  ++ . ++  ++",
	"  +++++ .  ++++ ",
	"        .       ",
	"        .       ",
	"      .. ..     ",
	"                ",
	"                "};

static const char* const elnew_xpm[] = {
	"16 16 5 1",
	"   c None",
	".  c #7F7F7F",
	"+  c #FFFFFF",
	"@  c #FFFF00",
	"#  c #000000",
	"                ",
	"                ",
	" .  .+ .@       ",
	"  . .@.@# # #   ",
	"  @.@+....   #  ",
	" ... @@         ",
	"  @ . @.     #  ",
	" .# .@          ",
	"    .        #  ",
	"  #             ",
	"             #  ",
	"  #             ",
	"             #  ",
	"  # # # # # #   ",
	"                ",
	"                "};

static const char* const eldel_xpm[] = {
	"16 16 3 1",
	"   c None",
	".  c #7F0000",
	"+  c #FFFFFF",
	"                ",
	"                ",
	"                ",
	" ..+        ..+ ",
	" ....+     ..+  ",
	"  ....+   ..+   ",
	"    ...+ .+     ",
	"     .....+     ",
	"      ...+      ",
	"     .....+     ",
	"    ...+ ..+    ",
	"   ...+   ..+   ",
	"  ...+     .+   ",
	"  ...+      .+  ",
	"   .         .  ",
	"                "};

static const char* const eldown_xpm[] = {
	"16 16 2 1",
	"   c None",
	".  c #000000",
	"                ",
	"                ",
	"         ...    ",
	"        ...     ",
	"       ...      ",
	"       ...      ",
	"       ...      ",
	"       ...      ",
	"   ...........  ",
	"    .........   ",
	"     .......    ",
	"      .....     ",
	"       ...      ",
	"        .       ",
	"                ",
	"                "};

static const char* const elup_xpm[] = {
	"16 16 2 1",
	"   c None",
	".  c #000000",
	"                ",
	"        .       ",
	"       ...      ",
	"      .....     ",
	"     .......    ",
	"    .........   ",
	"   ...........  ",
	"       ...      ",
	"       ...      ",
	"       ...      ",
	"       ...      ",
	"      ...       ",
	"     ...        ",
	"                ",
	"                ",
	"                "};

const wxWindowIDRef wxID_ELB_DELETE = wxWindow::NewControlId();
const wxWindowIDRef wxID_ELB_EDIT = wxWindow::NewControlId();
const wxWindowIDRef wxID_ELB_NEW = wxWindow::NewControlId();
const wxWindowIDRef wxID_ELB_UP = wxWindow::NewControlId();
const wxWindowIDRef wxID_ELB_DOWN = wxWindow::NewControlId();
const wxWindowIDRef wxID_ELB_LISTCTRL = wxWindow::NewControlId();
class CModifierEditorDlg : public wxDialog
{
public:
	CModifierEditorDlg();

	void Init();

	CModifierEditorDlg(wxWindow *parent,
		const wxString& message,
		const wxString& caption,
		wxString& value,
		long style = wxAEDIALOG_STYLE,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& sz = wxDefaultSize );

	bool Create(wxWindow *parent,
		const wxString& message,
		const wxString& caption,
		wxString& value,
		long style = wxAEDIALOG_STYLE,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& sz = wxDefaultSize );

	const wxArrayDouble& GetArray() const { return m_array; }

	// Extra method for this type of array
	void SetPrecision ( int precision )
	{
		m_precision = precision;
		m_dtoaTemplate.Empty();
	}

	void OnItemSelected(wxListEvent& event);
	void OnEndLabelEdit(wxListEvent& event);
	void OnNewItem(wxCommandEvent& event);
	void OnDelItem(wxCommandEvent& event);
	void OnEditItem(wxCommandEvent& event);
	void OnUpItem(wxCommandEvent& event);
	void OnDownItem(wxCommandEvent& event);
protected:
	wxStaticText *m_editorText;
	wxTextCtrl *m_descTipInfo;
	wxBitmapButton *m_bDel, *m_bNew, *m_bUp, *m_bDown, *m_bEdit;
	CModifierSeqListView *m_listCtrl;
	int m_selection;
	long m_style;

	// Mandatory array of type
	wxArrayDouble   m_array;

	// Use this to avoid extra wxString creation+Printf
	// on double-to-wxString conversion.
	wxString        m_dtoaTemplate;

	int             m_precision;

	// Mandatory overridden methods
private:
	DECLARE_DYNAMIC_CLASS_NO_COPY(CModifierEditorDlg)
	DECLARE_EVENT_TABLE()
};

IMPLEMENT_DYNAMIC_CLASS(CModifierEditorDlg, wxDialog)

BEGIN_EVENT_TABLE(CModifierEditorDlg, wxDialog)
EVT_LIST_ITEM_SELECTED(wxID_ELB_LISTCTRL, CModifierEditorDlg::OnItemSelected)
EVT_LIST_END_LABEL_EDIT(wxID_ELB_LISTCTRL, CModifierEditorDlg::OnEndLabelEdit)
EVT_BUTTON(wxID_ELB_NEW, CModifierEditorDlg::OnNewItem)
EVT_BUTTON(wxID_ELB_UP, CModifierEditorDlg::OnUpItem)
EVT_BUTTON(wxID_ELB_DOWN, CModifierEditorDlg::OnDownItem)
EVT_BUTTON(wxID_ELB_EDIT, CModifierEditorDlg::OnEditItem)
EVT_BUTTON(wxID_ELB_DELETE, CModifierEditorDlg::OnDelItem)
END_EVENT_TABLE()

void CModifierEditorDlg::OnNewItem(wxCommandEvent& WXUNUSED(event))
{
	//m_listCtrl->SetItemState(m_listCtrl->GetItemCount()-1,
	//	wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
	//m_listCtrl->EditLabel(m_selection);
}
void CModifierEditorDlg::OnItemSelected(wxListEvent& event)
{
	//m_selection = event.GetIndex();
	//if (!(m_style & wxEL_NO_REORDER))
	//{
	//	m_bUp->Enable(m_selection != 0 && m_selection < m_listCtrl->GetItemCount()-1);
	//	m_bDown->Enable(m_selection < m_listCtrl->GetItemCount()-2);
	//}

	//if (m_style & wxEL_ALLOW_EDIT)
	//	m_bEdit->Enable(m_selection < m_listCtrl->GetItemCount()-1);
	//if (m_style & wxEL_ALLOW_DELETE)
	//	m_bDel->Enable(m_selection < m_listCtrl->GetItemCount()-1);
}
void CModifierEditorDlg::OnEndLabelEdit(wxListEvent& event)
{
	//if ( event.GetIndex() == m_listCtrl->GetItemCount()-1 &&
	//	!event.GetText().empty() )
	//{
	//	// The user edited last (empty) line, i.e. added new entry. We have to
	//	// add new empty line here so that adding one more line is still
	//	// possible:
	//	m_listCtrl->InsertItem(m_listCtrl->GetItemCount(), wxEmptyString);

	//	// Simulate a wxEVT_COMMAND_LIST_ITEM_SELECTED event for the new item,
	//	// so that the buttons are enabled/disabled properly
	//	wxListEvent selectionEvent(wxEVT_COMMAND_LIST_ITEM_SELECTED, m_listCtrl->GetId());
	//	selectionEvent.m_itemIndex = event.GetIndex();
	//	m_listCtrl->GetEventHandler()->ProcessEvent(selectionEvent);
	//}
}

void CModifierEditorDlg::OnDelItem(wxCommandEvent& WXUNUSED(event))
{
	//m_listCtrl->DeleteItem(m_selection);
	//m_listCtrl->SetItemState(m_selection,
	//	wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
}

void CModifierEditorDlg::OnEditItem(wxCommandEvent& WXUNUSED(event))
{
	//m_listCtrl->EditLabel(m_selection);
}

void CModifierEditorDlg::OnUpItem(wxCommandEvent& WXUNUSED(event))
{
	//wxString t1, t2;

	//t1 = m_listCtrl->GetItemText(m_selection - 1);
	//t2 = m_listCtrl->GetItemText(m_selection);
	//m_listCtrl->SetItemText(m_selection - 1, t2);
	//m_listCtrl->SetItemText(m_selection, t1);
	//m_listCtrl->SetItemState(m_selection - 1,
	//	wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
}

void CModifierEditorDlg::OnDownItem(wxCommandEvent& WXUNUSED(event))
{
	//wxString t1, t2;

	//t1 = m_listCtrl->GetItemText(m_selection + 1);
	//t2 = m_listCtrl->GetItemText(m_selection);
	//m_listCtrl->SetItemText(m_selection + 1, t2);
	//m_listCtrl->SetItemText(m_selection, t1);
	//m_listCtrl->SetItemState(m_selection + 1,
	//	wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
}

CModifierEditorDlg::CModifierEditorDlg()
: wxDialog()
{
	Init();
}

void CModifierEditorDlg::Init()
{
	wxDialog::Init();
	SetPrecision(-1);
}

CModifierEditorDlg::CModifierEditorDlg(wxWindow *parent,
													 const wxString& message,
													 const wxString& caption,
													 wxString& value,
													 long style,
													 const wxPoint& pos,
													 const wxSize& sz )
													 : wxDialog()
{
	Init();
	Create(parent,message,caption,value,style,pos,sz);
}

bool CModifierEditorDlg::Create(wxWindow *parent,
									   const wxString& message,
									   const wxString& caption,
									   wxString& value,
									   long style,
									   const wxPoint& pos,
									   const wxSize& sz )
{

	// On wxMAC the dialog shows incorrectly if style is not exactly wxCAPTION
	// FIXME: This should be only a temporary fix.
#ifdef __WXMAC__
	wxUnusedVar(style);
	int useStyle = wxCAPTION;
#else
	int useStyle = style;
#endif

	bool res = wxDialog::Create(parent, wxID_ANY, caption, pos, sz, useStyle | wxCLOSE_BOX);

	SetFont(parent->GetFont()); // To allow entering chars of the same set as the propGrid

#if !wxPG_SMALL_SCREEN
	const int spacing = 4;
#else
	const int spacing = 3;
#endif

	wxSizer *hSizer = new wxBoxSizer(wxHORIZONTAL);
	wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

	wxPanel *subp = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxSUNKEN_BORDER | wxTAB_TRAVERSAL);
	wxSizer *subsizer = new wxBoxSizer(wxHORIZONTAL);
	m_editorText = new wxStaticText(subp, wxID_ANY, value);
	subsizer->Add(m_editorText, 1, wxALIGN_CENTRE_VERTICAL | wxLEFT, 4);
#ifdef __WXMSW__
#define BTN_BORDER 4
	// FIXME - why is this needed? There's some reason why sunken border is
	//         ignored by sizers in wxMSW but not in wxGTK that I can't
	//         figure out...
#else
#define BTN_BORDER 0
#endif

	m_bEdit = new wxBitmapButton(subp, wxID_ELB_EDIT, wxBitmap(eledit_xpm));
	subsizer->Add(m_bEdit, 0, wxALIGN_CENTRE_VERTICAL | wxTOP | wxBOTTOM, BTN_BORDER);

	m_bNew = new wxBitmapButton(subp, wxID_ELB_NEW, wxBitmap(elnew_xpm));
	subsizer->Add(m_bNew, 0, wxALIGN_CENTRE_VERTICAL | wxTOP | wxBOTTOM, BTN_BORDER);
	m_bDel = new wxBitmapButton(subp, wxID_ELB_DELETE, wxBitmap(eldel_xpm));
	subsizer->Add(m_bDel, 0, wxALIGN_CENTRE_VERTICAL | wxTOP | wxBOTTOM, BTN_BORDER);
	m_bUp = new wxBitmapButton(subp, wxID_ELB_UP, wxBitmap(elup_xpm));
	subsizer->Add(m_bUp, 0, wxALIGN_CENTRE_VERTICAL | wxTOP | wxBOTTOM, BTN_BORDER);

	m_bDown = new wxBitmapButton(subp, wxID_ELB_DOWN, wxBitmap(eldown_xpm));
	subsizer->Add(m_bDown, 0, wxALIGN_CENTRE_VERTICAL | wxTOP | wxBOTTOM, BTN_BORDER);

	m_descTipInfo = new wxTextCtrl(this, wxID_ANY, wxT("Modifier Tips\nhelloworld!"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_LEFT | wxTE_RICH | wxTE_MULTILINE);

#if wxUSE_TOOLTIPS
	if ( m_bEdit ) m_bEdit->SetToolTip(_("Edit item"));
	if ( m_bNew ) m_bNew->SetToolTip(_("New item"));
	if ( m_bDel ) m_bDel->SetToolTip(_("Delete item"));
	if ( m_bUp ) m_bUp->SetToolTip(_("Move up"));
	if ( m_bDown ) m_bDown->SetToolTip(_("Move down"));
#endif

	subp->SetSizer(subsizer);
	subsizer->Fit(subp);

	sizer->Add(subp, 0, wxEXPAND);

	//long st = wxLC_REPORT | wxLC_NO_HEADER | wxLC_SINGLE_SEL | wxSUNKEN_BORDER;
	//if ( style & wxEL_ALLOW_EDIT )
	//	st |= wxLC_EDIT_LABELS;
	m_listCtrl = new CModifierSeqListView(this, wxID_ELB_LISTCTRL,
		wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_VRULES | wxLC_HRULES);
	m_listCtrl->initWithReportItems();
	/*wxArrayString empty_ar;
	SetStrings(empty_ar);*/

	hSizer->Add(m_listCtrl, 3, wxEXPAND);
	hSizer->Add(m_descTipInfo, 1, wxEXPAND);
	sizer->Add(hSizer, 1, wxEXPAND);

	wxStdDialogButtonSizer* buttonSizer = new wxStdDialogButtonSizer();
	buttonSizer->AddButton(new wxButton(this, wxID_OK));
	buttonSizer->AddButton(new wxButton(this, wxID_CANCEL));
	buttonSizer->Realize();
	sizer->Add( buttonSizer, 0,
		wxALIGN_RIGHT|wxALIGN_CENTRE_VERTICAL|wxALL,
		spacing );

	
	SetSizer(sizer);
	//Layout();
	m_listCtrl->SetFocus();
	if ( sz.x == wxDefaultSize.x &&
		sz.y == wxDefaultSize.y )
		SetSize( wxSize(675,460) );
	else
		SetSize(sz);
	return true;
}

#include <math.h> // for fabs

// Comparison required by value type implementation.
bool operator == (const wxArrayDouble& a, const wxArrayDouble& b)
{
	if ( a.GetCount() != b.GetCount() )
		return FALSE;

	size_t i;

	for ( i=0; i<a.GetCount(); i++ )
	{
		// Can't do direct equality comparison with floating point numbers.
		if ( fabs(a[i] - b[i]) > 0.0000000001 )
		{
			//wxLogDebug(wxT("%f != %f"),a[i],b[i]);
			return FALSE;
		}
	}
	return TRUE;
}

WX_PG_IMPLEMENT_VARIANT_DATA_DUMMY_EQ(wxString)

WX_PG_IMPLEMENT_PROPERTY_CLASS(CModifierProperty,
							   wxPGProperty,
							   wxString,
							   const wxString&,
							   TextCtrlAndButton)


CModifierProperty::CModifierProperty (const wxString& label,
							   const wxString& name,
							   const wxString& value)
							   : wxPGProperty(label,name)
{
	m_precision = -1;

	//
	// Need to figure out delimiter needed for this locale
	// (ie. can't use comma when comma acts as decimal point in float).
	wxChar use_delimiter = wxT(',');

	if (wxString::Format(wxT("%.2f"),12.34).Find(use_delimiter) >= 0)
		use_delimiter = wxT(';');

	m_delimiter = use_delimiter;

	SetValue( (value) );
}

CModifierProperty::~CModifierProperty () { }

void CModifierProperty::OnSetValue()
{
	if ( !m_value.IsNull() && m_value.GetString() == wxS("<composed>") )
		SetFlag(wxPG_PROP_COMPOSED_VALUE);

	if ( HasFlag(wxPG_PROP_COMPOSED_VALUE) )
	{
		wxString s;
		DoGenerateComposedValue(s);
		m_value = s;
	}
}

wxString CModifierProperty::ValueToString( wxVariant& value,
											  int argFlags ) const
{
	wxString s = value.GetString();

	if ( GetChildCount() && HasFlag(wxPG_PROP_COMPOSED_VALUE) )
	{
		// Value stored in m_value is non-editable, non-full value
		if ( (argFlags & wxPG_FULL_VALUE) ||
			(argFlags & wxPG_EDITABLE_VALUE) ||
			!s.length() )
		{
			// Calling this under incorrect conditions will fail
			wxASSERT_MSG( argFlags & wxPG_VALUE_IS_CURRENT,
				"Sorry, currently default wxPGProperty::ValueToString() "
				"implementation only works if value is m_value." );

			DoGenerateComposedValue(s, argFlags);
		}

		return s;
	}

	// If string is password and value is for visual purposes,
	// then return asterisks instead the actual string.
	if ( (m_flags & wxPG_PROP_PASSWORD) && !(argFlags & (wxPG_FULL_VALUE|wxPG_EDITABLE_VALUE)) )
		return wxString(wxChar('*'), s.Length());

	return s;
}

bool CModifierProperty::OnEvent( wxPropertyGrid* propgrid,
									wxWindow* WXUNUSED(primary),
									wxEvent& event)
{
	if ( propgrid->IsMainButtonEvent(event) )
	{
		// Update the value in case of last minute changes
		wxVariant useValue = propgrid->GetUncommittedPropertyValue();

		wxString& value = useValue.GetString();

		// Create editor dialog.
		CModifierEditorDlg dlg;
		dlg.Create( propgrid, wxEmptyString, m_label, value );
		dlg.Move( propgrid->GetGoodEditorDialogPosition(this,dlg.GetSize()) );

		// Execute editor dialog
		int res = dlg.ShowModal();
		if ( res == wxID_OK /*&& dlg.IsModified()*/ )
		{
			//SetValueInEvent( WXVARIANT(dlg.GetArray()) );
			return true;
		}
		return false;
	}
	return false;
}

bool CModifierProperty::StringToValue( wxVariant& variant, const wxString& text, int argFlags) const
{
	if ( GetChildCount() && HasFlag(wxPG_PROP_COMPOSED_VALUE) )
		return wxPGProperty::StringToValue(variant, text, argFlags);

	if ( variant != text )
	{
		variant = text;
		return true;
	}

	return false;
}

bool CModifierProperty::DoSetAttribute( const wxString& name, wxVariant& value )
{
	if ( name == wxPG_STRING_PASSWORD )
	{
		m_flags &= ~(wxPG_PROP_PASSWORD);
		if ( value.GetLong() ) m_flags |= wxPG_PROP_PASSWORD;
		RecreateEditor();
		return false;
	}
	return true;
}

