#! /bin/bash
#SBATCH -A see200002p
#SBATCH -p RM-shared
#SBATCH -N 1
#SBATCH -n 4
#SBATCH -t 00:10:00
./knapsack_large_gprof