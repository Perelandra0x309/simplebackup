/*  SimpleBackup- written by Brian Hill, perelandra777@gmail.com

    This program was written for Haiku (http://www.haiku-os.org) and provides an


    --Protected under General Public License--

    Copyright (C) 1999-2009,  Brian Hill <perelandra777@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#include "SimpleBackup.h"
#include "BackupQueue.h"

//#define SB_version "1.20"
//const rgb_color bg_color = {216,216,216,0};
/*
uchar tuBits[] = {	0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x12, 0x12, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x1b, 0x1b,
					0x1b, 0xb, 0x3f, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0xb, 0x1b,
					0x1b, 0xb, 0x1e, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x1b,
					0x1b, 0xb, 0x1e, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x1b,
					0x1b, 0xb, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0xb, 0x1b,
					0x1b, 0x1b, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x3f, 0x3f, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b
					};
uchar tdBits[] = {	0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x12, 0x12, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x1b, 0x1b,
					0x1b, 0xb, 0x3f, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0xb, 0x1b,
					0x1b, 0xb, 0x1e, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x1b,
					0x1b, 0xb, 0x1e, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x1b,
					0x1b, 0xb, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0xb, 0x1b,
					0x1b, 0x1b, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x3f, 0x3f, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b
					};
#if USE_DATE_CONTROL
uchar incuBits[]={	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x1b, 0x18, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x1b, 0x1b, 0x1b, 0x18, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x13, 0x1e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xb, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x13, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x13, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18
					};
uchar incsBits[]={	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x1b, 0x18, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x1b, 0x1b, 0x1b, 0x18, 0x13, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xb, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					};
uchar decuBits[]={	0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0xb, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x13, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x16, 0xb, 0x13, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x13, 0x13, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x16, 0xb, 0x13, 0x13, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x16, 0xb, 0x13, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0xb, 0x13, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18
					};
uchar decsBits[]={	0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0xb, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x16, 0xb, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x16, 0xb, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x16, 0xb, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0xb, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18
					};
#endif
*/
//float button_height;
//void uuencode(entry_ref, bool);
//void uudecode(entry_ref, bool);
//void testzip(entry_ref);
//void zipsplit(entry_ref, int, bool, bool);
//float max(const float&,const float&);

int main()
{	SBApp myApp;
	myApp.Run();
	return(0);
}
void SBApp::printhelp()
{	printf(	"SimpleBackup v%s by Brian Hill\n"
			"Usage: SimpleBackup [settings_file] [backup_file]\n"
			"If settings_file is specified, settings will be restored from\n"
			"that previously configured and saved settings file.\n"
			"If backup_file is specified (must follow a settings_file\n"
			"arguement) saving of the backup into backup_file is started\n"
			"automatically\n",SB_version);
	return;
}
SBApp::SBApp()	:BApplication(APPLICATION_SIGNATURE), ready_to_run(false)
{
	aWindow = new SBWindow(BRect(200,50,850,570));
}
SBApp::~SBApp()
{	}
void SBApp::ReadyToRun()
{	//aWindow->Show();
	ready_to_run = true;
}
void SBApp::ArgvReceived(int32 argc, char** argv)
{	if(strcmp(argv[1],"-q")==0 || strcmp(argv[1],"--quit")==0)
	{	be_app->PostMessage(B_QUIT_REQUESTED); return; }
	if(strcmp(argv[1],"-h")==0 || strcmp(argv[1],"--help")==0)
	{	printhelp(); return; }
	if(argc!=2 && argc!=3) { printhelp(); return; }
	BPath settingsPath;
	find_directory(B_USER_SETTINGS_DIRECTORY, &settingsPath);
	settingsPath.Append(DEFAULT_SETTINGS_DIR);
	BString backupString;
	BEntry settingsEntry(argv[1]);
	if(!settingsEntry.Exists())
	{	settingsPath.Append(argv[1]);
		settingsEntry.SetTo(settingsPath.Path());
		if(!settingsEntry.Exists())
		{	printf("Error: Could not find settings file %s\n"
					"Using settings from last session.\n",argv[1]);
			return;
		}
	}
	//aWindow->UpdateIfNeeded();//?????
	entry_ref settingsRef; //Send message to restore settings
	settingsEntry.GetRef(&settingsRef);
	if(argc == 2){//only restore settings
		BMessage *setmsg = new BMessage(RESTORES_REF);
		setmsg->AddRef("refs",&settingsRef);
		aWindow->PostMessage(setmsg);
		delete setmsg;
	}
	else if(argc==3)//send message to start backup
	{	BEntry backupEntry(argv[2]);
		bool newBackup = !(backupEntry.Exists());
		char backupName[B_FILE_NAME_LENGTH];
		backupEntry.GetName(backupName);
		backupEntry.GetParent(&backupEntry);
		if(!backupEntry.Exists())
		{	printf("Error: invalid target directory\n");
			return;
		}
		entry_ref backupRef;
		backupEntry.GetRef(&backupRef);
		BMessage *savemsg = new BMessage(NEW_BACKUP);
		savemsg->AddRef("settings_ref",&settingsRef);
		savemsg->AddRef("directory",&backupRef);
		savemsg->AddString("name",backupName);
		savemsg->AddBool("newBackup",newBackup);
		aWindow->PostMessage(savemsg);
	}
}

