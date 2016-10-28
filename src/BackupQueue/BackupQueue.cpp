/* BackupQueue.cpp
 * Copyright 2016 Brian Hill
 * All rights reserved. Distributed under the terms of the BSD License.
 */
#include "BackupQueue.h"

int main()
{	SBQApp myApp;
	myApp.Run();
	return(0);
}
SBQApp::SBQApp() : BApplication(SBQ_app_sig)
{	queue = new SBBackupQueue();
#if DEBUG
	debugWindow = new SBQDWindow();
#endif//DEBUG
}
SBQApp::~SBQApp()
{	queue->Lock();
	queue->Quit();
}
bool SBQApp::QuitRequested()
{	//(new BAlert("","SBQueue is quitting","OK"))->Go();
	if(queue->QuitRequested())
	{	return true; }
	else {
#if DEBUG
		debugWindow->print("Cannot quit, queue may not be empty\n");
#endif//DEBUG
		return false;
	}
}
void SBQApp::Pulse()
{	//check if queue is empty, if it then quit
	if(queue->QuitRequested())
	{	be_app->PostMessage(B_QUIT_REQUESTED); }
	return;
}
void SBQApp::MessageReceived(BMessage *msg)
{	switch(msg->what)
	{case SB_READY_TO_SEND: {
#if DEBUG
		debugWindow->print("SimpleBackup sent SB_READY_TO_SEND message\n");
		debugWindow->print("Sending reply message QUE_READY_TO_RECEIVE\n");
#endif//DEBUG
		msg->SendReply(QUE_READY_TO_RECEIVE);
		break; }
	case QUE_BACKUP_TERM:
	case QUE_BACKUP_THREAD: {
		queue->PostMessage(msg);
#if AUTO_QUIT
		SetPulseRate(1000000);
#endif//AUTO_QUIT
		break; }
	}
	return;
}
SBBackupQueue::SBBackupQueue()
	:BLooper()
{	Run();
}
bool SBBackupQueue::QuitRequested()
{	if(MessageQueue()->IsEmpty() && CountLockRequests() == 0)
	{	return true; }
	else return false;
}
void SBBackupQueue::MessageReceived(BMessage *msg)
{	switch(msg->what)
	{	case QUE_BACKUP_TERM: {
			int arg_c = 0;
			char** arg_v = (char**)malloc(sizeof(char *) * 16);
			arg_v[arg_c++] = strdup("/bin/sh");
			arg_v[arg_c++] = strdup("--login");
			arg_v[arg_c++] = strdup("-c");
			BString zipArg, tempStr;
			msg->FindString("zipArg", &zipArg);
			zipArg.Insert("echo Loading source info...; ", 0);
			if(msg->FindString("excludeList", &tempStr) == B_OK)
			{	zipArg += "; rm -f ";
				zipArg += tempStr;
			}
			if(msg->FindString("includeList", &tempStr) == B_OK)
			{	zipArg += "; rm -f ";
				zipArg += tempStr;
			}
			bool closeTerm;
			msg->FindBool("closeTerm", &closeTerm);
			if(!closeTerm)
			{ zipArg += "; read -p \"Finished\nPress Enter to close terminal\""; }
			arg_v[arg_c++] = strdup(zipArg.String());
			char *termSig = strdup("application/x-vnd.Haiku-Terminal");
			team_id termTeam;
			status_t result = be_roster->Launch(termSig, arg_c, arg_v, &termTeam);
			if (result != B_NO_ERROR)
			{	if(msg->FindString("excludeList", &tempStr) == B_OK)
				{	tempStr.Prepend("rm -f ");
					system(tempStr.String());
				}
				if(msg->FindString("includeList", &tempStr) == B_OK)
				{	tempStr.Prepend("rm -f ");
					system(tempStr.String());
				}
				(new BAlert("", "Error launching backup in terminal", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go();
			}
			free(arg_v);
			break; }
		case QUE_BACKUP_THREAD: {
			int arg_c = 0;
			char** arg_v = (char**)malloc(sizeof(char *) * 16);
			BString zipArg;
			msg->FindString("zipArg", &zipArg);
			zipArg.RemoveFirst("zip ");
			arg_v[arg_c++] = strdup("/bin/zip");
			int i;
			BString tempStr("");
			while( (i = zipArg.IFindFirst(" "))!=B_ERROR )//split command into args
			{	if(zipArg[0] == '"')
				{	zipArg.Remove(0,1);
					i = zipArg.IFindFirst("\"");
				}
				zipArg.CopyInto(tempStr, 0, i);
				arg_v[arg_c++] = strdup(tempStr.String());
				zipArg.Remove(0, i+1);
			}
			if(zipArg != "")
			{	zipArg.RemoveSet("\"");
				arg_v[arg_c++] = strdup(zipArg.String());
			}
			arg_v[arg_c] = NULL;
			extern char **environ;
			thread_id zipThread;
			zipThread = load_image(arg_c, (const char**)arg_v, (const char**)environ);
			if(zipThread==B_ERROR)
			{	(new BAlert("","Zip thread not running","OK"))->Go(); }
			else
			{	status_t exitval;
				wait_for_thread(zipThread, &exitval);
			}
			if(msg->FindString("excludeList", &tempStr) == B_OK)
			{	tempStr.Prepend("rm -f ");
				system(tempStr.String());
			}
			if(msg->FindString("includeList", &tempStr) == B_OK)
			{	tempStr.Prepend("rm -f ");
				system(tempStr.String());
			}
			free(arg_v);
			break; }
	}
}

#if DEBUG
SBQDWindow::SBQDWindow()
	:BWindow(BRect(100,100,600,400), "SimpleBackupDebug", B_TITLED_WINDOW, B_NOT_RESIZABLE | B_NOT_ZOOMABLE)
{	BRect viewRect = Bounds();
	viewRect.OffsetBy(1,1);
	debugTV = new BTextView(viewRect, "Debug Text", viewRect, B_FOLLOW_NONE, B_WILL_DRAW);
	debugSV = new BScrollView("Debug Text ScrollView", debugTV, B_FOLLOW_NONE, 0,
							false, true);
	AddChild(debugSV);
	ResizeTo(debugSV->Frame().right-1, debugSV->Frame().bottom-1);
	Show();
}
SBQDWindow::~SBQDWindow()
{	}
bool SBQDWindow::QuitRequested()
{	be_app->PostMessage(B_QUIT_REQUESTED);
	return false;
}
void SBQDWindow::print(char *text)
{	Lock();
	debugTV->Insert(text, strlen(text));//, debugTV->TextLength());
	Unlock();
	return;
}
#endif//DEBUG
