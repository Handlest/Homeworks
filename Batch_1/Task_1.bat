@ECHO OFF
setlocal
set year=%1
set /A "leap=!(year%%4) + (!!(year%%100)-!!(year%%400))"

if %leap% == 1 ( echo %year% is a leap year 
) else ( echo %year% is not a leap year 
)
