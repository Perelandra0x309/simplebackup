#include "SBSettings.h"

//Settings View
SBSettings::SBSettings(BPicture *incupic, BPicture *incspic,
								BPicture *decupic, BPicture *decspic)
	:BView("Settings", B_WILL_DRAW | B_FRAME_EVENTS)
{
	SetViewColor(gui_background_color);
	BRect dummyRect(0,0,0,0);
	view1 = new BView("General", B_WILL_DRAW | B_FRAME_EVENTS);
	view2 = new BView("Compression", B_WILL_DRAW | B_FRAME_EVENTS);
	view3 = new BView("Ex/Include", B_WILL_DRAW | B_FRAME_EVENTS);
	view4 = new BView("Utilities", B_WILL_DRAW | B_FRAME_EVENTS);
/*	rgb_color test_color = {216,216,0,0};
	view1->SetViewColor(test_color);
	view2->SetViewColor(gui_background_color);
	view3->SetViewColor(gui_background_color);
	view4->SetViewColor(gui_background_color);*/
	tab1 = new BTab();
	tab2 = new BTab();
	tab3 = new BTab();
	tab4 = new BTab();
	settingsTabView = new BTabView("Settings View", B_WIDTH_FROM_WIDEST);
	settingsTabView->AddTab(view1, tab1);
	settingsTabView->AddTab(view2, tab2);
	settingsTabView->AddTab(view3, tab3);
	settingsTabView->AddTab(view4, tab4);

	//Tabview1
	freshenRB = new BRadioButton("Freshen File", "Update changed files but do not add new files",
							new BMessage(FRESHEN_CHANGED));
	updateRB = new BRadioButton("Update File", "Update changed files and add new files",
							new BMessage(UPDATE_CHANGED));
	recurse = new BCheckBox("Recurse", "Recurse directories", NULL);
	storeSym = new BCheckBox("Symlinks", "Save symlinks as a link, not the referenced file", NULL);
	removeDir = new BCheckBox("DirPath", "Don't save directory path information", NULL);
	deleteFiles = new BCheckBox("deleteFiles", "Delete files after compressing",
							new BMessage(DELETE_WARNING));
	exModBefore = new BCheckBox("Exclude Mod Before",
					"Don't add files modified before:", NULL);
	exModAfter = new BCheckBox("Exclude Mod After",
					"Don't add files modified after:", NULL);
#if USE_DATE_CONTROL
	modBeforeDate = new SBDateControl("Before", incupic, incspic, decupic, decspic);
	modAfterDate = new SBDateControl("After", incupic, incspic, decupic, decspic);
#else
	modBeforeDate = new SBDateControl("Before");
	modAfterDate = new SBDateControl("After");
#endif
	BStringView *monthLabel = new BStringView("MonthLabel", "Month");
	BStringView *dayLabel = new BStringView("DayLabel", "Day");
	BStringView *yearLabel = new BStringView("YearLabel", "Year");
//	BStringView *dayLabelDivider = new BStringView("DayLabelDivider", "/");
//	BStringView *yearLabelDivider = new BStringView("YearLabelDivider", "/");

	useTerm = new BCheckBox("Use Terminal",
						"Run zip in new terminal window", new BMessage(TERM_CHANGED));
	closeTerm = new BCheckBox("Close Terminal",
						"Automatically close terminal window after job is finished", NULL);

//	deleteFiles->SetExplicitMaxSize(BSize(deleteFiles->PreferredSize().width, B_SIZE_UNSET));
	exModBefore->SetExplicitMaxSize(BSize(exModBefore->PreferredSize().width, B_SIZE_UNSET));
//	exModAfter->SetExplicitMaxSize(BSize(exModAfter->PreferredSize().width, B_SIZE_UNSET));

	view1->SetLayout(new BGroupLayout(B_HORIZONTAL));
	view1->AddChild(BGroupLayoutBuilder(B_VERTICAL, gui_control_padding)
		.Add(freshenRB)
		.Add(updateRB)
		.Add(recurse)
		.Add(storeSym)
		.Add(removeDir)
		.Add(deleteFiles)
	/*	.Add(BGridLayoutBuilder(gui_control_padding, gui_control_padding)
			.Add(exModBefore, 0, 0)
			.Add(modBeforeDate, 1, 0)
			.Add(exModAfter, 0, 1)
			.Add(modAfterDate, 1, 1)
			.Add(BSpaceLayoutItem::CreateGlue(), 2, 0)
		)*/
		.Add(BGridLayoutBuilder(gui_control_padding, gui_control_padding)
			.Add(exModBefore, 0, 0)
			.Add(modBeforeDate->monthControl, 1, 0)
			.Add(modBeforeDate->dayLabelDivider, 2, 0)
			.Add(modBeforeDate->dayControl, 3, 0)
			.Add(modBeforeDate->yearLabelDivider, 4, 0)
			.Add(modBeforeDate->yearControl, 5, 0)
			.Add(monthLabel, 1, 1)
			//.Add(dayLabelDivider, 2, 1)
			.Add(dayLabel, 3, 1)
			//.Add(yearLabelDivider, 4, 1)
			.Add(yearLabel, 5, 1)
			.Add(exModAfter, 0, 2)
			.Add(modAfterDate->monthControl, 1, 2)
			.Add(modAfterDate->dayLabelDivider, 2, 2)
			.Add(modAfterDate->dayControl, 3, 2)
			.Add(modAfterDate->yearLabelDivider, 4, 2)
			.Add(modAfterDate->yearControl, 5, 2)
			.Add(BSpaceLayoutItem::CreateGlue(), 6, 0)
		)
		.Add(useTerm)
		.Add(BGroupLayoutBuilder(B_HORIZONTAL, gui_control_padding)
			.Add(closeTerm)
			.SetInsets(gui_control_indent, 0, 0, 0)
		)
		.AddGlue()
		.SetInsets(gui_group_inset, gui_group_inset, gui_group_inset, gui_group_inset)
	);

	//TabView2

	clSlider = new BSlider("Compression Level", "Compression Level",
							new BMessage(COMP_CHANGED), 0, 9, B_HORIZONTAL, B_TRIANGLE_THUMB);
	clSlider->SetHashMarks(B_HASH_MARKS_BOTTOM);
	clSlider->SetHashMarkCount(10);
	rgb_color barColor = {205,205,255,0};
	clSlider->SetBarColor(barColor);
	rgb_color fillColor = {200,255,200,0};
	clSlider->UseFillColor(true, &fillColor);

	noCompress = new BCheckBox("No Compress",
				"Do not use compression on files with these extensions:", NULL);

	noCompressList = new BListView(dummyRect, "No Compress List", B_MULTIPLE_SELECTION_LIST,
						B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_NAVIGABLE | B_FRAME_EVENTS);
	noCompressView = new BScrollView("No Compress List View", noCompressList, B_FOLLOW_NONE,
						B_WILL_DRAW | B_FRAME_EVENTS, false, true, B_FANCY_BORDER);
	noCompressView->SetViewColor(gui_background_color);

	custNoCompB = new BButton("Custom No Compress", "Add This",
								new BMessage(ADD_CSTMNOCOMP));

	remNoCompB = new BButton("Remove", "Remove", new BMessage(REMOVE_NOCOMP));

	custNoCompTC = new BTextControl("Custom No Compress", ":", ".", NULL);

	tempDir = new BCheckBox("TempDir", "Use temporary compression directory:", NULL);

	browseTempB = new BButton("Browse", "Browse" B_UTF8_ELLIPSIS, new BMessage(TEMP_PANEL));

	dirTextView = new BTextControl("Temp Dir", NULL, "/boot", new BMessage(CHECK_TEMP));

	noCompressList->SetExplicitMaxSize(BSize(be_plain_font->StringWidth("0000000000"), B_SIZE_UNSET));
	custNoCompTC->SetDivider(be_plain_font->StringWidth(custNoCompTC->Label()) + 4);
	custNoCompTC->SetExplicitMaxSize(BSize(be_plain_font->StringWidth("0000000000"), B_SIZE_UNSET));
	remNoCompB->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNSET));

	view2->SetLayout(new BGroupLayout(B_HORIZONTAL));
	view2->AddChild(BGroupLayoutBuilder(B_VERTICAL, gui_control_padding)
		.Add(clSlider)
		.Add(noCompress)
		.Add(BGridLayoutBuilder(gui_control_padding, gui_control_padding)
			.Add(noCompressView, 0, 0, 1, 4)
			.Add(custNoCompB, 1, 0)
			.Add(remNoCompB, 1, 1)
			.Add(custNoCompTC, 2, 0)
			.Add(BSpaceLayoutItem::CreateGlue(), 3, 0)
			.SetInsets(gui_control_indent, 0, 0, 0)
		)
		.Add(tempDir)
		.Add(BGroupLayoutBuilder(B_HORIZONTAL, gui_control_padding)
			.Add(dirTextView)
			.Add(browseTempB)
			.SetInsets(gui_control_indent, 0, 0, 0)
		)
		.SetInsets(gui_group_inset, gui_group_inset, gui_group_inset, gui_group_inset)
	);

	//Tabview3
	exclude = new BCheckBox("Exclude", "Exclude these files:", new BMessage(EXCLUDE_CHANGED));
	newExcludeB = new BButton("Add", "Add" B_UTF8_ELLIPSIS, new BMessage(NEW_EXCLUDE));
	delExcludeB = new BButton("Remove", "Remove", new BMessage(REMOVE_EXCLUDES));
	custExcludeB = new BButton("Custom Exclude", "Add Custom", new BMessage(ADD_CSTMEXCLUDE));
	excludeList = new BListView(dummyRect, "Exclude List", B_MULTIPLE_SELECTION_LIST,
						B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_NAVIGABLE | B_FRAME_EVENTS);
	excludeView = new BScrollView("Exclude List View", excludeList, B_FOLLOW_NONE,
						B_WILL_DRAW | B_FRAME_EVENTS, true, true, B_FANCY_BORDER);
	excludeView->SetViewColor(gui_background_color);
	custExcludeTC = new BTextControl("Custom Exclude", ":", "*.", NULL);
	custExcludeTC->SetDivider(be_plain_font->StringWidth(custExcludeTC->Label()) + 4);
	include = new BCheckBox("Include", "Include only these files:",
							new BMessage(INCLUDE_CHANGED));
	newIncludeB = new BButton("Add", "Add" B_UTF8_ELLIPSIS, new BMessage(NEW_INCLUDE));
	delIncludeB = new BButton("Remove", "Remove", new BMessage(REMOVE_INCLUDES));
	custIncludeB = new BButton("Custom Include", "Add Custom", new BMessage(ADD_CSTMINCLUDE));
	includeList = new BListView(dummyRect, "Include List", B_MULTIPLE_SELECTION_LIST,
						B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_NAVIGABLE | B_FRAME_EVENTS);
	includeView = new BScrollView("Include List View", includeList, B_FOLLOW_NONE,
						B_WILL_DRAW | B_FRAME_EVENTS, true, true, B_FANCY_BORDER);
	includeView->SetViewColor(gui_background_color);
	custIncludeTC = new BTextControl("Custom Include", ":", "*.", NULL);
	custIncludeTC->SetDivider(be_plain_font->StringWidth(custIncludeTC->Label()) + 4);

	newExcludeB->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNSET));
	excludeList->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNLIMITED));
	newIncludeB->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNSET));
	includeList->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNLIMITED));

	view3->SetLayout(new BGroupLayout(B_HORIZONTAL));
	view3->AddChild(BGroupLayoutBuilder(B_VERTICAL, gui_control_padding)
		.Add(exclude)
		.Add(BGridLayoutBuilder(gui_control_padding, gui_control_padding)
			.Add(excludeView, 0, 0, 1, 3)
			.Add(newExcludeB, 1, 0)
			.Add(delExcludeB, 1, 1)
			.Add(BGroupLayoutBuilder(B_HORIZONTAL, gui_control_padding)
				.Add(custExcludeB)
				.Add(custExcludeTC)
			, 0, 3)
			.SetInsets(gui_control_indent, 0, 0, 0)
		)
		.Add(include)
		.Add(BGridLayoutBuilder(gui_control_padding, gui_control_padding)
			.Add(includeView, 0, 0, 1, 3)
			.Add(newIncludeB, 1, 0)
			.Add(delIncludeB, 1, 1)
			.Add(BGroupLayoutBuilder(B_HORIZONTAL, gui_control_padding)
				.Add(custIncludeB)
				.Add(custIncludeTC)
			, 0, 3)
			.SetInsets(gui_control_indent, 0, 0, 0)
		)
		.SetInsets(gui_group_inset, gui_group_inset, gui_group_inset, gui_group_inset)
	);

	//TabView4
	zipTestB = new BButton("Test Zip", "Choose a zip file to test" B_UTF8_ELLIPSIS, new BMessage(TEST_ZIP));
	zipTestBox = new BBox("Zip Test");
	zipTestBox->SetLabel("Zip File Integrity Test");
	BGroupLayout *zipTestLayout = BLayoutBuilder::Group<>(B_HORIZONTAL)
		.Add(zipTestB)
		.SetInsets(gui_group_inset, gui_group_inset, gui_group_inset, gui_group_inset)
	;
	zipTestBox->AddChild(zipTestLayout->View());

	zipsplitB = new BButton("ZipSplit", "Choose a zip file to split" B_UTF8_ELLIPSIS, new BMessage(ZIP_SPLIT));
	splitsize = new BTextControl("ZipSplit size", "Split zip file into sections of:", NULL, NULL);
	splitsize->SetDivider(be_plain_font->StringWidth(splitsize->Label()) + 4);
