# Monty Hall problem

![workflow](https://github.com/GerbenAaltink/monty-hall-problem/actions/workflows/c-cpp.yml/badge.svg)

## Description 
This is my answer to the Monty Hall problem. As some people mentioned, I do let Monty choose before the prize is placed. Yes, that's incorrect but it shouldn't matter since Monty will always pick a door with a goat behind it. The prize will always be one that Monty didn't choose. Reason that I didn't change the sequence is because people are reviewing my code. It's not convenient/fair to change source in between.

## Makefile

Makefile contains three targets, `doors`, `run` and `all`.

### Targets

1. **`all`**:
   - The default target that depends on both the `doors` and `run` targets.
   - Running `make` without specifying a target will invoke `all`, which compiles the program and then runs it.

2. **`doors`**:
   - Compiles the C source file `doors.c` into an executable named `doors`.
   - Uses the `gcc` compiler with the following flags:
     - `-Wall`: Enables all compiler warning messages, helping identify potential issues in the code.
     - `-Werror`: Treats all warnings as errors, ensuring the code compiles without any warnings.

3. **`run`**:
   - Runs application named `doors`.
   