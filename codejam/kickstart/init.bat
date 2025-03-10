@echo off

set argc=0
for %%i in (%*) do set /A argc+=1

if %argc% neq 2 (
	echo how to use : %0 [name] [subtask_count]
	exit /b 1
)

set name=%1
set subtask_count=%2

if not exist dump mkdir dump

if not exist %name%.c (
	type NUL > %name%.c
)

gcc -o %name% %name%.c

if exist %name%.exe (
	(%name%.exe < problem_statement\%name%_sample_ts1_input.txt) > dump\%name%_sample_ts1_test.txt
	fc /W problem_statement\%name%_sample_ts1_output.txt dump\%name%_sample_ts1_test.txt

	set count=1
	for %%i in (%*) do (
		(%name%.exe < subtask%count%\1.in) > dump\1.test
		fc /W subtask%count%\1.ans dump\1.test
		
		set /A count+=1
	)
)