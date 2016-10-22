#ifndef SB_WINDOW_H
#define SB_WINDOW_H

#include <InterfaceKit.h>
#include "BackupQueue.h"
#include "constants.h"
#include "SBControls.h"
#include "SBSettings.h"
#include "SWDOpenFilePanel.h"

#include "BarberPole.h"

class SBWindow : public BWindow
{public:
					SBWindow(BRect);
					~SBWindow();
	virtual	bool	QuitRequested();
	void			AboutRequested();
	virtual void	MessageReceived(BMessage*);
private:
	SBControls		*controlsView;
	SBSettings		*settingsView;
	BFilePanel		*savePanel, *openFilePanel, *openDirPanel, *openFileOrDirPanel, *saveProfilePanel;
	SWDOpenFilePanel *openProfilePanel, *openSWDPanel;
	BDirectory		settingsDir, profilesDir;
//	bool			settingsShown;
//	void			toggleSettings();
	void			showFilePanel(BFilePanel*,BMessage*);
	void			saveBackup(BPath&, bool);
};

#endif
