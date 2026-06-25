*This project has been created as part of the 42 curriculum by acirino*

## Description
Libft is a custom C library that reimplements standard libc functions along with additional utilities. The project serves as a foundational exercise to understand the "building blocks" of C and to provide a toolkit for future assignments. It focuses on memory management, string manipulation, and data structures.

## Instructions
To compile the library, run the following command in the terminal:
`make`
This will execute the `all` rule and generate the `libft.a` static library.
- Use `make clean` to remove object files.
- Use `make fclean` to remove object files and the library.
- Use `make re` to recompile the entire project.

## Resources
- Standard C Manual Pages (man)
- 42 Project Documentation
- 42 Norminette Documentation
- Piscine's Projects Documentation
- Online free resources, like Harvard's course CS50
- **AI Usage**: AI was used to clarify logic for specific edge cases, to write tests, and to structure the initial layout of this documentation.

## Library Overview
The library is divided into three main areas:
1. **Libc Functions**: Reimplementations of standard functions from the *libc*.
2. **Additional Functions**: Useful utilities not found in the standard library. These additional functions bridge the gap between low-level C and higher-level languages like Python.
3. **Linked Lists**: A set of functions to manage and manipulate `t_list` structures.