//	splitsize->TextView()->MakeSelectable(false);
	long i;
	for (i = 0; i < 256; i++) splitsize->TextView()->DisallowChar(i);
	for (i = '0'; i <= '9'; i++) splitsize->TextView()->AllowChar(i);
	splitsize->TextView()->AllowChar('.');
	splitsize->TextView()->AllowChar(B_BACKSPACE);
	splitsizeMenu = new BPopUpMenu("ZipSplit Blocks");
	splitsizeMenu->AddItem(new BMenuItem("Bytes", NULL));
	splitsizeMenu->AddItem(new BMenuItem("KiloBytes", NULL));
	splitsizeMenu->AddItem(new BMenuItem("MegaBytes", NULL));
	splitsizeMenu->ItemAt(2)->SetMarked(true);
	splitsizeField = new BMenuField("ZipSplit MenuField", NULL, splitsizeMenu);
	zsplitRB = new BRadioButton("use zsplit", "Use the \'zipsplit\' command (each split file is a valid archive)", NULL/*,
							new BMessage(ZSPLIT_CHANGED)*/);
	splitRB = new BRadioButton("use split", "Use the \'split\' command", NULL/*,
							new BMessage(SPLIT_CHANGED)*/);
	zipsplitBox = new BBox("Zip Split");
	zipsplitBox->SetLabel("Split A Zip File");
	BGroupLayout *zipSplitLayout = BLayoutBuilder::Group<>(B_VERTICAL)
		.Add(BGroupLayoutBuilder(B_HORIZONTAL, gui_control_padding)
			.Add(splitsize)
			.Add(splitsizeField)
			.AddGlue()
		)
		.Add(zsplitRB)
		.Add(splitRB)
		.Add(zipsplitB)
		.SetInsets(gui_group_inset, gui_group_inset, gui_group_inset, gui_group_inset)
	;
	zipsplitBox->AddChild(zipSplitLayout->View());

	uuencodeB = new BButton("UUencode", "UUencode File" B_UTF8_ELLIPSIS, new BMessage(UUENCODE_FILE));
	uudecodeB = new BButton("UUdecode", "UUdecode File" B_UTF8_ELLIPSIS, new BMessage(UUDECODE_FILE));
	uueBox = new BBox("UUE");
	uueBox->SetLabel("UUE Encoding and Decoding");
	BGroupLayout *uueLayout = BLayoutBuilder::Group<>(B_HORIZONTAL)
		.Add(uuencodeB)
		.Add(uudecodeB)
		.SetInsets(gui_group_inset, gui_group_inset, gui_group_inset, gui_group_inset)
	;
	uueBox->AddChild(uueLayout->View());

	zipTestBox->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNSET));
	zipsplitBox->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNSET));
	splitsizeField->ResizeToPreferred();
	splitsizeField->SetExplicitMaxSize(BSize(splitsizeField->Frame().Width(), B_SIZE_UNSET));
	uueBox->SetExplicitMaxSize(BSize(B_SIZE_UNLIMITED, B_SIZE_UNSET));

	BGroupLayout *view4Layout = new BGroupLayout(B_VERTICAL);
	view4->SetLayout(view4Layout);
	BLayoutBuilder::Group<>(view4Layout)
		.Add(zipTestBox)
		.Add(zipsplitBox)
		.Add(uueBox)
		.AddGlue()
		.SetInsets(gui_group_inset, gui_group_inset, gui_group_inset, gui_group_inset)
	;

	BGroupLayout *thisViewLayout = new BGroupLayout(B_HORIZONTAL);
	SetLayout(thisViewLayout);
	BLayoutBuilder::Group<>(thisViewLayout)
		.Add(settingsTabView)
	;

	InitSettings();
}
SBSettings::~SBSettings()
{	}
//Set all the default settings values
void SBSettings::InitSettings()
{	//setFreshen(false);
	setUpdate(true);
	setRecurse(true);
	setStoreSym(true);
	setRemoveDir(false);
	setDeleteFiles(false);
	setModBefore(false);
	modBeforeDate->setMonth("01");
	modBeforeDate->setDay("01");
	modBeforeDate->setYear("1999");
	setModAfter(false);
	modAfterDate->setMonth("01");
	modAfterDate->setDay("01");
	modAfterDate->setYear("1999");
	setUseTerm(true);
	setCloseTerm(false);
	setCompLevel(6);
	setNoCompression(true);
	setNoCompress(false);
	setTempDir(false);
	setTempDir("/boot");
	setExclude(false);
	setInclude(false);
	zsplitRB->SetValue(true);
}
BString SBSettings::getModDate(SBDateControl* modDate)
{	BString date("");
	date.Append(modDate->getMonth());
	date.Append(modDate->getDay());
	date.Append(modDate->getYear());
	return date;
}
void SBSettings::setCompLabel()
{	BString label("Compression Level: ");
	char n[4];
	int value = clSlider->Value();
	sprintf(n, "%i", value);
	label += n;
	switch(value)
	{	case 0: label += "- none"; break;
		case 1: label += "- fastest"; break;
		case 6: label += "- default"; break;
		case 9: label += "- slowest (compress everything)"; break;
	}
	clSlider->SetLabel(label.String());
}
void SBSettings::setNoCompression(bool a)
{	noCompress->SetEnabled(a);
	custNoCompTC->SetEnabled(a);
	remNoCompB->SetEnabled(a);
	custNoCompB->SetEnabled(a);
	int noCompressNumber = noCompressList->CountItems();
	for(int i=0; i<noCompressNumber; i++)
	{	if(!a) noCompressList->ItemAt(i)->Deselect();
		noCompressList->ItemAt(i)->SetEnabled(a);
		noCompressList->InvalidateItem(i);
	}
}
void SBSettings::addCustomNoCompress()
{
	addCustomNoCompress(custNoCompTC->Text(),true);
}
void SBSettings::addCustomNoCompress(const char *ncchar, bool cstm)
{	if( strcmp(ncchar,"") == 0 )
	{	(new BAlert("","Invalid entry", "OK"))->Go(NULL);
		return; }
	char* path;
	int count = noCompressList->CountItems();
	for(int i=0; i<count; i++) //Check for previous entry
	{	path = (char*)(static_cast<SBListItem*>(noCompressList->ItemAt(i)))->Text();
		if( strcmp(path, ncchar) == 0 )
		{	BString alertStr("The file extension \"");
			alertStr.Append(ncchar);
			alertStr.Append("\" is already listed");
			(new BAlert("", alertStr.String(), "Oops"))->Go(NULL);
			return; }
	}
	noCompressList->AddItem(new SBListItem(ncchar,cstm));
	return;
}
void SBSettings::removeNoCompressItems()
{	int32 count = noCompressList->CountItems();
	for(int i=count-1; i>=0; i--)
	{	if(noCompressList->IsItemSelected(i)) noCompressList->RemoveItem(i); }
	return;
}
void SBSettings::addExclude(BEntry excEntry)
{	BPath excPath(&excEntry);
	char* path;
	int count = excludeList->CountItems();
	for(int i=0; i<count; i++) //Check for previous entry
	{	path = (char*)(static_cast<SBListItem*>(excludeList->ItemAt(i)))->Text();
		if( strcmp(path, excPath.Path()) == 0 )
		{	BString alertStr("The entry \"");
			alertStr.Append(path);
			alertStr.Append("\" is already listed");
			(new BAlert("", alertStr.String(), "Oops"))->Go(NULL);
			return; }
	}
	excludeList->AddItem(new SBListItem(excPath.Path()));
	return;
}
void SBSettings::addCustomExclude()
{
	addCustomExclude(custExcludeTC->Text(),true);
}
void SBSettings::addCustomExclude(const char *excchar,bool cstm)
{	if( strcmp(excchar,"") == 0 )
	{	(new BAlert("","Invalid entry", "OK"))->Go(NULL);
		return; }
	char* path;
	int count = excludeList->CountItems();
	for(int i=0; i<count; i++) //Check for previous entry
	{	path = (char*)(static_cast<SBListItem*>(excludeList->ItemAt(i)))->Text();
		if( strcmp(path, excchar) == 0 )
		{	BString alertStr("The entry \"");
			alertStr.Append(path);
			alertStr.Append("\" is already listed");
			(new BAlert("", alertStr.String(), "Oops"))->Go(NULL);
			return; }
	}
	excludeList->AddItem(new SBListItem(excchar,cstm));
	return;
}
void SBSettings::removeExcludes()
{	int32 count = excludeList->CountItems();
	for(int i=count-1; i>=0; i--)
	{	if(excludeList->IsItemSelected(i)) excludeList->RemoveItem(i); }
	return;
}
void SBSettings::addInclude(BEntry incEntry) //Manip Includes
{	BPath incPath(&incEntry);
	char* path;
	int count = includeList->CountItems();
	for(int i=0; i<count; i++) //Check for previous entry
	{	path = (char*)(static_cast<SBListItem*>(includeList->ItemAt(i)))->Text();
		if( strcmp(path, incPath.Path()) == 0 )
		{	BString alertStr("The entry \"");
			alertStr.Append(path);
			alertStr.Append("\" is already listed");
			(new BAlert("", alertStr.String(), "Oops"))->Go(NULL);
			return; }
	}
	includeList->AddItem(new SBListItem(incPath.Path()));
	return;
}
void SBSettings::addCustomInclude()
{
	addCustomInclude(custIncludeTC->Text(),true);
}
void SBSettings::addCustomInclude(const char *incchar, bool cstm)
{	if( strcmp(incchar,"") == 0 )
	{	(new BAlert("","Invalid entry", "OK"))->Go(NULL);
		return; }
	char* path;
	int count = includeList->CountItems();
	for(int i=0; i<count; i++) //Check for previous entry
	{	path = (char*)(static_cast<SBListItem*>(includeList->ItemAt(i)))->Text();
		if( strcmp(path, incchar) == 0 )
		{	BString alertStr("The entry \"");
			alertStr.Append(path);
			alertStr.Append("\" is already listed");
			(new BAlert("", alertStr.String(), "Oops"))->Go(NULL);
			return; }
	}
	includeList->AddItem(new SBListItem(incchar,cstm));
	return;
}
void SBSettings::removeIncludes()
{	int32 count = includeList->CountItems();
	for(int i=count-1; i>=0; i--)
	{	if(includeList->IsItemSelected(i)) includeList->RemoveItem(i); }
	return;
}
BString SBSettings::getNoCompressEntrys()
{	int count = noCompressList->CountItems();
	BString args("");
	for(int i=0; i<count; i++)
	{	if(i>0) args += ":";
		args += (char*)((static_cast<SBListItem*>(noCompressList->ItemAt(i)))->Text());
	}
	return args;
}
bool SBSettings::getExcludeEntrys(BPath& exListPath)
{
	return(getListEntrys(excludeList,exListPath));
}
bool SBSettings::getIncludeEntrys(BPath& inListPath)
{
	return(getListEntrys(includeList,inListPath));
}
bool SBSettings::getListEntrys(BListView* list, BPath &listPath)
{	BFile listFile;
	status_t error;
	do
	{	error = listFile.SetTo(listPath.Path(),
						B_READ_WRITE | B_CREATE_FILE | B_ERASE_FILE);
	} while(error == B_PERMISSION_DENIED);
	if(error!=B_OK)
	{	(new BAlert("","Error creating list file","OK"))->Go(NULL);
		return(false);
	}
	char *entryPtr;
	BPath filePath;
	BEntry fileEntry;
	int32 count = list->CountItems();
	for(int i=0; i<count; i++)
	{	entryPtr = (char*)((static_cast<SBListItem*>(list->ItemAt(i)))->Text());
		if((static_cast<SBListItem*>(list->ItemAt(i)))->getCustomValue()) //Custom entry
		{	listFile.Write(entryPtr, strlen(entryPtr));
			listFile.Write("\n",1); }
		else
		{	if( (fileEntry.SetTo(entryPtr, !getStoreSymValue())) == B_OK)
			{	fileEntry.GetPath(&filePath);
				listFile.Write(filePath.Path(), strlen(filePath.Path()));
				listFile.Write("\n",1);
				if(fileEntry.IsDirectory() && getRecurseValue())
				{	writeDirEntrys(&fileEntry, &listFile); }
			}
		}
	}
	return(true);
}
void SBSettings::writeDirEntrys(BEntry* dirEntry, BFile* listFile)
{	BDirectory thisDir(dirEntry);
	if(thisDir.InitCheck() != B_OK) { return; }
	BEntry curEntry;
	BPath filePath;
	while(thisDir.GetNextEntry(&curEntry, !getStoreSymValue()) == B_OK)
	{	curEntry.GetPath(&filePath);
		listFile->Write(filePath.Path(), strlen(filePath.Path()));
		listFile->Write("\n",1);
		if(curEntry.IsDirectory() && getRecurseValue())
		{	writeDirEntrys(&curEntry, listFile); }
	}
	return;
}
void SBSettings::storeSettings(BMessage &archive)
{	archive.AddString("SBC:source", parent->getSrc());
	archive.AddInt8("SBS:comp", getCompLevel());
	archive.AddBool("SBS:update", getUpdateValue());
	archive.AddBool("SBS:recurse", getRecurseValue());
	archive.AddBool("SBS:storeSym", getStoreSymValue());
	archive.AddBool("SBS:removeDir", getRemoveDirValue());
	archive.AddBool("SBS:deleteFiles", getDeleteFilesValue());
	archive.AddBool("SBS:tempDir", getTempDirValue());
	archive.AddString("SBS:tempDirRef", getTempDir());
	archive.AddBool("SBS:modBefore", getModBeforeValue());
	archive.AddString("SBS:modBeforeMonth", modBeforeDate->getMonth());
	archive.AddString("SBS:modBeforeDay", modBeforeDate->getDay());
	archive.AddString("SBS:modBeforeYear", modBeforeDate->getYear());
	archive.AddBool("SBS:modAfter", getModAfterValue());
	archive.AddString("SBS:modAfterMonth", modAfterDate->getMonth());
	archive.AddString("SBS:modAfterDay", modAfterDate->getDay());
	archive.AddString("SBS:modAfterYear", modAfterDate->getYear());
	archive.AddBool("SBS:useTerm", getUseTermValue());
	archive.AddBool("SBS:closeTerm", getCloseTermValue());
	archive.AddBool("SBS:noCompress", getNoCompressValue()); //No Compression
	int noCompressNumber = noCompressList->CountItems();
	archive.AddInt8("SBS:noCompressNumber", noCompressNumber);
	int i;
	for(i=0; i<noCompressNumber; i++)
	{	archive.AddString("SBS:noCompressEntry",
			(static_cast<SBListItem*>(noCompressList->ItemAt(i)))->Text() );
		archive.AddBool("SBS:noCompressCustom",
			(static_cast<SBListItem*>(noCompressList->ItemAt(i)))->getCustomValue() );
	}
	archive.AddBool("SBS:exclude", getExcludeValue()); //Excludes
	int excludeNumber = excludeList->CountItems();
	archive.AddInt8("SBS:excludeNumber", excludeNumber);
	for(i=0; i<excludeNumber; i++)
	{	archive.AddString("SBS:excludeEntry",
			(static_cast<SBListItem*>(excludeList->ItemAt(i)))->Text() );
		archive.AddBool("SBS:excludeCustom",
			(static_cast<SBListItem*>(excludeList->ItemAt(i)))->getCustomValue() );
	}
	archive.AddBool("SBS:include", getIncludeValue()); //Includes
	int includeNumber = includeList->CountItems();
	archive.AddInt8("SBS:includeNumber", includeNumber);
	for(i=0; i<includeNumber; i++)
	{	archive.AddString("SBS:includeEntry",
			(static_cast<SBListItem*>(includeList->ItemAt(i)))->Text() );
		archive.AddBool("SBS:includeCustom",
			(static_cast<SBListItem*>(includeList->ItemAt(i)))->getCustomValue() );
	}
	return;
}
bool SBSettings::restoreSettingsRef(BMessage *msg){
	bool success = false;
	entry_ref srcRef;
	msg->FindRef("refs", &srcRef);
	BEntry srcEntry(&srcRef, true);
	BFile srcFile(&srcEntry, B_READ_ONLY);
	off_t datasize;
	srcFile.GetSize(&datasize);
	char* databuf = new char[datasize];
	if((srcFile.Read(databuf, datasize))!=datasize)
	{	(new BAlert("","Error loading archive file","OK",
						NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
	}
	else
	{	BMessage archive;
		if(archive.Unflatten(databuf)!=B_OK)
		{	(new BAlert("","Error reading archived settings","OK",
						NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		}
		else
		{	restoreSettings(archive);
			success = true;
		}
	}
	delete[] databuf;
	return success;
}
void SBSettings::restoreSettings(BMessage &archive)
{	Window()->Lock();
	char *charPtr;
	archive.FindString("SBC:source", (const char**)&charPtr);
	parent->setSrc(charPtr);
	int8 a_compValue;
	archive.FindInt8("SBS:comp", &a_compValue);
	setCompLevel(a_compValue);
	bool bvalue;
	archive.FindBool("SBS:update", &bvalue);
	setUpdate(bvalue);
	archive.FindBool("SBS:recurse", &bvalue);
	setRecurse(bvalue);
	archive.FindBool("SBS:storeSym", &bvalue);
	setStoreSym(bvalue);
	archive.FindBool("SBS:removeDir", &bvalue);
	setRemoveDir(bvalue);
	archive.FindBool("SBS:deleteFiles", &bvalue);
	setDeleteFiles(bvalue);
	archive.FindBool("SBS:tempDir", &bvalue);
	setTempDir(bvalue);
	archive.FindString("SBS:tempDirRef", (const char**)&charPtr);
	setTempDir(charPtr);
	archive.FindBool("SBS:modBefore", &bvalue);
	setModBefore(bvalue);
	archive.FindString("SBS:modBeforeMonth", (const char**)&charPtr);
	modBeforeDate->setMonth(charPtr);
	archive.FindString("SBS:modBeforeDay", (const char**)&charPtr);
	modBeforeDate->setDay(charPtr);
	archive.FindString("SBS:modBeforeYear", (const char**)&charPtr);
	modBeforeDate->setYear(charPtr);
	archive.FindBool("SBS:modAfter", &bvalue);
	setModAfter(bvalue);
	archive.FindString("SBS:modAfterMonth", (const char**)&charPtr);
	modAfterDate->setMonth(charPtr);
	archive.FindString("SBS:modAfterDay", (const char**)&charPtr);
	modAfterDate->setDay(charPtr);
	archive.FindString("SBS:modAfterYear", (const char**)&charPtr);
	modAfterDate->setYear(charPtr);
	archive.FindBool("SBS:useTerm", &bvalue);
	setUseTerm(bvalue);
	archive.FindBool("SBS:closeTerm", &bvalue);
	setCloseTerm(bvalue);
	archive.FindBool("SBS:noCompress", &bvalue);
	setNoCompress(bvalue);
	int32 count = noCompressList->CountItems();
	int i;
	for(i=count-1; i>=0; i--)
	{	noCompressList->RemoveItem(i); }
	int8 noCompressNumber;
	archive.FindInt8("SBS:noCompressNumber", &noCompressNumber);
	bool cstm;
	char *noCompressPath;
	for(i=0; i<noCompressNumber; i++)
	{	archive.FindString("SBS:noCompressEntry", i, (const char**)&noCompressPath);
		archive.FindBool("SBS:noCompressCustom", i, &cstm);
		addCustomNoCompress(noCompressPath,cstm); }
	archive.FindBool("SBS:exclude", &bvalue); //Excludes
	setExclude(bvalue);
	count = excludeList->CountItems();
	for(i=count-1; i>=0; i--)
	{	excludeList->RemoveItem(i); }
	int8 excludeNumber;
	archive.FindInt8("SBS:excludeNumber", &excludeNumber);
	char *excludePath;
	for(i=0; i < excludeNumber; i++)
	{	archive.FindString("SBS:excludeEntry", i, (const char**)&excludePath);
		archive.FindBool("SBS:excludeCustom", i, &cstm);
		addCustomExclude(excludePath,cstm); }
	archive.FindBool("SBS:include", &bvalue); //Includes
	setInclude(bvalue);
	count = includeList->CountItems();
	for(i=count-1; i>=0; i--)
	{	includeList->RemoveItem(i); }
	int8 includeNumber;
	archive.FindInt8("SBS:includeNumber", &includeNumber);
	char *includePath;
	for(i=0; i < includeNumber; i++)
	{	archive.FindString("SBS:includeEntry", i, (const char**)&includePath);
		archive.FindBool("SBS:includeCustom", i, &cstm);
		addCustomInclude(includePath,cstm); }
	Window()->Unlock();
	return;
}
void SBSettings::MessageReceived(BMessage *msg)
{	switch(msg->what)
	{//	case FRESHEN_CHANGED: toggleUpdate(); break;
	//	case UPDATE_CHANGED: toggleFreshen(); break;
		case DELETE_WARNING:{
			if(deleteFiles->Value())
			{int ans = (new BAlert("",	"Warning! Files will be deleted after they have "
										"been compressed.  Are you sure you want to "
										"do this?  (Be assured, the archive is checked "
										"for integrity before any files are deleted.)",
						"Yes", "NO!", NULL, B_WIDTH_AS_USUAL, B_WARNING_ALERT))->Go();
				if(ans==1) setDeleteFiles(false);
			}
			break; }
		case TERM_CHANGED: {
			closeTerm->SetEnabled(useTerm->Value());
			break; }
		case CHECK_TEMP: {
			BDirectory tmpDir(getTempDir());
			BPath path(&tmpDir, NULL);
			if((char*)path.Path() == NULL)
			{	BString errorText("\"");
				errorText.Append(getTempDir()).Append("\" is not a valid directory");
				(new BAlert("", errorText.String(), "OK", NULL, NULL,
							B_WIDTH_AS_USUAL, B_WARNING_ALERT))->Go(NULL);
			}
			break; }
		case SET_TEMP: {
			entry_ref tmpRef;
			msg->FindRef("refs", &tmpRef);
			BDirectory tmpDir(&tmpRef); //Acts as filter to pass only directories
			BPath path(&tmpDir, NULL);
			setTempDir((char*)path.Path());
			break; }
		case COMP_CHANGED: {
			int compValue = clSlider->Value();
			setNoCompression(compValue!=0 && compValue!=9);
			setCompLabel();
			break; }
		case REMOVE_NOCOMP:{ removeNoCompressItems(); break; }
		case ADD_CSTMNOCOMP: { addCustomNoCompress(); break; }
		case EXCLUDE_REF: {
			entry_ref excRef;
			msg->FindRef("refs", &excRef);
			BEntry excEntry(&excRef);
			addExclude(excEntry);
			break; }
		case REMOVE_EXCLUDES: { removeExcludes(); break; }
		case ADD_CSTMEXCLUDE: { addCustomExclude(); break; }
		case INCLUDE_REF: {
			entry_ref incRef;
			msg->FindRef("refs", &incRef);
			BEntry incEntry(&incRef);
			addInclude(incEntry);
			break; }
		case REMOVE_INCLUDES: { removeIncludes(); break; }
		case ADD_CSTMINCLUDE: { addCustomInclude(); break; }
		case SAVES_REF: {
			entry_ref dirRef;
			msg->FindRef("directory",&dirRef);
			char *name;
			msg->FindString("name", (const char**)&name);
			BDirectory saveDir(&dirRef);
			BEntry saveEntry(&saveDir, name);
			BMessage archive;
			storeSettings(archive);
			BFile saveFile(&saveEntry, B_READ_WRITE | B_CREATE_FILE | B_ERASE_FILE);
			int datasize = archive.FlattenedSize();
			char* databuf = new char[datasize];
			if(archive.Flatten(databuf, datasize)!=B_OK)
			{	(new BAlert("","Error flattening data archive.","OK",
								NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
				delete[] databuf; break; }
			if( (saveFile.Write(databuf, datasize))!=datasize )
			{	(new BAlert("","Error writing archive file.","OK",
						NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
			}
			delete[] databuf; break; }
		case DEFAULTS: { InitSettings(); break; }
		case UUENCODE_REF: {
			entry_ref ref;
			msg->FindRef("refs",&ref);
			uuencode(ref, getCloseTermValue());
			break; }
		case UUDECODE_REF: {
			entry_ref ref;
			msg->FindRef("refs",&ref);
			uudecode(ref, getCloseTermValue());
			break; }
		case TEST_ZIP_REF: {
			entry_ref ref;
			msg->FindRef("refs",&ref);
			testzip(ref);
			break; }
//		case ZSPLIT_CHANGED: { toggleSplit(); break; }
//		case SPLIT_CHANGED: { toggleZsplit(); break; }
		case ZIP_SPLIT_REF: {
			entry_ref ref;
			msg->FindRef("refs",&ref);
			int bytes = getZipSplitBytes();
			if(bytes>0) zipsplit(ref, bytes, zsplitRB->Value(), getCloseTermValue());
			else (new BAlert("", "Error: Invalid number of bytes.", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
			break; }
/*		default: {
			BView::MessageReceived(msg);
			break; }*/
	}
	return;
}

int SBSettings::getZipSplitBytes(){
	int bytes = (int)(strtod(splitsize->Text(),NULL)*
				pow(1024,splitsizeMenu->IndexOf(splitsizeMenu->FindMarked()) ));
	return bytes;
}

