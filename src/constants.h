#ifndef SB_CONSTANTS_H
#define SB_CONSTANTS_H

//compile options
#define USE_DATE_CONTROL 0
#define NO_BACKUP 0

//Appication
#define SB_version "2.0.1"
#define APPLICATION_SIGNATURE "application/x-vnd.BH-SimpleBackup"
#define DEFAULT_SETTINGS_DIR "SimpleBackup"

//Messages
#define SB_NOTHING		'nada'
#define CURRENT_SET		'curs'
#define GOTO_PROFILE_DIR 'gopd'
#define SRC_PANEL		'srcp'
#define CHECK_SRC		'csrc'
#define SET_SRC			'ssrc'
#define NEW_PANEL		'newp'
#define UPDATE_PANEL	'updp'
#define NEW_BACKUP		'newb'
#define UPDATE_BACKUP	'updb'
#define SET_PROFILE_DIR 'sprd'
#define TOGGLE_S		'tgls'
#define FRESHEN_CHANGED	'frch'
#define UPDATE_CHANGED	'upch'
#define DELETE_WARNING	'dwrn'
#define TERM_CHANGED	'shch'
#define TEMP_PANEL		'tmpp'
#define CHECK_TEMP		'ctmp'
#define SET_TEMP		'stmp'
#define COMP_CHANGED	'cmch'
#define REMOVE_NOCOMP	'rmnc'
#define ADD_CSTMNOCOMP	'ancp'
#define EXCLUDE_CHANGED	'exch'
#define NEW_EXCLUDE		'nexc'
#define EXCLUDE_REF		'excr'
#define REMOVE_EXCLUDES	'rmex'
#define ADD_CSTMEXCLUDE	'aexc'
#define INCLUDE_CHANGED	'inch'
#define NEW_INCLUDE		'ninc'
#define INCLUDE_REF		'incr'
#define REMOVE_INCLUDES	'rmin'
#define ADD_CSTMINCLUDE	'ainc'
#define DEFAULTS		'dflt'
#define RESTORES		'rsts'
#define RESTORES_REF	'rstr'
#define SAVES			'savs'
#define SAVES_REF		'savr'
#define UUENCODE_FILE	'uuef'
#define UUENCODE_REF	'uuer'
#define UUDECODE_FILE	'uudf'
#define UUDECODE_REF	'uudr'
#define TEST_ZIP		'tzip'
#define TEST_ZIP_REF	'tzrf'
#define ZIP_SPLIT		'zspl'
//#define ZSPLIT_CHANGED	'zsch'
//#define SPLIT_CHANGED	'spch'
#define ZIP_SPLIT_REF	'zsrf'

//GUI
const rgb_color gui_background_color = {216,216,216,0};
const float gui_control_padding = 3;
const float gui_control_indent = 25;
const float gui_group_inset = 5;

#endif