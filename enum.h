#pragma once

#include <iostream>
#include <wx/wx.h>

using namespace std;

enum ID_Frame1 
{
	SETTINGS = 1

};

enum bitType 
{
	png, jpeg, bmp

};

struct q_param
{
public:
	q_param(wxString img, bitType format, wxString q, wxString c1, wxString c2, wxString c3, wxString c4, int a, int qt) : 
		imgFile(img), type(format), question(q), first(c1), second(c2), third(c3), fourth(c4), answer(a), qType(qt) {}
	q_param(wxString q, wxString c1, wxString c2, wxString c3, wxString c4, int a, int qt) : 
		question(q), first(c1), second(c2), third(c3), fourth(c4), answer(a), qType(qt) {}
	
	wxString imgFile;
	bitType type;
	wxString question;
	wxString first;
	wxString second;
	wxString third;
	wxString fourth;
	int answer;
	int qType;
};

bitType StrToBit(string type)
{
	if(type == "png") return png;
	else if(type == "jpeg") return jpeg;
	else return bmp;
}
