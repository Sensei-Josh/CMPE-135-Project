#pragma once

//#include <wx/generic/artprov.h>
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
#include "wxImageFrame.h"

using namespace std;

class gamePanel : public wxScrolledWindow
{
public:
	gamePanel(wxWindow* parent, wxFrame* ptr) : wxScrolledWindow(parent, wxID_ANY)
	{
		//fileHandler loader("q_data.txt");
		enabler = ptr;
		
		main_sizer = new wxBoxSizer(wxVERTICAL);
		
		wxMenuItem *newItem = new wxMenuItem(NULL, wxID_NEW, "New"); //to access wxID_NEW

		//set Round title
		wxPanel *round_panel = new ImgPanel(this, "images/PokeTest.png", png, wxSize(200, 100));
		//wxBoxSizer* roundSizer = new wxBoxSizer(wxHORIZONTAL);
		
		//wxStaticText* roundTitle = new wxStaticText(round_panel, wxID_ANY, "The PokeTest: ");
		//roundTitle->SetMinSize(wxSize(200, -1));
		//roundSizer->Add(roundTitle);

		// questions section
		int num_questions = 10;
		questionPanels.reserve(num_questions);
		
		add_questions(num_questions);
		
		//set End Button
		wxBoxSizer* endSizer = new wxBoxSizer(wxHORIZONTAL);
		
		endButton->Bind(wxEVT_BUTTON, &gamePanel::OnEnd, this);
		
		endSizer->Add(endButton);
		end_panel->SetSizer(endSizer);


		// end section to add everything to the panel
		main_sizer->AddSpacer(30);
		main_sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(30);

		for(int i = 0; i < num_questions; i++)
		{
			main_sizer->Add(questionPanels[i], 0, wxALIGN_CENTER, 0);
			main_sizer->AddSpacer(10);
		}

		main_sizer->AddSpacer(10);
		main_sizer->Add(end_panel, 0, wxALIGN_RIGHT, 0);

		SetSizer(main_sizer);
		this->FitInside();
		this->SetScrollRate(5, 5);
	}
	
	void OnEnd(wxCommandEvent& event)
	{	
		enabler->GetMenuBar()->Enable(wxID_NEW, true);
		endDialog dialog(this, _("Final Score"), s->get_max(), s->get_score());
		dialog.ShowModal();
		this->Hide();
	}

private:
	scorer* s = new scorer(10);
	wxPanel *end_panel = new wxPanel(this, wxID_ANY);
	wxSizer* main_sizer;
	wxFrame* enabler;
	
	vector<Q0Panel*> questionPanels;
	wxButton* endButton = new wxButton(end_panel, wxID_ANY, "Finish", wxPoint(100, 50), wxSize(70,20));
	
	void add_questions(int num)
	{
		fileHandler loader("q_data.txt");
		
		for(int i = 0; i < num; i++)
		{
			q_param question = loader.getQuestion();
			if(question.qType == 1) {
				questionPanels.push_back(new Q1Panel(this, question, s));
			} else if(question.qType == 2) {
				questionPanels.push_back(new Q2Panel(this, question, s));
			}
		}
	}
};
