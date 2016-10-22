#include "SWDOpenFilePanel.h"

SWDOpenFilePanel::SWDOpenFilePanel(BMessenger* target = NULL,
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
void SWDOpenFilePanel::MessageReceived(BMessage *msg)
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
}