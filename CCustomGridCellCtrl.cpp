#include "CCustomGridCellCtrl.h"
#ifdef __WXGTK__
#include <gtk/gtk.h>
#endif
#include <wx/tokenzr.h>
#include "CListView.h"

void CGridCellChoiceRenderer::Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc,
									const wxRect& rectCell, int row, int col, bool isSelected)
{
	wxGridCellRenderer::Draw(grid, attr, dc, rectCell, row, col, isSelected);
	// first calculate button size
	// don't draw outside the cell
	int nButtonWidth = 17;
	if (rectCell.height < 2) return;	
	wxRect rectButton;
	rectButton.x = rectCell.x + rectCell.width - nButtonWidth;
	rectButton.y = rectCell.y + 1;
	int cell_rows, cell_cols;
	attr.GetSize(&cell_rows, &cell_cols);
	rectButton.width = nButtonWidth;
	if (cell_rows == 1)
		rectButton.height = rectCell.height-2;
	else
		rectButton.height = nButtonWidth;

	SetTextColoursAndFont(grid, attr, dc, isSelected);
	int hAlign, vAlign;
	attr.GetAlignment(&hAlign, &vAlign);
	// leave room for button
	wxRect rect = rectCell;
	rect.SetWidth(rectCell.GetWidth() - rectButton.GetWidth()-2);
	rect.Inflate(-1);
	grid.DrawTextRectangle(dc, grid.GetCellValue(row, col), rect, hAlign, vAlign);

	// don't bother drawing if the cell is too small
	if (rectButton.height < 4 || rectButton.width < 4) return;
	// draw 3-d button
	wxColour colourBackGround = wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE);
	dc.SetBrush(wxBrush(colourBackGround, wxSOLID));
	dc.SetPen(wxPen(colourBackGround, 1, wxSOLID));
	dc.DrawRectangle(rectButton);
	dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT), 1, wxSOLID));
	dc.DrawLine(rectButton.GetLeft(), rectButton.GetBottom(), 
		rectButton.GetRight(), rectButton.GetBottom());
	dc.DrawLine(rectButton.GetRight(), rectButton.GetBottom(), 
		rectButton.GetRight(), rectButton.GetTop()-1);
	dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW), 
		1, wxSOLID));
	dc.DrawLine(rectButton.GetLeft()+1, rectButton.GetBottom()-1, 
		rectButton.GetRight()-1, rectButton.GetBottom()-1);
	dc.DrawLine(rectButton.GetRight()-1, rectButton.GetBottom()-1, 
		rectButton.GetRight()-1, rectButton.GetTop());
	dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT), 
		1, wxSOLID));
	dc.DrawLine(rectButton.GetRight()-2, rectButton.GetTop()+1, 
		rectButton.GetLeft()+1, rectButton.GetTop()+1);
	dc.DrawLine(rectButton.GetLeft()+1, rectButton.GetTop()+1, 
		rectButton.GetLeft()+1, rectButton.GetBottom()-1);
	// Draw little triangle
	int nTriWidth = 7;
	int nTriHeight = 4;
	wxPoint point[3];
	point[0] = wxPoint(rectButton.GetLeft() + (rectButton.GetWidth()-nTriWidth)/2, 
		rectButton.GetTop()+(rectButton.GetHeight()-nTriHeight)/2);
	point[1] = wxPoint(point[0].x+nTriWidth-1, point[0].y);
	point[2] = wxPoint(point[0].x+3, point[0].y+nTriHeight-1);
	dc.SetBrush(wxBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT), wxSOLID));
	dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT), 1, wxSOLID));
	dc.DrawPolygon(3, point);
	if (m_border == wxLAYOUT_TOP)
	{
		dc.SetPen(wxPen(*wxBLACK, 1, wxDOT));
		dc.DrawLine(rectCell.GetRight(), rectCell.GetTop(), 
			rectCell.GetLeft(), rectCell.GetTop());
	}
}


