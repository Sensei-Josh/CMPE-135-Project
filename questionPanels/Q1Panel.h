#pragma once

#include <wx/wx.h>
#include "Q0Panel.h"
#include "../enum.h"

/*
	question panel for type 1 questions, child of Q0Panel
	components: question, 4 button choices
*/

class Q1Panel : public Q0Panel
{
public:
	Q1Panel(wxWindow* parent, q_param p, scorer *s) : 
			Q0Panel(parent, wxSize(400, 200))
	{
		mainSizer = new wxBoxSizer(wxVERTICAL);
		
		init_questionPanel(p.question);
		init_buttonPanel(p.first, p.second, p.third, p.fourth);
		
		mainSizer->AddSpacer(10);
		mainSizer->Add(questionPanel, 0, wxALIGN_CENTER);
		mainSizer->AddSpacer(10);
		
		mainSizer->Add(buttonPanel, 0, wxALIGN_CENTER, 0);
		mainSizer->AddSpacer(10);
		
		this->SetBackgroundColour(wxColour(*wxRED));
		
		this->SetSizer(mainSizer);
		
		sPtr = s;
		answer = p.answer;
	}
	
	void reset() override
	{
		EnableButtons();
	}
private:
	wxPanel* buttonPanel;
	
	wxButton* b1;
	wxButton* b2;
	wxButton* b3;
	wxButton* b4;
	
	void init_questionPanel(wxString q)
	{
		//write question onto a panel
		questionPanel = new wxPanel(this, wxID_ANY);
		questionPanel->SetForegroundColour(wxColour(*wxWHITE));
		wxStaticText* qTitle = new wxStaticText(questionPanel, wxID_ANY, q);
		qTitle->SetMinSize(wxSize(200, -1));
	}
	
	void init_buttonPanel(wxString C1, wxString C2, wxString C3, wxString C4)
	{
		//create and set choice buttons based on passed arguments
		buttonPanel = new wxPanel(this, wxID_ANY);
		wxBoxSizer* bSizer = new wxBoxSizer(wxVERTICAL);
		
		b1 = new wxButton(buttonPanel, wxID_ANY, C1, wxPoint(100, 50), wxSize(300,30));
		b2 = new wxButton(buttonPanel, wxID_ANY, C2, wxPoint(100, 50), wxSize(300,30));
		b3 = new wxButton(buttonPanel, wxID_ANY, C3, wxPoint(100, 50), wxSize(300,30));
		b4 = new wxButton(buttonPanel, wxID_ANY, C4, wxPoint(100, 50), wxSize(300,30));
		
		bSizer->Add(b1);
		bSizer->AddSpacer(5);
		bSizer->Add(b2);
		bSizer->AddSpacer(5);
		bSizer->Add(b3);
		bSizer->AddSpacer(5);
		bSizer->Add(b4);
		
		b1->Bind(wxEVT_BUTTON, &Q1Panel::Onb1, this);
		b2->Bind(wxEVT_BUTTON, &Q1Panel::Onb2, this);
		b3->Bind(wxEVT_BUTTON, &Q1Panel::Onb3, this);
		b4->Bind(wxEVT_BUTTON, &Q1Panel::Onb4, this);
		
		buttonPanel->SetSizer(bSizer);
	}
	
	void DisableButtons()
	{
		b1->Enable(false);
		b2->Enable(false);
		b3->Enable(false);
		b4->Enable(false);
	}
	
	void EnableButtons()
	{
		b1->Enable(true);
		b2->Enable(true);
		b3->Enable(true);
		b4->Enable(true);
	}
	
	//on each button event
	//check if correct choice then disable buttons to prevent changing answers
	
	void Onb1(wxCommandEvent& event)
	{
		sPtr->check(1, answer);
		DisableButtons();
	}
	
	void Onb2(wxCommandEvent& event)
	{
		sPtr->check(2, answer);
		DisableButtons();
	}
	
	void Onb3(wxCommandEvent& event)
	{
		sPtr->check(3, answer);
		DisableButtons();
	}
	
	void Onb4(wxCommandEvent& event)
	{
		sPtr->check(4, answer);
		DisableButtons();
	}
};
