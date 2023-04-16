#pragma once

#include <wx/wx.h>

using namespace std;
 
class MyApp : public wxApp
{
private:
    static wxColour* m_backgroundColour;
public:
    virtual bool OnInit() override;
    static const wxColour& BackgroundColour();
};