void CGridCellNumberRenderer::Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc,
								   const wxRect& rectCell, int row, int col, bool isSelected)
{
	wxGridCellRenderer::Draw(grid, attr, dc, rectCell, row, col, isSelected);
	// first calculate button size
	// don't draw outside the cell
	int nButtonWidth = 17;
	if (rectCell.height < 2) return;	
	wxRect rectButton;
	rectButton.x = rectCell.x + rectCell.width - nButtonWidth;
	rectButton.y = rectCell.y + 1;
	int cell_rows, cell_cols;
	attr.GetSize(&cell_rows, &cell_cols);
	rectButton.width = nButtonWidth;
	if (cell_rows == 1)
		rectButton.height = rectCell.height-2;
	else
		rectButton.height = nButtonWidth;

	SetTextColoursAndFont(grid, attr, dc, isSelected);
	int hAlign, vAlign;
	attr.GetAlignment(&hAlign, &vAlign);
	// leave room for button
	wxRect rect = rectCell;
	rect.SetWidth(rectCell.GetWidth() - rectButton.GetWidth()-2);
	rect.Inflate(-1);
	grid.DrawTextRectangle(dc, grid.GetCellValue(row, col), rect, hAlign, vAlign);

	// don't bother drawing if the cell is too small
	if (rectButton.height < 4 || rectButton.width < 4) return;
	// draw up button
	wxRect upRectButton = rectButton;
	upRectButton.height = upRectButton.height/2 -1;
	wxColour colourBackGround = wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE);
	dc.SetBrush(wxBrush(colourBackGround, wxSOLID));
	dc.SetPen(wxPen(colourBackGround, 1, wxSOLID));
	dc.DrawRectangle(upRectButton);
	dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT), 1, wxSOLID));
	dc.DrawLine(upRectButton.GetLeft(), upRectButton.GetBottom(), 
		upRectButton.GetRight(), upRectButton.GetBottom());
	dc.DrawLine(upRectButton.GetRight(), upRectButton.GetBottom(), 
		upRectButton.GetRight(), upRectButton.GetTop()-1);
	dc.SetPen(wxPen(wxSystemSettings::GetColour(/*wxSYS_COLOUR_BTNHIGHLIGHT*/wxSYS_COLOUR_BTNSHADOW), 
		1, wxSOLID));
	dc.DrawLine(upRectButton.GetLeft()+1, upRectButton.GetBottom()-1, 
		upRectButton.GetRight()-1, upRectButton.GetBottom()-1);
	dc.DrawLine(upRectButton.GetRight()-1, upRectButton.GetBottom()-1, 
		upRectButton.GetRight()-1, upRectButton.GetTop());
	dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT), 
		1, wxSOLID));
	dc.DrawLine(upRectButton.GetRight()-2, upRectButton.GetTop()+1, 
		upRectButton.GetLeft()+1, upRectButton.GetTop()+1);
	dc.DrawLine(upRectButton.GetLeft()+1, upRectButton.GetTop()+1, 
		upRectButton.GetLeft()+1, upRectButton.GetBottom()-1);

	// Draw little triangle
	int nTriWidth = 7;
	int nTriHeight = 4;
	wxPoint point[3];
	point[0] = wxPoint(upRectButton.GetLeft() + (upRectButton.GetWidth()-nTriWidth)/2, 
		upRectButton.GetBottom()-(upRectButton.GetHeight()-nTriHeight)/2);
	point[1] = wxPoint(point[0].x+nTriWidth-1, point[0].y);
	point[2] = wxPoint(point[0].x + 3, point[0].y-nTriHeight-1);
	dc.SetBrush(wxBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT), wxSOLID));
	dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT), 1, wxSOLID));
	dc.DrawPolygon(3, point);

	upRectButton = rectButton;
	upRectButton.y = upRectButton.y + upRectButton.height/2 +1;
	upRectButton.height = upRectButton.height/2 -1;
	//wxColour colourBackGround = wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE);
	dc.SetBrush(wxBrush(colourBackGround, wxSOLID));
	dc.SetPen(wxPen(colourBackGround, 1, wxSOLID));
	dc.DrawRectangle(upRectButton);
	dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT), 1, wxSOLID));
	dc.DrawLine(upRectButton.GetLeft(), upRectButton.GetBottom(), 
		upRectButton.GetRight(), upRectButton.GetBottom());
	dc.DrawLine(upRectButton.GetRight(), upRectButton.GetBottom(), 
		upRectButton.GetRight(), upRectButton.GetTop()-1);
	dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW), 
		1, wxSOLID));
	dc.DrawLine(upRectButton.GetLeft()+1, upRectButton.GetBottom()-1, 
		upRectButton.GetRight()-1, upRectButton.GetBottom()-1);
	dc.DrawLine(upRectButton.GetRight()-1, upRectButton.GetBottom()-1, 
		upRectButton.GetRight()-1, upRectButton.GetTop());
	dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNHIGHLIGHT), 
		1, wxSOLID));
	dc.DrawLine(upRectButton.GetRight()-2, upRectButton.GetTop()+1, 
		upRectButton.GetLeft()+1, upRectButton.GetTop()+1);
	dc.DrawLine(upRectButton.GetLeft()+1, upRectButton.GetTop()+1, 
		upRectButton.GetLeft()+1, upRectButton.GetBottom()-1);

	// Draw little triangle
	point[0] = wxPoint(upRectButton.GetLeft() + (upRectButton.GetWidth()-nTriWidth)/2, 
		upRectButton.GetTop()+(upRectButton.GetHeight()-nTriHeight)/2);
	point[1] = wxPoint(point[0].x+nTriWidth-1, point[0].y);
	point[2] = wxPoint(point[0].x+3, point[0].y+nTriHeight-1);
	dc.SetBrush(wxBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT), wxSOLID));
	dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT), 1, wxSOLID));
	dc.DrawPolygon(3, point);
}


