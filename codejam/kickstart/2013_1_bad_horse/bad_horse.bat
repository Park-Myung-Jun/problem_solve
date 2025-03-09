@echo off

(bad_horse < problem_statement/bad_horse_sample_ts1_input.txt) > dump\bad_horse_test.txt
fc /W dump\bad_horse_test.txt problem_statement/bad_horse_sample_ts1_output.txt

(bad_horse < data\secret\subtask1/1.in) > dump\bad_horse_subtask1_test.txt
fc /W dump\bad_horse_subtask1_test.txt data\secret\subtask1\1.ans

(bad_horse < data\secret\subtask2\1.in) > dump\bad_horse_subtask2_test.txt
fc /W dump\bad_horse_subtask2_test.txt data\secret\subtask2\1.ans