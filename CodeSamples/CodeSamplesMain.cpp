/***************************************************************
 * Name:      CodeSamplesMain.cpp
 * Purpose:   Code for Application Frame
 * Created:   2022-01-30
 **************************************************************/

#include "CodeSamplesMain.h"
#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include <wx/filename.h>
#include <wx/log.h>

//(*InternalHeaders(CodeSamplesFrame)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

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

//(*IdInit(CodeSamplesFrame)
const long CodeSamplesFrame::ID_BUTTON1 = wxNewId();
const long CodeSamplesFrame::ID_PANEL2 = wxNewId();
const long CodeSamplesFrame::ID_BUTTON2 = wxNewId();
const long CodeSamplesFrame::ID_BUTTON3 = wxNewId();
const long CodeSamplesFrame::ID_BUTTON4 = wxNewId();
const long CodeSamplesFrame::ID_STATICBITMAP1 = wxNewId();
const long CodeSamplesFrame::ID_BUTTON5 = wxNewId();
const long CodeSamplesFrame::ID_BITMAPBUTTON1 = wxNewId();
const long CodeSamplesFrame::ID_PANEL1 = wxNewId();
const long CodeSamplesFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CodeSamplesFrame,wxFrame)
    //(*EventTable(CodeSamplesFrame)
    //*)
END_EVENT_TABLE()

CodeSamplesFrame::CodeSamplesFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(CodeSamplesFrame)
    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(800,480));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(288,120), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Geometric Lines"), wxPoint(32,40), wxSize(168,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    drawPanel = new wxPanel(Panel1, ID_PANEL2, wxPoint(240,24), wxSize(536,432), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Colored Lines"), wxPoint(32,96), wxSize(168,34), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Brush Styles"), wxPoint(32,144), wxSize(168,34), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Fonts"), wxPoint(32,192), wxSize(168,34), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("wxLogo.png")).Rescale(wxSize(136,88).GetWidth(),wxSize(136,88).GetHeight())), wxPoint(40,368), wxSize(136,88), 0, _T("ID_STATICBITMAP1"));
    Button5 = new wxButton(Panel1, ID_BUTTON5, _("Bitmaps"), wxPoint(32,240), wxSize(168,34), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BitmapButton1 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("demoBtn.png"))), wxPoint(32,304), wxSize(168,34), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(800, false);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CodeSamplesFrame::OnButton1Click);
    drawPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&CodeSamplesFrame::OndrawPanelPaint,0,this);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CodeSamplesFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CodeSamplesFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CodeSamplesFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CodeSamplesFrame::OnButton5Click);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CodeSamplesFrame::OnBitmapButton1Click);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&CodeSamplesFrame::OnTimer1Trigger);
    //*)

    wxString myPath(wxGetCwd());
    //To Log
    wxLogDebug(myPath);

    //Load Image
    m_imageRGB = new wxImage(myPath + "/codeBlocksIco.png" , wxBITMAP_TYPE_ANY, -1);  // ANY => can load many image formats
    m_imageBitmap = wxBitmap(*m_imageRGB, -1);                  // ...to get the corresponding bitmap

    m_imageWidth = m_imageRGB->GetWidth() ;
    m_imageHeight = m_imageRGB->GetHeight();

    Timer1.Stop();

    srand (time(NULL));
}

CodeSamplesFrame::~CodeSamplesFrame()
{
    //(*Destroy(CodeSamplesFrame)
    //*)
}

void CodeSamplesFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CodeSamplesFrame::OnAbout(wxCommandEvent& event)
{
}

void CodeSamplesFrame::OnButton1Click(wxCommandEvent& event)
{
    Timer1.Stop();
    drawTypes = GEOMETRIC_LINES;
    drawPanel->Refresh();
}

void CodeSamplesFrame::OnButton2Click(wxCommandEvent& event)
{
    Timer1.Stop();
    drawTypes = COLORED_LINES;
    drawPanel->Refresh();
}

void CodeSamplesFrame::OnButton3Click(wxCommandEvent& event)
{
    Timer1.Stop();
    drawTypes = BRUSH_STYLES;
    drawPanel->Refresh();
}

void CodeSamplesFrame::OnButton4Click(wxCommandEvent& event)
{
    Timer1.Stop();
    drawTypes = FONTS;
    drawPanel->Refresh();
}

void CodeSamplesFrame::OnButton5Click(wxCommandEvent& event)
{
    Timer1.Stop();
    drawTypes = BITMAPS;
    drawPanel->Refresh();
}

