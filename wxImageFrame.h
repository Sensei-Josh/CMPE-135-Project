#pragma once

#include <wx/wx.h>
#include <wx/sound.h>
#include "enum.h"
#include "gamePanel.h"

using namespace std;

class wxImageFrame: public wxFrame
{
public:
    wxImageFrame(wxWindow *parent, wxString file, wxBitmapType format) : 
        wxFrame(parent, wxID_ANY, "RPS DOODS Style")
	{
		init_bg_img(file, format);	//set the background image
        	init_menu_bar();		//sets menu bar
        	init_frame_size();		//sets sizer

        	CreateStatusBar();
    		SetStatusText("Welcome, are you a Pokemon Master?"); 
	}

    wxDECLARE_EVENT_TABLE();

private:

    wxPanel* quiz;		//the game panel
    wxPanel* m_imagePanel;	//background image panel
    wxImage m_image;		//background image
    wxBitmap m_scaledBg;	//background image bitmap

    void init_menu_bar()
    {
    	//set menu items
        wxMenu *menuFile = new wxMenu;
    	menuFile->Append(wxID_NEW, "&New Game...\tCtrl-E",
                     "Help string shown in status bar for this menu item");
    	menuFile->AppendSeparator();
    	menuFile->Append(wxID_EXIT);
 
    	wxMenu *menuAbout = new wxMenu;
    	menuAbout->Append(wxID_ABOUT);
 	
 	//add menu items to menu bar
    	wxMenuBar *menuBar = new wxMenuBar;
    	menuBar->Append(menuFile, "&Menu");
    	menuBar->Append(menuAbout, "&About");
 
    	SetMenuBar( menuBar );
    }

    void init_bg_img(wxString file, wxBitmapType format)
    {
    	//create wxImage
        m_image = wxImage(file, format);
        if (!m_image.IsOk()) { return; }

    
        m_imagePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(600,700));
        CreateScaledBg();	//scale image
	
	//set gamePanel onto background image panel
	//puts gamePanel on top of background image, otherwise switch between game and background image
        quiz = new gamePanel(m_imagePanel, this); 

        wxBoxSizer* bg_sizer = new wxBoxSizer(wxVERTICAL);
        bg_sizer->Add(quiz, 1, wxEXPAND);

        quiz->Show(false); // hide gamePanel until new game

        m_imagePanel->SetSizer(bg_sizer);
        Layout(); // invokes paint event
	
	//bind paint event to panel you want to insert image
        m_imagePanel->Bind(wxEVT_PAINT, &wxImageFrame::OnImagePanelPaint, this);
    }

    void init_frame_size()
    {
        wxBoxSizer* frameSizer = new wxBoxSizer(wxVERTICAL);
	
	//add background image to sizer
        frameSizer->Add(m_imagePanel, 0, wxEXPAND, 0);

        this->SetSizerAndFit(frameSizer);
    }

    void OnImagePanelPaint(wxPaintEvent&)
    {
    	//paints image onto panel, must be done via event handler
        if (m_imagePanel->GetSize() != m_scaledBg.GetSize()) { CreateScaledBg(); }

        wxPaintDC dc(m_imagePanel);
        dc.DrawBitmap(m_scaledBg,0,0);
    }

    void CreateScaledBg()
    {
    	//scales background image
        wxSize sz = m_imagePanel->GetSize();
        m_scaledBg = wxBitmap(m_image.Scale(sz.GetWidth(), sz.GetHeight(), wxIMAGE_QUALITY_HIGH));
    }

    void OnNewGame(wxCommandEvent& event) //new game
    {
    	//reveal gamePanel, disable new game menu option
    	quiz->Show(true);
        GetMenuBar()->Enable(wxID_NEW, false);
        Layout(); // Need this so scrolling window shows when window not maximized!
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

wxBEGIN_EVENT_TABLE(wxImageFrame, wxFrame)
	EVT_MENU(wxID_NEW, wxImageFrame::OnNewGame)
	EVT_MENU(wxID_EXIT, wxImageFrame::OnExit)
	EVT_MENU(wxID_ABOUT, wxImageFrame::OnAbout)
wxEND_EVENT_TABLE()

