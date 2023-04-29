// wxWidgets "Hello World" Program
 
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wx.h>
#include <wx/sizer.h>
#include <iostream>
#include "MyApp.h"
#include "wxImageFrame.h"

using namespace std;

/*bool MyApp::OnInit()
{
	wxInitAllImageHandlers();
	
	MyFrame *frame = new MyFrame();
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}

wxIMPLEMENT_APP(MyApp);*/

bool MyApp::OnInit()
        {
            // call to be able to insert images
            wxInitAllImageHandlers();
            
            wxImageFrame* frame = new wxImageFrame(NULL, "images/bg.bmp", wxBITMAP_TYPE_BMP);
            
            frame->Show();
            return true;
        } 

IMPLEMENT_APP(MyApp);

