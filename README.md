# Push Swap

> A sorting algorithm challenge using two stacks and a limited set of operations.

## 📦 Project Overview

**Push Swap** is a program that sorts a list of integers using two stacks (`a` and `b`) and a specific set of operations. The goal is to sort the stack `a` with the **minimum number of moves**.

The project focuses on algorithm optimization, memory handling, and adherence to strict coding standards (e.g., Norminette at 42).

---

Features

    Handles invalid input (duplicates, non-integers, overflows).

    Efficient sorting for:

        2 to 5 numbers (hardcoded optimal moves).

		< 500 numbers using Greedy Longest Increasing Subsequence Sort.

        Large inputs (> 500) using Greedy Chunk Sort.

    Optimized move generation:

        Greedy best node selection

        Rotation cost analysis

    Norminette compliant, modular file structure



| Command | Description                      |
| ------- | -------------------------------- |
| `sa`    | swap top 2 of stack a            |
| `sb`    | swap top 2 of stack b            |
| `ss`    | `sa` and `sb` at the same time   |
| `pa`    | push top of b onto a             |
| `pb`    | push top of a onto b             |
| `ra`    | rotate a upwards                 |
| `rb`    | rotate b upwards                 |
| `rr`    | `ra` and `rb` at the same time   |
| `rra`   | reverse rotate a                 |
| `rrb`   | reverse rotate b                 |
| `rrr`   | `rra` and `rrb` at the same time |


Check your program with:
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

Count operations:
./push_swap $ARG | wc -l

Sample Test Cases to Try:
# Already sorted
ARG="1 2 3 4 5"; ./push_swap $ARG | ./checker $ARG

# Reverse sorted
ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker $ARG

# Small random
ARG="3 1 4 2 5"; ./push_swap $ARG | ./checker $ARG

# Large random (check performance)
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l

# check leaks
valgrind --leak-check=full ./push_swap $ARG 

MY_CHECKER
run: make bonus
./push_swap $ARG | ./checker $ARG

# push_swap_visualizer
https://github.com/o-reo/push_swap_visualizer
cd push_swap_visualizer/build/
./bin/visualizer 