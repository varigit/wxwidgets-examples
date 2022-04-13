/***************************************************************
 * Name:      wxDashBoardMain.h
 * Purpose:   Defines Application Frame
 * Created:   2022-03-27
 **************************************************************/

#ifndef WXDASHBOARDMAIN_H
#define WXDASHBOARDMAIN_H

//(*Headers(wxDashBoardFrame)
#include <MyDashIcon.h>
#include <MyVerticalBar.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/timer.h>
#include <wxImageTakiPanel.h>
//*)

#include <wx/dcclient.h>

class wxDashBoardFrame: public wxFrame
{
    public:

        wxDashBoardFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxDashBoardFrame();

        wxBitmap backGroundImage;
        //wxBitmap takiBackImage;
        //wxBitmap takiTopImage;


    private:

        //(*Handlers(wxDashBoardFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void Onicon3Paint(wxPaintEvent& event);
        void OnSlider1CmdScroll(wxScrollEvent& event);
        //*)

        //(*Identifiers(wxDashBoardFrame)
        static const long ID_CUSTOM5;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_CUSTOM1;
        static const long ID_CUSTOM2;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_CUSTOM3;
        static const long ID_CUSTOM4;
        static const long ID_CUSTOM6;
        static const long ID_CUSTOM7;
        static const long ID_CUSTOM8;
        static const long ID_CUSTOM9;
        static const long ID_CUSTOM10;
        static const long ID_CUSTOM11;
        static const long ID_CUSTOM12;
        static const long ID_CUSTOM13;
        static const long ID_CUSTOM14;
        static const long ID_CUSTOM15;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(wxDashBoardFrame)
        MyDashIcon* icon1;
        MyDashIcon* icon2;
        MyDashIcon* icon4;
        MyDashIcon* icon5;
        MyDashIcon* icon6;
        MyDashIcon* icon7;
        MyDashIcon* icon8;
        MyDashIcon* icon9;
        MyDashIcon* iconA;
        MyDashIcon* iconB;
        MyDashIcon* iconC;
        MyDashIcon* iconD;
        MyVerticalBar* levelBar;
        MyVerticalBar* oilBar;
        wxImageTakiPanel* centralTakiPanel;
        wxStaticText* DateLabel;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* TimeLabel;
        wxStaticText* speedLabel;
        wxStaticText* totalKmLabel;
        wxTimer Timer1;
        //*)


        #define MAX_ICONS 12
        MyDashIcon* icons[MAX_ICONS];

        #define MAX_LED_STATUS 9
        const int leds[MAX_LED_STATUS] = {
            0x0821,
            0x0000,
            0x0080,
            0x0001,
            0x0000,
            0x0010,
            0x0000,
            0x0120,
            0x0000
        };
        int ledStatusIdx = 0;



        DECLARE_EVENT_TABLE()
};

#endif // WXDASHBOARDMAIN_H