class SComboBox : public wxComboBox
{
public:
	SComboBox();
	SComboBox(wxWindow *parent, wxWindowID id,
		const wxString& value = wxEmptyString,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		int n = 0, const wxString choices[] = NULL,
		long style = 0,
		const wxValidator& validator = wxDefaultValidator,
		const wxString& name = wxComboBoxNameStr);
	void SetCellData(int nRow, int nCol, wxGrid* pGrid)
	{
		m_nRow = nRow;
		m_nCol = nCol;
		m_pGrid = pGrid;
	}
private:
	DECLARE_EVENT_TABLE()
	void OnChange(wxCommandEvent& event);
	int m_nRow;
	int m_nCol; 
	wxGrid* m_pGrid;
};


SComboBox::SComboBox(wxWindow *parent, wxWindowID id,
						 const wxString& value,
						 const wxPoint& pos,
						 const wxSize& size,
						 int n, const wxString choices[],
						 long style,
						 const wxValidator& validator,
						 const wxString& name)
{
	Create(parent, id, value, pos, size, n, choices, style, validator, name);
}

SComboBox::SComboBox() : m_pGrid(NULL)
{ 
}

BEGIN_EVENT_TABLE(SComboBox, wxComboBox)
EVT_COMBOBOX(-1, SComboBox::OnChange)
END_EVENT_TABLE()

void SComboBox::OnChange(wxCommandEvent& event)
{
	if (m_pGrid) 
	{
		m_pGrid->GetTable()->SetValue(m_nRow, m_nCol, event.GetString());
		//		m_pGrid->SetCellValue(m_nRow, m_nCol, event.GetString());
		wxGridEvent gridEvt(m_pGrid->GetId(),
			wxEVT_GRID_CELL_CHANGE, m_pGrid, m_nRow, m_nCol);
		gridEvt.SetString(event.GetString());
		GetEventHandler()->ProcessEvent(gridEvt);
	}
	event.Skip();
}

