#ifndef SB_UTILITIES_H
#define SB_UTILITIES_H

#include <StorageKit.h>
#include <Alert.h>
#include <String.h>
#include <Roster.h>
#include <stdio.h>

void uuencode(entry_ref, bool);
void uudecode(entry_ref, bool);
void testzip(entry_ref);
void zipsplit(entry_ref, int, bool, bool);
//float max(const float&,const float&);

#endif