void CodeSamplesFrame::OndrawPanelPaint(wxPaintEvent& event)
{
    wxPaintDC dc(drawPanel);

    int width  = dc.GetSize().GetWidth();
    int height = dc.GetSize().GetHeight();

    switch(drawTypes){

    case GEOMETRIC_LINES:
    {

        dc.SetPen(*wxGREEN_PEN);

        dc.DrawRectangle(1,1,width-2,height-2);


        int nx = width/20;

        for(int i=0;i<20;i++){
            dc.DrawLine(1,1,1+i*nx,height-2);
        }

        for(int i=0;i<20;i++){
            dc.DrawLine(1,height-2,width-(1+i*nx),1);
        }


        for(int i=0;i<20;i++){
            dc.DrawLine(width-1,1,width-1-(i*nx),height-2);
        }

        for(int i=0;i<20;i++){
            dc.DrawLine(width-1,height-2,width-(1+i*nx),1);
        }


        wxCoord w = rand() % 255 + 1, h = rand() % 150 + 1;

        int x = wxMax(0,width/2-(w/2));
        int y = wxMax(0,height/2-(h/2));

        wxRect rectToDraw(x,y,w,h);
        dc.DrawRectangle(rectToDraw);

    }
    break;


    case COLORED_LINES:
    {
        /* Pen Styles wx Defines
            wxSOLID      =   100,
            wxDOT,
            wxLONG_DASH,
            wxSHORT_DASH,
            wxDOT_DASH,
            wxUSER_DASH,
            */
        int penStyles = wxSOLID;

        wxColor color( 0,255,0);

        for(int i = 0; i<45; i++){

            int r = rand() % 255 + 1;
            int g = rand() % 255 + 1;
            int b = rand() % 255 + 1;

            color.Set(r,g,b);

            wxPen pen (color,(rand()%7+1),penStyles++);
            dc.SetPen(pen);

            if(penStyles >wxUSER_DASH)
                penStyles = wxSOLID;

            dc.DrawLine(rand()%width+1, height-2, rand()%width+1, 1);

        }
    }
        break;
    case BRUSH_STYLES:
    {
        wxColor strokeColor(0,0,0);
        wxColor fillColor(0,0,rand() % 255);

        wxBrush brush(fillColor);
        wxPen pen(strokeColor,4,wxSOLID);

        dc.SetPen(pen);
        dc.SetBrush(brush);
        dc.DrawRectangle(0, 0, 200, 300);

        fillColor.Set(0,rand() % 255,0);
        brush.SetColour(fillColor);
        dc.SetBrush(brush);
        dc.DrawRectangle(40, 80, 200, 300);

        strokeColor.Set(255,0,0);
        fillColor.Set(rand() % 255,0,0);
        brush.SetColour(fillColor);
        dc.SetPen(pen);
        dc.SetBrush(brush);
        dc.DrawRectangle(80, 120, 200, 300);


        strokeColor.Set(255,0,0);
        fillColor.Set(255,50,86);
        brush.SetColour(fillColor);
        brush.SetStyle(wxBDIAGONAL_HATCH);
        dc.SetPen(pen);
        dc.SetBrush(brush);
        dc.DrawRectangle(280, 0, 200, 300);

        strokeColor.Set(255,89,4);
        fillColor.Set(55,90,86);
        brush.SetColour(fillColor);
        brush.SetStyle(wxHORIZONTAL_HATCH);
        dc.SetPen(pen);
        dc.SetBrush(brush);
        dc.DrawRectangle(280+40, 80, 200, 300);

        strokeColor.Set(0,255,255);
        fillColor.Set(25,40,106);
        brush.SetColour(fillColor);
        brush.SetStyle(wxCROSSDIAG_HATCH);
        dc.SetPen(pen);
        dc.SetBrush(brush);
        dc.DrawRectangle(280+80, 128, 200, 300);


    }
    break;
    case FONTS:
    {
        wxFont font(14,wxFONTFAMILY_SWISS, wxNORMAL, wxBOLD);

        for (int i=0;i<30; i++){

            int r = rand() % 255 + 1;
            int g = rand() % 255 + 1;
            int b = rand() % 255 + 1;
            int fontFamily = rand() % 7 + 70;
            int fontSize = rand() % 18 + 4;
            int fontStyle = rand() % 3 + 92;
            if (fontStyle == 92)
                fontStyle = wxNORMAL;

            font.SetPointSize(fontSize);
            font.SetFamily(fontFamily);
            font.SetStyle(fontStyle);

            dc.SetFont(font);
            dc.SetBackgroundMode(wxTRANSPARENT);
            dc.SetTextForeground(wxColor(r,g,b));
            dc.SetBackground(*wxWHITE);
            dc.DrawText("Hello World!!", wxPoint(rand() % width + 10,rand() % height + 10));
        }
    }

        break;
    case BITMAPS:
    {

        for(int i=0;i<height/20;i++){

            for(int j=0;j<6;j++){

                int r = rand() % 255 + 1;
                int g = rand() % 255 + 1;
                int b = rand() % 255 + 1;


                wxFont font(14,wxFONTFAMILY_SWISS, wxNORMAL, wxBOLD);
                dc.SetFont(font);
                dc.SetBackgroundMode(wxTRANSPARENT);
                dc.SetTextForeground(wxColor(r,g,b));
                dc.SetBackground(*wxWHITE);
                dc.DrawText("Hello !!", wxPoint(10+j*90,10+i*(height/20)+5));

            }
        }

        for(int i=0;i<3;i++){

            dc.DrawBitmap(m_imageBitmap, rand() % (width-m_imageWidth) + 1, rand() % (height-m_imageHeight) + 1) ;

        }
    }



    }//switch
}

void CodeSamplesFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    wxLogDebug("Timer Event");

    if(m_ccAutoDemo < 3){
        drawTypes = GEOMETRIC_LINES;
    }else if(m_ccAutoDemo < 6){
        drawTypes = COLORED_LINES;
    }else if(m_ccAutoDemo < 9){
        drawTypes = BRUSH_STYLES;
    }else if(m_ccAutoDemo <12){
        drawTypes = FONTS;
    }else if(m_ccAutoDemo <15){
        drawTypes = BITMAPS;
    }else{
        m_ccAutoDemo = 0;
        drawTypes = GEOMETRIC_LINES;
    }

    drawPanel->Refresh();

    m_ccAutoDemo++;
}

void CodeSamplesFrame::OnBitmapButton1Click(wxCommandEvent& event)
{
    if(m_timerStarted){
        Timer1.Stop();
        m_timerStarted = false;

    }else{
        Timer1.Start();
        m_timerStarted = true;
        m_ccAutoDemo = 0;
    }
}
