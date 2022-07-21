/***************************************************************
 * Name:      wxDashBoardApp.cpp
 * Purpose:   Code for Application Class
 * Created:   2022-03-27
 **************************************************************/

#include "wxDashBoardApp.h"

//(*AppHeaders
#include "wxDashBoardMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxDashBoardApp);

bool wxDashBoardApp::OnInit()
{
    wxDashBoardFrame* Frame;

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Frame = new wxDashBoardFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)

#ifdef __aarch64__
    Frame->ShowFullScreen(true, wxFULLSCREEN_NOBORDER);
#endif // __aarch64__

    return wxsOK;

}
