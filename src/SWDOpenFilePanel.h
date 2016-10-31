#ifndef SB_SWDOPENFILEPANEL_H
#define SB_SWDOPENFILEPANEL_H

#include <InterfaceKit.h>
#include <StorageKit.h>
#include <LayoutBuilder.h>
#include "constants.h"

class SWDOpenFilePanel : public BFilePanel, public BHandler
{public:
					SWDOpenFilePanel(BMessenger* target = NULL,
							entry_ref *panel_directory = NULL,
							uint32 node_flavors = 0,
							bool allow_multiple_selection = true,
							BMessage *messge = NULL,
							BRefFilter *filter = NULL,
							bool modal = false,
							bool hide_when_done = true);
	void			MessageReceived(BMessage*);
	void			setButtonCommand(uint32 a) { button_command = a; }
	void			setHideOnSWD(bool a) { hide_on_SWD = a; }
	void			setButtonLabel(char *text)
					{	Window()->Lock();
						currentDirB->SetLabel(text);
						currentDirB->ResizeTo(be_plain_font->StringWidth(text) + 20, currentDirB->Frame().Height());
						Window()->Unlock();
					}
private:
	BButton			*currentDirB;
	uint32			button_command;
	bool			hide_on_SWD;
};

#endif
