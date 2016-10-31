#include "SBWindow.h"


uchar tuBits[] = {	0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x12, 0x12, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x1b, 0x1b,
					0x1b, 0xb, 0x3f, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0xb, 0x1b,
					0x1b, 0xb, 0x1e, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x1b,
					0x1b, 0xb, 0x1e, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x1b,
					0x1b, 0xb, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0xb, 0x1b,
					0x1b, 0x1b, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x3f, 0x3f, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b
					};
uchar tdBits[] = {	0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x12, 0x12, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x1b, 0x1b, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b,
					0x1b, 0x1b, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x1b, 0x1b,
					0x1b, 0xb, 0x3f, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0xb, 0x1b,
					0x1b, 0xb, 0x1e, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x1b,
					0x1b, 0xb, 0x1e, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x1b,
					0x1b, 0xb, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0xb, 0x1b,
					0x1b, 0x1b, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x1b, 0x1b,
					0x1b, 0x1b, 0x1b, 0x1b, 0x12, 0x3f, 0x3f, 0x3f, 0x1b, 0x1b, 0x1b, 0x1b
					};
#if USE_DATE_CONTROL
uchar incuBits[]={	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x1b, 0x18, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x1b, 0x1b, 0x1b, 0x18, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x13, 0x1e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xb, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x13, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x13, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18
					};
uchar incsBits[]={	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x1b, 0x18, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x1b, 0x1b, 0x1b, 0x18, 0x13, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xb, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					};
uchar decuBits[]={	0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0xb, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x13, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x16, 0xb, 0x13, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x13, 0x13, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x16, 0xb, 0x13, 0x13, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x16, 0xb, 0x13, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0xb, 0x13, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18
					};
uchar decsBits[]={	0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0xb, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x13, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x16, 0xb, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x1b, 0x1b, 0x16, 0xb, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x1b, 0x1b, 0x16, 0xb, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x13, 0x16, 0xb, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0xb, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x3f, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x18,
					0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18
					};
#endif

