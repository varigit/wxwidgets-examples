#include <wx/wx.h>
#include "MyVerticalBar.h"

MyVerticalBar::MyVerticalBar(
                            wxWindow *parent,
                            wxWindowID id,
                            const wxPoint& pos,
                            const wxSize& size,
                            const long style,
                            const wxString& name)

      : wxPanel((wxWindow*)parent, id, pos, size, wxSUNKEN_BORDER)
{
    Connect(wxEVT_PAINT, wxPaintEventHandler(MyVerticalBar::OnPaint));
}

void MyVerticalBar::OnPaint(wxPaintEvent& event)
{
  wxPaintDC dc(this);

  int width = GetSize().GetWidth();
  int height= GetSize().GetHeight();

  float h = (height/(m_maxVal*1.0))*m_val;

  if(m_val < (m_maxVal/3))
    dc.SetBrush(*wxYELLOW_BRUSH);
  else
    dc.SetBrush(*wxGREEN_BRUSH); // green filling

  dc.DrawRectangle(1,height-h,width-4,height-2);
}

MyVerticalBar::~MyVerticalBar()
{
    //dtor
}

