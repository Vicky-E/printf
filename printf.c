#include "main.h"
void print_buffer(char b[], int *b_ind);
/**
 * _printf - prints output according to a format
 * @format: character string
 * Return: returns number of characters printed excluding null byte
 */
int _printf(const char *format, ...)
{
	char ch, *str, b[BUFFER], bin;
	int ind, i = 0, count = 0, b_ind = 0;
	unsigned int a[32], num, rem;
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
			if (str == NULL)
				str = "(null)";
			while (*str)
			{
				b[b_ind++] = *str;
				if (b_ind <= BUFFER)
					print_buffer(b, &b_ind);
				str++;
				count++;
			}
		}
		else if (format[ind] == '%' && format[ind + 1] == 'b')
		{
			ind++;
			num = va_arg(args, unsigned int);
			if (num == '\0')
				return (-1);
			if (num == 0)
			{
				bin = '0';
				write(1, &bin, 1);
				count++;
			}
			else
			{
				while (num != 0 && i < 2147483648)
				{
					if (num < 2)
					{
						rem = 1;
						a[i] = rem;
						count++;
						break;
					}
					rem = num % 2;
					a[i] = rem;
					num = num / 2;
					count++;
					i++;
				}
			}
			while (i >= 0)
			{
				b[b_ind++] = a[i] + '0';
				if (b_ind <= BUFFER)
					print_buffer(b, &b_ind);
				i--;
			}
		}
		else
		{
			if (format[ind] == '%' && format[ind + 1] == '\0')
				return (-1);
			b[b_ind++] = format[ind];
			if (b_ind <= BUFFER)
				print_buffer(b, &b_ind);
			count++;
		}
	}
	return (count);
}
/**
 * print_buffer - prints with description
 * @b: array
 * @b_ind: buffer index
 */
void print_buffer(char b[], int *b_ind)
{
	if (*b_ind > 0)
		write(1, &b[0], *b_ind);
	*b_ind = 0;
}
