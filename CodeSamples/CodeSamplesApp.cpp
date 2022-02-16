/***************************************************************
 * Name:      CodeSamplesApp.cpp
 * Purpose:   Code for Application Class
 * Created:   2022-01-30
 **************************************************************/

#include "CodeSamplesApp.h"

//(*AppHeaders
#include "CodeSamplesMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(CodeSamplesApp);

bool CodeSamplesApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	CodeSamplesFrame* Frame = new CodeSamplesFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)

#ifdef __aarch64__
    /* The following hack allow starting the application in full screen mode,
     * ignoring the toolbar in Weston
     */
    CodeSamplesFrame* Frame = new CodeSamplesFrame(0);
    Frame->ShowFullScreen(true, wxFULLSCREEN_NOTOOLBAR | wxFULLSCREEN_NOSTATUSBAR | wxFULLSCREEN_NOBORDER);
    SetTopWindow(Frame);
#endif /* __aarch64__ */

    return wxsOK;
}