//Controls View
/*SBControls::SBControls(BRect& size, BPicture *tupic, BPicture *tdpic, SBSettings *settingsView)
	:BView(size, "Backup options", B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_FRAME_EVENTS)
{	SetViewColor(gui_background_color);
	
	/*
	BRect viewRect(5,4,Bounds().right - 5,4);
	//Browse button
	viewRect.left = viewRect.right - (be_plain_font->StringWidth("Browse") + 20);
	viewRect.OffsetBy(0,-3);
	browseSrc = new BButton(viewRect, "Browse", "Browse", new BMessage(SRC_PANEL));
	
	//Source textbox
	viewRect.left = 5;
	viewRect.right = browseSrc->Frame().left - 5;
	backupSrc = new BTextControl(viewRect, "Backup Source", "Source:", "/boot/home",
									new BMessage(CHECK_SRC));
	backupSrc->SetDivider(be_plain_font->StringWidth(backupSrc->Label()) + 4);
	
	AddChild(backupSrc);
	AddChild(browseSrc);
	
	//Backup buttons
	button_height = browseSrc->Bounds().Height();
	viewRect.Set(0,0,155,30);
	viewRect.OffsetTo(5, browseSrc->Frame().bottom + 3);
	viewRect.bottom = viewRect.top + button_height;
	newB = new BButton(viewRect, "New", "Create New Backup", new BMessage(NEW_PANEL));
	AddChild(newB);
	viewRect.OffsetBy(viewRect.Width() + 5, 0);
	updateB = new BButton(viewRect, "Update", "Update Existing Backup",
								new BMessage(UPDATE_PANEL));
	AddChild(updateB);
	viewRect.OffsetTo(Bounds().right - 20, updateB->Frame().top +
							(updateB->Frame().Height() - 20.0)/2.0 );
	viewRect.right = viewRect.left + 15;
	viewRect.bottom = viewRect.top + 20;
	togglePB = new BPictureButton(viewRect, "Toggle Settings", tupic, tdpic,
								new BMessage(TOGGLE_S), B_TWO_STATE_BUTTON,
								B_FOLLOW_LEFT | B_FOLLOW_TOP, B_WILL_DRAW);
	AddChild(togglePB);
	
	browseSrc = new BButton("Browse", "Browse", new BMessage(SRC_PANEL));
	backupSrc = new BTextControl("Backup Source", "Source:", "/boot/home",
								new BMessage(CHECK_SRC));
	//backupSrc->SetAlignment(B_ALIGN_LEFT, B_ALIGN_LEFT);
	//backupSrc->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNSET));
	newB = new BButton("New", "Create New Backup", new BMessage(NEW_PANEL));
	newB->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNSET));
	updateB = new BButton(BRect(0, 1, 80, 1), "Update", "Update Existing Backup",
								new BMessage(UPDATE_PANEL));
	updateB->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNSET));
	BRect viewRect(0,0,15,20);
	togglePB = new BPictureButton(viewRect, "Toggle Settings", tupic, tdpic,
								new BMessage(TOGGLE_S), B_TWO_STATE_BUTTON);
	
	// Build the layout
	SetLayout(new BGroupLayout(B_HORIZONTAL));
	AddChild(BGroupLayoutBuilder(B_VERTICAL, gui_control_padding)
		.Add(BGroupLayoutBuilder(B_HORIZONTAL, gui_control_padding)
			.Add(backupSrc)
			.Add(browseSrc)
		)
		.Add(BGroupLayoutBuilder(B_HORIZONTAL, gui_control_padding)
			.Add(newB)
			.Add(updateB)
			//.Add(togglePB)
		)
		.Add(settingsView)
		.SetInsets(gui_group_inset, gui_group_inset, gui_group_inset, gui_group_inset)
	);
}
SBControls::~SBControls()
{	}*/
/*void SBControls::FrameResized(float width, float height)
{	browseSrc->MoveTo(width - browseSrc->Frame().Width() - 3, browseSrc->Frame().top);
	backupSrc->ResizeTo(browseSrc->Frame().left - 10, backupSrc->Frame().Height());
	togglePB->MoveTo(width - togglePB->Frame().Width() - 5, togglePB->Frame().top);
	newB->ResizeTo((togglePB->Frame().left - newB->Frame().left - 10)/2 - 3, newB->Frame().Height());
	updateB->MoveTo(newB->Frame().right + 5, updateB->Frame().top);
	updateB->ResizeTo(togglePB->Frame().left - newB->Frame().right - 10, updateB->Frame().Height());
	
	//newB->Draw(newB->Bounds());
}*/


