#pragma once

#include <wx/wx.h>
#include <iostream>
#include "enum.h"

using namespace std;

class gamePanel : public wxPanel
{
public:
	gamePanel(wxFrame* parent) : wxPanel(parent, wxID_ANY)
	{
		wxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
		
		//set Round title
		wxPanel *round_panel = new wxPanel(this, wxID_ANY);
		wxBoxSizer* roundSizer = new wxBoxSizer(wxHORIZONTAL);
		
		wxStaticText* roundTitle = new wxStaticText(round_panel, wxID_ANY, "Test: ");
		roundTitle->SetMinSize(wxSize(200, -1));
		roundSizer->Add(roundTitle);
		
		//set End Button
		wxBoxSizer* endSizer = new wxBoxSizer(wxHORIZONTAL);
		
		endButton->Bind(wxEVT_BUTTON, &gamePanel::OnEnd, this);
		
		endSizer->Add(endButton);
		end_panel->SetSizer(endSizer);
		
		main_sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(30);
		main_sizer->Add(end_panel, 0, wxALIGN_RIGHT, 0);
		
		SetSizer(main_sizer);
	}
	
	void OnEnd(wxCommandEvent& event)
	{
		Hide();
	}
private:
	wxPanel *end_panel = new wxPanel(this, wxID_ANY);
	
	wxButton* endButton = new wxButton(end_panel, wxID_ANY, "Finish", wxPoint(100, 50), wxSize(70,20));
};
