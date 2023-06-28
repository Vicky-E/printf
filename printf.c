#include "main.h"
/**
 * _printf - prints output according to a format
 * @format: character string
 * Return: returns number of characters printed excluding null byte
 */
int _printf(const char *format, ...)
{
	char ch, *str;
	int ind, count = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (ind = 0; format[ind] != '\0'; ind++)
	{
		if (format[ind] == '%' && format[ind + 1] == 'c')
		{
			ind++;
			ch = va_arg(args, int);
			write(1, &ch, 1);
			count++;
		}
		else if (format[ind] == '%' && format[ind + 1] == '%')
		{
			ind++;
			write(1, "%", 1);
			count++;
		}
		else if (format[ind] == '%' && format[ind + 1] == 's')
		{
			ind++;
			str = va_arg(args, char*);
			if (*str == '\0')
				str = "(nil)";
			while (*str)
			{
				write(1, &str, 1);
				str++;
				count++;
			}
		}
		else
		{
			if (format[ind] == '%' && format[ind + 1] == '\0')
				return (-1);
			write(1, &format[ind], 1);
			count++;
		}
	}
	return (count);
}
