#include "SBListItem.h"

SBListItem::SBListItem(const char* entryPath, bool cstm)
	:BStringItem(entryPath)
{	isCustom = cstm; }
