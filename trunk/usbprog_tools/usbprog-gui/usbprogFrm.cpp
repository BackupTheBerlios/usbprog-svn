/*
   usbprog - Change easy the firmware on the usbprog adapter.

   Copyright (C) 2007 Robert Schilling

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

*/

#include "usbprogFrm.h"
#include <wx/arrstr.h>
#include "../lib2/usbprog.h"
#include "../lib2/xmlParser.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
#include "Images/usbprogFrm_WxStaticBitmap1_XPM.xpm"
////Header Include End


// Global Variables:
struct usbprog_context usbprog;

//----------------------------------------------------------------------------
// usbprogFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(usbprogFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(usbprogFrm::OnClose)
	EVT_ACTIVATE(usbprogFrm::usbprogFrmActivate)
	EVT_BUTTON(ID_WXBUTTON5,usbprogFrm::WxButton5Click)
	EVT_BUTTON(ID_WXBUTTON4,usbprogFrm::WxButton4Click)
	EVT_BUTTON(ID_WXBUTTON2,usbprogFrm::WxButton2Click)
	EVT_BUTTON(ID_WXBUTTON3,usbprogFrm::WxButton3Click)
	EVT_BUTTON(ID_WXBUTTON1,usbprogFrm::WxButton1Click)
	EVT_RADIOBUTTON(ID_WXRADIOBUTTON2,usbprogFrm::WxRadioButton2Click)
	EVT_RADIOBUTTON(ID_WXRADIOBUTTON1,usbprogFrm::WxRadioButton1Click)
END_EVENT_TABLE()
////Event Table End

usbprogFrm::usbprogFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
    usbprog_init(&usbprog);
    int devices = usbprog_get_numberof_devices(&usbprog);
    char *buf[devices];
    usbprog_print_devices(&usbprog,buf);

    WxComboBox1->Clear();

    for(int i = 0; i < devices; i++)
    {
        WxComboBox1->Append(wxString(buf[i], wxConvUTF8));
    }
    
    	if(usbprog_online_get_netlist(&usbprog, "http://www.ixbat.de/usbprog/versions.xml")<=0)    //download firmware list
	{
       printWxEdit2(usbprog.error_str);
    }
    else
    {
        printWxEdit2(usbprog.status_str);
        int firmwareNr = usbprog_online_numberof_firmwares(&usbprog);
        char *versions[firmwareNr];
        usbprog_online_print_netlist(&usbprog, versions, firmwareNr);

        WxComboBox2->Clear();

        for(int i = 0; i < firmwareNr; i++)
        {
            WxComboBox2->Append(wxString(versions[i], wxConvUTF8));
        }
    }
}

usbprogFrm::~usbprogFrm()
{
}

void usbprogFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	SetTitle(wxT("usbprog flash tool"));
	SetIcon(wxNullIcon);
	SetSize(8,8,464,328);
	Center();
	

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, wxT("Read more: http://www.embedded-projects.net/usbprog"), wxPoint(128,267), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxStaticText4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxOpenFileDialog1 =  new wxFileDialog(this, wxT("Choose a file"), wxT("C:\\"), wxT(""), wxT("*.bin"), wxOPEN);

	wxBitmap WxStaticBitmap1_BITMAP(usbprogFrm_WxStaticBitmap1_XPM);
	WxStaticBitmap1 = new wxStaticBitmap(this, ID_WXSTATICBITMAP1, WxStaticBitmap1_BITMAP, wxPoint(16,46), wxSize(82,194));
	WxStaticBitmap1->Enable(false);
	WxStaticBitmap1->SetBackgroundColour(wxColour(0,0,153));
	WxStaticBitmap1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton5 = new wxButton(this, ID_WXBUTTON5, wxT("Refresh"), wxPoint(383,75), wxSize(51,21), 0, wxDefaultValidator, wxT("WxButton5"));
	WxButton5->Enable(false);
	WxButton5->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton4 = new wxButton(this, ID_WXBUTTON4, wxT("Refresh"), wxPoint(383,45), wxSize(51,21), 0, wxDefaultValidator, wxT("WxButton4"));
	WxButton4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("(C) 2007 by Benedikt Sauter and Robert Schilling"), wxPoint(128,246), wxDefaultSize, 0, wxT("WxStaticText3"));
	WxStaticText3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton2 = new wxButton(this, ID_WXBUTTON2, wxT("Browse"), wxPoint(383,105), wxSize(51,21), 0, wxDefaultValidator, wxT("WxButton2"));
	WxButton2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxGauge1 = new wxGauge(this, ID_WXGAUGE1, 100, wxPoint(180,178), wxSize(254,16), wxGA_HORIZONTAL, wxDefaultValidator, wxT("WxGauge1"));
	WxGauge1->SetRange(100);
	WxGauge1->SetValue(0);
	WxGauge1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton3 = new wxButton(this, ID_WXBUTTON3, wxT("Update"), wxPoint(270,143), wxSize(75,25), 0, wxDefaultValidator, wxT("WxButton3"));
	WxButton3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton1 = new wxButton(this, ID_WXBUTTON1, wxT("Quit"), wxPoint(359,141), wxSize(75,25), 0, wxDefaultValidator, wxT("WxButton1"));
	WxButton1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT("Status"), wxPoint(128,211), wxDefaultSize, 0, wxT("WxStaticText2"));
	WxStaticText2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, wxT(""), wxPoint(180,209), wxSize(254,19), 0, wxDefaultValidator, wxT("WxEdit2"));
	WxEdit2->Enable(false);
	WxEdit2->SetForegroundColour(wxColour(*wxWHITE));
	WxEdit2->SetBackgroundColour(wxColour(*wxWHITE));
	WxEdit2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, wxT("C:\\"), wxPoint(180,105), wxSize(197,19), 0, wxDefaultValidator, wxT("WxEdit1"));
	WxEdit1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxRadioButton2 = new wxRadioButton(this, ID_WXRADIOBUTTON2, wxT("Local Disk"), wxPoint(102,106), wxSize(69,19), 0, wxDefaultValidator, wxT("WxRadioButton2"));
	WxRadioButton2->SetValue(true);
	WxRadioButton2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxRadioButton1 = new wxRadioButton(this, ID_WXRADIOBUTTON1, wxT("Online Pool"), wxPoint(102,76), wxSize(75,19), 0, wxDefaultValidator, wxT("WxRadioButton1"));
	WxRadioButton1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("Device"), wxPoint(120,52), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	wxArrayString arrayStringFor_WxComboBox2;
	WxComboBox2 = new wxComboBox(this, ID_WXCOMBOBOX2, wxT(""), wxPoint(180,75), wxSize(197,21), arrayStringFor_WxComboBox2, wxCB_READONLY, wxDefaultValidator, wxT("WxComboBox2"));
	WxComboBox2->Enable(false);
	WxComboBox2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	wxArrayString arrayStringFor_WxComboBox1;
	WxComboBox1 = new wxComboBox(this, ID_WXCOMBOBOX1, wxT(""), wxPoint(180,45), wxSize(197,21), arrayStringFor_WxComboBox1, wxCB_READONLY, wxDefaultValidator, wxT("WxComboBox1"));
	WxComboBox1->SetHelpText(wxT("Device"));
	WxComboBox1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxStaticBox1 = new wxStaticBox(this, ID_WXSTATICBOX1, wxT("usbprog flash tool v0.2 (GNU/GPL2)"), wxPoint(4,10), wxSize(447,284));
	WxStaticBox1->SetFont(wxFont(9, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
	////GUI Items Creation End
	// SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
}

void usbprogFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * usbprogFrmActivate
 */
void usbprogFrm::usbprogFrmActivate(wxActivateEvent& event)
{
	// insert your code here
}


/*
 * WxButton3Click
 */
void usbprogFrm::WxButton3Click(wxCommandEvent& event)  //Update Button
{
	// insert your code here
	
	int device = WxComboBox1->GetCurrentSelection();
	int firmware = 0, error = 0;
	
	WxGauge1->SetValue(0);
	
	if(device == -1)   //No Device selceted
	{
        printWxEdit2("No Device Selected");
        return;
    }
    
    WxGauge1->SetValue(20);
	
	if(WxRadioButton1->GetValue() == true)     //online
	{
         firmware = WxComboBox2->GetCurrentSelection();  //Get Firmware from ComboBox
         
       	if(firmware == -1)   //No selceted Firmware
    	{
             printWxEdit2("No Firmware selected");
             return;
        }
    }
    
   /* XMLNode xNode=usbprog.xMainNode.getChildNode("pool");     //Device Check
    for(int i = 0; i < xNode.nChildNode("firmware"); i++)
    {
        if(strcmp(WxComboBox1->GetValue().c_str(), xNode.getChildNode("firmware",i).getAttribute("label")) == 0)
            break;
        else
        {
            printWxEdit2("Wrong Device");
            WxGauge1->SetValue(0);
            return;
        }
        
    }*/
         
  	printWxEdit2("Starting");
    usbprog_update_mode_number(&usbprog, WxComboBox1->GetCurrentSelection());
    WxGauge1->SetValue(40);
    
    if(WxRadioButton1->GetValue() == true)     //Online Pool
	{
        
       if((error = usbprog_flash_netfirmware(&usbprog, firmware)) == -1)
         printWxEdit2(usbprog.error_str);
        WxGauge1->SetValue(60);
    }
    else        //local Firmware
    {
        wxString wxPath = WxEdit1->GetValue();
        char* charPath = (char*)wxPath.c_str(); //converts wxString to charArray
        
        if((error = usbprog_flash_firmware(&usbprog, charPath)) == -1)
                printWxEdit2(usbprog.error_str);
        WxGauge1->SetValue(60);
    }
    
    usbprog_stop_updatemode(&usbprog); 
    WxGauge1->SetValue(80);
    
    int devices = usbprog_get_numberof_devices(&usbprog);
    char *buf[devices];
    usbprog_print_devices(&usbprog,buf);

    WxComboBox1->Clear();

    for(int i = 0; i < devices; i++)
    {
        WxComboBox1->Append(wxString(buf[i], wxConvUTF8));
    }
    
    if(!error)
        printWxEdit2(usbprog.status_str);
    WxGauge1->SetValue(100);
}

/*
 * WxButton1Click
 */
void usbprogFrm::WxButton1Click(wxCommandEvent& event)
{
	// insert your code here
	Destroy();
}


/*
 * WxEdit1Updated
 */
void usbprogFrm::WxEdit1Updated(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * WxButton2Click
 */
void usbprogFrm::WxButton2Click(wxCommandEvent& event)
{
	// insert your code here
	if(WxOpenFileDialog1->ShowModal() == wxID_OK)
    {
        WxEdit1->SetValue(WxOpenFileDialog1->GetPath());
    }
}

/*
 * WxRadioButton1Click  Browse online
 */
void usbprogFrm::WxRadioButton1Click(wxCommandEvent& event)
{
	// insert your code here
	
   if(WxRadioButton1->GetValue() == true)
	{
        WxComboBox2->Enable(true);
        WxEdit1->Enable(false); 
        WxButton2->Enable(false);
        WxButton5->Enable(true);
    }
}

/*
 * WxRadioButton2Click Browse locally
 */
void usbprogFrm::WxRadioButton2Click(wxCommandEvent& event)
{
	// insert your code here
	if(WxRadioButton2->GetValue() == true)
	{
        WxComboBox2->Enable(false);
        WxEdit1->Enable(true);  
        WxButton2->Enable(true);
        WxButton5->Enable(false);
    }
}


/*
 * WxButton5Click
 */
void usbprogFrm::WxButton5Click(wxCommandEvent& event)
{
	// insert your code here

	if(usbprog_online_get_netlist(&usbprog, "http://www.ixbat.de/usbprog/versions.xml")<=0)    //download firmware list
	{
       printWxEdit2(usbprog.error_str);
    }
    else
    {
        printWxEdit2(usbprog.status_str);
        int firmwareNr = usbprog_online_numberof_firmwares(&usbprog); 
        
        if(firmwareNr == -1)
        {
            printWxEdit2(usbprog.error_str);
            return;
        }
            
        char *versions[firmwareNr];
        usbprog_online_print_netlist(&usbprog, versions, firmwareNr);
        
        WxComboBox2->Clear();
        
        for(int i = 0; i < firmwareNr; i++)
        {
            WxComboBox2->Append(wxString(versions[i], wxConvUTF8));
        }
    }
}


/*
 * WxButton4Click
 */
void usbprogFrm::WxButton4Click(wxCommandEvent& event)
{
	// insert your code here
	
    int devices = usbprog_get_numberof_devices(&usbprog);
    char *buf[devices];
    usbprog_print_devices(&usbprog,buf);
    
    WxComboBox1->Clear();
    
    for(int i = 0; i < devices; i++)
    {
        WxComboBox1->Append(wxString(buf[i], wxConvUTF8));
    }
    
    char status[40];
    sprintf(status, "Found %d devices on USB Bus", devices);
    printWxEdit2(status);  
}



// No description
void usbprogFrm::printWxEdit2(char * text)
{
	/* TODO (#1#): Implement usbprogFrm::printWxEdit2() */
	
	WxEdit2->Clear();
	WxEdit2->WriteText(wxString(text, wxConvUTF8));
}

