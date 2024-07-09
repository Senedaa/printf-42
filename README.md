
# School 42 printf()

<div id="header" align="center">
  <img src="https://media.giphy.com/media/QXJd9XVrgJuDFhhcOX/giphy.gif" width="200"/>
</div>

<h1 align="center">School 42 printf()</h1>

This repository contains all files for the __printf__ project from School 42 Málaga cursus. The project consists of duplicating the [`printf()`](https://es.wikipedia.org/wiki/Printf) function, part of the `stdio.h` library.

<h2 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#index">Index</a>
	<span> · </span>
	<a href="#requirements">Requirements</a>
	<span> · </span>
	<a href="#instructions">Instructions</a>
	<span> · </span>
	<a href="#testing">Testing</a>
</h2>

## <a name="about">About</a>
This project consists of duplicating the behavior of the C function `printf()`. It is not necessary to implement the buffer management of the original function. It must handle the following parameters:

- `char` type variables.
- `string` type variables.
- `int` type variables.
- `unsigned int` type variables.
- hexadecimal `int` type variables (uppercase and lowercase).
- `pointer` type variables.

You will find more details in the [subject of the project](https://github.com/Senedaa/printf-42/blob/main/printf.es.subject.pdf).

## <a name="index">Index</a>
- [Structure](#structure)
- [Formats](#formats)
  - [va_list](#va_list)
  - [Returning an integer](#returning-an-integer)


### <a name="structure">Structure</a>
The main obstacles during the execution of the project have been handling a variable number of parameters and the function `ft_printf()` returning an `int`.

#### <a name="va_list">va_list</a>
To deal with the variable number of parameters entered, the macros `va_list`, `va_start`, `va_arg`, and `va_end` have been used. The `ft_printf()` function calls the `ft_format()` function when it finds the `%` sign among the entered parameters. It then checks the next character in the string to call one of the functions that print the different variable types. To use this macro, the library `<stdarg.h>` is included in the `ft_printf.h`.

#### <a name="returning-an-integer">Returning an integer</a>
To handle the integer returned by `ft_printf()`, a pointer is given in the format printing functions. In this way, the function handles the number of characters printed before continuing with the string sent by parameter. Example:

```c
void	ft_putchar_pf(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++; // increasing the pointer with each character printed
}
```

### <a name="formats">Formats</a>
The different types of variables are printed using a function for each of the formats:

* [__`ft_printf_hex()`__](https://github.com/Senedaa/printf-42/blob/main/ft_printf_hex.c) prints hexadecimal integers, using a string included in the `ft_printf.h` library. There is one string for uppercase and one for lowercase characters.
* [__`ft_print_nbr()`__](https://github.com/Senedaa/printf-42/blob/main/ft_print_nbr.c) recursively prints an integer, handling the maximum negative value with a conditional (`if-else`) and casting the integer to characters.
* [__`ft_print_putptr()`__](https://github.com/Senedaa/printf-42/blob/main/ft_print_putptr.c) prints a pointer in hexadecimal format (lowercase), preceded by the string "0x".
* [__`ft_print_unsigned()`__](https://github.com/Senedaa/printf-42/blob/main/ft_print_unsigned.c) prints an `unsigned int` type variable.


## <a name="requirements">Requirements</a>
The functions are written in __C language__ and need the `gcc` compiler, with `<stdlib.h>`, `<stdarg.h>`, and `<unistd.h>` standard libraries to run.

## <a name="instructions">Instructions</a>

### 1. Compiling the archives

To compile the project, go to its path and run:

For __mandatory__ functions:
```sh
$ make
```
### 2. Cleaning all binary (.o) and executable files (.a)

To delete all files generated with make, go to the path and run:
```sh
$ make fclean
```

### 3. Using it in your code

To use this project in your code, simply include this header:
```c
#include "ft_printf.h"
```

## <a name="testing">Testing</a>
This function has been tested with [Francinette](https://github.com/xicodomingues/francinette).

