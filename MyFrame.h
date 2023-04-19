#pragma once

#include <wx/wx.h>
#include <iostream>
#include "MyApp.h"
#include "enum.h"
#include "gamePanel.h"

using namespace std;

class MyFrame : public wxFrame
{
public:
    MyFrame(): wxFrame(nullptr, wxID_ANY, "RPS_DOODS Style")
    {
    	init_menu_bar();
    }
    
    wxDECLARE_EVENT_TABLE();
 
private:
	wxSizer* frameSizer = new wxBoxSizer(wxVERTICAL);
	gamePanel* quiz = new gamePanel(this);
	
    void init_menu_bar()
    {
	wxMenu *menuFile = new wxMenu;
    	menuFile->Append(wxID_NEW, "&New Game...\tCtrl-E",
                     "Help string shown in status bar for this menu item");
    	menuFile->AppendSeparator();
    	menuFile->Append(wxID_EXIT);
 
    	wxMenu *menuAbout = new wxMenu;
    	menuAbout->Append(wxID_ABOUT);

	wxMenu *menuSettings = new wxMenu; 
	//menuSettings->Append(SETTINGS);
 
    	wxMenuBar *menuBar = new wxMenuBar;
    	menuBar->Append(menuFile, "&Menu");
	menuBar->Append(menuSettings, "&Settings");
    	menuBar->Append(menuAbout, "&About");
 
    	SetMenuBar( menuBar );
    
    	//SetBackgroundColour(MyApp::BackgroundColour());
    	
    	CreateStatusBar();
    	SetStatusText("Welcome, are you a Pokemon Master?");
    	
    	frameSizer->AddSpacer(20);
    	frameSizer->Add(quiz, 0, wxALIGN_CENTER,0);
    	quiz->Hide();
    	SetSizerAndFit(frameSizer);
    	
    	wxSize size = GetBestSize();
    	SetMinClientSize(size);
    	
    	size = GetSize();
    	size.SetWidth(size.GetWidth() + 40);
    	SetSize(size);    	
    }
    void OnNewGame(wxCommandEvent& event) //new game
    {
    	quiz->Show();
    }

    void OnSettings(wxCommandEvent& event)
    {
	Close(true);
    }

    void OnAbout(wxCommandEvent& event)
    {
    	wxMessageBox("This is a trivia game that will question you about the Pokemon World."
    		"There will be questions about the history, certain Pokemons, and many more."
    		"\n By DOODS:""\n Josh Samoy\n Thien Nguyen\n Albert Lu\n Andy Ngo \n",
                 "About Hello World", wxOK | wxICON_INFORMATION);
    }

    void OnExit(wxCommandEvent& event)
    {
    	
    	Close(true);
    }

};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(wxID_NEW, MyFrame::OnNewGame)
	EVT_MENU(wxID_EXIT, MyFrame::OnExit)
	//EVT_MENU(SETTINGS, MyFrame::OnSettings)
	EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()


