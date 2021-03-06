/* SBApp.h
 * Copyright 2016 Brian Hill
 * All rights reserved. Distributed under the terms of the BSD License.
 */
#ifndef SB_APP_H
#define SB_APP_H

#include <AppKit.h>
#include "constants.h"
#include "SBWindow.h"

class SBApp : public BApplication
{
public:
					SBApp();
	virtual void	ArgvReceived(int32,char**);
private:
	SBWindow		*fWindow;
	void			printhelp();
};

#endif
