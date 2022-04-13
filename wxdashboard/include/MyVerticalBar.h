#ifndef MYVERTICALBAR_H
#define MYVERTICALBAR_H

#include <wx/wx.h>

class MyVerticalBar : public wxPanel
{
    public:
        MyVerticalBar(
                    wxWindow *parent,
                    wxWindowID id,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    const long style = wxTAB_TRAVERSAL,
                    const wxString& name = "MyVerticalBar"
                    );

        virtual ~MyVerticalBar();

        int GetValue(){
            return(m_val);
        }

        void SetValue(int val){
            if(val != m_val){
                m_val = val;
                this->Refresh();
            }
        }

        void OnPaint(wxPaintEvent& event);

    private:
        int m_maxVal = 100;
        int m_val    = 90;

};

#endif // MYVERTICALBAR_H
