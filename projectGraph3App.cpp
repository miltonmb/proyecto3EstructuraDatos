/***************************************************************
 * Name:      projectGraph3App.cpp
 * Purpose:   Code for Application Class
 * Author:    Milton (miltonmb@unitec.edu)
 * Created:   2017-02-21
 * Copyright: Milton ()
 * License:
 **************************************************************/

#include "projectGraph3App.h"

//(*AppHeaders
#include "projectGraph3Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(projectGraph3App);

bool projectGraph3App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	projectGraph3Frame* Frame = new projectGraph3Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
        