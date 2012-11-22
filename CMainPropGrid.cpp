#include "CMainPropGrid.h"
#include "Process_error.h"


BEGIN_EVENT_TABLE(CMainPropCtrl, wxControl)
	EVT_SIZE(		CMainPropCtrl::OnSize)
	EVT_PG_COL_BEGIN_DRAG( PGID, CMainPropCtrl::OnPropertyGridColBeginDrag )
	EVT_PG_COL_DRAGGING( PGID, CMainPropCtrl::OnPropertyGridColDragging )
	EVT_PG_COL_END_DRAG( PGID, CMainPropCtrl::OnPropertyGridColEndDrag )

END_EVENT_TABLE()


CMainPropCtrl::CMainPropCtrl(wxWindow *parent, const wxWindowID id,
			  const wxPoint& pos, const wxSize& size,
			  long style)
			  : wxControl(parent, id, pos, size, style)//wxPropertyGridManager(parent, id, pos, size, style)
{
	/*m_panel = new wxPanel(this, wxID_ANY,
		pos, size,
		wxTAB_TRAVERSAL);*/

	m_propItemDesc = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RICH2 | wxTE_MULTILINE);
	m_topSizer = new wxBoxSizer ( wxHORIZONTAL );
	
}
CMainPropCtrl::~CMainPropCtrl()
{
	wxDELETE(m_propItemDesc);
	//wxDELETE(m_topSizer);
	wxDELETE(m_pPropManager);
}
void CMainPropCtrl::OnPropertyGridColBeginDrag( wxPropertyGridEvent& event )
{
	//
}
void CMainPropCtrl::OnPropertyGridColDragging( wxPropertyGridEvent& event )
{
	//
}
void CMainPropCtrl::OnPropertyGridColEndDrag( wxPropertyGridEvent& event )
{
	//
}
void CMainPropCtrl::OnSize(wxSizeEvent& event)
{
	m_pPropManager->SetSplitterPosition(event.GetSize().GetWidth() *4 / 8, 0);
	event.Skip();
}
void CMainPropCtrl::finalizePanel( bool wasCreated )
{
	// Button for tab traversal testing
	m_topSizer->Add(m_pPropManager,  3, wxEXPAND);

	wxBoxSizer* vSizer = new wxBoxSizer (wxVERTICAL );
	//vSizer->Add(new wxButton(this, wxID_ANY, wxT("ÃèÊö"), wxDefaultPosition, wxd, wxALIGN_LEFT), 0, wxEXPAND);
	vSizer->Add(m_propItemDesc, 1, wxALIGN_BOTTOM | wxEXPAND | wxALL);

	m_topSizer->Add( vSizer, 1, wxEXPAND );

	SetSizer(m_topSizer);
	m_topSizer->SetSizeHints(this);
	/*m_panel->SetSizer( m_topSizer );
	m_topSizer->SetSizeHints( m_panel );*/

	//wxBoxSizer* panelSizer = new wxBoxSizer( wxHORIZONTAL );
	//panelSizer->Add( this, 1, wxEXPAND | wxALL);

	//SetSizer( panelSizer );
	//panelSizer->Fit(GetParent());
	//panelSizer->SetSizeHints(GetParent());

	/*if ( wasCreated )
		FinalizeFramePosition();*/
}
bool CMainPropCtrl::createPropGrid()
{
	int style = wxPG_BOLD_MODIFIED | wxPG_SPLITTER_AUTO_CENTER |wxPG_NO_INTERNAL_BORDER/*| wxPG_AUTO_SORT |
		wxPG_TOOLBAR | wxPG_DESCRIPTION*/;
	m_pPropManager = new wxPropertyGridManager(this,
							PGID, 
							wxDefaultPosition,
							wxDefaultSize,
							style);

	m_propGridPages[ECreateItemType_Skill] = m_pPropManager->AddPage(wxT("Skill"));
	m_propGridPages[ECreateItemType_Eot] = m_pPropManager->AddPage(wxT("Eot"));
	m_propGridPages[ECreateItemType_Aura] = m_pPropManager->AddPage(wxT("Aura"));

	m_pPropManager->SetColumnCount(2, 0);
	m_pPropManager->SetColumnTitle(0, wxT("Ãû³Æ"));
	m_pPropManager->SetColumnTitle(1, wxT("Öµ"));
	m_pPropGrid = m_pPropManager->GetGrid();
	//m_pPropGrid->SetVerticalSpacing( 2 );
	//m_pPropManager->ShowHeader(true);

	

	registerSkillProp();
	//_appendSkillProp();
	wxPropertyGridEvent MyEvent(wxEVT_PG_COL_DRAGGING, m_pPropManager->GetId()); 
	m_pPropManager->GetEventHandler()->ProcessEvent(MyEvent);
	
	//AddPendingEvent(MyEvent);
	finalizePanel();

	showGridPage(ECreateItemType_Skill, false);
	return true;

}

bool CMainPropCtrl::_appendSkillProp()
{
	std::vector <SKILLEDITOR::SListItemShowData> showDataVec = SKILLEDITOR::sSkillMgr.getShowData();
	BSLib::s32 rowSize = showDataVec.size();
	for (BSLib::s32 i = 0; i < rowSize; ++i)
	{

		if (m_skillItemWindow[showDataVec[i].indexName])
		{
			m_propGridPages[ECreateItemType_Skill]->Append(m_skillItemWindow[showDataVec[i].indexName]);
			//SetCellRenderer(i, 1, m_skillItemWindow[showDataVec[i].indexName]->m_cellRenderer);
		}
	}
	return true;
}
bool CMainPropCtrl::showGridPage(ECreateItemType _type, bool show)
{
	PropViewItemMap::iterator begIter;

	wxPropertyGridIterator it;
	wxPropertyGridPage *gridPage = m_propGridPages[_type];
	PropViewItemMap *propViewMap = NULL;
	switch (_type)
	{
	case ECreateItemType_Skill:
		{
			//_createItemSkill();
			propViewMap = & m_skillItemWindow;
		}
		break;
	case ECreateItemType_Eot:
		{
			propViewMap = &m_eotItemWindow;
		}
		break;
	case ECreateItemType_Aura:
		{
			propViewMap = &m_auraItemWindow;
		}
		break;
	default:
		break;
	}

	LOG_PROCESS_ERROR(propViewMap);

	

	for ( it = gridPage->GetIterator();
		!it.AtEnd();
		it++ )
	{
		wxPGProperty* p = *it;

		p->Hide(!show);
	}
	/*m_propGridPages[0]->GetIterator()
	begIter = propViewMap->begin();
	for (; begIter != propViewMap->end(); ++ begIter)
	{
		wxPGProperty *prop = (begIter->second);
		LOG_PROCESS_ERROR(prop);
		prop->Hide(!show);
	}*/
	return true;
Exit0:
	return false;
}