CFastComboEditor::CFastComboEditor(size_t count,
									 const wxString choices[],
									 bool allowOthers)
									 : m_allowOthers(allowOthers)
{
	SetClientData((void*)&m_pointActivate);
	if ( count )
	{
		m_choices.Alloc(count);
		for (size_t n = 0; n < count; n++ )
		{
			m_choices.Add(choices[n]);
		}
	}
}

wxGridCellEditor *CFastComboEditor::Clone() const
{
	CFastComboEditor *editor = new CFastComboEditor;
	editor->m_allowOthers = m_allowOthers;
	editor->m_choices = m_choices;
	return editor;
}

void CFastComboEditor::Create(wxWindow* parent,
							   wxWindowID id,
							   wxEvtHandler* evtHandler)
{
	size_t count = m_choices.GetCount();
	wxString *choices = new wxString[count];
	for ( size_t n = 0; n < count; n++ )
	{
		choices[n] = m_choices[n];
	}
	m_control = new SComboBox(parent, id, wxEmptyString,
		wxDefaultPosition, wxDefaultSize,
		count, choices,
		m_allowOthers ? 0 : wxCB_READONLY);
	delete [] choices;
	wxGridCellEditor::Create(parent, id, evtHandler);
}

void CFastComboEditor::PaintBackground(const wxRect& rectCell,
										wxGridCellAttr * attr)
{
	wxGridCellEditor::PaintBackground(rectCell, attr);
}

void CFastComboEditor::BeginEdit(int row, int col, wxGrid* grid)
{
	wxASSERT_MSG(m_control,
		wxT("The wxGridCellEditor must be Created first!"));

	CListView* pEzGrid = (CListView*)grid;
	pEzGrid->RevertSel();

	m_startValue = grid->GetTable()->GetValue(row, col);

	if (m_allowOthers)
		Combo()->SetValue(m_startValue);
	else
	{
		// find the right position, or default to the first if not found
		int pos = Combo()->FindString(m_startValue);
		if (pos == -1)
			pos = 0;
		Combo()->SetSelection(pos);
	}
	//Combo()->SetInsertionPointEnd();
	Reset();
	Combo()->SetFocus();
	Combo()->SetCellData(row, col, grid);
	if (m_pointActivate.x > -1 && m_pointActivate.y > -1)
	{
		m_pointActivate = Combo()->ScreenToClient(m_pointActivate);
#ifdef __WINDOWS__
		SendMessage((HWND)Combo()->GetHandle(), WM_LBUTTONDOWN, 0,
			MAKELPARAM(m_pointActivate.x, m_pointActivate.y));
#else
		GtkCombo *combo = GTK_COMBO(Combo()->m_widget);
		combo->current_button = 0;
		GtkWidget *button = GTK_COMBO(Combo()->m_widget)->button;
		GdkEventButton event;
		memset(&event, 0, sizeof(event));
		gdk_window_ref (button->window);
		// to do: only call when the click point is on the button
		//		event.x = m_pointActivate.x;
		//		event.y = m_pointActivate.y;
		event.x = 0;
		event.y = 0;
		event.deviceid = GDK_CORE_POINTER;
		event.type = GDK_BUTTON_PRESS;
		event.source = GDK_SOURCE_MOUSE;
		event.time = 0; 
		event.window = button->window;
		event.send_event = TRUE;
		event.button = 1;
		gtk_widget_event (button, (GdkEvent *)&event);
		gdk_window_unref (button->window);
		while (gtk_events_pending())
			gtk_main_iteration();
#endif
	}
}

