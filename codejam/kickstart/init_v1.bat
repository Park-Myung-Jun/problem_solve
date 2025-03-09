@echo off

set name=name

if not exist dump mkdir dump
if not exist source mkdir source

type NUL > source\%name%.c

echo @echo off>build.bat
echo.>>build.bat
echo set name=%name%>>build.bat
echo gcc -o %name% source/%name%.c>>build.bat

echo @echo off>compare.bat
echo.>>compare.bat
echo set name=%name%>>compare.bat
echo.>>compare.bat
echo (%name% ^< problem_statement\%name%_sample_ts1_input.txt) ^> dump\%name%_test.txt>>compare.bat
echo fc /W dump\%name%_test.txt problem_statement\%name%_sample_ts1_output.txt>>compare.bat
echo.>>compare.bat
echo (%name% ^< data\secret\subtask1\1.in) ^> dump\%name%_subtask1_test.txt>>compare.bat
echo fc /W dump\%name%_subtask1_test.txt data\secret\subtask1\1.ans>>compare.bat
echo.>>compare.bat
echo (%name% ^< data\secret\subtask2\1.in) ^> dump\%name%_subtask2_test.txt>>compare.bat
echo fc /W dump\%name%_subtask2_test.txt data\secret\subtask2\1.ans>>compare.bat