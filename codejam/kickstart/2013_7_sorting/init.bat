@echo off

set argc=0
for %%i in (%*) do set /A argc+=1

if %argc% neq 2 (
	echo how to use : %0 [name] [subtask_count]
	exit /b 1
)

set name=%1
set /A subtask_count=%2

if %2 leq 0 (
	echo subtask_count must be greater than 0
	exit /b 1
)

if not exist dump mkdir dump

if not exist %name%.c (
	type NUL > %name%.c
) else (
	gcc -o %name% %name%.c
)

if exist %name%.exe (
	(%name%.exe < problem_statement\%name%_sample_ts1_input.txt) > dump\%name%_sample_ts1_test.txt
	fc /W problem_statement\%name%_sample_ts1_output.txt dump\%name%_sample_ts1_test.txt

	for /L %%a in (1,1,%subtask_count%) do (
		(%name%.exe < subtask%%a\1.in) > dump\%%a.test
		fc /W subtask%%a\1.ans dump\%%a.test
	)
)