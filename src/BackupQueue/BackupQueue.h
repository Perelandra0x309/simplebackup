/*  Couch Potato's Planner- written by Brian Hill, perelandra@iname.com
    
    This program was written for BeOS (www.be.com) and provides an interface
    for searching the internet for TV schedules of your favorite programs.
    
    
    --Protected under General Public License--
    
    Copyright (C) 2001,  Brian Hill <perelandra@iname.com>

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