SBWindow::SBWindow(BRect size)
	:BWindow(size, "SimpleBackup", B_TITLED_WINDOW, B_NOT_ZOOMABLE/* | B_AUTO_UPDATE_SIZE_LIMITS*/)
{	BRect viewRect;
//	BPicture *tuPict, *tdPict;
//	BView *tempView = new BView(viewRect, "temp", B_FOLLOW_ALL, B_WILL_DRAW | B_FRAME_EVENTS);
//	AddChild(tempView);

	//Create toggle button
/*	BRect pictRect(0,0,11,19); //toggle setting shown button pictures
	BBitmap tuBitmap(pictRect, B_COLOR_8_BIT );
	tuBitmap.SetBits(tuBits, 1600, 0, B_COLOR_8_BIT);
	BBitmap tdBitmap(pictRect, B_COLOR_8_BIT );
	tdBitmap.SetBits(tdBits, 1600, 0, B_COLOR_8_BIT);
	viewRect = pictRect;
	viewRect.InsetBy(-1,-1);
	tempView->BeginPicture(new BPicture);//Up
	tempView->DrawBitmap(&tuBitmap);
	tuPict = tempView->EndPicture();
	tempView->BeginPicture(new BPicture);//Down
	tempView->DrawBitmap(&tdBitmap);
	tdPict = tempView->EndPicture();
	RemoveChild(tempView);
	delete tempView;*/
#if USE_DATE_CONTROL
	BRect pictRect;
	BPicture	*incuPict, *incsPict, *decuPict, *decsPict;
	BView *temp1View = new BView(viewRect, "temp", B_FOLLOW_NONE, B_WILL_DRAW );
	AddChild(temp1View);
	pictRect.Set(0,0,15,9); //Increment/decrement button pictures
	BBitmap incuBitmap(pictRect, B_COLOR_8_BIT );
	incuBitmap.SetBits(incuBits, 1280, 0, B_COLOR_8_BIT);
	BBitmap incsBitmap(pictRect, B_COLOR_8_BIT );
	incsBitmap.SetBits(incsBits, 1280, 0, B_COLOR_8_BIT);
	BBitmap decuBitmap(pictRect, B_COLOR_8_BIT );
	decuBitmap.SetBits(decuBits, 1280, 0, B_COLOR_8_BIT);
	BBitmap decsBitmap(pictRect, B_COLOR_8_BIT );
	decsBitmap.SetBits(decsBits, 1280, 0, B_COLOR_8_BIT);
	temp1View->BeginPicture(new BPicture);//Increment unselected
	temp1View->DrawBitmap(&incuBitmap);
	incuPict = temp1View->EndPicture();
	temp1View->BeginPicture(new BPicture);//Increment selected
	temp1View->DrawBitmap(&incsBitmap);
	incsPict = temp1View->EndPicture();
	temp1View->BeginPicture(new BPicture);//Decrement unselected
	temp1View->DrawBitmap(&decuBitmap);
	decuPict = temp1View->EndPicture();
	temp1View->BeginPicture(new BPicture);//Decrement selected
	temp1View->DrawBitmap(&decsBitmap);
	decsPict = temp1View->EndPicture();
	RemoveChild(temp1View);
	delete temp1View;
#endif

	//Create the GUI views
	Lock();
	viewRect = Bounds();
#if USE_DATE_CONTROL
	settingsView = new SBSettings(/*viewRect, */incuPict, incsPict, decuPict, decsPict);
	delete incuPict;
	delete incsPict;
	delete decuPict;
	delete decsPict;
#else
	settingsView = new SBSettings(/*viewRect*/);
#endif
	controlsView = new SBControls(viewRect,/* tuPict, tdPict,*/ settingsView);
	settingsView->setControlsView(controlsView);
	AddChild(controlsView);
//	delete tuPict;
//	delete tdPict;

	//Window size
	BSize minSize = controlsView->PreferredSize();
	ResizeTo(minSize.width + 2*gui_control_padding, minSize.height);
	SetSizeLimits(minSize.width + 2*gui_control_padding, B_SIZE_UNLIMITED, minSize.height, B_SIZE_UNLIMITED);


	//Create the settings folder if not found
	BPath settingsPath;
	find_directory(B_USER_SETTINGS_DIRECTORY, &settingsPath);
	settingsPath.Append(DEFAULT_SETTINGS_DIR);
	if( fSettingsDir.SetTo(settingsPath.Path()) == B_ENTRY_NOT_FOUND )
	{	//(new BAlert("","Settings directory not found, creating directory "
						//"~/config/settings/SimpleBackup", "OK"))->Go(NULL);
		if(fSettingsDir.CreateDirectory(settingsPath.Path(), &fSettingsDir)!=B_OK)
		{	(new BAlert("","Error creating settings folder","OK"))->Go(NULL); }
	}

	//Restore all settings from when app was last closed
//	profilesDir = settingsDir;
	settingsPath.Append("settings");
	BEntry archiveEntry(settingsPath.Path());
	if(archiveEntry.Exists())
	{	BFile archiveFile(&archiveEntry, B_READ_ONLY);
		off_t datasize; archiveFile.GetSize(&datasize);
		char *databuf = new char[datasize];
		BMessage archive;
		if((archiveFile.Read(databuf, datasize))!=datasize)
		{	(new BAlert("","Error loading settings file","OK",
							NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		}
		else if(archive.Unflatten(databuf)!=B_OK)
		{	(new BAlert("","Error reading settings settings","OK",
							NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		}
		else
		{	float windowTop, windowLeft;
			if(archive.FindFloat("SB:windowTop",&windowTop) == B_OK)
			{
				if(archive.FindFloat("SB:windowLeft",&windowLeft) == B_OK)
				{
					MoveTo(windowLeft,windowTop);
				}
			}
			float width, height;
			if(archive.FindFloat("SB:windowWidth", &width) == B_OK)
			{
				if( archive.FindFloat("SB:windowHeight", &height) == B_OK)
				{
					ResizeTo(width, height);
				}
			}
			if(archive.FindRef("profilesRef", &fProfilesDirRef) != B_OK)
			{
				BPath profilesPath;
				find_directory(B_USER_DIRECTORY, &profilesPath);
				BEntry profilesEntry(profilesPath.Path());
				profilesEntry.GetRef(&fProfilesDirRef);
			}
//			archive.FindBool("SB:showSettings", &settingsShown);
//			settingsShown = !settingsShown;
//			toggleSettings();
			settingsView->restoreSettings(archive);
		}
		delete[] databuf;
	}
/*	else
	{	settingsShown = true;
//		toggleSettings();
	}*/

	//Create open and save file panel objects
	savePanel = new BFilePanel(B_SAVE_PANEL);//normal save panel
	openFilePanel = new BFilePanel(B_OPEN_PANEL, NULL, NULL, B_FILE_NODE, false);//normal open panel
	openDirPanel = new BFilePanel(B_OPEN_PANEL, NULL, NULL, B_DIRECTORY_NODE, false);//open file panel for folders only
//	openDirPanel->SetButtonLabel(B_DEFAULT_BUTTON, "Select");
	openFileOrDirPanel = new BFilePanel(B_OPEN_PANEL, NULL, NULL, B_FILE_NODE | B_DIRECTORY_NODE, false);//panel to select a folder or file
//	openFileOrDirPanel->SetButtonLabel(B_DEFAULT_BUTTON, "Select");
	saveProfilePanel = new SettingsFilePanel(B_SAVE_PANEL, new BMessenger(this), &fProfilesDirRef);//save a setting profile
	saveProfilePanel->SetTarget(this);
	openProfilePanel = new SettingsFilePanel(B_OPEN_PANEL, new BMessenger(this), &fProfilesDirRef);//open a setting profile
	openProfilePanel->SetTarget(this);
	Unlock();
	Show();
}
SBWindow::~SBWindow()
{
	//Save settings to be restored when app runs next
	BMessage archive;
	archive.AddFloat("SB:windowTop", Frame().top);
	archive.AddFloat("SB:windowLeft", Frame().left);
	archive.AddFloat("SB:windowWidth", Frame().Width());
	archive.AddFloat("SB:windowHeight", Frame().Height());
	archive.AddRef("profilesRef", &fProfilesDirRef);
//	archive.AddBool("SB:showSettings", settingsShown);
	settingsView->storeSettings(archive);
	BPath settingsPath(&fSettingsDir, "settings");
	BFile saveFile(settingsPath.Path(), B_READ_WRITE | B_CREATE_FILE | B_ERASE_FILE);
	int datasize = archive.FlattenedSize();
	char *databuf = new char[datasize];
	if(archive.Flatten(databuf, datasize)!=B_OK)
	{	//(new BAlert("","Error flattening data archive.","OK",
		//				NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
	}
	else if( (saveFile.Write(databuf, datasize))!=datasize )
	{	//(new BAlert("","Error writing archive file.","OK",
		//				NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
	}
	delete[] databuf;
	delete savePanel;
	delete openFilePanel;
	delete openDirPanel;
	delete openFileOrDirPanel;
	delete saveProfilePanel;
	delete openProfilePanel;
//	delete openSWDPanel;
}
//Open the BFilePanel object specified and configure
void SBWindow::showFilePanel(BFilePanel* panel, BMessage *msg)
{	panel->SetMessage(msg);
	panel->SetTarget(this);
//	if(panel == openSWDPanel) openSWDPanel->setButtonCommand(msg->what);
	panel->Show();
}
//Create the backup job and send it to the backup queue
void SBWindow::saveBackup(BPath& filePath, bool newBackup)
{	BEntry zipEntry("/bin/zip");
	if(!zipEntry.Exists())
	{	(new BAlert("", "Zip command does not exist in /bin", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	char *backupSrc = controlsView->getSrc();
	BEntry srcEntry(backupSrc);
	if(!srcEntry.Exists())
	{	(new BAlert("", "Invalid source", "OK", NULL, NULL, B_WIDTH_AS_USUAL,
					B_STOP_ALERT))->Go(NULL);
		return; }
	BString singleArgs("-"), compArg("-"), tempArg("-b '"), ncArg("-n "),
				modBArg("-t "), modAArg("-tt "), excArg(" -x@"), incArg(" -i@");
	bool singleB(false), tempDirB(false), modBeforeB(false), modAfterB(false),
			noCompressB(false), excludeB(false), includeB(false);
	BEntry fileEntry(filePath.Path());
	switch(newBackup)
	{case true:
	{	if(fileEntry.Exists()) //Add entry for non - .zip
		{	//(new BAlert("", "File exists, will be replaced", "OK", NULL, NULL,
					//	B_WIDTH_AS_USUAL, B_WARNING_ALERT))->Go();
			switch(fileEntry.Remove()) //delete file to create new zip
			{	case B_OK: break;
				case B_BUSY:
				{	(new BAlert("","File locked or busy, cannot delete.", "OK",
							NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go();
					return; }
				default:
				{	(new BAlert("","Unknown error while deleting file.", "OK",
							NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go();
					return; }
			}
		}
		break;
	}
	case false:
	{	if(!fileEntry.Exists())
		{	(new BAlert("", "File does not exist, can't update","OK",
						NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go();
			return; }
		if(settingsView->getUpdateValue()) { singleArgs += "u"; singleB = true; }
		else { singleArgs += "f"; singleB = true; }
		break;
	}}
	if(settingsView->getRecurseValue()) { singleArgs += "r"; singleB = true; }
	if(settingsView->getStoreSymValue()) { singleArgs += "y"; singleB = true; }
	if(settingsView->getRemoveDirValue()) { singleArgs += "j"; singleB = true; }
	if(settingsView->getDeleteFilesValue()) { singleArgs += "mT"; singleB = true; }
	compArg += ('/0' + (settingsView->getCompLevel()));
	compArg += " ";
	if(settingsView->getTempDirValue())
	{	BDirectory tempDir(settingsView->getTempDir());
		BPath tempPath(&tempDir, NULL);
		if((char*)tempPath.Path() == NULL)
		{	(new BAlert("", "Invalid temp directory", "OK", NULL, NULL,
						B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
			return; }
		tempArg += tempPath.Path();
		tempArg += "' ";
		tempDirB = true;
	}
	if(settingsView->getModBeforeValue())
	{	modBArg += (settingsView->getModBeforeDate()).String();
		modBArg += " ";
		modBeforeB = true;
	}
	if(settingsView->getModAfterValue())
	{	modAArg += (settingsView->getModAfterDate()).String();
		modAArg += " ";
		modAfterB = true;
	}
	if(settingsView->getNoCompressValue())
	{	if(settingsView->getNoCompressNumber()>0)
		{	ncArg += (settingsView->getNoCompressEntrys()).String();
			if(strcmp(ncArg.String(),"-n ")!=0)
			{	ncArg += " ";
				noCompressB = true;
			}
		}
	}
	BPath exListPath, inListPath;
	BEntry listEntry;
	BString listString;
	int file_num;
	if(settingsView->getExcludeValue())
	{	if(settingsView->getExcludeNumber()>0)
		{	file_num = 1;
			do{	listString.SetTo("/boot/home/config/settings/SimpleBackup/exlist");
				listString += ('/0' + file_num++);
				listEntry.SetTo(listString.String());
			}while(listEntry.Exists());
			exListPath.SetTo(listString.String());
			if(settingsView->getExcludeEntrys(exListPath))
			{	excArg += exListPath.Path();
				excludeB = true; }
		}
		else{ (new BAlert("", "No entrys listed to exclude", "Continue"))->Go(); }
	}
	if(settingsView->getIncludeValue())
	{	if(settingsView->getIncludeNumber()>0)
		{	file_num = 1;
			do{	listString.SetTo("/boot/home/config/settings/SimpleBackup/inlist");
				listString += ('/0' + file_num++);
				listEntry.SetTo(listString.String());
			}while(listEntry.Exists());
			inListPath.SetTo(listString.String());
			if(settingsView->getIncludeEntrys(inListPath))
			{	incArg += inListPath.Path();
				includeB = true; }
		}
		else{ (new BAlert("","No entrys listed to include", "Continue"))->Go(); }
	}
	//create zip arguement string
	BString zipArg("zip ");
	if(singleB) { zipArg += singleArgs.String(); zipArg += " "; }
	zipArg += compArg.String();
	if(tempDirB) { zipArg += tempArg.String(); }
	if(noCompressB) { zipArg += ncArg.String(); }
	if(modBeforeB) { zipArg += modBArg.String(); }
	if(modAfterB) { zipArg += modAArg.String(); }
	zipArg += "\""; zipArg += filePath.Path();
	zipArg += "\" \""; zipArg += backupSrc; zipArg += "\"";
	if(excludeB) { zipArg += excArg.String(); }
	if(includeB) { zipArg += incArg.String(); }
	//Send backup message to backup que
	status_t err = be_roster->Launch(SBQ_app_sig);
	if(err != B_OK && err != B_ALREADY_RUNNING)
	{	(new BAlert("", "Error: Could not launch SBQueue","OK"))->Go(NULL); return; }
	BMessenger SBQMessenger(SBQ_app_sig);
	if(!SBQMessenger.IsValid())
	{	(new BAlert("", "Error: Could not create messenger for SBQueue","OK"))->Go(NULL); return; }
	BMessage replyMsg, sndMsg(SB_READY_TO_SEND);
	err = SBQMessenger.SendMessage(&sndMsg, &replyMsg, 10000000, 10000000);
	if(err != B_OK)
	{	(new BAlert("", "Error: Could not send message to SBQueue","OK"))->Go(NULL); return; }
	if(replyMsg.what != QUE_READY_TO_RECEIVE)
	{	(new BAlert("", "Error: SBQueue not ready to receive data","OK"))->Go(NULL); return; }
#if !NO_BACKUP
	if(settingsView->getUseTermValue())
	{	BMessage backupMsg(QUE_BACKUP_TERM);
		backupMsg.AddString("zipArg", zipArg);
		backupMsg.AddBool("closeTerm", settingsView->getCloseTermValue());
		if(excludeB) backupMsg.AddString("excludeList", exListPath.Path());
		if(includeB) backupMsg.AddString("includeList", inListPath.Path());
		SBQMessenger.SendMessage(&backupMsg);
	}
	else
	{	BMessage backupMsg(QUE_BACKUP_THREAD);
		backupMsg.AddString("zipArg", zipArg);
		if(excludeB) backupMsg.AddString("excludeList", exListPath.Path());
		if(includeB) backupMsg.AddString("includeList", inListPath.Path());
		SBQMessenger.SendMessage(&backupMsg);
	}
#endif
	return;
}
//Hide or show the settings view
/*void SBWindow::toggleSettings()
{	if(settingsShown)
	{	ResizeTo(controlsView->Frame().Width(), controlsView->getBottom() + 1); }
	else
	{	ResizeTo(controlsView->Frame().Width(), controlsView->Frame().bottom); }
	settingsShown = !settingsShown;
	controlsView->setToggleB(settingsShown);
	return;
}*/
//Quit
bool SBWindow::QuitRequested()
{	be_app->PostMessage(B_QUIT_REQUESTED);
	return(true);
}
//About
void SBWindow::AboutRequested()
{	(new BAlert("About SimpleBackup",
				"SimpleBackup version "SB_version"\n"
				"by Brian Hill\n\n"
				"This program is intended for creating "
				"large backups.  Tell me what you think.\n\n"
				"Contact information and the latest version\n"
				"of this application can be found in\n"
				"HaikuDepot", "OK"))->Go(NULL);
	return;
}
//Things to do when the control objects are clicked
void SBWindow::MessageReceived(BMessage* msg)
{	switch(msg->what)
	{	case B_ABOUT_REQUESTED: { AboutRequested(); break; }
		case SB_NOTHING: break;
		case NEW_PANEL: {
			if(!BEntry("/bin/zip").Exists())
			{	(new BAlert("", "Zip command does not exist in /bin", "OK"))->Go(NULL);
				return; }
			BMessage *newmsg = new BMessage(NEW_BACKUP);
			newmsg->AddBool("newBackup", true);
			BString backupName("backup");
			char dateString[7];
			time_t now = time(NULL);
			struct tm *date;
			date = localtime(&now);
			strftime(dateString, 16, "%m%d%y", date);
			backupName += dateString;
			backupName += ".zip";
			showFilePanel(savePanel,newmsg);
			savePanel->SetSaveText(backupName.String());
			delete newmsg;
			break; }
		case UPDATE_PANEL: {
			if(!BEntry("/bin/zip").Exists())
			{	(new BAlert("", "Zip command does not exist in /bin", "OK",
						NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
				return; }
			BMessage *updtmsg = new BMessage(UPDATE_BACKUP);
			updtmsg->AddBool("newBackup", false);
			showFilePanel(openFilePanel,updtmsg);
			delete updtmsg;
			break; }
		case NEW_BACKUP:
		case UPDATE_BACKUP: {
			entry_ref dirRef;
			if(msg->FindRef("settings_ref", &dirRef) == B_OK)
			{	BMessage setmsg;
				setmsg.what = RESTORES_REF;
				setmsg.AddRef("refs",&dirRef);
				if(!(settingsView->restoreSettingsRef(&setmsg)))
				{	break; }
			}
			//UpdateIfNeeded();
			BRect viewRect(0,0,200,25);
			viewRect.OffsetTo(Frame().left + (Bounds().Width() - viewRect.Width())/2.0,
							Frame().top + (Bounds().Height() - viewRect.Height())/2.0);
			BWindow *modalW = new BWindow(viewRect, "Reading Settings for Backup",
					B_FLOATING_WINDOW_LOOK, B_MODAL_APP_WINDOW_FEEL,
					B_NOT_ZOOMABLE | B_NOT_RESIZABLE | B_NOT_CLOSABLE);
			modalW->Lock();
			viewRect = modalW->Bounds();
			BView *mainView = new BView(viewRect, "Main View", B_FOLLOW_ALL, B_WILL_DRAW);
			mainView->SetViewColor(gui_background_color);
			viewRect.InsetBy(5, 5);
			BarberPole *poleView = new BarberPole(viewRect, "Pole", B_FOLLOW_ALL, B_WILL_DRAW, bpdLeftToRight);
			mainView->AddChild(poleView);
			modalW->AddChild(mainView);
			modalW->Unlock();
			poleView->SetActive(true);
			modalW->Show();

			//get path for zip file target
			BPath path;
			switch(msg->what){
				case NEW_BACKUP: {//get the directory and file name provided by the save file panel
					msg->FindRef("directory",&dirRef);
					char *namePtr;
					msg->FindString("name", (const char**)&namePtr);
					BEntry entry(&dirRef);
					entry.GetPath(&path);
					path.Append(namePtr);
				}
				case UPDATE_BACKUP:{//get the file name from the open file panel
					msg->FindRef("refs", &dirRef);
					BEntry entry(&dirRef, true);
					entry.GetPath(&path);
				}
			}
			bool newB;
			msg->FindBool("newBackup", &newB);
			saveBackup(path, newB);
			//(new BAlert("", "Backup done", "OK", NULL, NULL))->Go();
			poleView->SetActive(false);
			modalW->Lock();
			modalW->Quit();
			break; }
		case CHECK_SRC: {
			BEntry srcEntry(controlsView->getSrc());
			if(!srcEntry.Exists())
			{	BString errorText("\"");
				errorText.Append(controlsView->getSrc()).Append("\" is not a valid source entry");
				(new BAlert("", errorText.String(), "OK", NULL, NULL,
							B_WIDTH_AS_USUAL, B_WARNING_ALERT))->Go(NULL);
			}
			break; }
		case SRC_PANEL: {
			BMessage *srcmsg = new BMessage(SET_SRC);
			showFilePanel(openFileOrDirPanel,srcmsg);
			delete srcmsg;
			break; }
		case SET_SRC: {
			entry_ref srcRef;
			msg->FindRef("refs", &srcRef);
			BEntry srcEntry(&srcRef, true);
			BPath path(&srcEntry);
			controlsView->setSrc((char*)path.Path());
			break; }
		case TEMP_PANEL: {
			BMessage *tmpmsg = new BMessage(SET_TEMP);
			showFilePanel(openDirPanel,tmpmsg);
			delete tmpmsg;
			break; }
		case NEW_EXCLUDE: {
			BMessage *excmsg = new BMessage(EXCLUDE_REF);
			showFilePanel(openFileOrDirPanel,excmsg);
			delete excmsg;
			break; }
		case NEW_INCLUDE: {
			BMessage *incmsg = new BMessage(INCLUDE_REF);
			showFilePanel(openFileOrDirPanel,incmsg);
			delete incmsg;
			break; }
		case SAVES: {
			BMessage *ssmsg = new BMessage(SAVES_REF);
			showFilePanel(saveProfilePanel,ssmsg);
			delete ssmsg;
			break; }
		case RESTORES: {
			BMessage *rsmsg = new BMessage(RESTORES_REF);
			showFilePanel(openProfilePanel,rsmsg);
			delete rsmsg;
			break; }
		case RESTORES_REF: {
			settingsView->restoreSettingsRef(msg);
			break; }
		case SET_PROFILE_DIR: {
			msg->FindRef("refs", &fProfilesDirRef);
			saveProfilePanel->UpdateSettingsDirectory(&fProfilesDirRef);
			openProfilePanel->UpdateSettingsDirectory(&fProfilesDirRef);
			break; }
/*		case TOGGLE_S: {
			toggleSettings();
			break; }*/
		case UUENCODE_FILE: {
			BMessage *uuemsg = new BMessage(UUENCODE_REF);
			showFilePanel(openFilePanel, uuemsg);
			delete uuemsg;
			break; }
		case UUDECODE_FILE: {
			BMessage *uudmsg = new BMessage(UUDECODE_REF);
			showFilePanel(openFilePanel, uudmsg);
			delete uudmsg;
			break; }
		case TEST_ZIP: {
			BMessage *testmsg = new BMessage(TEST_ZIP_REF);
			showFilePanel(openFilePanel, testmsg);
			delete testmsg;
			break; }
		case ZIP_SPLIT: {
			int bytes = settingsView->getZipSplitBytes();
			if(bytes<1){
				(new BAlert("", "Error: Invalid number of bytes.", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
				break;
			}
			BMessage *zsmsg = new BMessage(ZIP_SPLIT_REF);
			showFilePanel(openFilePanel, zsmsg);
			delete zsmsg;
			break; }
		default:
			settingsView->MessageReceived(msg);
			BWindow::MessageReceived(msg);
			break;
	}
	return;
}
