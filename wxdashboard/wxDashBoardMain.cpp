/***************************************************************
 * Name:      wxDashBoardMain.cpp
 * Purpose:   Code for Application Frame
 * Created:   2022-03-27
 **************************************************************/

#include "wxDashBoardMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxDashBoardFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/log.h>
#include <iostream>
using namespace std;

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxDashBoardFrame)
const long wxDashBoardFrame::ID_CUSTOM5 = wxNewId();
const long wxDashBoardFrame::ID_STATICTEXT1 = wxNewId();
const long wxDashBoardFrame::ID_STATICTEXT2 = wxNewId();
const long wxDashBoardFrame::ID_STATICTEXT3 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM1 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM2 = wxNewId();
const long wxDashBoardFrame::ID_STATICTEXT5 = wxNewId();
const long wxDashBoardFrame::ID_STATICTEXT6 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM3 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM4 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM6 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM7 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM8 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM9 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM10 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM11 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM12 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM13 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM14 = wxNewId();
const long wxDashBoardFrame::ID_CUSTOM15 = wxNewId();
const long wxDashBoardFrame::ID_STATICTEXT4 = wxNewId();
const long wxDashBoardFrame::ID_STATICTEXT7 = wxNewId();
const long wxDashBoardFrame::ID_STATICTEXT8 = wxNewId();
const long wxDashBoardFrame::ID_TIMER1 = wxNewId();
//*)

const long ID_VERTICAL_BAR = wxNewId();

BEGIN_EVENT_TABLE(wxDashBoardFrame,wxFrame)
    //(*EventTable(wxDashBoardFrame)
    //*)
END_EVENT_TABLE()

wxString GetImageDir(){

#ifdef __aarch64__
    return("/usr/share/wxDashBoard/images/");
#else
    return("./images/");
#endif
}

