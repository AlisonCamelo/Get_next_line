*This project has been created as part of the 42 curriculum by acamelo.*

# Get Next Line (GNL)

## Description
The **Get Next Line** project consists of writing a function in C that returns a single line read from a file descriptor (`fd`). Calling `get_next_line()` repeatedly in a loop allows reading an entire text file or standard input line by line until the end of the file (EOF) is reached.

This project introduces fundamental concepts such as:
- **Static variables** in C and their persistence across function calls.
- Dynamic memory allocation (`malloc`, `free`) and memory leak management.
- Buffer handling and file I/O operations using the `read()` system call.

## Instructions

### Compilation
The project must be compiled using `cc` with the mandatory flags `-Wall -Wextra -Werror` and the macro definition `-D BUFFER_SIZE=n`.

Example compilation with a custom buffer size:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

```

If no `BUFFER_SIZE` flag is provided, the header `get_next_line.h` defaults to `BUFFER_SIZE=42`.

## Resources

* [Linux Programmer's Manual - `read(2)](https://man7.org/linux/man-pages/man2/read.2.html)`
* [C Static Variables - GeeksforGeeks](https://www.geeksforgeeks.org/static-variables-in-c/)

### AI Usage Disclosure

Artificial Intelligence (AI) was used during this project for the following tasks:

* **Code Review & Debugging:** Identifying dangling pointers, memory leaks, and operator precedence bugs (`while` conditions).
* **Evaluation Preparation:** Explaining theoretical concepts (Stack vs Heap, Static Variables) and generating evaluation test cases.

---

## Algorithm Explanation

The algorithm relies on a **3-step modular strategy** managed by a `static char *leftovers` pointer to preserve state between function calls:

1. **Reading Loop (`get_next_line`):**
* Continuously calls `read()` with a buffer of size `BUFFER_SIZE` until a newline (`\n`) is found in `leftovers` or `read()` returns `0` (EOF).
* Dynamically concatenates new chunks into `leftovers` using `ft_strjoin()`.


2. **Line Extraction (`ft_linebreak`):**
* Scans `leftovers` up to the first `\n` (or `\0`).
* Allocates exact memory for the line (including the `\n` if present and the `\0` terminator) and returns it.


3. **Cleanup (`ft_clean_leftovers`):**
* Scans `leftovers` past the first `\n`.
* Allocates new memory for the remaining unread text, frees the old `leftovers` string, and updates the pointer to point to the new residual buffer.
