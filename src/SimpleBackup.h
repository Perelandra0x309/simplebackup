/*  SimpleBackup- written by Brian Hill, perelandra777@gmail.com

    This program was written for Haiku (http://www.haiku-os.org) and provides an


    --Protected under General Public License--

    Copyright (C) 1999-2009,  Brian Hill <perelandra777@gmail.com>

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
#ifndef SB_SIMPLEBACKUP_H
#define SB_SIMPLEBACKUP_H

//Kits
#include <SupportKit.h>
#include <AppKit.h>
#include <InterfaceKit.h>
#include <StorageKit.h>

//GUI layout
#include <GridLayoutBuilder.h>
#include <GroupLayout.h>
#include <GroupLayoutBuilder.h>
#include <SpaceLayoutItem.h>

//Other libraries
#include <stdio.h>
#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include "BarberPole.h"

//SimpleBackup classes
#include "constants.h"
#include "utilities.h"
#include "SBApp.h"
#include "SBControls.h"
#include "SBDateControl.h"
#include "SBListItem.h"
#include "SBSettings.h"
#include "SWDOpenFilePanel.h"
#include "SBWindow.h"

//Classes
//class SBWindow;
//class SBControls;
//class SBSettings;
//class SBDateControl;
//class SBListItem;
//class SWDOpenFilePanel;
/*class SBApp : public BApplication
{public:
					SBApp();
					~SBApp();
	virtual void	ReadyToRun();
	virtual void	ArgvReceived(int32,char**);
	void			printhelp();
private:
	SBWindow		*aWindow;
	bool			ready_to_run;
};*/
/*class SBWindow : public BWindow
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
	bool			settingsShown;
	void			toggleSettings();
	void			showFilePanel(BFilePanel*,BMessage*);
	void			saveBackup(BPath&, bool);
};*/
/*class SBControls : public BView
{public:
					SBControls(BRect&, BPicture* = NULL, BPicture* = NULL, SBSettings* = NULL);
					~SBControls();
//	virtual void	FrameResized(float,float);
	char*			getSrc() { return (char*)backupSrc->Text(); }
	void			setSrc(char* src) { backupSrc->SetText(src); return; }
	void			setToggleB(bool a) { togglePB->SetValue(a); }
	float			getBottom() { return newB->Frame().bottom; }
private:
	BTextControl	*backupSrc;
	BButton			*newB, *updateB, *browseSrc;
	BPictureButton	*togglePB;
};*/
/*class SBSettings : public BView
{public:
					SBSettings(BRect&, BPicture* = NULL,
							BPicture* = NULL, BPicture* = NULL, BPicture* = NULL);
					~SBSettings();
	virtual void	MessageReceived(BMessage*);
	void			setControlsView(SBControls* ptr){ parent = ptr;}
	float			getPreferredWidth()
					{	return settingsTabView->TabFrame(4).left + 8; }
	bool			getUpdateValue() { return updateRB->Value(); }
	bool			getRecurseValue() { return recurse->Value(); }
	bool			getStoreSymValue() { return storeSym->Value(); }
	bool			getRemoveDirValue() { return removeDir->Value(); }
	bool			getDeleteFilesValue() { return deleteFiles->Value(); }
	bool			getTempDirValue() { return tempDir->Value(); }
	int				getCompLevel() { return clSlider->Value(); }
	char*			getTempDir() { return (char*)dirTextView->Text(); }
	bool			getModBeforeValue() { return exModBefore->Value(); }
	BString			getModBeforeDate() { return getModDate(modBeforeDate); }
	bool			getModAfterValue() { return exModAfter->Value(); }
	BString			getModAfterDate() { return getModDate(modAfterDate); }
	BString			getModDate(SBDateControl*);
	bool			getUseTermValue() { return useTerm->Value(); }
	bool			getCloseTermValue() { return closeTerm->Value(); }
	bool			getNoCompressValue() { return noCompress->Value(); }
	int				getNoCompressNumber() { return noCompressList->CountItems(); }
	bool			getExcludeValue() { return exclude->Value(); }
	int				getExcludeNumber() { return excludeList->CountItems(); }
	bool			getIncludeValue() { return include->Value(); }
	int				getIncludeNumber() { return includeList->CountItems(); }
	BString			getNoCompressEntrys();
	bool			getExcludeEntrys(BPath&);
	bool			getIncludeEntrys(BPath&);
	void			storeSettings(BMessage&);
	bool			restoreSettingsRef(BMessage*);
	void			restoreSettings(BMessage&);
	SBControls		*parent;
private:
	BSlider			*clSlider;
	BRadioButton	*freshenRB, *updateRB, *zsplitRB, *splitRB;
	BCheckBox		*recurse, *storeSym, *removeDir, *deleteFiles, *exModBefore,
					*exModAfter, *useTerm, *closeTerm, *noCompress, *tempDir,
					*exclude, *include;
	BTextControl	*dirTextView, *splitsize,
					*custNoCompTC, *custExcludeTC, *custIncludeTC;
	SBDateControl	*modBeforeDate, *modAfterDate;
	BListView		*excludeList, *includeList, *noCompressList;
	BScrollView		*excludeView, *includeView, *noCompressView;
	BButton			*browseTempB, *remNoCompB, *custNoCompB,
					*newExcludeB, *delExcludeB, *custExcludeB,
					*newIncludeB, *delIncludeB, *custIncludeB,
					*uuencodeB, *uudecodeB, *zipTestB, *zipsplitB,
					*defaultSB, *restoreSB, *saveSB, *aboutB;
	BPopUpMenu		*splitsizeMenu;
	BMenuField		*splitsizeField;
	BTabView		*settingsTabView;
	BTab			*tab1, *tab2, *tab3, *tab4;
	BView			*view1, *view2, *view3, *view4;
	BStringView		*uueLabel, *uudLabel, *testZipLabel;
	BBox			*zipTestBox, *uueBox, *zipsplitBox;
	void			InitSettings();
//	void			toggleFreshen() { freshen->SetValue(!freshen->Value()); }
//	void			toggleUpdate() { update->SetValue(!update->Value()); }
//	void			toggleZsplit() { zsplitCB->SetValue(!zsplitCB->Value()); }
//	void			toggleSplit() { splitCB->SetValue(!splitCB->Value()); }
//	void			setFreshen() { freshenRB->SetValue(true); }
	void			setUpdate(bool a) { if(a) updateRB->SetValue(true);
										else freshenRB->SetValue(true); }
	void			setZipsplit(bool a) { if(a) zsplitRB->SetValue(true);
										else splitRB->SetValue(true); }
	void			setRecurse(bool a) { recurse->SetValue(a); }
	void			setStoreSym(bool a) { storeSym->SetValue(a); }
	void			setRemoveDir(bool a) { removeDir->SetValue(a); }
	void			setDeleteFiles(bool a) { deleteFiles->SetValue(a); }
	void			setTempDir(bool a) { tempDir->SetValue(a); }
	void			setTempDir(char* a) { dirTextView->SetText(a); }
	void			setModBefore(bool a) { exModBefore->SetValue(a); }
	//void			setModBeforeDate(char* a) { modBeforeDate->SetDate(a); }
	void			setModAfter(bool a) { exModAfter->SetValue(a); }
	//void			setModAfterDate(char* a) { modAfterDate->SetDate(a); }
	void			setUseTerm(bool a) {	useTerm->SetValue(a);
											BMessage setmsg(TERM_CHANGED);
											MessageReceived(&setmsg); }
	void			setCloseTerm(bool a) { closeTerm->SetValue(a); }
	void			setCompLevel(int a)
					{	clSlider->SetValue(a); setCompLabel(); }
	void			setCompLabel();
	void			setNoCompress(bool a) { noCompress->SetValue(a); }
	void			setNoCompression(bool a);
	void			setExclude(bool a) { exclude->SetValue(a); }
	void			setCstmExc(char* cstm) { custExcludeTC->SetText(cstm); }
	void			setInclude(bool a) { include->SetValue(a); }
	void			setCstmInc(char* cstm) { custIncludeTC->SetText(cstm); }
	void			addCustomNoCompress();
	void			addCustomNoCompress(const char*,bool=false);
	void			removeNoCompressItems();
	void			addExclude(BEntry);
	void			addCustomExclude();
	void			addCustomExclude(const char*,bool=false);
	void			removeExcludes();
	void			addInclude(BEntry);
	void			addCustomInclude();
	void			addCustomInclude(const char*,bool=false);
	void			removeIncludes();
	bool			getListEntrys(BListView*,BPath&);
	void			writeDirEntrys(BEntry*, BFile*);
};*/
/*class SBDateControl : public BView
{public:
					SBDateControl(BRect&, char*, BPicture* = NULL,
						BPicture* = NULL, BPicture* = NULL, BPicture* = NULL);
	char*			getMonth() { return (char*)monthControl->Text(); }
	char*			getDay() { return (char*)dayControl->Text(); }
	char*			getYear() { return (char*)yearControl->Text(); }
	void			setMonth(char* a) { monthControl->SetText(a); }
	void			setDay(char* a) { dayControl->SetText(a); }
	void			setYear(char* a) { yearControl->SetText(a); }
/*	virtual void	MouseDown(BPoint point)
					{	//BTextControl::MouseDown(point);
						(new BAlert("","MouseDown called","OK"))->Go();
						int32 charOffset(dateView->OffsetAt(point));
						if(charOffset>=0 && charOffset<=3)
							dateView->Select(0,3);
						if(charOffset>=5 && charOffset<=8)
							dateView->Select(4,8);
						if(charOffset>=10 && charOffset<=14)
							dateView->Select(9,14);
					}
/*	virtual void	MakeFocus(bool focusState = true)
					{	BTextControl::MakeFocus(focusState);
						(new BAlert("","MakeFocus called","OK"))->Go();
					}
private:
	BTextControl	*monthControl, *dayControl, *yearControl;
#if USE_DATE_CONTROL
	BPictureButton	*incrementPB, *decrementPB;
	//BRegion			monthRegion, dayRegion, yearRegion;
#endif
};*/
/*class SBListItem : public BStringItem
{public:
					SBListItem(const char*,bool cstm=false);
	bool			getCustomValue() { return isCustom; }
private:
	bool			isCustom;
};*/
/*class SWDOpenFilePanel : public BFilePanel, public BHandler
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
};*/
#endif
