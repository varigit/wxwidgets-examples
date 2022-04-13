#ifndef MYDASHICON_H
#define MYDASHICON_H

#include <wx/wx.h>

class MyDashIcon : public wxPanel
{
    public:
        MyDashIcon(
                    wxFrame *parent,
                    wxWindowID id,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    const long style = 0,
                    const wxValidator& val = wxDefaultValidator,
                    const wxString& name = "MyDashIcon"
                  );

        virtual ~MyDashIcon();

        void OnPaint(wxPaintEvent& event);

        void SetOnImage(wxString filename);
        void SetOffImage(wxString filename);

        void  SetOn();
        void  SetOff();
        void  SetStatus(bool onoff);

        bool   GetStatus(){
            return(m_status);
        }

        bool m_status = false;

    protected:

    private:

        wxBitmap* pOnImage;
        wxBitmap* pOffImage;
};

#endif // MYDASHICON_H
