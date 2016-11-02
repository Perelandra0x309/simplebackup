#ifndef SB_SETTINGS_H
#define SB_SETTINGS_H

#include <InterfaceKit.h>
#include <StorageKit.h>
#include <stdio.h>
#include <stdlib.h>
#include "SBControls.h"
#include "SBDateControl.h"
#include "SBListItem.h"
#include "utilities.h"

//GUI layout
#include <LayoutBuilder.h>
#include <GridLayoutBuilder.h>
#include <GroupLayout.h>
#include <GroupLayoutBuilder.h>
#include <SpaceLayoutItem.h>

class SBControls;

class SBSettings : public BView
{public:
					SBSettings(BPicture* = NULL, BPicture* = NULL,
							BPicture* = NULL, BPicture* = NULL);
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
	int				getZipSplitBytes();
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
					*zipTestB, *zipsplitB;//2016UUE *uuencodeB, *uudecodeB,
	BPopUpMenu		*splitsizeMenu;
	BMenuField		*splitsizeField;
	BTabView		*settingsTabView;
	BTab			*tab1, *tab2, *tab3, *tab4;
	BView			*view1, *view2, *view3, *view4;
	BStringView		*testZipLabel;//2016UUE *uueLabel, *uudLabel,
	BBox			*zipTestBox, *zipsplitBox;//2016UUE *uueBox,
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
};

#endif
