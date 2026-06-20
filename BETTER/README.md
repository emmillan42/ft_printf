*This project has been created as part of the 42 curriculum by emmmilla.*

# ft_printf

A custom implementation of the standard C `printf()` function developed as part of the 42 curriculum.

---

## Description

**ft_printf** is one of the core projects in the 42 curriculum. Its objective is to reimplement the behavior of the standard C library function `printf()` while working under a restricted set of authorized functions.

The project introduces several fundamental concepts of low-level programming:

* Variadic functions (`stdarg.h`)
* Format string parsing
* Integer representation in different numerical bases
* Recursive algorithms
* Pointer manipulation
* Modular software design

The resulting library provides a custom implementation of:

```c
int ft_printf(const char *format, ...);
```

supporting the following conversions:

| Conversion | Description              |
| ---------- | ------------------------ |
| `%c`       | Character                |
| `%s`       | String                   |
| `%p`       | Pointer address          |
| `%d`       | Signed decimal integer   |
| `%i`       | Signed decimal integer   |
| `%u`       | Unsigned decimal integer |
| `%x`       | Hexadecimal (lowercase)  |
| `%X`       | Hexadecimal (uppercase)  |
| `%%`       | Percent sign             |

---

## Features

* Reimplementation of `printf()` from scratch.
* No usage of the original libc `printf()`.
* Recursive number printing.
* Generic base conversion system.
* Modular architecture.
* Fully compliant with the 42 Norm.
* Static library generation using `ar`.

---

## Architecture Overview

The project is intentionally divided into small, single-responsibility modules.

```text
ft_printf()
│
└── ft_print_format()
    │
    ├── ft_putchar()
    ├── ft_putstr()
    └── ft_putbase()
        │
    	├──	ft_putnbr()
		├── ft_putunsigned()
		├── ft_puthex()
		└── ft_putptr()

```
These modules comprises two major subsystems:

### Format Parsing

Responsible for scanning the format string, extracting variadic arguments and dispatching the correct conversion function.

```text
ft_printf()
│
└── ft_print_format()
    │
    ├── %c → ft_putchar()
    ├── %s → ft_putstr()
    ├── %p → ft_putptr()
    ├── %d → ft_putnbr()
    ├── %i → ft_putnbr()
    ├── %u → ft_putunsigned()
    ├── %x → ft_puthex()
    ├── %X → ft_puthex()
    └── %% → ft_putchar()
```

### Numeric Conversion

All numeric conversions are built on top of a generic base-printing engine.

```text
ft_putbase()
│
├── ft_putnbr()
├── ft_putunsigned()
├── ft_puthex()
└── ft_putptr()
```

This design removes duplicated recursive algorithms and centralizes all base-conversion logic in a single reusable function.
```text

			 ft_printf
				 ↓
		  ft_print_format
				 ↓
 ┌───────────────┬───────────────┬───────────────┬───────────────┬───────────────┐
 │               │               │               │               │               │
ft_putchar    ft_putstr      ft_putnbr   ft_putunsigned      ft_puthex       ft_putptr
                                 │               │               │               │
                                 └───────────────┴───────────────┴───────────────┘
                                                         ↓
		                                            ft_putbase

```

Each module has a clearly defined purpose:

| Function          | Responsibility                     |
| ----------------- | ---------------------------------- |
| `ft_printf`       | Parse the format string            |
| `ft_print_format` | Dispatch conversion specifiers     |
| `ft_putchar`      | Print a single character           |
| `ft_putstr`       | Print strings                      |
| `ft_putbase`      | Print positive numbers in any base |
| `ft_putnbr`       | Handle signed integers             |
| `ft_putunsigned`  | Handle unsigned integers           |
| `ft_puthex`       | Handle hexadecimal conversion      |
| `ft_putptr`       | Handle pointer conversion          |

---

## Algorithm & Design Decisions

### Variadic Arguments

The core of the project relies on C variadic functions:

```c
va_list
va_start
va_arg
va_end
```

The format string is scanned character by character.

Whenever a `%` symbol is encountered, the next character determines the expected argument type and the appropriate conversion function is called.

---

### Generic Base Conversion

Instead of implementing separate recursive algorithms for decimal, hexadecimal and pointer conversions, a generic function named `ft_putbase()` is used.

Example:

```c
ft_putbase(n, "0123456789");
ft_putbase(n, "0123456789abcdef");
ft_putbase(n, "0123456789ABCDEF");
```

This approach:

* Reduces code duplication.
* Improves maintainability.
* Simplifies future extensions.

---

### Recursive Number Printing

Numbers are printed recursively.

For example:

```text
1234
```

becomes:

```text
print(123)
print(12)
print(1)
```

and then prints:

```text
1
2
3
4
```

This technique naturally preserves digit order without requiring additional buffers.

---

### Pointer Representation

Pointers are converted to:

```c
unsigned long
```

before being printed.

This guarantees compatibility with 64-bit architectures and allows pointer addresses to be printed using the same base conversion algorithm used for hexadecimal numbers.

---

### Data Structures

No dynamic data structures are required.

The project only uses:

* Primitive integer types
* Character arrays
* String literals
* The `va_list` structure provided by `<stdarg.h>`

Because the format string is processed sequentially, no additional storage or buffering mechanism is necessary.

---

## File Structure

```text
.
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_print_format.c
├── ft_putchar.c
├── ft_putstr.c
├── ft_putbase.c
├── ft_putnbr.c
├── ft_putunsigned.c
├── ft_puthex.c
└── ft_putptr.c
```

---

## Instructions

### Clone the Repository

```bash
git clone https://github.com/emmmilla/ft_printf.git
```

### Build the Library

```bash
make
```

This generates:

```text
libftprintf.a
```

### Available Makefile Rules

| Command       | Description                     |
| ------------- | ------------------------------- |
| `make`        | Build the library               |
| `make all`    | Build the library               |
| `make clean`  | Remove object files             |
| `make fclean` | Remove object files and library |
| `make re`     | Rebuild everything              |

---

## Usage Example

Include the header:

```c
#include "ft_printf.h"
```

Compile:

```bash
cc main.c libftprintf.a -I. -o program
```

Example:

```c
ft_printf("Hello %s! Score: %d\n", "Student", 42);
```

Output:

```text
Hello Student! Score: 42
```

---

## Technical Decisions

* Written in ISO C.
* Compiled using `-Wall -Wextra -Werror`.
* Uses only authorized functions.
* No internal buffering.
* Recursive number conversion.
* Generic base conversion through `ft_putbase()`.
* Pointer printing compatible with 64-bit systems.
* Fully compliant with the 42 Norm.

---

## Resources

### Official Documentation

* POSIX Specification
* Linux Manual Pages
* GNU C Library Documentation
* ISO C Standard

### Recommended Reading

* The C Programming Language — Brian Kernighan & Dennis Ritchie
* The Standard C Library - P.J. Plauger
* C, A Software Engineering Approach — Peter A. Darnell & Philip E. Margolis

### Testing Tools

* Francinette
* Tripouille ft_printf Tester
* ft_printf Tester by mapena-z

---

## Use of Artificial Intelligence

Artificial Intelligence tools were used exclusively as learning, documentation and review aids.

AI assistance was used for:

* Understanding the behavior of standard printf function.
* Discussing variadic functions.
* Reviewing edge cases.
* Generating and formatting this README document.

All source code was designed, implemented, tested and validated by the author.

---

## Author

**emmmilla**

42 Madrid Student

Repository:
https://github.com/emmmilla/ft_printf
