// -*- C++ -*- generated by wxGlade 0.4.1 on Fri Feb  9 21:15:48 2007

#include "mainwindow.h"


MainWindow::MainWindow(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
    // begin wxGlade: MainWindow::MainWindow
    label_4 = new wxStaticText(this, -1, wxT("USB Device"));
    label_5 = new wxStaticText(this, -1, wxT("VID "));
    text_ctrl_2 = new wxTextCtrl(this, -1, wxT(""));
    label_6 = new wxStaticText(this, -1, wxT(" PID "));
    text_ctrl_3 = new wxTextCtrl(this, -1, wxT(""));
    button_8 = new wxButton(this, -1, wxT("Find"));
    label_3 = new wxStaticText(this, -1, wxT("URL"));
    text_ctrl_4 = new wxTextCtrl(this, -1, wxT(""));
    Download = new wxButton(this, -1, wxT("Download"));
    label_7 = new wxStaticText(this, -1, wxT("Firmware Pool"));
    const wxString combo_box_1_choices[] = {
        
    };
    combo_box_1 = new wxComboBox(this, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 0, combo_box_1_choices, wxCB_DROPDOWN);
    label_8 = new wxStaticText(this, -1, wxT("Custom"));
    text_ctrl_5 = new wxTextCtrl(this, -1, wxT(""));
    button_4 = new wxButton(this, -1, wxT("Browse"));
    label_9 = new wxStaticText(this, -1, wxT("Log"));
    text_ctrl_6 = new wxTextCtrl(this, -1, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    button_5 = new wxButton(this, -1, wxT("Cancel"));
    button_6 = new wxButton(this, -1, wxT("Quit"));
    button_7 = new wxButton(this, -1, wxT("OK"));
    label_2 = new wxStaticText(this, -1, wxT("Created by Benedikt Sauter"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);

    set_properties();
    do_layout();
    // end wxGlade
}


void MainWindow::set_properties()
{
    // begin wxGlade: MainWindow::set_properties
    SetTitle(wxT("usbprog Online"));
    label_4->SetFont(wxFont(10, wxDEFAULT, wxNORMAL, wxBOLD, 0, wxT("")));
    label_3->SetFont(wxFont(10, wxDEFAULT, wxNORMAL, wxBOLD, 0, wxT("")));
    text_ctrl_4->SetMinSize(wxSize(200, 27));
    label_7->SetFont(wxFont(10, wxDEFAULT, wxNORMAL, wxBOLD, 0, wxT("")));
    label_8->SetFont(wxFont(10, wxDEFAULT, wxNORMAL, wxBOLD, 0, wxT("")));
    text_ctrl_5->SetMinSize(wxSize(200, 27));
    label_9->SetFont(wxFont(10, wxDEFAULT, wxNORMAL, wxBOLD, 0, wxT("")));
    // end wxGlade
}


void MainWindow::do_layout()
{
    // begin wxGlade: MainWindow::do_layout
    wxBoxSizer* sizer_7 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_8 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_12 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_11 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_10 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_9 = new wxBoxSizer(wxHORIZONTAL);
    sizer_8->Add(label_4, 0, wxSHAPED|wxADJUST_MINSIZE, 0);
    sizer_9->Add(label_5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_9->Add(text_ctrl_2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_9->Add(label_6, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_9->Add(text_ctrl_3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_9->Add(button_8, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_8->Add(sizer_9, 1, wxEXPAND, 0);
    sizer_8->Add(label_3, 0, wxADJUST_MINSIZE, 0);
    sizer_10->Add(text_ctrl_4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    sizer_10->Add(Download, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_8->Add(sizer_10, 1, wxEXPAND, 0);
    sizer_8->Add(label_7, 0, wxADJUST_MINSIZE, 0);
    sizer_8->Add(combo_box_1, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_8->Add(label_8, 0, wxADJUST_MINSIZE, 0);
    sizer_11->Add(text_ctrl_5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    sizer_11->Add(button_4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_8->Add(sizer_11, 1, wxEXPAND, 0);
    sizer_8->Add(label_9, 0, wxADJUST_MINSIZE, 0);
    sizer_8->Add(text_ctrl_6, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_12->Add(button_5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_12->Add(button_6, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_12->Add(button_7, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    sizer_8->Add(sizer_12, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    sizer_7->Add(sizer_8, 1, wxEXPAND, 0);
    sizer_7->Add(label_2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxADJUST_MINSIZE, 0);
    SetAutoLayout(true);
    SetSizer(sizer_7);
    sizer_7->Fit(this);
    sizer_7->SetSizeHints(this);
    Layout();
    Centre();
    // end wxGlade
}

