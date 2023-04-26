#pragma once

#include <wx/wx.h>
#include "scorer.h"

class Q1Panel : public wxPanel
{
public:
	Q1Panel(wxWindow* parent, wxString question,
		wxString c1, wxString c2, wxString c3, wxString c4, scorer *s, int a) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(400,400))
	{
		wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
		
		init_questionPanel(question);
		init_buttonPanel(c1, c2, c3, c4);
		
		mainSizer->Add(questionPanel, 0, wxALIGN_CENTER, 0);
		mainSizer->AddSpacer(10);
		
		mainSizer->Add(buttonPanel, 0, wxALIGN_CENTER, 0);
		
		this->SetSizer(mainSizer);
        this->SetBackgroundColour(wxColour(*wxGREEN));
		
		sPtr = s;
		answer = a;
	}
private:
	wxPanel* buttonPanel;
	wxPanel* questionPanel;
	
	wxButton* b1;
	wxButton* b2;
	wxButton* b3;
	wxButton* b4;
	
	scorer* sPtr;
	int answer;
	
	void init_questionPanel(wxString q)
	{
		questionPanel = new wxPanel(this, wxID_ANY);
		
		wxStaticText* qTitle = new wxStaticText(questionPanel, wxID_ANY, q);
		qTitle->SetMinSize(wxSize(200, -1));
	}
	
	void init_buttonPanel(wxString C1, wxString C2, wxString C3, wxString C4)
	{
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
