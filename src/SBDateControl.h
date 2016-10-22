#ifndef SB_DATECONTROL_H
#define SB_DATECONTROL_H

#include <InterfaceKit.h>
#include "constants.h"

//GUI layout
#include <GridLayoutBuilder.h>
#include <GroupLayout.h>
#include <GroupLayoutBuilder.h>
#include <SpaceLayoutItem.h>

class SBDateControl// : public BView
{public:
					SBDateControl(char*, BPicture* = NULL,
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
	virtual void	MakeFocus(bool focusState = true)
					{	BTextControl::MakeFocus(focusState);
						(new BAlert("","MakeFocus called","OK"))->Go();
					}*/
//private:
	BTextControl	*monthControl, *dayControl, *yearControl;
	BStringView		*dayLabelDivider, *yearLabelDivider;
#if USE_DATE_CONTROL
	BPictureButton	*incrementPB, *decrementPB;
	//BRegion			monthRegion, dayRegion, yearRegion;
#endif
};

#endif
