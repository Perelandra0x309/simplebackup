#include "SBApp.h"

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
