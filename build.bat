@echo off
set app_name=app-base
ctime -begin %app_name%.ctm

if [%1]==[] goto MissingBuildFlag
if [%1]==[Debug] goto Debug
if [%1]==[Test] goto Test
if [%1]==[Release] goto Release

:MissingBuildFlag
echo Missing build flag (Debug, Test, Release), defaulting to debug.
goto Debug

rem todo set build params for each 
:Debug
echo Debug
goto Build

:Test
echo Test
goto Build

:Release
echo Release
goto Build


:Build
if not defined DevEnvDir call vcvarsall x64
if not exist .\build mkdir .\build 
pushd .\build
echo -----------------
cl -Zi -FC  ..\code\test.cpp -Fetest-%app_name%.exe /link shell32.lib /subsystem:console
popd
ctime -end %app_name%.ctm %LastError%
