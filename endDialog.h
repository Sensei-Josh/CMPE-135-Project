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
		wxBoxSizer* scoreSizer = new wxBoxSizer(wxVERTICAL); //was wxHorizontal
		//wxPanel scorePanel = new wxPanel(this);
		//wxPanel numPanel = new wxPanel(this);

		wxString total = wxString::Format(wxT("Your Score: %i | Total Score: %i\n"), score, max);
		wxStaticText* label1 = new wxStaticText(this, wxID_ANY, total); //wxDefaultPosition, wxDefaultSize, wxST_ELLIPSIZE_START
		label1->SetMinSize(wxSize(300, -1));
		//label1->Wrap(1000);
		scoreSizer->Add(label1);


		int percentage = score * 10; 

		wxString finalTitle = displayFinalTitle(percentage);
		wxStaticText* label2 = new wxStaticText(this, wxID_ANY, finalTitle); // wxDefaultPosition, wxDefaultSize, wxST_ELLIPSIZE_START)
		label2->SetMinSize(wxSize(300, -1));
		//label2->Wrap(1000);
		scoreSizer->Add(label2);
		
		/*wxStaticText* label2 = new wxStaticText(this, wxID_ANY, _("You got:"));
		label2->SetMinSize(wxSize(200, -1));
		scoreSizer->Add(label2)*/
		
		mainSizer->Add(scoreSizer);
		
		SetSizer(mainSizer);
		
		SetMinSize(wxSize(400,200));
		Fit();
		
	}
private:
	wxString displayFinalTitle(int val)
	{
		wxString titleScore; 
		if (val == 100){titleScore = "A+ for Arceus";}
		else if (val >= 90 && val <= 99) {titleScore =  "A upcoming Pokemon Monster";}	
		else if (val >= 80 && val <= 89) {titleScore =  "B blasting off again";}
		else if (val >= 70 && val <= 79) {titleScore =  "Chansey you later";}
		else if (val >= 60 && val <= 69) {titleScore = "Diglett the Dugtrio help";}
		else if (val >= 1 && val <= 59) {titleScore =  "Farfetch'd from being a Pokemon Master";}
		else titleScore =  "You are a Magikarp.";

		return titleScore; 
	}
};