bool CFastComboEditor::EndEdit(int row, int col,
							   const wxGrid* grid,
							   const wxString& WXUNUSED(oldval),
							   wxString *newval)
{
	wxString value = Combo()->GetValue();
	bool changed = value != grid->GetTable()->GetValue(row, col);

	if ( changed )
		grid->GetTable()->SetValue(row, col, value);

	m_startValue = wxEmptyString;
	if (m_allowOthers)
		Combo()->SetValue(m_startValue);
	else
		Combo()->SetSelection(0);

	if ( newval )
		*newval = value;

	return changed;
}
void CFastComboEditor::ApplyEdit(int row, int col, wxGrid* grid)
{
	grid->GetTable()->SetValue(row, col, GetValue());
}
void CFastComboEditor::Reset()
{
	if (m_allowOthers)
	{
		Combo()->SetValue(m_startValue);
		Combo()->SetInsertionPointEnd();
	}
	else // the combobox is read-only
	{
		// find the right position, or default to the first if not found
		int pos = Combo()->FindString(m_startValue);
		if (pos == wxNOT_FOUND)
			pos = 0;
		Combo()->SetSelection(pos);
	}
}
wxString CFastComboEditor::GetValue() const
{
	return Combo()->GetValue();
}
void CFastComboEditor::SetParameters(const wxString& params)
{
	if ( !params )
	{
		return;
	}
	m_choices.Empty();
	wxStringTokenizer tk(params, _T(','));
	while ( tk.HasMoreTokens() )
	{
		m_choices.Add(tk.GetNextToken());
	}
}

void CFastComboEditor::SetParameters(size_t count, const wxString choices[])
{
	m_choices.Empty();
	if ( count )
	{
		m_choices.Alloc(count);
		for ( size_t n = 0; n < count; n++ )
		{
			m_choices.Add(choices[n]);
		}
	}
}


class SCheckComboBox : public wxCheckListBox, public wxComboPopup
{
public:
	SCheckComboBox();
	// Initialize member variables
	virtual void Init()
	{
		m_nRow = m_nCol = -1; 
		m_pGrid = NULL;
		m_value = "";
		m_curItem = -1;
	}

	virtual bool Create(wxWindow* parent)
	{
		return wxCheckListBox::Create(parent, wxID_ANY, parent->GetPosition(),wxDefaultSize);
	}
	// Translate string into a list selection
	virtual void SetStringValue(const wxString& s)
	{
		int n = wxCheckListBox::FindString(s);
		if ( n >= 0 && n < wxCheckListBox::GetCount() )
			wxCheckListBox::Check(n);
	}
	// Get list selection as a string
	virtual wxString GetStringValue() const
	{
		wxString valueStr = "";
		for (size_t i = 0; i < wxCheckListBox::GetCount(); ++i)
		{
			if (wxCheckListBox::IsChecked(i))
			{
				valueStr += wxCheckListBox::GetString(i) + ',';
			}
		}
		return valueStr;
	}
	virtual wxWindow *GetControl() { return this; }
	void SetCellData(int nRow, int nCol, wxGrid* pGrid)
	{
		m_nRow = nRow;
		m_nCol = nCol;
		m_pGrid = pGrid;
	}

	virtual void OnDismiss()
	{
		if (m_pGrid) 
		{
			m_pGrid->GetTable()->SetValue(m_nRow, m_nCol, GetStringValue());
			//		m_pGrid->SetCellValue(m_nRow, m_nCol, event.GetString());
			wxGridEvent gridEvt(m_pGrid->GetId(),
				wxEVT_GRID_CELL_CHANGE, m_pGrid, m_nRow, m_nCol);
			gridEvt.SetString(GetStringValue());
			GetEventHandler()->ProcessEvent(gridEvt);
		}
		wxComboPopup::OnDismiss();
	}
	// Do mouse hot-tracking (which is typical in list popups)
	void OnMouseMove(wxMouseEvent& event)
	{
		// TODO: Move selection to cursor
		int hitItem = HitTest(event.GetPosition());
		if (hitItem >= 0)
		{
			//Select(hitItem);
			m_curItem = hitItem;
		}
	}

