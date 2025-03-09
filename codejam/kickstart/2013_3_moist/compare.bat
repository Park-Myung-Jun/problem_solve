@echo off

set name=moist

if not exist dump mkdir dump

(%name% < problem_statement\%name%_sample_ts1_input.txt) > dump\%name%_test.txt
fc /W dump\%name%_test.txt problem_statement\%name%_sample_ts1_output.txt

(%name% < data\secret\subtask1\1.in) > dump\%name%_subtask1_test.txt
fc /W dump\%name%_subtask1_test.txt data\secret\subtask1\1.ans

(%name% < data\secret\subtask2\1.in) > dump\%name%_subtask2_test.txt
fc /W dump\%name%_subtask2_test.txt data\secret\subtask2\1.ans