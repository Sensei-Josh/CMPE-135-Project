#pragma once

#include <wx/wx.h>
#include "enum.h"
#include "gamePanel.h"

using namespace std;

class wxImageFrame: public wxFrame
{
public:
    wxImageFrame(wxWindow *parent, wxString file, wxBitmapType format) : 
        wxFrame(parent, wxID_ANY, "RPS DOODS Style")
	{
		init_bg_img(file, format);
        init_menu_bar();
        init_frame_size();

        CreateStatusBar();
    	SetStatusText("Welcome, are you a Pokemon Master?"); 
	}

    wxDECLARE_EVENT_TABLE();

private:

    wxPanel* quiz;
    wxPanel* m_imagePanel;
    wxImage m_image;
    wxBitmap m_scaledBg;

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
	menuSettings->Append(SETTINGS, "&Settings...\tCtrl-S", "System Settings");
 
    	wxMenuBar *menuBar = new wxMenuBar;
    	menuBar->Append(menuFile, "&Menu");
	menuBar->Append(menuSettings, "&Settings");
    	menuBar->Append(menuAbout, "&About");
 
    	SetMenuBar( menuBar );
    }

    void init_bg_img(wxString file, wxBitmapType format)
    {
        m_image = wxImage(file, format);
        if (!m_image.IsOk()) { return; }

    
        m_imagePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(600,700));
        CreateScaledBg();

        quiz = new gamePanel(m_imagePanel);

        wxBoxSizer* bg_sizer = new wxBoxSizer(wxVERTICAL);
        bg_sizer->Add(quiz, 1, wxEXPAND);

        quiz->Show(false);

        m_imagePanel->SetSizer(bg_sizer);
        Layout();

        m_imagePanel->Bind(wxEVT_PAINT, &wxImageFrame::OnImagePanelPaint, this);
    }

    void init_frame_size()
    {
        wxBoxSizer* frameSizer = new wxBoxSizer(wxVERTICAL);

        frameSizer->Add(m_imagePanel, 0, wxEXPAND, 0);

        this->SetSizerAndFit(frameSizer);
    }

    void OnImagePanelPaint(wxPaintEvent&)
    {
        if (m_imagePanel->GetSize() != m_scaledBg.GetSize()) { CreateScaledBg(); }

        wxPaintDC dc(m_imagePanel);
        dc.DrawBitmap(m_scaledBg,0,0);
    }

    void CreateScaledBg()
    {
        wxSize sz = m_imagePanel->GetSize();
        m_scaledBg = wxBitmap(m_image.Scale(sz.GetWidth(), sz.GetHeight(), wxIMAGE_QUALITY_HIGH));
    }

    void OnNewGame(wxCommandEvent& event) //new game
    {
    	quiz->Show(true);
        Layout();
    }

    void OnAbout(wxCommandEvent& event)
    {
    	wxMessageBox("This is a trivia game that will question you about the Pokemon World."
    		"There will be questions about the history, certain Pokemons, and many more."
    		"\n By DOODS:""\n Josh Samoy\n Thien Nguyen\n Albert Lu\n Andy Ngo \n",
                 "About Hello World", wxOK | wxICON_INFORMATION);
    }

    void OnSettings(wxCommandEvent& event)
    {
    	Close(true);
    }

    void OnExit(wxCommandEvent& event)
    {
    	Close(true);
    }
};

wxBEGIN_EVENT_TABLE(wxImageFrame, wxFrame)
	EVT_MENU(wxID_NEW, wxImageFrame::OnNewGame)
	EVT_MENU(wxID_EXIT, wxImageFrame::OnExit)
	EVT_MENU(SETTINGS, wxImageFrame::OnSettings)
	EVT_MENU(wxID_ABOUT, wxImageFrame::OnAbout)
wxEND_EVENT_TABLE()

