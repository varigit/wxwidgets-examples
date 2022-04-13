#include "wxImageTakiPanel.h"

wxImageTakiPanel::wxImageTakiPanel(
                                    wxFrame* parent,
                                    wxWindowID id,
                                    const wxPoint& pos,
                                    const wxSize& size,
                                    const long style,
                                    const wxString& name
                                    ) :
    wxWindow((wxWindow*)parent, id, pos, size)
{
    Connect(wxEVT_PAINT, wxPaintEventHandler(wxImageTakiPanel::OnPaint));
}

void wxImageTakiPanel::setImage(wxString file, wxBitmapType format){

    // load the file... ideally add a check to see if loading was successful
    image.LoadFile(file, format);
}

void wxImageTakiPanel::OnPaint(wxPaintEvent & evt)
{
    wxPaintDC dc(this);

    int  penw   = 20;
    int wid     = 410;
    int offset  = 180 + 45;

    dc.SetPen( wxPen( wxColor(0,255,0), penw ) );

    dc.DrawEllipticArc(wxPoint(224-(wid/2),225-(wid/2)),wxSize(wid,wid),offset-m_arcEnd,offset);

    dc.DrawBitmap( image, -2, 0, false );

}

