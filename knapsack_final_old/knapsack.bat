#! /bin/bash
#SBATCH -A see200002p
#SBATCH -p GPU-shared
#SBATCH --gpus=v100-32:1
#SBATCH -N 1
#SBATCH -n 4
#SBATCH -t 00:30:00
./knapsack_gprof
