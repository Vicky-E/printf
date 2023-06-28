#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int _printf(const char *format, ...);

int (*check_specifier(const char *specifier))(va_list);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_S(va_list args);

#endif
