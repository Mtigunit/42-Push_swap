# Push_swap Project

## Summary
The Push_swap project involves sorting data on a stack using a limited set of instructions. The goal is to achieve the sorting with the lowest possible number of actions. This requires manipulating various algorithms and selecting the most appropriate solution for optimized data sorting.

## Contents
1. [Introduction](#introduction)
2. [Objectives](#objectives)
3. [Common Instructions](#common-instructions)
4. [Mandatory Part](#mandatory-part)
   - [Rules](#rules)
   - [Example](#example)
   - [Push_swap Program](#push_swap-program)
   - [Benchmark](#benchmark)
5. [Bonus Part](#bonus-part)
   - [Checker Program](#checker-program)

## Introduction
The Push_swap project is a straightforward algorithm project where data must be sorted using a set of instructions to manipulate two stacks. The objective is to write a program in C, named `push_swap`, that calculates and displays the smallest program made of Push_swap instructions to sort integers received as arguments.

## Objectives
The project aims to teach sorting algorithms and their complexities. It emphasizes rigor, C programming, and basic algorithmic concepts, focusing particularly on their complexity.

## Common Instructions
- The project must be written in C.
- Adhere to the Norm.
- Ensure no unexpected crashes.
- Free all allocated memory.
- Provide a Makefile for compiling source files.
- Global variables are forbidden.
- The program must handle errors gracefully.

## Mandatory Part

### Rules
- Two stacks: `a` (initially containing random integers) and `b` (initially empty).
- The goal is to sort stack `a` in ascending order using specific operations:
  - `sa`: Swap the first two elements of stack `a`.
  - `sb`: Swap the first two elements of stack `b`.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa`: Push the first element from `b` to `a`.
  - `pb`: Push the first element from `a` to `b`.
  - `ra`: Rotate stack `a` (shift up all elements by 1).
  - `rb`: Rotate stack `b` (shift up all elements by 1).
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra`: Reverse rotate stack `a` (shift down all elements by 1).
  - `rrb`: Reverse rotate stack `b` (shift down all elements by 1).
  - `rrr`: Perform `rra` and `rrb` simultaneously.

### Example
To illustrate the effect of some of these instructions, let’s sort a list of integers:
```
Init a and b:
2 1 3 6 5 8
_ _

Exec sa:
1 2 3 6 5 8
_ _

Exec pb pb pb:
6 3
5 2
8 1
_ _

Exec ra rb:
5 2
8 1
6 3
_ _

Exec rra rrb:
6 3
5 2
8 1
_ _

Exec sa:
5 3
6 2
8 1
_ _

Exec pa pa pa:
1 2 3 5 6 8
_ _
```

### Push_swap Program
- **Program Name**: `push_swap`
- **Turn-in Files**: `Makefile`, `*.h`, `*.c`
- **Arguments**: A list of integers for stack `a`
- **External Functions**: `read`, `write`, `malloc`, `free`, `exit`, `ft_printf` (or equivalent coded by you)
- **Libft Authorized**: Yes

The program must:
- Display the smallest list of instructions to sort stack `a`.
- Separate instructions with '\n'.
- Validate that the stack is sorted with the minimum operations.
- Handle errors such as invalid arguments gracefully.

### Benchmark
- **Minimal validation**: Sort 100 numbers in fewer than 700 operations.
- **Maximal validation**: Sort 500 numbers in fewer than 5500 operations.

## Bonus Part

### Checker Program
- **Program Name**: `checker`
- **Turn-in Files**: `*.h`, `*.c`
- **Makefile**: `bonus`
- **Arguments**: A list of integers for stack `a`
- **External Functions**: `read`, `write`, `malloc`, `free`, `exit`, `ft_printf` (or equivalent coded by you)
- **Libft Authorized**: Yes

The `checker` program:
- Takes stack `a` as an argument.
- Reads instructions from standard input.
- Executes instructions on the stack.
- Outputs "OK" if the stack is sorted, otherwise "KO".
- Handles errors gracefully.
---

This README provides a comprehensive guide to the Push_swap project, detailing the rules, objectives, and requirements for both the mandatory and bonus parts. Follow these guidelines to ensure your project meets the expected standards.
