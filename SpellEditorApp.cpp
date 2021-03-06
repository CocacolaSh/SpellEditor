
//#include <vld.h> 
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "Process_error.h"
#include "ILogger.h"

#include "MainFrame.h"
#include "./logic/skill/CSkillMgr.h"
#include "./logic/skill/CModifyMgr.h"


class SpellEditorApp : public wxApp
{
public:
	virtual bool OnInit();
protected:
private:
};



IMPLEMENT_APP(SpellEditorApp)


// ==========================================================================
// implementation
// ==========================================================================
bool SpellEditorApp::OnInit()
{
	if (!wxApp::OnInit())
	{
		return false;
	}
	SKILLEDITOR::sModifierMgr.load();
	SKILLEDITOR::sSkillMgr.load();
	CMainFrame *mainFrame = new CMainFrame(wxT("SpellEditor"));
	//mainFrame->Maximize(true);
	mainFrame->Show(true);
	
	
	return true;
}

