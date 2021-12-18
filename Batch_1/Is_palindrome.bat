@echo off
set word=%1
if "%word%"=="" (goto :notentered)

:loop
if "%word%"=="" (goto :yes)
if not "%word:~0,1%"=="%word:~-1%" (goto :no)
set word=%word:~1,-1%
goto :loop

:yes
echo it is palindrome
exit /b

:no
echo it is not palindrome
exit /b

:notentered
echo nothing entered
