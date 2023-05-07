#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "enum.h"

using namespace std;

/*
	file handler class responsible for reading the file information
	puts question information onto a q_param struct
*/

class fileHandler
{
public:
	fileHandler(string data)
	{
		index = 0;
		q_info.reserve(10);
		string type;
		
		loader.open(data);
		
		//read file using getline
		while(getline(loader, type))
		{
			//first info of a question is question type
			//load question a certain way depending on type
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
		//type 1: regular question with multiple choice
		string question, c1, c2, c3, c4, answer;
		
		//read question, then 4 multiple choice then the answer
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
		//type 2: a type 1 but dependent on an image
		string img, format, question, c1, c2, c3, c4, answer;
		
		//read image file name and format
		//then read question 4 multiple choices then the answer
		getline(loader, img);
		getline(loader, format);
		getline(loader, question);
		getline(loader, c1);
		getline(loader, c2);
		getline(loader, c3);
		getline(loader, c4);
		getline(loader, answer);
		
		//for Windows machines, takes away possible extra spaces in read image and format
		//otherwise get an error, however code works fine on Linux even if you do not use erase
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
