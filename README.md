*This project has been created as part of the 42 curriculum by apinho-a.*

---

## Description
The goal of this project is to program a function that returns a line read from a file descriptor[cite: 4, 87]. It serves as an introduction to using static variables in C programming. Repeated calls to the function read the text file one line at a time until the end of the file or an error occurs[cite: 88, 91].

## Instructions
**Compilation**
The project must be compiled using `cc` with the mandatory flags and a defined buffer size. Run the following at the root of the repository[cite: 108]:
`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c`

To compile the bonus part, which allows managing multiple file descriptors simultaneously using a single static variable:
`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c`

## Resources
* **Documentation**: `man 2 read`, `man 3 malloc`, `man 3 free`.
* **AI Usage**: AI was used to parse the subject requirements, format the README structure, and draft the algorithm justification.

## Algorithm Justification
The algorithm relies on a static variable to persist the reading state of the file descriptor between function calls. 
1. A temporary buffer of size `BUFFER_SIZE` is allocated to read chunks of the file.
2. The `read()` function fetches data into the buffer, which is then joined with the existing data in the static variable.
3. The static string is parsed for a newline character (`\n`).
4. If a newline is found, the string is split: the substring up to the newline is returned as the current line, and the remaining string is stored back in the static variable for the next call.
5. If the end of the file is reached, the remaining content of the static variable is returned, and all allocated memory is properly freed to prevent leaks.
