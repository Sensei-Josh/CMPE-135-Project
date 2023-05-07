#pragma once

#include <wx/wx.h>
#include "enum.h"

/*
	Image panel class that paints an image onto a panel
	takes in parent window, file name, file format(png, jpeg, bmp), panel size (i.e. image size you want)
*/

class ImgPanel : public wxPanel
{
public:
	ImgPanel(wxWindow* parent, wxString file, bitType format, wxSize size) : 
		wxPanel(parent, wxID_ANY, wxDefaultPosition, size)
	{
		wxBitmapType type = chooseFactory(format);
		m_image = wxImage(file, type);
		if (!m_image.IsOk()) { return; }
		
		CreateScaledBg();
		
		wxBoxSizer* bg_sizer = new wxBoxSizer(wxVERTICAL);
		this->SetSizer(bg_sizer);
        	this->Layout(); // invokes the paint event
		
		//insert image using a paint event
        	this->Bind(wxEVT_PAINT, &ImgPanel::OnImagePanelPaint, this);		
	}
private:
	wxImage m_image;
    	wxBitmap m_scaledBg;
    	
    	wxBitmapType chooseFactory(bitType type)
    	{
    		//choose Factory return a wxbitmap_type depending on bitType
    		switch(type)
    		{
    			case png: return wxBITMAP_TYPE_PNG;
    			case jpeg: return wxBITMAP_TYPE_JPEG;
    			case bmp: return wxBITMAP_TYPE_BMP;
    			default: return wxBITMAP_TYPE_PNG;
    		};
    	}
    	
	void CreateScaledBg()
    	{
    		//scales image
        	wxSize sz = this->GetSize();
        	m_scaledBg = wxBitmap(m_image.Scale(sz.GetWidth(), sz.GetHeight(), wxIMAGE_QUALITY_HIGH));
    	}
    	
    	void OnImagePanelPaint(wxPaintEvent&)
    	{
    		//paint image onto panel, must be done with an event handler
        	if (this->GetSize() != m_scaledBg.GetSize()) { CreateScaledBg(); }

        	wxPaintDC dc(this);
        	dc.DrawBitmap(m_scaledBg,0,0);
    	}    	
};