	void OnCheckListbox(wxCommandEvent& event)
	{
		wxLogMessage( wxT("Listbox item %d toggled"), event.GetInt() );
	}
	// On mouse left up, set the value and close the popup
	void OnMouseClick(wxMouseEvent& WXUNUSED(event))
	{
		//int checkItem = HitTest(event.GetPosition());
		wxCheckListBox::Check(m_curItem, !wxCheckListBox::IsChecked(m_curItem));
		//m_value = "";
		//for (size_t i = 0; i < wxCheckListBox::GetCount(); ++i)
		//{
		//	if (wxCheckListBox::IsChecked(i))
		//	{
		//		m_value += wxCheckListBox::GetString(i) + ',';
		//	}
		//}
		//m_value = wxListView::GetFirstSelected();

		// TODO: Send event as well

		//Dismiss();
	}
private:
	DECLARE_EVENT_TABLE()
	int m_nRow;
	int m_nCol; 
	int m_curItem;
	wxGrid* m_pGrid;
	wxString m_value;
};

SCheckComboBox::SCheckComboBox() : m_pGrid(NULL)
{ 
}

BEGIN_EVENT_TABLE(SCheckComboBox, wxCheckListBox)
EVT_CHECKLISTBOX(-1, SCheckComboBox::OnCheckListbox)
EVT_MOTION(SCheckComboBox::OnMouseMove)
EVT_LEFT_UP(SCheckComboBox::OnMouseClick)
END_EVENT_TABLE()


CCheckComboEditor::CCheckComboEditor(size_t count,
								   const wxString choices[],
								   bool allowOthers)
								   : m_allowOthers(allowOthers)
{
	SetClientData((void*)&m_pointActivate);
	if ( count )
	{
		m_choices.Alloc(count);
		for (size_t n = 0; n < count; n++ )
		{
			m_choices.Add(choices[n]);
		}
	}
}

wxGridCellEditor *CCheckComboEditor::Clone() const
{
	CCheckComboEditor *editor = new CCheckComboEditor;
	editor->m_allowOthers = m_allowOthers;
	editor->m_choices = m_choices;
	return editor;
}

void CCheckComboEditor::Create(wxWindow* parent,
							  wxWindowID id,
							  wxEvtHandler* evtHandler)
{
	m_control = new wxComboCtrl(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize);
	SCheckComboBox *popupCombobox = new SCheckComboBox();
	Combo()->SetPopupControl(popupCombobox);
	popupCombobox->InsertItems(m_choices, 0);

	wxGridCellEditor::Create(parent, id, evtHandler);
}

void CCheckComboEditor::PaintBackground(const wxRect& rectCell,
									   wxGridCellAttr * attr)
{
	wxGridCellEditor::PaintBackground(rectCell, attr);
}

