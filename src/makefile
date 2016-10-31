NAME = SimpleBackup
TYPE = APP
SRCS = BarberPole.cpp utilities.cpp SBListItem.cpp SettingsFilePanel.cpp SBDateControl.cpp SBSettings.cpp SBControls.cpp SBWindow.cpp SBApp.cpp
LIBS = be tracker
OPTIMIZE = FULL
RDEFS = SimpleBackup.rdef

#Additional makerules go here, use '#' to comment out lines

LOCAL_INCLUDE_PATHS = ./BackupQueue
TARGET_DIR = ..


DEVEL_DIRECTORY := \
	$(shell findpaths -r "makefile_engine" B_FIND_PATH_DEVELOP_DIRECTORY)
include $(DEVEL_DIRECTORY)/etc/makefile-engine
