/* BackupQueue.h
 * Copyright 2016 Brian Hill
 * All rights reserved. Distributed under the terms of the BSD License.
 */
#ifndef SIMPLEBACKUPQUEUE_H
#define SIMPLEBACKUPQUEUE_H
//includes
#include <AppKit.h>
#include <InterfaceKit.h>
#include <SupportKit.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio.h>
//Constants
#define SB_READY_TO_SEND 'sbsn'
#define QUE_READY_TO_RECEIVE 'qrec'
#define QUE_BACKUP_TERM	'qbtm'
#define QUE_BACKUP_THREAD 'qbth'
#define QUE_BACKUP_CLEAN 'qbcl'
#define DEBUG 0
#define AUTO_QUIT 1
#define SBQ_app_sig "application/x-vnd.BH-SimpleBackupQueue"

//Classes
class SBBackupQueue;//backup queue
#if DEBUG
class SBQDWindow;//debug window
#endif

class SBQApp : public BApplication
{public:
					SBQApp();
					~SBQApp();
	virtual	bool	QuitRequested();
	virtual void	Pulse();
	virtual void	MessageReceived(BMessage*);
private:
#if DEBUG
	SBQDWindow		*debugWindow;
#endif
	SBBackupQueue	*queue;
};
class SBBackupQueue : public BLooper
{public:
					SBBackupQueue();
	virtual	bool	QuitRequested();
	virtual void	MessageReceived(BMessage*);
private:
	
};

#if DEBUG
class SBQDWindow : public BWindow
{public:
					SBQDWindow();
					~SBQDWindow();
	virtual bool	QuitRequested();
	void			print(char*);
private:
	BTextView		*debugTV;
	BScrollView		*debugSV;
};
#endif//DEBUG


#endif//SIMPLEBACKUPQUEUE_H
