*This project has been created as part of the 42 curriculum by apinho-a.*

---
## Get_next_line
### Description
The goal of this project is to program a function that returns a line read from a file descriptor. It serves as an introduction to using static variables in C programming. Repeated calls to the function read the text file one line at a time until the end of the file or an error occurs.

### Instructions
**Compilation**
The project must be compiled using `cc` with the mandatory flags and a defined buffer size. Run the following at the root of the repository:
`cc -Wall -Wextra -Werror -D BUFFER_SIZE=X get_next_line.c get_next_line_utils.c get_next_line.h`

`X can be any number you'd like` (as long as it doesn't exceed the PC's available memory).

`X defaults to 42`.

>[!NOTE]
>All code adheres to **42 Norm V4**

### Resources

- **[GeekForGeek IO system calls](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/)**.
- **Documentation:** `man 2 read`, `man 3 malloc`, `man 3 free`.
- **[Francinette tester](https://github.com/xicodomingues/francinette):** Great tool for testing a lot of possibilities.

### **LLM Usage Disclosure**

The learning process was assisted by Google Gemini for:
- **Debugging:** Tracing memory leaks and segmentation faults caused by extreme edge cases.

- **Memory Management:** Clarifying proper error handling and cleanup paths for malloc failures.

### Algorithm Justification
The algorithm relies on a static variable to persist the reading state of the file descriptor between function calls.
1. A buffer (char *buffer) of size `BUFFER_SIZE` is allocated to read chunks of the file.
2. The `read()` function fetches data into the buffer, which is then joined with the existing data in the static variable (char *acc).
3. The static string is parsed for a newline character (`\n`).
4. If a newline is found, the string is split: the substring up to the newline is returned as the current line, and the remaining string is stored back in the static variable for the next call.
5. If the end of the file is reached, the remaining content of the static variable is returned, and all allocated memory is properly freed to prevent leaks.
