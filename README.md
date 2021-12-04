# 21F-CISC372-Team-2-Final-Project
[Source code](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)
You can find our previous (not-so) "final" version of our knapsack code in './knapsack_final_old' (this is the version of the code we presented in class).

# Maintainers (a.k.a. project members)
- Justin Tenerelli (jtener@udel.edu)  
- Diou Dai (dioudai@udel.edu)

# Notes on Final Project Presentation
On slide 4 of our presentation, we displayed a screenshot of the batch script we used. The '_gprof' at the end of the command is there because we originally were profiling using GProf. When we realized we were not getting the results we wanted, we abandoned GProf and opted to use functions from the time.h C library to measure the performance of our programs. Despite this move, we did not change the name of the executable to omit '_gprof' to save time.

We were compiling using several methods depending on whether the code was serial or parallel. We would run '$ gcc -fopenmp knapsack.c -o knapsack_gprof' on the command line. Then, we would run the batch script. We intended to run the code on the GPU at the time without realizing we should have ran on the CPU, since we were comparing threads. In new iterations of our project, the third line is changed to '#SBATCH -p RM-shared' and the fourth line is deleted. This will make the program run on the CPU as intended. Later, when we have our program run on the GPU, the batch script that comes with the code will be the old version.

On slide 6, we typed the line "omp_set_num_threads(N)" so our program would run with N number of threads. In our corrected code, we will instead set the number of threads on the command line with "export OMP_NUM_THREADS=N".

# New Project Topic
We've decided to switch our project topic to something else since we found that the knapsack code we were using seemed very difficult to parallelize without changing the code a lot.

The new topic that we decided on was a program that prints a multiplication table with n rows and n columns. If the input n is sufficiently large, only the last 14 columns of the table will be printed out so it fits on one screen.

I (Justin) thought this code would be very easy to parallelize. That part wasn't particularly difficult (albeit time-consuming), but even with inputs as large as 1000 (so 1000 * 1000 computations) proved to be very easy for bridges2 (calling the function a few times was 0.00 seconds in GProf). Considering there was little time left, we decided to simply run the program many times with very large inputs so we had enough CPU time to work with in GProf.

First, we tried to compile our OMP code with GNU GCC. After testing many thread counts, we moved on to ACC and realized that we should use NVC instead. Due to this, we recompiled our OMP code with NVC so we could compare the two compilers fairly. In summary, we found that using NVC, the OMP code was slightly faster than the serial code. The ACC code was much faster than both. Increasing the threads for the OMP code and increasing the cores for the ACC code had very little effect on the GProf results. We also decided that NVC would almost always give us better results, so we are omitting any results of executions of GCC-compiled code.

Serial time (in seconds):       3.38 s

OpenMP (time in seconds)  
- Parallel time (2 threads):    2.81 s
- Parallel time (4 threads):    3.02 s
- Parallel time (8 threads):    2.98 s
- Parallel time (16 threads):   2.88 s
- Parallel time (32 threads):   3.11 s
- Parallel time (64 threads):   2.71 s

OpenACC
- Parallel time (2 cores):      0.70 s
- Parallel time (4 cores):      0.74 s
- Parallel time (8 cores):      0.57 s
- Parallel time (16 cores):     0.52 s
- Parallel time (32 cores):     0.80 s
- Parallel time (64 cores):     0.34 s

# 1. Run/profile serial code
Open ./mult_table/. In this directory, you will find the serial code for the mult_table program.

Download the contents of the directory and place on the login node of bridges2. Run this command to load NVHPC:  
$ module load nvhpc/21.7

Run this command to compile (this will also prepare the user for profiling):    
$ nvc -Wall -pg mult_table.c -o mult_table

Run this command to execute the batch script:  
$ sbatch mult_table.bat

View the resulting slurm file for the answer. Run this command (replace ??? with the actual numbers):  
$ cat slurm-???.out

Profile with GProf. Run this command:
$ gprof mult_table gmon.out > analysis.txt

View results in analysis.txt.

# 2. Run/profile OpenMP code
Open ./mult_omp/. This directory contains an OpenMP version of the serial code. It will also be profiled using GProf.

Download the contents of the directory and place on the login node of bridges2. Run this command to compile:  
$ nvc -Wall -pg -mp -ta=multicore -Minfo=accel mult_omp.c -o mult_omp

Run this command to set the number of threads:  
$ export OMP_NUM_THREADS=2

Run this command to execute the batch script:  
$ sbatch mult_omp.bat

View the resulting slurm file for the answer. Run this command (replace ??? with the actual numbers):  
$ cat slurm-???.out

Profile by running this command:  
$ gprof mult_omp gmon.out > analysis.txt

View result by running this command:  
$ cat analysis.txt

Repeat these steps to test the performance of setting OMP_NUM_THREADS to other values such as 4, 8, 16, 32, and 64.

# 3. Run/profile OpenACC code
Open ./mult_acc/. This directory contains an OpenACC version of the serial code. It will also be profiled using GProf.

Download the contents of the directory and place on the login node of bridges2. Run this command to compile:  
$ nvc -Wall -pg -acc -ta=multicore -Minfo=accel mult_acc.c -o mult_acc

Run this command to set the number of cores:  
$ export ACC_NUM_CORES=2

Edit the batch script and change the last number on line 7 (where is says -n 32 or some other number) to be the number of cores (first iteration, set to 2).

Run this command to execute the batch script:  
$ sbatch mult_omp.bat

View the resulting slurm file for the answer. Run this command (replace ??? with the actual numbers):  
$ cat slurm-???.out

Profile by running this command:  
$ gprof mult_acc gmon.out > analysis.txt

View result by running this command:  
$ cat analysis.txt

Repeat these steps to test the performance of setting ACC_NUM_CORES to other values such as 4, 8, 16, 32, and 64.
