#pragma once

#include <wx/wx.h>

class ImgPanel : public wxPanel
{
public:
	ImgPanel(wxWindow* parent, wxString file, wxBitmapType format) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(250,250))
	{
		m_image = wxImage(file, format);
		if (!m_image.IsOk()) { return; }
		
		CreateScaledBg();
		
		wxBoxSizer* bg_sizer = new wxBoxSizer(wxVERTICAL);
		this->SetSizer(bg_sizer);
        	this->Layout();

        	this->Bind(wxEVT_PAINT, &ImgPanel::OnImagePanelPaint, this);		
	}
private:
	wxImage m_image;
    	wxBitmap m_scaledBg;
    	
	void CreateScaledBg()
    	{
        	wxSize sz = this->GetSize();
        	m_scaledBg = wxBitmap(m_image.Scale(sz.GetWidth(), sz.GetHeight(), wxIMAGE_QUALITY_HIGH));
    	}
    	
    	void OnImagePanelPaint(wxPaintEvent&)
    	{
        	if (this->GetSize() != m_scaledBg.GetSize()) { CreateScaledBg(); }

        	wxPaintDC dc(this);
        	dc.DrawBitmap(m_scaledBg,0,0);
    	}    	
};
