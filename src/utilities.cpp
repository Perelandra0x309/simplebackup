#include "utilities.h"

void uuencode(entry_ref srcRef, bool closeT)
{	BEntry uueEntry("/bin/uuencode");
	if(!uueEntry.Exists())
	{	(new BAlert("", "UUencode command does not exist in /bin", "OK",
					NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	int arg_c = 0;
	char *arg_v[6];
	BEntry srcEntry(&srcRef);
	if(!srcEntry.Exists())
	{	(new BAlert("", "Invalid source", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	arg_v[arg_c++] = "/bin/sh";
	arg_v[arg_c++] = "--login";
	arg_v[arg_c++] = "-c";
	BPath srcPath(&srcEntry);
	char *name = new char[B_FILE_NAME_LENGTH];
	srcEntry.GetName(name);
	BString uueArg("echo Starting encoding; uuencode ");
	uueArg += srcPath.Path(); uueArg += " ";
	uueArg += name; uueArg += " > ";
	uueArg += srcPath.Path(); uueArg += ".uue";
	if(!closeT) { uueArg += "; read -p \"Finished\nPress Enter to close terminal\""; }
	arg_v[arg_c++] = (char*)uueArg.String();
	char *termSig = "application/x-vnd.Haiku-Terminal";
	team_id termTeam;
	status_t result = be_roster->Launch(termSig, arg_c, arg_v, &termTeam);
	if (result != B_NO_ERROR)
	{ (new BAlert("", "Error launching terminal", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL); }
	delete[] name;
	return;
}
void uudecode(entry_ref srcRef, bool closeT)
{	BEntry uueEntry("/bin/uudecode");
	if(!uueEntry.Exists())
	{	(new BAlert("", "UUdecode command does not exist in /bin", "OK",
					NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	int arg_c = 0;
	char *arg_v[6];
	BEntry srcEntry(&srcRef);
	if(!srcEntry.Exists())
	{	(new BAlert("", "Invalid source", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	arg_v[arg_c++] = "/bin/sh";
	arg_v[arg_c++] = "--login";
	arg_v[arg_c++] = "-c";
	BDirectory srcDir;
	srcEntry.GetParent(&srcDir);
	BPath srcDirPath(&srcDir,NULL);
	char *name = new char[B_FILE_NAME_LENGTH];
	srcEntry.GetName(name);
	BString uueArg("Starting decoding; cd ");
	uueArg += srcDirPath.Path(); uueArg += "; uudecode ";
	uueArg += name;
	if(!closeT) { uueArg += "; read -p \"Finished\nPress Enter to close terminal\""; }
	arg_v[arg_c++] = (char*)uueArg.String();
	char *termSig = "application/x-vnd.Haiku-Terminal";
	team_id termTeam;
	status_t result = be_roster->Launch(termSig, arg_c, arg_v, &termTeam);
	if (result != B_NO_ERROR)
	{ (new BAlert("", "Error launching terminal", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL); }
	delete[] name;
	return;
}
void testzip(entry_ref srcRef)
{	BEntry zipEntry("/bin/zip");
	if(!zipEntry.Exists())
	{	(new BAlert("", "zip command does not exist in /bin", "OK",
					NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	BEntry srcEntry(&srcRef);
	if(!srcEntry.Exists())
	{	(new BAlert("", "Invalid source", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	BPath srcPath(&srcEntry);
	BString testArg("echo Testing integrity of ");
	testArg += srcPath.Path();
	testArg += "; zip -T \"";
	testArg += srcPath.Path();
	testArg += "\"; read -p \"Press Enter to close terminal\"";
	int arg_c = 0;
	char *arg_v[6];
	arg_v[arg_c++] = "/bin/sh";
	arg_v[arg_c++] = "--login";
	arg_v[arg_c++] = "-c";
	arg_v[arg_c++] = (char*)testArg.String();
	char *termSig = "application/x-vnd.Haiku-Terminal";
	team_id termTeam;
	status_t result = be_roster->Launch(termSig, arg_c, arg_v, &termTeam);
	if (result != B_NO_ERROR)
	{ (new BAlert("", "Error launching terminal", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL); }
}
void zipsplit(entry_ref srcRef, int bytes, bool usezipsplit, bool closeT)
{	BEntry zipEntry("/bin/zipsplit");
	if(!zipEntry.Exists())
	{	(new BAlert("", "zipsplit command does not exist in /bin", "OK",
					NULL, NULL, B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	BEntry srcEntry(&srcRef);
	if(!srcEntry.Exists())
	{	(new BAlert("", "Invalid source", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL);
		return; }
	BPath srcPath(&srcEntry);
	BDirectory srcDir;
	srcEntry.GetParent(&srcDir);
	BPath srcDirPath(&srcDir,NULL);
	BString splitArg("cd \"");
	splitArg += srcDirPath.Path();
	splitArg += "\"; echo Splitting zip file...; ";
	char *number = new char[16];
	sprintf(number, "%i", bytes);
	if(usezipsplit)
	{	splitArg += "zipsplit -n ";
		splitArg += number;
	}
	else
	{	splitArg += "split -b ";
		splitArg += number;
	}
	delete[] number;
	splitArg += " \"";
	splitArg += srcPath.Path();
	splitArg += "\"";
	if(!usezipsplit)
	{	char *name = new char[B_FILE_NAME_LENGTH];
		srcEntry.GetName(name);
		splitArg += " \"";
		splitArg += name;
		splitArg += "\"";
		delete[] name;
	}
	if(!closeT) { splitArg += "; read -p \"Finished\nPress Enter to close terminal\""; }
	int arg_c = 0;
	char *arg_v[6];
	arg_v[arg_c++] = "/bin/sh";
	arg_v[arg_c++] = "--login";
	arg_v[arg_c++] = "-c";
	arg_v[arg_c++] = (char*)splitArg.String();
	char *termSig = "application/x-vnd.Haiku-Terminal";
	team_id termTeam;
	status_t result = be_roster->Launch(termSig, arg_c, arg_v, &termTeam);
	if (result != B_NO_ERROR)
	{ (new BAlert("", "Error launching terminal", "OK", NULL, NULL,
					B_WIDTH_AS_USUAL, B_STOP_ALERT))->Go(NULL); }
}
//float max(const float& a, const float& b)
//{	return (a>b)?a:b; }

