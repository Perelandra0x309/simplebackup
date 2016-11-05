#ifndef SB_WINDOW_H
#define SB_WINDOW_H

#include <InterfaceKit.h>
#include "BackupQueue.h"
#include "constants.h"
#include "SBControls.h"
#include "SBSettings.h"
#include "SettingsFilePanel.h"

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
	BFilePanel		*savePanel, *openFilePanel, *openDirPanel, *openFileOrDirPanel;
//	SWDOpenFilePanel *openProfilePanel, *openSWDPanel;
	SettingsFilePanel	*saveProfilePanel, *openProfilePanel;
	BDirectory		fSettingsDir;//, profilesDir;
	entry_ref		fProfilesDirRef;
//	bool			settingsShown;
//	void			toggleSettings();
	void			_showFilePanel(BFilePanel*,BMessage*);
	void			_saveBackup(BPath&, bool);
	bool			_RestoreSettingsFromFilename(const char *filename);
};

#endif