wxDashBoardFrame::wxDashBoardFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxDashBoardFrame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(800,480));
    SetBackgroundColour(wxColour(144,144,144));
    centralTakiPanel = new wxImageTakiPanel(this,ID_CUSTOM5,wxPoint(184,16),wxSize(452,452),1,_T("ID_CUSTOM5"));
    DateLabel = new wxStaticText(this, ID_STATICTEXT1, _("12 April 2020"), wxPoint(16,440), wxSize(160,25), 0, _T("ID_STATICTEXT1"));
    DateLabel->SetForegroundColour(wxColour(255,255,255));
    wxFont DateLabelFont(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    DateLabel->SetFont(DateLabelFont);
    TimeLabel = new wxStaticText(this, ID_STATICTEXT2, _("8:30:00"), wxPoint(672,440), wxSize(49,25), 0, _T("ID_STATICTEXT2"));
    TimeLabel->SetForegroundColour(wxColour(255,255,255));
    wxFont TimeLabelFont(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    TimeLabel->SetFont(TimeLabelFont);
    speedLabel = new wxStaticText(this, ID_STATICTEXT3, _("100"), wxPoint(336,200), wxSize(144,72), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_STATICTEXT3"));
    speedLabel->SetForegroundColour(wxColour(255,255,255));
    wxFont speedLabelFont(50,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    speedLabel->SetFont(speedLabelFont);
    oilBar = new MyVerticalBar(this,ID_CUSTOM1,wxPoint(64,152),wxSize(19,184),1,_T("ID_CUSTOM1"));
    levelBar = new MyVerticalBar(this,ID_CUSTOM2,wxPoint(100,152),wxSize(19,184),1,_T("ID_CUSTOM2"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT5, _("Oil"), wxPoint(64,128), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText1->SetForegroundColour(wxColour(255,255,255));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT6, _("Fuel"), wxPoint(96,128), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText2->SetForegroundColour(wxColour(255,255,255));
    icon1 = new MyDashIcon(this,ID_CUSTOM3,wxPoint(626,96),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM3"));
    icon2 = new MyDashIcon(this,ID_CUSTOM4,wxPoint(682,96),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM4"));
    icon4 = new MyDashIcon(this,ID_CUSTOM6,wxPoint(626,168),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM6"));
    icon5 = new MyDashIcon(this,ID_CUSTOM7,wxPoint(682,168),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM7"));
    icon6 = new MyDashIcon(this,ID_CUSTOM8,wxPoint(738,168),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM8"));
    icon7 = new MyDashIcon(this,ID_CUSTOM9,wxPoint(626,240),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM9"));
    icon8 = new MyDashIcon(this,ID_CUSTOM10,wxPoint(682,240),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM10"));
    icon9 = new MyDashIcon(this,ID_CUSTOM11,wxPoint(738,240),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM11"));
    iconA = new MyDashIcon(this,ID_CUSTOM12,wxPoint(626,308),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM12"));
    iconB = new MyDashIcon(this,ID_CUSTOM13,wxPoint(682,308),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM13"));
    iconC = new MyDashIcon(this,ID_CUSTOM14,wxPoint(738,308),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM14"));
    iconD = new MyDashIcon(this,ID_CUSTOM15,wxPoint(738,96),wxSize(52,52),1,wxDefaultValidator,_T("ID_CUSTOM15"));
    totalKmLabel = new wxStaticText(this, ID_STATICTEXT4, _("100001"), wxPoint(358,352), wxSize(112,32), 0, _T("ID_STATICTEXT4"));
    totalKmLabel->SetForegroundColour(wxColour(96,96,96));
    wxFont totalKmLabelFont(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    totalKmLabel->SetFont(totalKmLabelFont);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT7, _("km"), wxPoint(470,362), wxSize(48,17), 0, _T("ID_STATICTEXT7"));
    StaticText3->SetForegroundColour(wxColour(144,144,144));
    wxFont StaticText3Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT8, _("km/h"), wxPoint(392,272), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(100, false);

    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&wxDashBoardFrame::OnTimer1Trigger);
    Connect(wxEVT_PAINT,(wxObjectEventFunction)&wxDashBoardFrame::OnPaint);
    //*)


    centralTakiPanel->setImage(GetImageDir() + "03_taki_top.png",wxBITMAP_TYPE_JPEG);


    int idx = 0;
    icons[idx++]=icon1;
    icons[idx++]=icon2;
    icons[idx++]=iconD;
    icons[idx++]=icon4;
    icons[idx++]=icon5;
    icons[idx++]=icon6;
    icons[idx++]=icon7;
    icons[idx++]=icon8;
    icons[idx++]=icon9;
    icons[idx++]=iconA;
    icons[idx++]=iconB;
    icons[idx++]=iconC;

    icon1->SetOffImage(GetImageDir() + "01_ico_green.png");
    icon1->SetOnImage( GetImageDir() + "01_ico_red.png");

    icon2->SetOffImage(GetImageDir() + "02_ico_green.png");
    icon2->SetOnImage( GetImageDir() + "02_ico_red.png");

    iconD->SetOffImage(GetImageDir() + "03_ico_green.png");
    iconD->SetOnImage( GetImageDir() + "03_ico_red.png");

    icon4->SetOffImage(GetImageDir() + "04_ico_green.png");
    icon4->SetOnImage( GetImageDir() + "04_ico_red.png");

    icon5->SetOffImage(GetImageDir() + "05_ico_green.png");
    icon5->SetOnImage( GetImageDir() + "05_ico_red.png");

    icon6->SetOffImage(GetImageDir() + "06_ico_green.png");
    icon6->SetOnImage( GetImageDir() + "06_ico_red.png");

    icon7->SetOffImage(GetImageDir() + "07_ico_green.png");
    icon7->SetOnImage( GetImageDir() + "07_ico_red.png");

    icon8->SetOffImage(GetImageDir() + "08_ico_green.png");
    icon8->SetOnImage( GetImageDir() + "08_ico_red.png");

    icon9->SetOffImage(GetImageDir() + "09_ico_green.png");
    icon9->SetOnImage( GetImageDir() + "09_ico_red.png");

    iconA->SetOffImage(GetImageDir() + "0A_ico_green.png");
    iconA->SetOnImage( GetImageDir() + "0A_ico_red.png");

    iconB->SetOffImage(GetImageDir() + "0B_ico_green.png");
    iconB->SetOnImage( GetImageDir() + "0B_ico_red.png");

    iconC->SetOffImage(GetImageDir() + "0C_ico_green.png");
    iconC->SetOnImage( GetImageDir() + "0C_ico_red.png");

    //Logger
    //wxLog* logger = new wxLogStream(&cout);
    //wxLog::SetActiveTarget(logger);
    wxLogDebug("Start Program\n");

    wxString myPath(wxGetCwd());
    //To Log
    wxLogDebug(myPath);

    //Load GUI images
    backGroundImage.LoadFile(GetImageDir() + "01_screen_background.png", wxBITMAP_TYPE_JPEG);

}

wxDashBoardFrame::~wxDashBoardFrame()
{
    //(*Destroy(wxDashBoardFrame)
    //*)
}

void wxDashBoardFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxDashBoardFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxDashBoardFrame::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    dc.DrawBitmap( backGroundImage, 0, 0, false );
}

int ccUpdate = 0;
int speed = 45;
float totalKm=100000;
int inc_vel = 5;
int ccIconTimer=0;

void wxDashBoardFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    //wxLogDebug("Timer Event\n");

    if(ccUpdate == 0){
        //DateTime
        wxString temp3 = ("");
        wxDateTime now = wxDateTime::Now();

        temp3 += wxString::Format("%d ", now.GetDay());
        temp3 += wxString::Format("%s ", now.GetEnglishMonthName(now.GetMonth()));
        temp3 += wxString::Format("%d ", now.GetYear());
        DateLabel->SetLabel(temp3);

        temp3 = "";
        temp3 += wxString::Format("%02d:", now.GetHour());
        temp3 += wxString::Format("%02d:", now.GetMinute());
        temp3 += wxString::Format("%02d" , now.GetSecond());
        TimeLabel->SetLabel(temp3);

    }

    ccUpdate++;
    if( ccUpdate >= 5){
        ccUpdate = 0;
    }

    //Speed
    speed  += inc_vel;

    centralTakiPanel->setSpeed(speed);

    speedLabel->SetLabel(wxString::Format("%d", speed));

    totalKm += abs(inc_vel * 0.018);
    totalKmLabel->SetLabel(wxString::Format("%d", (int)totalKm));

	if(speed >= 180){
        inc_vel = -inc_vel;
	}
    else{
        if(speed <= 15){
            inc_vel = -inc_vel;
        }
    }

    ccIconTimer++;
    int mask = 0x00001;
    if((ccIconTimer % 30)==0){
        for(int i=0;i<MAX_ICONS;i++){
            icons[i]->SetStatus(leds[ledStatusIdx]&mask);
            mask = mask << 1;
        }
        ledStatusIdx++;
        if(ledStatusIdx>MAX_LED_STATUS)
            ledStatusIdx =0;

        oilBar->SetValue(oilBar->GetValue()-(abs(inc_vel)/6));
        levelBar->SetValue(levelBar->GetValue()-abs(inc_vel/3));
    }
}
