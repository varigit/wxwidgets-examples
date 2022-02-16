/***************************************************************
 * Name:      CodeSamplesMain.h
 * Purpose:   Defines Application Frame
 * Created:   2022-01-30
 **************************************************************/

#ifndef CODESAMPLESMAIN_H
#define CODESAMPLESMAIN_H

//(*Headers(CodeSamplesFrame)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/timer.h>
//*)

#include <wx/image.h>
#include <wx/bitmap.h>


enum {
    GEOMETRIC_LINES = 1,
    COLORED_LINES,
    BRUSH_STYLES,
    FONTS,
    BITMAPS

};



class CodeSamplesFrame: public wxFrame
{
    public:

        int drawTypes = 0;

        CodeSamplesFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~CodeSamplesFrame();

    private:

        //(*Handlers(CodeSamplesFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OndrawPanelPaint(wxPaintEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(CodeSamplesFrame)
        static const long ID_BUTTON1;
        static const long ID_PANEL2;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_STATICBITMAP1;
        static const long ID_BUTTON5;
        static const long ID_BITMAPBUTTON1;
        static const long ID_PANEL1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(CodeSamplesFrame)
        wxBitmapButton* BitmapButton1;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxButton* Button5;
        wxPanel* Panel1;
        wxPanel* drawPanel;
        wxStaticBitmap* StaticBitmap1;
        wxTimer Timer1;
        //*)

        DECLARE_EVENT_TABLE()

        int m_imageWidth ;
        int m_imageHeight ;
        wxBitmap m_imageBitmap ;	// used to display the image
        wxImage *m_imageRGB ;		// used to load the image
        bool m_timerStarted = false;
        int  m_ccAutoDemo = 0;
};

#endif // CODESAMPLESMAIN_H
