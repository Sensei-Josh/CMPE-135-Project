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

		int percentage = score * 10; 

		wxString total = wxString::Format(wxT("Your Score: %i | Total Score: %i | Percentage: %i% \n"), score, max, percentage);
		wxStaticText* label1 = new wxStaticText(this, wxID_ANY, total); //wxDefaultPosition, wxDefaultSize, wxST_ELLIPSIZE_START
		label1->SetMinSize(wxSize(350, -1));
		scoreSizer->Add(label1);
		
		//Display Title for the score
		wxString finalTitle = displayFinalTitle(percentage);
		wxStaticText* label2 = new wxStaticText(this, wxID_ANY, finalTitle); // wxDefaultPosition, wxDefaultSize, wxST_ELLIPSIZE_START)
		label2->SetMinSize(wxSize(300, -1));
		scoreSizer->Add(label2);

		mainSizer->AddSpacer(10);

		//display image for the score
		wxString fileName = getFileName(percentage);
		wxImage image(fileName, wxBITMAP_TYPE_PNG);
		wxBitmap bitmap(image); //load image file 
		wxStaticBitmap* staticBitMap = new wxStaticBitmap(this, wxID_ANY, bitmap, wxDefaultPosition, wxDefaultSize); //create bitmap to display the image 
		scoreSizer->Add(staticBitMap, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 10); //add the bitmap controller to the sizer. 
		
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

	wxString getFileName(int val)
	{
		wxString picture; 

		if (val == 100){picture = "images/Arceus.png";}
		else if (val >= 90 && val <= 99) {picture=  "images/Ash_Master.png";}	
		else if (val >= 80 && val <= 89) {picture = "images/TeamRocketBlastingOff.png";}
		else if (val >= 70 && val <= 79) {picture = "images/Chansey.png";}
		else if (val >= 60 && val <= 69) {picture = "images/diglett-and-dugtrio-pack.png";}
		else if (val >= 1 && val <= 59) {picture = "images/farfetch.png";}
		else picture = "images/Magikarp.png";

		return picture;
	}

};
