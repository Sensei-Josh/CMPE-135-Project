#pragma once

#include <wx/wx.h>
#include "../scorer.h"

/*
	parent question panel class used for Liskov Substitution Principle
*/

class Q0Panel : public wxPanel
{
public:
	Q0Panel(wxWindow* parent, wxSize size) : wxPanel(parent, wxID_ANY, wxDefaultPosition, size) {}
	wxBoxSizer* mainSizer;
	wxPanel* questionPanel;
	
	scorer* sPtr;
	int answer;
	
	virtual void reset() {};
};
