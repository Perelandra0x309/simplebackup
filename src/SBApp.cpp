/* SBApp.cpp
 * Copyright 2016 Brian Hill
 * All rights reserved. Distributed under the terms of the BSD License.
 */
#include "SBApp.h"

int main()
{
	SBApp myApp;
	myApp.Run();
	return(0);
}


SBApp::SBApp()
	:BApplication(APPLICATION_SIGNATURE)
{
	fWindow = new SBWindow(BRect(200,50,850,570));
}


void
SBApp::ArgvReceived(int32 argc, char** argv)
{
	if(strcmp(argv[1],"-q")==0 || strcmp(argv[1],"--quit")==0)
	{	be_app->PostMessage(B_QUIT_REQUESTED); return; }
	if(strcmp(argv[1],"-h")==0 || strcmp(argv[1],"--help")==0)
	{	printhelp(); return; }
	if(argc!=2 && argc!=3) { printhelp(); return; }

	//only restore settings
	if(argc == 2)
	{
		BString fileString(argv[1]);
		BMessage setmsg(RESTORES_FILENAME);
		setmsg.AddString("filename", fileString);
		fWindow->PostMessage(&setmsg);
	}
	//send message to start backup
	else if(argc==3)
	{
		BString fileString(argv[1]);
		BEntry backupEntry(argv[2]);
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
		BMessage savemsg(NEW_BACKUP);
		savemsg.AddString("filename", fileString);
		savemsg.AddRef("directory",&backupRef);
		savemsg.AddString("name",backupName);
		savemsg.AddBool("newBackup",newBackup);
		fWindow->PostMessage(&savemsg);
	}
}


void SBApp::printhelp()
{
	printf(	"SimpleBackup v%s by Brian Hill\n"
			"Usage: SimpleBackup [settings_file] [backup_file]\n"
			"If settings_file is specified, settings will be restored from "
			"that previously configured and saved settings file. "
			"If backup_file is specified (must follow a settings_file "
			"arguement) saving of the backup into backup_file is started "
			"automatically\n",SB_version);
	return;
}

