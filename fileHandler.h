#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "enum.h"

using namespace std;

class fileHandler : public wxPanel
{
public:
	fileHandler(string data)
	{
		index = 0;
		q_info.reserve(10);
		string type;
		
		loader.open(data);
		
		while(getline(loader, type))
		{
			switch(type[0])
			{
				case '1': load_t1();
					break;
				case '2': load_t2();
					break;
				default: break;
			}
		}
		
		loader.close();
	}
	
	q_param getQuestion()
	{
		q_param quest = q_info[index];
		index++;
		return quest;
	}
private:
	vector<q_param> q_info;
	fstream loader;
	int index;
	
	void load_t1()
	{
		string question, c1, c2, c3, c4, answer;
		
	
		getline(loader, question);
		getline(loader, c1);
		getline(loader, c2);
		getline(loader, c3);
		getline(loader, c4);
		getline(loader, answer);
		
		//wxWidgets cannot directly convert String to wxString
		//Must convert String to char * then use wxString::FromUTF8()
		
		q_param quest(wxString::FromUTF8(question.data()), wxString::FromUTF8(c1.data()), 
			wxString::FromUTF8(c2.data()), wxString::FromUTF8(c3.data()), wxString::FromUTF8(c4.data()), 
				stoi(answer), 1);
		q_info.push_back(quest);
		
		//get the space separator in file
		getline(loader, question); 
		
		return;
	}
	
	void load_t2()
	{
		string img, format, question, c1, c2, c3, c4, answer;
		
		getline(loader, img);
		getline(loader, format);
		getline(loader, question);
		getline(loader, c1);
		getline(loader, c2);
		getline(loader, c3);
		getline(loader, c4);
		getline(loader, answer);

		img.erase(img.find_last_not_of("\t\n\r ") + 1);
		format.erase(format.find_last_not_of("\t\n\r ") + 1);
		
		q_param quest(wxString::FromUTF8(img.data()), StrToBit(format), 
			wxString::FromUTF8(question.data()), wxString::FromUTF8(c1.data()), 
				wxString::FromUTF8(c2.data()), wxString::FromUTF8(c3.data()), 
					wxString::FromUTF8(c4.data()), stoi(answer), 2);
		q_info.push_back(quest);
		
		//get the space seperator in file
		getline(loader, img);
		
		return;
	}
	
	
};
