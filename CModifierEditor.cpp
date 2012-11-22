#include "CModifierEditor.h"
#include "wx/renderer.h"
#include "CModifierSelectDlg.h"

BEGIN_EVENT_TABLE(STextButton, wxControl)
	EVT_SIZE(			STextButton::OnSize)
	EVT_BUTTON(wxTB_SUBID2, STextButton::OnButton)
END_EVENT_TABLE()
STextButton::STextButton(wxWindow *parent, wxWindowID id,
			const wxString& value,
			const wxPoint& pos,
			const wxSize& size,
			long style,
			const wxString& name)
			:wxControl(parent, id/*, value, pos, size, style*/)
{
	m_textCtrl = new wxTextCtrl(this, wxTB_SUBID1, wxT(""));
	m_button = new wxButton(this, wxTB_SUBID2, wxS("..."),wxDefaultPosition,wxDefaultSize,wxWANTS_CHARS); //(wxButton*)GenerateEditorButton(pos, size);

	//wxSizer* sz = new wxBoxSizer(wxHORIZONTAL);
	//wxSize ctrlSize = m_button->GetSize();
	//wxSize btnSize( ctrlSize.GetHeight()-2, ctrlSize.GetHeight()-2);
	//m_button->SetSize(btnSize);
	//sz->Add(m_textCtrl, 5, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL );
	//sz->Add(m_button,  0, 0);
	//SetSizer(sz); 
}

void STextButton::OnButton(wxCommandEvent& (event))
{
	CModifierSelectDlg dlg;
	dlg.Create(GetParent(), wxEmptyString, wxT("Ñ¡ÔñÐÞ¸ÄÆ÷"), GetValue() );
	//dlg.Move( propgrid->GetGoodEditorDialogPosition(this,dlg.GetSize()) );

	// Execute editor dialog
	int res = dlg.ShowModal();
	if ( res == wxID_OK /*&& dlg.IsModified()*/ )
	{
		//SetValueInEvent( WXVARIANT(dlg.GetArray()) );
		return ;
	}
}
void STextButton::OnSize(wxSizeEvent& event)
{
	wxSize ctrlSize = event.GetSize();

	wxSize btnSize( ctrlSize.GetHeight()-2, ctrlSize.GetHeight()-2);
	m_button->SetSize(btnSize);

	wxPoint btnPos = GetPosition();
	btnPos.x = btnPos.x + ctrlSize.x - btnSize.x - 1;
	btnPos.y -= 1;
	m_button->Move(btnPos);

	wxSize textCtrlSize(ctrlSize.x - btnSize.x, btnSize.y);
	m_textCtrl->SetSize(textCtrlSize);

	Layout();
	event.Skip();
}
void CGridCellTextButtonRenderer::Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc,
								   const wxRect& rectCell, int row, int col, bool isSelected)
{
	wxGridCellRenderer::Draw(grid, attr, dc, rectCell, row, col, isSelected);
	// first calculate button size
	// don't draw outside the cell
	//wxRect textCtrlRect = rectCell;
	//wxPoint pos = wxPoint(rectCell.GetRight() - rectCell.GetHeight(), 
	//	rectCell.GetBottom());
	//textCtrlRect.SetRightBottom(pos);
	//wxRect buttonCtrlRect = rectCell;
	//pos = wxPoint(rectCell.GetRight() - rectCell.GetHeight(),
	//	rectCell.GetBottom() - rectCell.GetHeight());
	//buttonCtrlRect.SetLeftTop(pos);
	//wxRendererNative::Get().DrawTextCtrl(&grid, dc, textCtrlRect, wxCONTROL_CURRENT);
	//wxRendererNative::Get().DrawPushButton(&grid, dc, buttonCtrlRect, wxCONTROL_CURRENT);

}


CTextButtonEditor::CTextButtonEditor(wxString buttonLabel, bool allowOthers)
								   : m_allowOthers(allowOthers), m_btnLabel(buttonLabel)
{
	SetClientData((void*)&m_pointActivate);
}

wxGridCellEditor *CTextButtonEditor::Clone() const
{
	CTextButtonEditor *editor = new CTextButtonEditor(m_btnLabel);
	editor->m_allowOthers = m_allowOthers;
	return editor;
}

void CTextButtonEditor::Create(wxWindow* parent,
							  wxWindowID id,
							  wxEvtHandler* evtHandler)
{
	m_control = new STextButton(parent, wxID_ANY, wxString("45612"), wxDefaultPosition,
		wxDefaultSize, wxTE_RICH2, m_btnLabel);

	wxGridCellEditor::Create(parent, id, evtHandler);
}

void CTextButtonEditor::PaintBackground(const wxRect& rectCell,
									   wxGridCellAttr * attr)
{
	wxGridCellEditor::PaintBackground(rectCell, attr);
}

void CTextButtonEditor::BeginEdit(int row, int col, wxGrid* grid)
{
	wxASSERT_MSG(m_control,
		wxT("The wxGridCellEditor must be Created first!"));

	m_value = grid->GetTable()->GetValue(row, col);
	
	Reset();

}

bool CTextButtonEditor::EndEdit(int row, int col,
							   const wxGrid* grid,
							   const wxString& WXUNUSED(oldval),
							   wxString *newval)
{
	const wxString value = GetValue();
	if ( value == m_value )
		return false;

	m_value = value;

	if ( newval )
		*newval = m_value;

	return true;
}
void CTextButtonEditor::ApplyEdit(int row, int col, wxGrid* grid)
{
	grid->GetTable()->SetValue(row, col, m_value);
	m_value.Clear();
}
void CTextButtonEditor::Reset()
{
	TextCtrl()->SetValue(m_value);
}
wxString CTextButtonEditor::GetValue() const
{
	return TextCtrl()->GetValue();
}
//void CTextButtonEditor::SetSize (const wxRect &rect)
//{
//	TextCtrl()->OnSize(wxSizeEvent(wxSize(rect.GetWidth(), rect.GetHeight())));
//}
