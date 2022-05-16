@echo off

set app_name=app-base

if not defined DevEnvDir call vcvarsall x64
if not exist .\build mkdir .\build 
pushd .\build
echo -----------------
cl -Zi -FC  ..\code\main.cpp -Fe%app_name%.exe /link shell32.lib /subsystem:console
popd
