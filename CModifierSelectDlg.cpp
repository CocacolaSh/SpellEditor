#include "CModifierSelectDlg.h"
//#include "wx/arrstr.h"
static const wxString SModifierArrayStr[] =
{
	wxT("人物修改器"),
	wxT("子弹修改器"),
	wxT("技能修改器"),
	wxT("EOT修改器"),
	wxT("Aura修改器"),
};

IMPLEMENT_DYNAMIC_CLASS(CModifierSelectDlg, wxDialog)

BEGIN_EVENT_TABLE(CModifierSelectDlg, wxDialog)
END_EVENT_TABLE()

CModifierSelectDlg::CModifierSelectDlg()
: wxDialog()
{
	Init();
}
CModifierSelectDlg::~CModifierSelectDlg ()
{
	wxDELETE(m_modifierComboBox);
	wxDELETE(m_modifierLB);
}
void CModifierSelectDlg::Init()
{
	wxDialog::Init();
}

CModifierSelectDlg::CModifierSelectDlg(wxWindow *parent,
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

bool CModifierSelectDlg::Create(wxWindow *parent,
								const wxString& message,
								const wxString& caption,
								wxString& value,
								long style,
								const wxPoint& pos,
								const wxSize& sz )
{
#ifdef __WXMAC__
	wxUnusedVar(style);
	int useStyle = wxCAPTION;
#else
	int useStyle = style;
#endif

#if !wxPG_SMALL_SCREEN
	const int spacing = 4;
#else
	const int spacing = 3;
#endif
	bool res = wxDialog::Create(parent, wxID_ANY, caption, pos, sz, useStyle | wxCLOSE_BOX);

	SetFont(parent->GetFont()); // To allow entering chars of the same set as the propGrid

	m_modifierComboBox = new wxComboBox(this, CModifierSelectDlg_ComboBoxID, wxEmptyString,
		wxDefaultPosition, wxDefaultSize, WXSIZEOF(SModifierArrayStr), SModifierArrayStr, wxCB_DROPDOWN | wxCB_READONLY);
	m_modifierLB = new wxListBox(this, CModifierSelectDlg_ListBoxID,
		wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_ALWAYS_SB);

	//m_modifierLB->SetSize(GetParent()->GetSize());
	wxSizer *horSizer = new wxBoxSizer(wxHORIZONTAL);
	wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

	horSizer->Add(m_modifierComboBox, 0, wxALIGN_CENTRE_VERTICAL | wxTOP | wxBOTTOM);
	//sizer->Add(m_modifierComboBox, 0, wxALIGN_CENTRE_VERTICAL | wxTOP | wxBOTTOM);
	sizer->Add(horSizer, 0, wxALIGN_CENTRE_VERTICAL | wxTOP | wxBOTTOM);
	sizer->Add(m_modifierLB, 8, wxEXPAND);
	//sizer->SetMinSize(parent->GetSize());
	//sizer->Add(sizer, 1, wxEXPAND);
	wxStdDialogButtonSizer* buttonSizer = new wxStdDialogButtonSizer();
	buttonSizer->AddButton(new wxButton(this, wxID_OK));
	buttonSizer->AddButton(new wxButton(this, wxID_CANCEL));
	buttonSizer->Realize();
	sizer->Add( buttonSizer, 0,
		wxALIGN_RIGHT|wxALIGN_CENTRE_VERTICAL|wxALL,
		spacing );

	SetSizer(sizer);
	sizer->SetSizeHints(this);

	SetSize(parent->GetSize());
	return res;
}