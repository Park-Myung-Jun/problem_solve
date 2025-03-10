@echo off

set argc=0
for %%i in (%*) do set /A argc+=1

if %argc% neq 2 (
	echo how to use : %0 [name] [test_num]
	exit /b 1
)

set name=%1
set /A test_num=%2

if not exist %name% (
	mkdir %name%
)

if not exist %name%\%name%.c (
	type NUL > %name%\%name%.c
)

for /L %%i in (1,1,%test_num%) do (
	if not exist %name%\%name%_input_%%i.txt (
		type NUL > %name%\%name%_input_%%i.txt
	)
	if not exist %name%\%name%_output_%%i.txt (
		type NUL > %name%\%name%_output_%%i.txt
	)
)

if not exist %name%\build.bat (
	echo @echo off>%name%\build.bat
	echo.>>%name%\build.bat
	echo gcc -o %name% %name%.c>>%name%\build.bat

	exit /b 1
) else (
	gcc -o %name%\%name% %name%\%name%.c
)

for /L %%i in (1,1,%test_num%) do (
	(%name%\%name% < %name%\%name%_input_%%i.txt) > %name%\%name%_dump_%%i.txt
	fc /w %name%\%name%_dump_%%i.txt %name%\%name%_output_%%i.txt
)