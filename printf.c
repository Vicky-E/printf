#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: buffer to be printed
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind);
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

/**
 * _printf - prints output according to a format
 * @format: character string
 * Return: returns number of characters printed excluding null byte
 */

int _printf(const char *format, ...)
{
	int ind, printed_chars = 0, printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list list;

	va_start(list, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_i);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}
