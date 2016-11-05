#!/bin/sh
#Modify these values to your folder paths
appDir="/boot/system/apps/SimpleBackup"
backupDir="/boot/backups"

#Run the backup and quit
$appDir/SimpleBackup home_backup_settings $backupDir/home$(date +%Y-%m-%d).zip&
sleep 5s
$appDir/SimpleBackup -q
