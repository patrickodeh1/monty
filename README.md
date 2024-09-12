# Monty Bytecode Interpreter

## Description

This project is an interpreter for Monty Bytecode files (.m), a language that processes stacks and queues. The interpreter reads Monty bytecode from a file and executes the commands to manipulate a doubly linked list as either a stack (LIFO) or a queue (FIFO).

## Requirements

- Ubuntu 20.04 LTS
- Compiled using `gcc` with the following flags:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
- Code must follow the Betty style guidelines.
- No more than 5 functions per file.
- Allowed C standard library functions:
- malloc, free, printf, exit
- Code must include a README.md file.
- A header file (monty.h) with function prototypes and include guards is mandatory.
- Use a global variable only when absolutely necessary.

## Usage

```bash
./monty <file.m>
```
- The interpreter reads Monty bytecode from the file <file.m> and executes the corresponding operations on a stack or queue.

## Authors
- Patrick Odeh