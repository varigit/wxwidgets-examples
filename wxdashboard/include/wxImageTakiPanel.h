#ifndef WXIMAGETAKIPANEL_H
#define WXIMAGETAKIPANEL_H

#include <wx/wx.h>

class wxImageTakiPanel : public wxWindow
{
    private:
        double m_arcEnd = 0;
        wxBitmap image;

    public:
        wxImageTakiPanel(
                        wxFrame *parent,
                        wxWindowID id,
                        const wxPoint& pos  = wxDefaultPosition,
                        const wxSize& size  = wxDefaultSize,
                        const long style    = 0,
                        const wxString& name= "MyTakiPanel"
                        );
        //virtual ~wxImageTakiPanel();

        void OnPaint(wxPaintEvent & evt);

        void setImage(wxString file, wxBitmapType format);

        void setSpeed(double v){
            m_arcEnd = (v-10)*1.5;
            Refresh();
        }


};

#endif // WXIMAGETAKIPANEL_H
