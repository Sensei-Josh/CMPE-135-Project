#pragma once

#include <wx/wx.h>


class endDialog : public wxDialog
{
public:
	endDialog(wxWindow *parent,
		const wxString& title,
		int max,
		int score) 
		: wxDialog(parent, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, wxASCII_STR(wxDialogNameStr))
	{
		wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
		wxBoxSizer* scoreSizer = new wxBoxSizer(wxHORIZONTAL);
		//wxPanel scorePanel = new wxPanel(this);
		//wxPanel numPanel = new wxPanel(this);
		
		wxString total = wxString::Format(wxT("%i/%i"), score, max);
		
		wxStaticText* label1 = new wxStaticText(this, wxID_ANY, total);
		label1->SetMinSize(wxSize(200, -1));
		scoreSizer->Add(label1);
		
		/*wxStaticText* label2 = new wxStaticText(this, wxID_ANY, _("You got:"));
		label2->SetMinSize(wxSize(200, -1));
		scoreSizer->Add(label2)*/
		
		mainSizer->Add(scoreSizer);
		
		SetSizer(mainSizer);
		
		SetMinSize(wxSize(400,100));
		Fit();
	}
private:
};
