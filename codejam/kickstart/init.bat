@echo off

set argc=0
for %%i in (%*) do set /A argc+=1

if %argc% neq 3 (
	echo how to use : %0 [relative_path] [name]
	exit /b 1
)

set relative_path=%1
set name=%2

if not exist dump mkdir dump
if not exist source mkdir source

type NUL > source\%relative_path%\%name%.c

echo @echo off>%relative_path%\build.bat
echo.>>%relative_path%\build.bat
echo gcc -o %relative_path%\%name% source\%relative_path%\%name%.c>>%relative_path%\build.bat

echo @echo off>%relative_path%\compare.bat
echo.>>%relative_path%\compare.bat
echo (%relative_path%\%name% ^< %relative_path%\problem_statement\%name%_sample_ts1_input.txt) ^> %relative_path%\dump\%name%_test.txt>>%relative_path%\compare.bat
echo fc /W %relative_path%\dump\%name%_test.txt %relative_path%\problem_statement\%name%_sample_ts1_output.txt>>%relative_path%\compare.bat
echo.>>%relative_path%\compare.bat
echo (%relative_path%\%name% ^< %relative_path%\data\secret\subtask1\1.in) ^> %relative_path%\dump\%name%_subtask1_test.txt>>%relative_path%\compare.bat
echo fc /W %relative_path%\dump\%name%_subtask1_test.txt %relative_path%\data\secret\subtask1\1.ans>>%relative_path%\compare.bat
echo.>>%relative_path%\compare.bat
echo (%relative_path%\%name% ^< %relative_path%\data\secret\subtask2\1.in) ^> %relative_path%\dump\%name%_subtask2_test.txt>>%relative_path%\compare.bat
echo fc /W %relative_path%\dump\%name%_subtask2_test.txt %relative_path%\data\secret\subtask2\1.ans>>%relative_path%\compare.bat