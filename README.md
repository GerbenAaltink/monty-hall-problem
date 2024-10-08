# Monty Hall problem

![workflow](https://github.com/GerbenAaltink/monty-hall-problem/actions/workflows/c-cpp.yml/badge.svg)

## Description 
The monty hall simulator to determine if it's better to stay with current option or to switch option.

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
   