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
		char *q, *one, *two, *three, *four;
		
		getline(loader, question);
		getline(loader, c1);
		getline(loader, c2);
		getline(loader, c3);
		getline(loader, c4);
		getline(loader, answer);
		
		//wxWidgets cannot directly convert String to wxString
		//Must convert String to char * then use wxString::FromUTF8()
		q = question.data();
		one = c1.data();
		two = c2.data();
		three = c3.data();
		four = c4.data();
		
		q_param quest(wxString::FromUTF8(q), wxString::FromUTF8(one), 
			wxString::FromUTF8(two), wxString::FromUTF8(three), wxString::FromUTF8(four), stoi(answer));
		q_info.push_back(quest);
		
		//get the space separator in file
		getline(loader, question); 
		
		return;
	}
	
	void load_t2()
	{
		string img, format, question, c1, c2, c3, c4, answer;
		char *pic, *q, *one, *two, *three, *four;
		
		getline(loader, img);
		getline(loader, format);
		getline(loader, question);
		getline(loader, c1);
		getline(loader, c2);
		getline(loader, c3);
		getline(loader, c4);
		getline(loader, answer);
		
		pic = img.data();
		q = question.data();
		one = c1.data();
		two = c2.data();
		three = c3.data();
		four = c4.data();
		
		q_param quest(wxString::FromUTF8(pic), StrToBit(format),wxString::FromUTF8(q), wxString::FromUTF8(one), 
			wxString::FromUTF8(two), wxString::FromUTF8(three), wxString::FromUTF8(four), stoi(answer));
		q_info.push_back(quest);
		
		//get the space seperator in file
		getline(loader, img);
		
		return;
	}
	
	
};
