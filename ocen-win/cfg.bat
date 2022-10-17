@echo off

if "%1"=="_chk_" shift

rem --- Konfiguracja ocen.bat ---
rem W przypadku opracowania wlasnego zestawu testow nalezy zmienic
rem zawartosc zmiennej TESTS a testy zabpiowac do kataloguw IN\, OUT\
rem nazwy testow powinny analogiczne do przykladowych

if "%1"=="kol" goto kol
if "%1"=="KOL" goto kol
if "%1"=="ply" goto ply
if "%1"=="PLY" goto ply
if "%1"=="poc" goto poc
if "%1"=="POC" goto poc
if "%1"=="wyp" goto wyp
if "%1"=="WYP" goto wyp
if "%1"=="zbo" goto zbo
if "%1"=="ZBO" goto zbo


set T=%1
goto end

:kol
set I=kol
set T=0 1 2 3
set C=bin\cmp.exe
goto end
:ply
set I=ply
set T=0 1 2 3
set C=bin\cmp.exe
goto end
:poc
set I=poc
set T=0 1 2
set C=bin\cmp.exe
goto end
:wyp
set I=wyp
set T=0 1 2 3 4
set C=bin\cmp.exe
goto end
:zbo
set I=zbo
set T=0 1 2
set C=bin\cmp.exe
goto end


rem --- Koniec konfiguracji

:end

if "%C%"=="" goto def_chk
goto new_chk
:def_chk
set C=bin\cmp.exe
:new_chk

:real_end
