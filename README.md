# 21F-CISC372-Team-2-Final-Project
[Source code](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)

# 1. Run serial code
Open ./knapsack_original/. In this directory, you will find the orignal C file for the knapsack algorithm.

Download the contents of the directory and place on the login node of bridges2. Run this command to compile:  
$ gcc knapsack.c -o knapsack

Run this command to execute the batch script:  
$ sbatch knapsack.bat

View the resulting slurm file for the answer. You should get an answer of 220. Run this command (replace ??? with the actual numbers):  
$ cat slurm-???.out

# 2. Run serial code with larger data set
Open ./knapsack_large/. This directory contains a modified version of the serial code. It has a larger data set.

Download the contents of the directory and place on the login node of bridges2. Run this command to compile:  
$ gcc knapsack_large.c -o knapsack_large

Run this command to execute the batch script:  
$ sbatch knapsack_large.bat

View the resulting slurm file for the answer. You should get an answer of ???. Run this command (replace ??? with the actual numbers):  
$ cat slurm-???.out