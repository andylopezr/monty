![](https://i.imgur.com/410mMJz.png)

### Description

This is an interpreter for Monty ByteCodes files.

### Environment
Has been tested on Ubuntu 14.04.6 and 18.04.3 LTS
Done and tested with VirtualBox on Ubuntu via Vagrant(2.2.10)

### Usage

First step is to clone the repository into your directory
```
$ git clone https://github.com/kjowong/monty.git
```
Compile all the `.c` files in monty
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## Example of Use
After compiling, run the executable `./monty` on your bytecode file.
```c
$ ./monty 00.m
3
2
1
$
```

### Main Functionality

- [X] Implement the `push` and `pall` opcodes.
- [X] Implement the `pint` opcode.
- [X] Implement the `pop` opcode.
- [X] Implement the `swap` opcode.
- [X] Implement the `add` opcode
- [X] Implement the `nop` opcode.
- [X] Implement the `sub` opcode.
- [X] Implement the `div` opcode.
- [X] Implement the `mul` opcode.
- [X] Implement the `mod` opcode.
- [X] Handled `#` comments.
- [X] Implement the `pchar` opcode.
- [X] Implement the `pstr` opcode.
- [X] Implement the `rotl` opcode.
- [X] Implement the `rotr` opcode.
- [X] Implement the `stack` and `queue` opcodes.
- [X] Produces output with (printf) conversion specifiers c, s, and %.
- [X] Handles conversion specifiers d, i.
- [X] man page added.

### Advance Tasks

- [X] Write a Brainf*ck script that prints Holberton, followed by a new line.
- [X] Add two digits given by the user.
- [X] Multiply two digits given by the user.
- [X] Multiply two digits given by the user followed by a new line.

## Authors
[Andres Lopez](https://github.com/andylopezr)-profesor.de.ingles@aol.com