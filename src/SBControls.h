#ifndef SB_CONTROLS_H
#define SB_CONTROLS_H

#include <InterfaceKit.h>
#include "SBSettings.h"

//GUI layout
#include <GridLayoutBuilder.h>
#include <GroupLayout.h>
#include <GroupLayoutBuilder.h>
#include <SpaceLayoutItem.h>

class SBSettings;

class SBControls : public BView
{public:
					SBControls(BRect&,/* BPicture* = NULL, BPicture* = NULL,*/ SBSettings* = NULL);
					~SBControls();
//	virtual void	FrameResized(float,float);
	const char*		getSrc() { return backupSrc->Text(); }
	void			setSrc(const char* src) { backupSrc->SetText(src); return; }
//	void			setToggleB(bool a) { togglePB->SetValue(a); }
//	float			getBottom() { return aboutB->Frame().bottom; }
private:
	BTextControl	*backupSrc;
	BButton			*newB, *updateB, *browseSrc, *defaultSB, *restoreSB, *saveSB, *aboutB;
//	BPictureButton	*togglePB;
};

#endif