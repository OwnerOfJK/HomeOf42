# libftprintf Project

## Overview
This project aims to replicate a simplified version of the standard `printf` function in C. It includes a set of functions that mimic some of the basic functionalities of `printf` to print formatted output.

## Implementation Details
The project consists of two main functions:
- **`print`:** This function interprets format specifiers and delegates the printing to corresponding functions based on the provided format characters.
- **`ft_printf`:** Acting as the main interface, this function processes the format string, identifies specifiers, and dispatches printing accordingly.

### Format Specifiers Supported
- `%c`: Character printing
- `%s`: String printing
- `%p`: Pointer printing
- `%i`/`%d`: Integer printing
- `%u`: Unsigned integer printing
- `%x`/`%X`: Hexadecimal printing
- `%%`: Percentage sign printing

## Usage
To use this implementation of `printf`, include the "libftprintf.h" header file in your C program and call the `ft_printf` function with the desired format string and arguments.

## Notes
- The project focuses on a limited set of format specifiers and might not cover the complete functionality of the standard `printf`.
- It's intended as an educational exercise to understand the basics of format string parsing and printing in C.

Feel free to contribute, suggest improvements, or expand the functionality to support additional format specifiers.
