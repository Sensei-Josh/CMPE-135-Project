// wxWidgets "Hello World" Program
 
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wx.h>
#include <iostream>
#include "MyApp.h"
#include "MyFrame.h"

using namespace std;

wxColour* MyApp::m_backgroundColour = 0;

bool MyApp::OnInit()
{
	MyFrame *frame = new MyFrame();
	frame->Show(true);
	return true;
}

const wxColour& MyApp::BackgroundColour()
{
	m_backgroundColour = new wxColour(0,100,50);
    	
    	return *m_backgroundColour;
}

wxIMPLEMENT_APP(MyApp);

