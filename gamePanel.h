#pragma once

#include <iostream>
#include <vector>

#include <wx/wx.h>
#include "enum.h"
#include "questionPanels/Q0Panel.h"
#include "questionPanels/Q1Panel.h"
#include "questionPanels/Q2Panel.h"

#include "fileHandler.h"
#include "scorer.h"
#include "endDialog.h"

using namespace std;

class gamePanel : public wxScrolledWindow
{
public:
	gamePanel(wxWindow* parent) : wxScrolledWindow(parent, wxID_ANY)
	{
		fileHandler loader("q_data.txt");
		main_sizer = new wxBoxSizer(wxVERTICAL);
		
		//set Round title
		wxPanel *round_panel = new wxPanel(this, wxID_ANY);
		//wxBoxSizer* roundSizer = new wxBoxSizer(wxHORIZONTAL);
		
		wxStaticText* roundTitle = new wxStaticText(round_panel, wxID_ANY, "The Poke Test: ");
		roundTitle->SetMinSize(wxSize(200, -1));
		//roundSizer->Add(roundTitle);

		// questions section
		
		q_param quest1 = loader.getQuestion();
		q_param quest2 = loader.getQuestion();
		q_param quest3 = loader.getQuestion();
		q_param quest4 = loader.getQuestion();
		q_param quest5 = loader.getQuestion();
		q_param quest6 = loader.getQuestion();
		q_param quest7 = loader.getQuestion();
		q_param quest8 = loader.getQuestion();
		q_param quest9 = loader.getQuestion();
		q_param quest10 = loader.getQuestion();
		
		Q0Panel* q1 = new Q1Panel(this, quest1, s);
		Q0Panel* q2 = new Q2Panel(this, quest2, s);
		Q0Panel* q3 = new Q2Panel(this, quest3, s);
		Q0Panel* q4 = new Q1Panel(this, quest4, s);
		Q0Panel* q5 = new Q1Panel(this, quest5, s);
		Q0Panel* q6 = new Q1Panel(this, quest6, s);
		Q0Panel* q7 = new Q2Panel(this, quest7, s);
		Q0Panel* q8 = new Q1Panel(this, quest8, s);
		Q0Panel* q9 = new Q1Panel(this, quest9, s);
		Q0Panel* q10 = new Q2Panel(this, quest10, s);
		
		//set End Button
		wxBoxSizer* endSizer = new wxBoxSizer(wxHORIZONTAL);
		
		endButton->Bind(wxEVT_BUTTON, &gamePanel::OnEnd, this);
		
		endSizer->Add(endButton);
		end_panel->SetSizer(endSizer);


		// end section to add everything to the panel
		main_sizer->AddSpacer(30);
		main_sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(30);
		
		main_sizer->Add(q1, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);
		
		main_sizer->Add(q2, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);

		main_sizer->Add(q3, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);
		
		main_sizer->Add(q4, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);
		
		main_sizer->Add(q5, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);
		
		main_sizer->Add(q6, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);
		
		main_sizer->Add(q7, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);
		
		main_sizer->Add(q8, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);
		
		main_sizer->Add(q9, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);
		
		main_sizer->Add(q10, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(10);

		main_sizer->AddSpacer(10);
		main_sizer->Add(end_panel, 0, wxALIGN_RIGHT, 0);
		
		SetSizer(main_sizer);
		this->FitInside();
		this->SetScrollRate(5, 5);
	}
	
	void OnEnd(wxCommandEvent& event)
	{	
		endDialog dialog(this, _("Final Score"), s->get_max(), s->get_score());
		dialog.ShowModal();
		this->Hide();
	}

private:
	scorer* s = new scorer(10);
	wxPanel *end_panel = new wxPanel(this, wxID_ANY);
	vector<Q0Panel> panels;
	wxSizer* main_sizer;
	
	wxButton* endButton = new wxButton(end_panel, wxID_ANY, "Finish", wxPoint(100, 50), wxSize(70,20));
};