/*SBDateControl::SBDateControl(BRect& size, char* name, BPicture *incuP, BPicture *incsP,
								BPicture *decuP, BPicture *decsP)
	:BView(size, name, B_FOLLOW_NONE, B_WILL_DRAW)
{	SetViewColor(gui_background_color);
	long i;
	BRect viewRect(Bounds());
	viewRect.right = viewRect.left + StringWidth("0")*2 + 10;
	monthControl = new BTextControl(viewRect, "Month", NULL, "01", NULL);
	monthControl->TextView()->SetMaxBytes(2);
	monthControl->TextView()->MakeSelectable(false);
	//monthControl->TextView()->SetViewColor(bg_color);
	//monthControl->TextView()->MakeEditable(false);
	//monthControl->SetEnabled(false);
	for (i = 0; i < 256; i++) monthControl->TextView()->DisallowChar(i);
	for (i = '0'; i <= '9'; i++) monthControl->TextView()->AllowChar(i);
	monthControl->TextView()->AllowChar(B_BACKSPACE);
	AddChild(monthControl);
	viewRect.OffsetTo(viewRect.right, viewRect.top);
	viewRect.right = viewRect.left + StringWidth("0")*2 + 15;
	dayControl = new BTextControl(viewRect, "Day", "/", "01", NULL);
	dayControl->SetDivider(be_plain_font->StringWidth(dayControl->Label()) + 1);
	dayControl->TextView()->SetMaxBytes(2);
	dayControl->TextView()->MakeSelectable(false);
	for (i = 0; i < 256; i++) dayControl->TextView()->DisallowChar(i);
	for (i = '0'; i <= '9'; i++) dayControl->TextView()->AllowChar(i);
	dayControl->TextView()->AllowChar(B_BACKSPACE);
	AddChild(dayControl);
	viewRect.OffsetTo(viewRect.right, viewRect.top);
	viewRect.right = viewRect.left + StringWidth("0")*4 + 15;
	yearControl = new BTextControl(viewRect, "Year", "/", "1999", NULL);
	yearControl->SetDivider(be_plain_font->StringWidth(yearControl->Label()) + 1);
	yearControl->TextView()->SetMaxBytes(4);
	yearControl->TextView()->MakeSelectable(false);
	for (i = 0; i < 256; i++) yearControl->TextView()->DisallowChar(i);
	for (i = '0'; i <= '9'; i++) yearControl->TextView()->AllowChar(i);
	yearControl->TextView()->AllowChar(B_BACKSPACE);
	AddChild(yearControl);
#if USE_DATE_CONTROL
	viewRect.Set(0,0,15,9);
	viewRect.OffsetTo(yearControl->Frame().right+2, yearControl->Frame().top);
	incrementPB = new BPictureButton(viewRect, "Increment", incuP, incsP,
								new BMessage(SB_NOTHING), B_ONE_STATE_BUTTON);
	AddChild(incrementPB);
	viewRect.OffsetTo(incrementPB->Frame().left, incrementPB->Frame().bottom+1);
	decrementPB = new BPictureButton(viewRect, "Decrement", decuP, decsP,
								new BMessage(SB_NOTHING), B_ONE_STATE_BUTTON);
	AddChild(decrementPB);
#endif
	ResizeTo(Bounds().Width(), monthControl->Frame().Height());
}*/
/*SBListItem::SBListItem(const char* entryPath, bool cstm)
	:BStringItem(entryPath)
{	isCustom = cstm; }*/
/*SWDOpenFilePanel::SWDOpenFilePanel(BMessenger* target = NULL,
							entry_ref *panel_directory = NULL,
							uint32 node_flavors = 0,
							bool allow_multiple_selection = true,
							BMessage *messge = NULL,
							BRefFilter *filter = NULL,
							bool modal = false,
							bool hide_when_done = true)
	:BFilePanel(B_OPEN_PANEL, target, panel_directory, node_flavors,
				allow_multiple_selection, messge, filter, modal, hide_when_done)
	,BHandler("SelectWorkingDirectoryOpenPanel")
	,button_command(0), hide_on_SWD(true)
{	Window()->Lock();
	Window()->AddHandler(this);
	SetButtonLabel(B_DEFAULT_BUTTON, "Select");
	BView *panelView = Window()->ChildAt(0);
	BRect viewRect(panelView->FindView("cancel button")->Frame());
	viewRect.left = 10;  viewRect.right = viewRect.left + be_plain_font->StringWidth("Select Current Directory") + 20;
	currentDirB = new BButton(viewRect,"select current","Select Current Directory",
							new BMessage(CURRENT_S), B_FOLLOW_LEFT | B_FOLLOW_BOTTOM);
	panelView->AddChild(currentDirB);
	currentDirB->SetTarget(this);
	Window()->Unlock();
}
/*void SWDOpenFilePanel::MessageReceived(BMessage *msg)
{	switch (msg->what)
	{	case CURRENT_S: {
			BMessage selmsg(button_command);
			entry_ref dir_ref;
			GetPanelDirectory(&dir_ref);
			selmsg.AddRef("refs", &dir_ref);
			if(hide_on_SWD) Hide();
			Messenger().SendMessage(&selmsg);
			break; }
		default:
			BHandler::MessageReceived(msg);
			break;
	}
}*/
/*void uuencode(entry_ref srcRef, bool closeT)
{	BEntry uueEntry("/bin/uuencode");
	if(!uueEntry.Exists())
	{	(new BAlert("", "UUencode command does not exist in /bin", "OK",
					NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	int arg_c = 0;
	char *arg_v[6];
	BEntry srcEntry(&srcRef);
	if(!srcEntry.Exists())
	{	(new BAlert("", "Invalid source", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	arg_v[arg_c++] = "/bin/sh";
	arg_v[arg_c++] = "--login";
	arg_v[arg_c++] = "-c";
	BPath srcPath(&srcEntry);
	char *name = new char[B_FILE_NAME_LENGTH];
	srcEntry.GetName(name);
	BString uueArg("echo Starting encoding; uuencode ");
	uueArg += srcPath.Path(); uueArg += " ";
	uueArg += name; uueArg += " > ";
	uueArg += srcPath.Path(); uueArg += ".uue";
	if(!closeT) { uueArg += "; read -p \"Finished\nPress Enter to close terminal\""; }
	arg_v[arg_c++] = (char*)uueArg.String();
	char *termSig = "application/x-vnd.Haiku-Terminal";
	team_id termTeam;
	status_t result = be_roster->Launch(termSig, arg_c, arg_v, &termTeam);
	if (result != B_NO_ERROR)
	{ (new BAlert("", "Error launching terminal", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL); }
	delete[] name;
	return;
}
/*void uudecode(entry_ref srcRef, bool closeT)
{	BEntry uueEntry("/bin/uudecode");
	if(!uueEntry.Exists())
	{	(new BAlert("", "UUdecode command does not exist in /bin", "OK",
					NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	int arg_c = 0;
	char *arg_v[6];
	BEntry srcEntry(&srcRef);
	if(!srcEntry.Exists())
	{	(new BAlert("", "Invalid source", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	arg_v[arg_c++] = "/bin/sh";
	arg_v[arg_c++] = "--login";
	arg_v[arg_c++] = "-c";
	BDirectory srcDir;
	srcEntry.GetParent(&srcDir);
	BPath srcDirPath(&srcDir,NULL);
	char *name = new char[B_FILE_NAME_LENGTH];
	srcEntry.GetName(name);
	BString uueArg("Starting decoding; cd ");
	uueArg += srcDirPath.Path(); uueArg += "; uudecode ";
	uueArg += name;
	if(!closeT) { uueArg += "; read -p \"Finished\nPress Enter to close terminal\""; }
	arg_v[arg_c++] = (char*)uueArg.String();
	char *termSig = "application/x-vnd.Haiku-Terminal";
	team_id termTeam;
	status_t result = be_roster->Launch(termSig, arg_c, arg_v, &termTeam);
	if (result != B_NO_ERROR)
	{ (new BAlert("", "Error launching terminal", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL); }
	delete[] name;
	return;
}
void testzip(entry_ref srcRef)
{	BEntry zipEntry("/bin/zip");
	if(!zipEntry.Exists())
	{	(new BAlert("", "zip command does not exist in /bin", "OK",
					NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	BEntry srcEntry(&srcRef);
	if(!srcEntry.Exists())
	{	(new BAlert("", "Invalid source", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	BPath srcPath(&srcEntry);
	BString testArg("echo Testing integrity of ");
	testArg += srcPath.Path();
	testArg += "; zip -T \"";
	testArg += srcPath.Path();
	testArg += "\"; read -p \"Press Enter to close terminal\"";
	int arg_c = 0;
	char *arg_v[6];
	arg_v[arg_c++] = "/bin/sh";
	arg_v[arg_c++] = "--login";
	arg_v[arg_c++] = "-c";
	arg_v[arg_c++] = (char*)testArg.String();
	char *termSig = "application/x-vnd.Haiku-Terminal";
	team_id termTeam;
	status_t result = be_roster->Launch(termSig, arg_c, arg_v, &termTeam);
	if (result != B_NO_ERROR)
	{ (new BAlert("", "Error launching terminal", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL); }
}
void zipsplit(entry_ref srcRef, int bytes, bool usezipsplit, bool closeT)
{	BEntry zipEntry("/bin/zipsplit");
	if(!zipEntry.Exists())
	{	(new BAlert("", "zipsplit command does not exist in /bin", "OK",
					NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	BEntry srcEntry(&srcRef);
	if(!srcEntry.Exists())
	{	(new BAlert("", "Invalid source", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	BPath srcPath(&srcEntry);
	BDirectory srcDir;
	srcEntry.GetParent(&srcDir);
	BPath srcDirPath(&srcDir,NULL);
	BString splitArg("cd \"");
	splitArg += srcDirPath.Path();
	splitArg += "\"; echo Splitting zip file...; ";
	char *number = new char[16];
	sprintf(number, "%i", bytes);
	if(usezipsplit)
	{	splitArg += "zipsplit -n ";
		splitArg += number;
	}
	else
	{	splitArg += "split -b ";
		splitArg += number;
	}
	delete[] number;
	splitArg += " \"";
	splitArg += srcPath.Path();
	splitArg += "\"";
	if(!usezipsplit)
	{	char *name = new char[B_FILE_NAME_LENGTH];
		srcEntry.GetName(name);
		splitArg += " \"";
		splitArg += name;
		splitArg += "\"";
		delete[] name;
	}
	if(!closeT) { splitArg += "; read -p \"Finished\nPress Enter to close terminal\""; }
	int arg_c = 0;
	char *arg_v[6];
	arg_v[arg_c++] = "/bin/sh";
	arg_v[arg_c++] = "--login";
	arg_v[arg_c++] = "-c";
	arg_v[arg_c++] = (char*)splitArg.String();
	char *termSig = "application/x-vnd.Haiku-Terminal";
	team_id termTeam;
	status_t result = be_roster->Launch(termSig, arg_c, arg_v, &termTeam);
	if (result != B_NO_ERROR)
	{ (new BAlert("", "Error launching terminal", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL); }
}*/
//float max(const float& a, const float& b)
//{	return (a>b)?a:b; }
