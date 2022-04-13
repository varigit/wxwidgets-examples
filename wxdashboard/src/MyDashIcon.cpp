#include "MyDashIcon.h"

MyDashIcon::MyDashIcon( wxFrame *parent,
                            wxWindowID id,
                            const wxPoint& pos,
                            const wxSize& size,
                            const long style,
                            const wxValidator& val,
                            const wxString& name)

      : wxPanel((wxPanel*)parent, id, pos, size, wxSIMPLE_BORDER)
{

    pOnImage = NULL;
    pOffImage= NULL;

    Connect(wxEVT_PAINT, wxPaintEventHandler(MyDashIcon::OnPaint));
}

MyDashIcon::~MyDashIcon()
{

}
void MyDashIcon::OnPaint(wxPaintEvent& event)
{

  wxPaintDC dc(this);

  if(m_status){
    if(pOnImage != NULL)
        dc.DrawBitmap( *pOnImage, 0, 0, false );
  }else{
    if(pOffImage != NULL)
        dc.DrawBitmap( *pOffImage, 0, 0, false );
  }

}

void MyDashIcon::SetOnImage(wxString filename){

    if(pOnImage != NULL)
        delete pOnImage;

    pOnImage = new wxBitmap(filename, wxBITMAP_TYPE_PNG);

}
void MyDashIcon::SetOffImage(wxString filename){

    if(pOffImage != NULL)
        delete pOffImage;

    pOffImage = new wxBitmap(filename, wxBITMAP_TYPE_PNG);
}

void MyDashIcon::SetOn(){
    SetStatus(true);
}
void MyDashIcon::SetOff(){
    SetStatus(false);
}
void MyDashIcon::SetStatus(bool onoff){

    if(onoff != m_status){
        m_status = onoff;
        Refresh();
    }
}

