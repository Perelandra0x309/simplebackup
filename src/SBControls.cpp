#include "SBControls.h"

SBControls::SBControls(BRect& size, /*BPicture *tupic, BPicture *tdpic,*/ SBSettings *settingsView)
	:BView(size, "Backup options", B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_FRAME_EVENTS)
{	SetViewColor(gui_background_color);
	
	browseSrc = new BButton("Browse", "Browse" B_UTF8_ELLIPSIS, new BMessage(SRC_PANEL));
	backupSrc = new BTextControl("Backup Source", "Source:", "/boot/home",
								new BMessage(CHECK_SRC));
	newB = new BButton("New", "Create New Backup" B_UTF8_ELLIPSIS, new BMessage(NEW_PANEL));
	
	updateB = new BButton(BRect(0, 1, 80, 1), "Update", "Update Existing Backup" B_UTF8_ELLIPSIS,
								new BMessage(UPDATE_PANEL));
	
	BRect viewRect(0,0,15,20);
//	togglePB = new BPictureButton(viewRect, "Toggle Settings", tupic, tdpic,
//								new BMessage(TOGGLE_S), B_TWO_STATE_BUTTON);
	
	defaultSB = new BButton("Default", "Defaults", new BMessage(DEFAULTS));
	restoreSB = new BButton("Restore", "Restore Settings" B_UTF8_ELLIPSIS, new BMessage(RESTORES));
	saveSB = new BButton("Save", "Save Settings" B_UTF8_ELLIPSIS, new BMessage(SAVES));
	aboutB = new BButton("About", "About", new BMessage(B_ABOUT_REQUESTED));
	
	newB->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNSET));
	updateB->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNSET));
	
	// Build the layout
	SetLayout(new BGroupLayout(B_HORIZONTAL));
	AddChild(BGroupLayoutBuilder(B_VERTICAL, gui_control_padding)
		.Add(BGroupLayoutBuilder(B_HORIZONTAL, gui_control_padding)
			.Add(backupSrc)
			.Add(browseSrc)
		)
		.Add(BGroupLayoutBuilder(B_HORIZONTAL, gui_control_padding)
			.Add(newB)
			.Add(updateB)
			//.Add(togglePB)
		)
		.Add(settingsView)
		.Add(BGroupLayoutBuilder(B_HORIZONTAL, gui_control_padding)
			.Add(defaultSB)
			.AddGlue()
			.Add(restoreSB)
			.AddGlue()
			.Add(saveSB)
			.AddGlue()
			.Add(aboutB)
		)
		.SetInsets(gui_group_inset, gui_group_inset, gui_group_inset, gui_group_inset)
	);
	
}
SBControls::~SBControls()
{	}

