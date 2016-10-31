#include "SettingsFilePanel.h"

SettingsFilePanel::SettingsFilePanel(file_panel_mode mode=B_OPEN_PANEL,
							BMessenger* target = NULL,
							const entry_ref *panel_directory = NULL,
							uint32 node_flavors = 0,
							bool allow_multiple_selection = false,
							BMessage *messge = NULL,
							BRefFilter *filter = NULL,
							bool modal = false,
							bool hide_when_done = true)
	:BFilePanel(mode, target, panel_directory, node_flavors,
				allow_multiple_selection, messge, filter, modal, hide_when_done),
	BHandler("SettingsFilePanel")
{	Window()->Lock();
	Window()->AddHandler(this);

	//Setup custom menu
	BMenuBar *menuBar = Window()->KeyMenuBar();
	BMenu *settingsMenu = new BMenu("Settings Folder");
	fSetFolderItem = new BMenuItem("Set this folder as the settings folder", new BMessage(CURRENT_SET));
	fSetFolderItem->SetTarget(this);
	fGoToFolderItem = new BMenuItem("Go to ", new BMessage(GOTO_PROFILE_DIR));
	fGoToFolderItem->SetTarget(this);
	settingsMenu->AddItem(fGoToFolderItem);
	settingsMenu->AddSeparatorItem();
	settingsMenu->AddItem(fSetFolderItem);
	menuBar->AddItem(settingsMenu);

	UpdateSettingsDirectory(panel_directory);

	Window()->Unlock();
}


void SettingsFilePanel::MessageReceived(BMessage *msg)
{	switch (msg->what)
	{	case CURRENT_SET: {
			BMessage selmsg(SET_PROFILE_DIR);
			entry_ref dir_ref;
			GetPanelDirectory(&dir_ref);
			selmsg.AddRef("refs", &dir_ref);
			Messenger().SendMessage(&selmsg);
			break; }
		case GOTO_PROFILE_DIR: {
			SetPanelDirectory(&fSettingsFolder);
			break; }
		default:
			BHandler::MessageReceived(msg);
			break;
	}
}


void SettingsFilePanel::UpdateSettingsDirectory(const entry_ref *profilesDirRef)
{
	fSettingsFolder = *profilesDirRef;
	BString label("Go to ");
	BPath settingsPath(&fSettingsFolder);
	label.Append(settingsPath.Path());

/*	float labelWidth, labelHeight;
//	fSetFolderItem->GetContentSize(&labelWidth, &labelHeight);

	BMenu *menu = fGoToFolderItem->Menu();
	labelWidth = menu->StringWidth(fSetFolderItem->Label())+50;
	if(menu->StringWidth(label.String()) > labelWidth)
	{
		menu->SetMaxContentWidth(labelWidth);
	}*/
	fGoToFolderItem->SetLabel(label.String());
//	menu->SetMaxContentWidth(labelWidth + 10);

	SetPanelDirectory(&fSettingsFolder);
}
