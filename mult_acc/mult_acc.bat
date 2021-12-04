#! /bin/bash
#SBATCH -A see200002p
#SBATCH -p RM-shared
#SBATCH -N 1
#SBATCH -n 32
#SBATCH -t 00:05:00
./mult_acc
