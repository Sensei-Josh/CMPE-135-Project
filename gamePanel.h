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

		// questions section
		int num_questions = 10;
		questionPanels.reserve(num_questions);
		
		add_questions(num_questions);
		add_endButton();

		// end section to add everything to the panel
		addTitle();
		addQuestionPanels(num_questions);
		main_sizer->AddSpacer(10);
		main_sizer->Add(end_panel, 0, wxALIGN_RIGHT, 0);

		setScroll_Sizer();
	}
	
	void OnEnd(wxCommandEvent& event)
	{	
		//re-enable the new game menu option
		enabler->GetMenuBar()->Enable(wxID_NEW, true);
		
		//generate a dialog box to show players total score
		endDialog dialog(this, _("Final Score"), s->get_max(), s->get_score());
		dialog.ShowModal();
		
		//hide gamePanel and reset the game
		this->Hide();
		reset_game();
	}
	
	void reset_game()
	{
		//reset the questions
		
		s->reset();
		
		for(auto & it : questionPanels)
		{
			it->reset();
		}
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
		//open data file
		fileHandler loader("q_data.txt");
		
		//read through the file and create questions then add to questionPanels vector
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
	
	void add_endButton()
	{
		//set End Button
		wxBoxSizer* endSizer = new wxBoxSizer(wxHORIZONTAL);
		endButton->Bind(wxEVT_BUTTON, &gamePanel::OnEnd, this);
		
		endSizer->Add(endButton);
		end_panel->SetSizer(endSizer);
	}
	
	void setScroll_Sizer()
	{
		SetSizer(main_sizer);
		this->FitInside();
		this->SetScrollRate(5, 5);
	}
	
	void addTitle()
	{
		//set Round title
		wxPanel *round_panel = new ImgPanel(this, "images/PokeTest.png", png, wxSize(200, 100));
		
		main_sizer->AddSpacer(30);
		main_sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
		main_sizer->AddSpacer(30);
	}
	
	void addQuestionPanels(int num_questions)
	{
		for(int i = 0; i < num_questions; i++)
		{
			main_sizer->Add(questionPanels[i], 0, wxALIGN_CENTER, 0);
			main_sizer->AddSpacer(10);
		}
	}
};
