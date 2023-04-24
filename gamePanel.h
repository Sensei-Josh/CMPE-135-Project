#pragma once

#include <wx/wx.h>
#include <iostream>
#include "enum.h"
#include "Q2Panel.h"
#include "scorer.h"

using namespace std;

class gamePanel : public wxScrolledWindow
{
public:
	gamePanel(wxWindow* parent) : wxScrolledWindow(parent, wxID_ANY)
	{
		wxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
		
		//set Round title
		wxPanel *round_panel = new wxPanel(this, wxID_ANY);
		//wxBoxSizer* roundSizer = new wxBoxSizer(wxHORIZONTAL);
		
		wxStaticText* roundTitle = new wxStaticText(round_panel, wxID_ANY, "Test: ");
		roundTitle->SetMinSize(wxSize(200, -1));
		//roundSizer->Add(roundTitle);


		// questions section
		wxPanel *questions_panel = new wxPanel(this, wxID_ANY);
		wxBoxSizer* questionsSizer = new wxBoxSizer(wxVERTICAL);
		
		wxPanel* q1 = new Q2Panel(this, wxT("Voltorb.png"), wxBITMAP_TYPE_PNG, wxT("Name this Pokemon?"), 
			wxT("Voltorb"), wxT("Electrode"), wxT("Solosis"), wxT("Pokeball"), s, 1);
			
		wxPanel* q2 = new Q2Panel(this, wxT("Solosis.png"), wxBITMAP_TYPE_PNG, wxT("Name this Pokemon?"), 
			wxT("Electrode"), wxT("Solosis"), wxT("Pokeball"), wxT("Voltorb"), s, 2);
		
        	for (int i = 0; i < 10; i++)
        	{
            		wxButton* testButton = new wxButton(questions_panel, wxID_ANY, "Question", wxPoint(100, 50), wxSize(70,20));
			questionsSizer->Add(testButton);
        	}
		questions_panel->SetSizer(questionsSizer);

		
		//set End Button
		wxBoxSizer* endSizer = new wxBoxSizer(wxHORIZONTAL);
		
		endButton->Bind(wxEVT_BUTTON, &gamePanel::OnEnd, this);
		
		endSizer->Add(endButton);
		end_panel->SetSizer(endSizer);


		// end section to add everything to the panel
		main_sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(30);
		
		main_sizer->Add(q1, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);
		
		main_sizer->Add(q2, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);

        	main_sizer->Add(questions_panel, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(30);

		main_sizer->Add(end_panel, 0, wxALIGN_RIGHT, 0);
		
		SetSizer(main_sizer);
		this->FitInside();
		this->SetScrollRate(5, 5);
	}
	
	void OnEnd(wxCommandEvent& event)
	{
		this->Hide();
	}

private:
	scorer* s = new scorer(10);
	wxPanel *end_panel = new wxPanel(this, wxID_ANY);
	
	wxButton* endButton = new wxButton(end_panel, wxID_ANY, "Finish", wxPoint(100, 50), wxSize(70,20));
};
