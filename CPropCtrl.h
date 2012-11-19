#ifndef __CPROPCTRL_H__
#define __CPROPCTRL_H__
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>


class CModifierProperty : public wxPGProperty
{
	WX_PG_DECLARE_PROPERTY_CLASS(CModifierProperty)
public:

	CModifierProperty( const wxString& label = wxPG_LABEL,
		const wxString& name = wxPG_LABEL,
		const wxString& value = wxEmptyString);

	virtual ~CModifierProperty ();

	virtual void OnSetValue();
	virtual wxString ValueToString( wxVariant& value, int argFlags = 0 ) const;
	virtual bool StringToValue( wxVariant& variant,
		const wxString& text,
		int argFlags = 0 ) const;
	virtual bool OnEvent( wxPropertyGrid* propgrid, wxWindow* primary, wxEvent& event );
	virtual bool DoSetAttribute( const wxString& name, wxVariant& value );

	// Generates cache for displayed text
	//virtual void GenerateValueAsString ( wxString& target, int prec, bool removeZeroes ) const;

protected:
	wxString        m_display; // Stores cache for displayed text
	int             m_precision; // Used when formatting displayed string.
	wxChar          m_delimiter; // Delimiter between array entries.
};


#endif