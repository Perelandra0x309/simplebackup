#ifndef SB_SETTINGSFILEPANEL_H
#define SB_SETTINGSFILEPANEL_H

#include <InterfaceKit.h>
#include <StorageKit.h>
#include <LayoutBuilder.h>
#include "constants.h"

class SettingsFilePanel : public BFilePanel, public BHandler
{public:
					SettingsFilePanel(file_panel_mode mode=B_OPEN_PANEL, BMessenger* target = NULL,
							const entry_ref *panel_directory = NULL,
							uint32 node_flavors = 0,
							bool allow_multiple_selection = false,
							BMessage *messge = NULL,
							BRefFilter *filter = NULL,
							bool modal = false,
							bool hide_when_done = true);
	void			MessageReceived(BMessage*);
	void			UpdateSettingsDirectory(const entry_ref *profilesDirRef);
private:
	BMenuItem		*fSetFolderItem, *fGoToFolderItem;
	entry_ref		fSettingsFolder;
};

#endif
