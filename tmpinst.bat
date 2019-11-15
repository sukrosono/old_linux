@echo off
echo Starting TmpInstall\setup-Aspell-en-0.50-2.exe
start /wait TmpInstall\setup-Aspell-en-0.50-2.exe
echo Removing TmpInstall
deltree /Y TmpInstall
del %0
