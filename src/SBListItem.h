#ifndef SB_LISTITEM_H
#define SB_LISTITEM_H

#include <StringItem.h>

class SBListItem : public BStringItem
{public:
					SBListItem(const char*,bool cstm=false);
	bool			getCustomValue() { return isCustom; }
private:
	bool			isCustom;
};

#endif
