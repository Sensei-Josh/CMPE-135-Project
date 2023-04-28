#pragma once

#include <iostream>
#include <wx/wx.h>

using namespace std;

enum ID_Frame1 
{
	SETTINGS = 1

};

struct q_param
{
public:
	q_param(wxString img, wxBitmapType format, wxString q, wxString c1, wxString c2, wxString c3, wxString c4) : 
		imgFile(img), type(format), question(q), first(c1), second(c2), third(c3), fourth(c4) {}
	q_param(wxString q, wxString c1, wxString c2, wxString c3, wxString c4) : 
		question(q), first(c1), second(c2), third(c3), fourth(c4) {}
	wxString imgFile;
	wxBitmapType type;
	wxString question;
	wxString first;
	wxString second;
	wxString third;
	wxString fourth;
};
