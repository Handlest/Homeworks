@ECHO OFF 
SETLOCAL ENABLEDELAYEDEXPANSION
type NUL > file_2.txt

for /f "usebackq tokens=1,2 delims= " %%a in ("file_1.txt") do (
	echo %%b %%a >> file_2.txt
)