void CCheckComboEditor::BeginEdit(int row, int col, wxGrid* grid)
{
	wxASSERT_MSG(m_control,
		wxT("The wxGridCellEditor must be Created first!"));

	CListView* pEzGrid = (CListView*)grid;
	pEzGrid->RevertSel();

	m_value = grid->GetTable()->GetValue(row, col);
	
	SCheckComboBox *popupCombobox = (SCheckComboBox *)(Combo()->GetPopupControl());
	if (m_allowOthers)
	{
		wxStringTokenizer tk(m_value, _T(','));
		
		while ( tk.HasMoreTokens() )
		{
			wxString insertItem = tk.GetNextToken();
			m_value += insertItem + ',';
			//m_values.Add(insertItem);
			popupCombobox->Insert(insertItem, popupCombobox->GetCount());
		}
	}
	else
	{
		wxStringTokenizer tk(m_value, _T(','));

		while ( tk.HasMoreTokens() )
		{
			wxString insertItem = tk.GetNextToken();
			int n = popupCombobox->FindString(insertItem);
			if ( n >= 0 && n < popupCombobox->GetCount() )
				popupCombobox->Check(n);
		}
	}
	//Combo()->SetInsertionPointEnd();
	Reset();
	Combo()->SetFocus();
	popupCombobox->SetCellData(row, col, grid);
	if (m_pointActivate.x > -1 && m_pointActivate.y > -1)
	{
		m_pointActivate = Combo()->ScreenToClient(m_pointActivate);
#ifdef __WINDOWS__
		SendMessage((HWND)Combo()->GetHandle(), WM_LBUTTONDOWN, 0,
			MAKELPARAM(m_pointActivate.x, m_pointActivate.y));
#else
		GtkCombo *combo = GTK_COMBO(Combo()->m_widget);
		combo->current_button = 0;
		GtkWidget *button = GTK_COMBO(Combo()->m_widget)->button;
		GdkEventButton event;
		memset(&event, 0, sizeof(event));
		gdk_window_ref (button->window);
		// to do: only call when the click point is on the button
		//		event.x = m_pointActivate.x;
		//		event.y = m_pointActivate.y;
		event.x = 0;
		event.y = 0;
		event.deviceid = GDK_CORE_POINTER;
		event.type = GDK_BUTTON_PRESS;
		event.source = GDK_SOURCE_MOUSE;
		event.time = 0; 
		event.window = button->window;
		event.send_event = TRUE;
		event.button = 1;
		gtk_widget_event (button, (GdkEvent *)&event);
		gdk_window_unref (button->window);
		while (gtk_events_pending())
			gtk_main_iteration();
#endif
	}
}

bool CCheckComboEditor::EndEdit(int row, int col,
							   const wxGrid* grid,
							   const wxString& WXUNUSED(oldval),
							   wxString *newval)
{

	SCheckComboBox *popupCombobox = (SCheckComboBox *)(Combo()->GetPopupControl());
	wxString value = GetValue();
	wxString checkComboString= grid->GetTable()->GetValue(row, col);

	bool changed = value != checkComboString;

	if ( changed )
		grid->GetTable()->SetValue(row, col, value);

	if (m_allowOthers)
		Combo()->SetValue(checkComboString);
	//else
	//	Combo()->SetSelection(0);

	if ( newval )
		*newval = checkComboString;

	return changed;
}
void CCheckComboEditor::ApplyEdit(int row, int col, wxGrid* grid)
{
	grid->GetTable()->SetValue(row, col, GetValue());
}
void CCheckComboEditor::Reset()
{
	Combo()->SetValue(m_value);
	//if (m_allowOthers)
	//{
	//	Combo()->SetValue(m_value);
	//	Combo()->SetInsertionPointEnd();
	//}
	//else // the combobox is read-only
	//{
	//	// find the right position, or default to the first if not found
	//	/*int pos = Combo()->FindString(m_value);
	//	if (pos == wxNOT_FOUND)
	//		pos = 0;
	//	Combo()->SetSelection(pos);*/
	//}
}
wxString CCheckComboEditor::GetValue() const
{
	return Combo()->GetValue();
	//SCheckComboBox *popupCombobox = (SCheckComboBox *)(Combo()->GetPopupControl());
	////wxString checkComboString="";
	///*for (size_t i = 0; i < popupCombobox->GetCount(); ++i)
	//{
	//	if (popupCombobox->IsChecked(i))
	//	{
	//		checkComboString += popupCombobox->GetString(i) + ',';
	//	}
	//}*/
	//return popupCombobox->GetStringValue();
}
void CCheckComboEditor::SetParameters(const wxString& params)
{
	if ( !params )
	{
		return;
	}
	m_choices.Empty();
	wxStringTokenizer tk(params, _T(','));
	while ( tk.HasMoreTokens() )
	{
		m_choices.Add(tk.GetNextToken());
	}
}

void CCheckComboEditor::SetParameters(size_t count, const wxString choices[])
{
	m_choices.Empty();
	if ( count )
	{
		m_choices.Alloc(count);
		for ( size_t n = 0; n < count; n++ )
		{
			m_choices.Add(choices[n]);
		}
	}
}
