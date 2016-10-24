#include "SBDateControl.h"

SBDateControl::SBDateControl(char* name, BPicture *incuP, BPicture *incsP,
								BPicture *decuP, BPicture *decsP)
//	:BView(name, B_WILL_DRAW | B_FRAME_EVENTS)
{	//SetViewColor(gui_background_color);
	long i;
	BRect viewRect(0,0,0,0);
//	BRect viewRect(Bounds());
//	viewRect.right = viewRect.left + StringWidth("0")*2 + 10;
	monthControl = new BTextControl(viewRect, "Month", NULL, "01", NULL);
	monthControl->TextView()->SetMaxBytes(2);
//	monthControl->TextView()->MakeSelectable(false);
	//monthControl->TextView()->SetViewColor(bg_color);
	//monthControl->TextView()->MakeEditable(false);
	//monthControl->SetEnabled(false);
	for (i = 0; i < 256; i++) monthControl->TextView()->DisallowChar(i);
	for (i = '0'; i <= '9'; i++) monthControl->TextView()->AllowChar(i);
	monthControl->TextView()->AllowChar(B_BACKSPACE);
//	AddChild(monthControl);

//	viewRect.OffsetTo(viewRect.right, viewRect.top);
//	viewRect.right = viewRect.left + StringWidth("0")*2 + 15;
	dayControl = new BTextControl(viewRect, "Day", NULL , "01", NULL);
//	dayControl->SetDivider(be_plain_font->StringWidth(dayControl->Label()) + 4);
	dayControl->TextView()->SetMaxBytes(2);
//	dayControl->TextView()->MakeSelectable(false);
	for (i = 0; i < 256; i++) dayControl->TextView()->DisallowChar(i);
	for (i = '0'; i <= '9'; i++) dayControl->TextView()->AllowChar(i);
	dayControl->TextView()->AllowChar(B_BACKSPACE);
//	AddChild(dayControl);
//	viewRect.OffsetTo(viewRect.right, viewRect.top);
//	viewRect.right = viewRect.left + StringWidth("0")*4 + 15;
	yearControl = new BTextControl(viewRect, "Year", NULL , "1999", NULL);
//	yearControl->SetDivider(be_plain_font->StringWidth(yearControl->Label()) + 4);
	yearControl->TextView()->SetMaxBytes(4);
//	yearControl->TextView()->MakeSelectable(false);
	for (i = 0; i < 256; i++) yearControl->TextView()->DisallowChar(i);
	for (i = '0'; i <= '9'; i++) yearControl->TextView()->AllowChar(i);
	yearControl->TextView()->AllowChar(B_BACKSPACE);
//	AddChild(yearControl);
#if USE_DATE_CONTROL
//	viewRect.Set(0,0,15,9);
//	viewRect.OffsetTo(yearControl->Frame().right+2, yearControl->Frame().top);
	incrementPB = new BPictureButton(viewRect, "Increment", incuP, incsP,
								new BMessage(SB_NOTHING), B_ONE_STATE_BUTTON);
//	AddChild(incrementPB);
//	viewRect.OffsetTo(incrementPB->Frame().left, incrementPB->Frame().bottom+1);
	decrementPB = new BPictureButton(viewRect, "Decrement", decuP, decsP,
								new BMessage(SB_NOTHING), B_ONE_STATE_BUTTON);
//	AddChild(decrementPB);
#endif

	dayLabelDivider = new BStringView("DayLabelDivider", "/");
	yearLabelDivider = new BStringView("YearLabelDivider", "/");

	monthControl->SetExplicitMaxSize(BSize(be_plain_font->StringWidth("0001"), B_SIZE_UNSET));
	monthControl->SetExplicitMinSize(BSize(be_plain_font->StringWidth("0001"), B_SIZE_UNSET));
	dayControl->SetExplicitMaxSize(BSize(be_plain_font->StringWidth("0001"), B_SIZE_UNSET));
	dayControl->SetExplicitMinSize(BSize(be_plain_font->StringWidth("0001"), B_SIZE_UNSET));
	yearControl->SetExplicitMaxSize(BSize(be_plain_font->StringWidth("000001"), B_SIZE_UNSET));

	// Build the layout
/*	SetLayout(new BGroupLayout(B_HORIZONTAL));
	AddChild(BGroupLayoutBuilder(B_HORIZONTAL, gui_control_padding)
		.Add(monthControl)
		.Add(dayLabel)
		.Add(dayControl)
		.Add(yearLabel)
		.Add(yearControl)
		.AddGlue()
//		.SetInsets(gui_group_inset, gui_group_inset, gui_group_inset, gui_group_inset)
	);
	BSize maxSize = PreferredSize();
	SetExplicitMaxSize(maxSize);*/

//	ResizeTo(Bounds().Width(), monthControl->Frame().Height());
}
