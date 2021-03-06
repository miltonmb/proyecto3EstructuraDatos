/***************************************************************
 * Name:      projectGraph3Main.h
 * Purpose:   Defines Application Frame
 * Author:    Milton (miltonmb@unitec.edu)
 * Created:   2017-02-21
 * Copyright: Milton ()
 * License:
 **************************************************************/

#ifndef PROJECTGRAPH3MAIN_H
#define PROJECTGRAPH3MAIN_H

//(*Headers(projectGraph3Frame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
//*)

class projectGraph3Frame: public wxFrame
{
    public:

        projectGraph3Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~projectGraph3Frame();

    private:

        //(*Handlers(projectGraph3Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void Onbtn_showGraphClick(wxCommandEvent& event);
        void Onbtn_loadfileClick(wxCommandEvent& event);
        void Onbtn_loadfileClick1(wxCommandEvent& event);
        //*)

        //(*Identifiers(projectGraph3Frame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT1;
        static const long ID_STATICBITMAP1;
        //*)

        //(*Declarations(projectGraph3Frame)
        wxStaticBitmap* Img_grafo;
        wxButton* btn_loadfile;
        wxButton* btn_other;
        wxButton* btn_showGraph;
        wxStaticText* txt_titulo;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PROJECTGRAPH3MAIN_H
                                    