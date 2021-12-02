# 21F-CISC372-Team-2-Final-Project
[Source code](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)
You can find our previous (not-so) "final" version of our knapsack code in './knapsack_final_old' (this is the version of the code we presented in class).

# Notes on Final Project Presentation
On slide 4 of our presentation, we displayed a screenshot of the batch script we used. The '_gprof' at the end of the command is there because we originally were profiling using GProf. When we realized we were not getting the results we wanted, we abandoned GProf and opted to use functions from the time.h C library to measure the performance of our programs. Despite this move, we did not change the name of the executable to omit '_gprof' to save time.

We were compiling using several methods depending on whether the code was serial or parallel. We would run '$ gcc -fopenmp knapsack.c -o knapsack_gprof' on the command line. Then, we would run the batch script. We intended to run the code on the GPU at the time without realizing we should have ran on the CPU, since we were comparing threads. In new iterations of our project, the third line is changed to '#SBATCH -p RM-shared' and the fourth line is deleted. This will make the program run on the CPU as intended. Later, when we have our program run on the GPU, the batch script that comes with the code will be the old version.

On slide 6, we typed the line "omp_set_num_threads(N)" so our program would run with N number of threads. In our corrected code, we will instead set the number of threads on the command line with "export OMP_NUM_THREADS=N".

# 1. Run serial code
Open ./knapsack_original/. In this directory, you will find the orignal C file for the knapsack algorithm.

Download the contents of the directory and place on the login node of bridges2. Run this command to compile:  
$ gcc knapsack.c -o knapsack

Run this command to execute the batch script:  
$ sbatch knapsack.bat

View the resulting slurm file for the answer. You should get an answer of 220. Run this command (replace ??? with the actual numbers):  
$ cat slurm-???.out

# 2. Run/profile serial code with larger data set
Open ./knapsack_large_gprof/. This directory contains a modified version of the serial code. It has a larger data set. It will also be profiled using GProf.

Download the contents of the directory and place on the login node of bridges2. Run this command to compile:  
$ gcc -Wall -pg knapsack_large.c -o knapsack_large_gprof

Run this command to execute the batch script:  
$ sbatch knapsack_large_gprof.bat

View the resulting slurm file for the answer. You should get an answer of ???. Run this command (replace ??? with the actual numbers):  
$ cat slurm-???.out

Profile by running this command:   
$ gprof knapsack_large_gprof gmon.out > analysis.txt

View result by running this command:  
$ cat analysis.txt