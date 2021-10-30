@ECHO OFF 
:loop
set /a num+=1

set /a num2=%num%*%num%

if %num2:~-6%==269696 goto end

goto loop

:end
echo %num% * %num% = %num2%

pause>nul

rem answer here is 25264^2 = 638269696, but code running pretty slow. Are there any ways to optimize it?