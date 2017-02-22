/***************************************************************
 * Name:      projectGraph3Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Milton (miltonmb@unitec.edu)
 * Created:   2017-02-21
 * Copyright: Milton ()
 * License:
 **************************************************************/

#include "projectGraph3Main.h"
#include <wx/msgdlg.h>
#include <boost/graph/undirected_graph.hpp>
#include <boost/graph/graphviz.hpp>

//(*InternalHeaders(projectGraph3Frame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//helper functions
typedef boost::undirected_graph<boost::no_property> Graph;
Graph g;
std::string filename = "output.dot";
std::ofstream fout(filename.c_str());
bool loading = false;

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

//(*IdInit(projectGraph3Frame)
const long projectGraph3Frame::ID_BUTTON1 = wxNewId();
const long projectGraph3Frame::ID_BUTTON2 = wxNewId();
const long projectGraph3Frame::ID_BUTTON3 = wxNewId();
const long projectGraph3Frame::ID_STATICTEXT1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(projectGraph3Frame,wxFrame)
    //(*EventTable(projectGraph3Frame)
    //*)
END_EVENT_TABLE()

projectGraph3Frame::projectGraph3Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(projectGraph3Frame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    btn_loadfile = new wxButton(this, ID_BUTTON1, _("Load File"), wxPoint(160,80), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btn_showGraph = new wxButton(this, ID_BUTTON2, _("Create"), wxPoint(160,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    btn_other = new wxButton(this, ID_BUTTON3, _("Other..."), wxPoint(160,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    txt_titulo = new wxStaticText(this, ID_STATICTEXT1, _("PROJECT #3"), wxPoint(112,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont txt_tituloFont(22,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("padmaa"),wxFONTENCODING_DEFAULT);
    txt_titulo->SetFont(txt_tituloFont);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&projectGraph3Frame::Onbtn_loadfileClick1);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&projectGraph3Frame::Onbtn_showGraphClick);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&projectGraph3Frame::OnClose);
    //*)
}

projectGraph3Frame::~projectGraph3Frame()
{
    //(*Destroy(projectGraph3Frame)
    //*)
}

void projectGraph3Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void projectGraph3Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void projectGraph3Frame::OnClose(wxCloseEvent& event)
{
    Close();
}


void projectGraph3Frame::Onbtn_showGraphClick(wxCommandEvent& event)
{
    if(loading == true){
    boost::write_graphviz(fout,g);
    wxMessageDialog(NULL,"Se ha creado el grafo correctamente","Cargado",wxOK|wxCENTER,wxDefaultPosition).ShowModal();
    }else{
        wxMessageDialog(NULL,"Lo siento!, cargue primero los datos!","Cargado",wxOK|wxCENTER,wxDefaultPosition).ShowModal();
    }
}

void projectGraph3Frame::Onbtn_loadfileClick1(wxCommandEvent& event)
{
     if(loading == false){
        Graph::vertex_descriptor v0 = g.add_vertex();
        Graph::vertex_descriptor v1 = g.add_vertex();
        Graph::vertex_descriptor v2 = g.add_vertex();
        boost::add_edge(v0,v1,g);
        boost::add_edge(v1,v0,g);
        boost::add_edge(v0,v2,g);
        loading = true;
        wxMessageDialog(NULL,"Ya Cargo","Cargado",wxOK|wxCENTER,wxDefaultPosition).ShowModal();

    }else{
        wxMessageDialog(NULL,"Ya cargo los datos!","Cargado",wxOK|wxCENTER,wxDefaultPosition).ShowModal();
    }
}
