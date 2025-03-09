@echo off

set name=captain_hammer
set name2=captain_hammer2

(%name% < problem_statement/%name%_sample_ts1_input.txt) > dump\%name%_test.txt
fc /W dump\%name%_test.txt problem_statement/%name%_sample_ts1_output.txt

(%name2% < data\secret\subtask1/1.in) > dump\%name2%_subtask1_test.txt
fc /W dump\%name2%_subtask1_test.txt data\secret\subtask1\1.ans
