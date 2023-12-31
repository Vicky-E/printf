#include "main.h"
void print_buffer(char b[], int *b_ind);
void pbuffer(char b[], int *b_ind);
void p_buffer(char b[], int *b_ind);
/**
 * _printf - prints output according to a format
 * @format: character string
 * Return: returns number of characters printed excluding null byte
 */
int _printf(const char *format, ...)
{
	char ch, *str, b[BUFFER];
	int ind, count = 0, i = 0, b_ind = 0, is_negative;
	unsigned int rem, num;
	int bit_l;
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
		else if (format[ind] == '%' && format[ind + 1] == 'S')
		{
			ind++;
			str = va_arg(args, char*);
			if (str == NULL)
				str = "(null)";
			while (*str)
			{
				if (*str < ' ' || *str >= 127)
				{
					b[b_ind++] = '\\';
					b[b_ind++] = 'x';
					b[b_ind++] = (*str >> 4) < 10 ? (*str >> 4) + '0'
						: (*str >> 4) + 'A' - 10;
					b[b_ind++] = (*str & 0xF) < 10 ? (*str & 0xF) + '0'
						: (*str & 0xF) + 'A' - 10;
					count += 4;
				}
				else
				{
					b[b_ind++] = *str;
					count++;
				}
				if (b_ind <= BUFFER)
					print_buffer(b, &b_ind);
				str++;
			}
		}
		else if (format[ind] == '%' && format[ind + 1] == 'b')
		{
			ind++;
			num = va_arg(args, unsigned int);
			bit_l = sizeof(num) * 8;
			if (num == '\0')
				return (-1);
			if (num == 0)
			{
				b[b_ind++] = '0';
				count++;
			}
			else
			{
				while (i < bit_l && b_ind < BUFFER)
				{
					b[b_ind++] = ((num >> (bit_l - 1 - i)) & 1) + '0';
					count++;
					i++;
				}
			}
			p_buffer(b, &b_ind);
		}
		else if (format[ind] == '%' && (format[ind + 1] == 'd'
					|| format[ind + 1] == 'i'))
		{
			ind++;
			num = va_arg(args, unsigned int);
			is_negative = 0;
			if ((int)num < 0)
			{
				is_negative = 1;
				num = -(int)num;
			}
			if (num == 0)
			{
				b[b_ind++] = '0';
				count++;
			}
			else
			{
				while (num != 0 && b_ind < BUFFER)
				{
					rem = num % 10;
					b[b_ind++] = rem + '0';
					num = num / 10;
					count++;
				}
			}
			if (is_negative && b_ind < BUFFER)
			{
				b[b_ind++] = '-';
				count++;
			}
			pbuffer(b, &b_ind);
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
/**
 * pbuffer - prints a format
 * @b: array
 * @b_ind: index
 */
void pbuffer(char b[], int *b_ind)
{
	int i;

	if (*b_ind > 0)
	{
		for (i = *b_ind - 1; i >= 0; i--)
		{
			write(1, &b[i], 1);
		}
		*b_ind = 0;
	}
}
void p_buffer(char b[], int *b_ind)
{
	if (*b_ind > 0)
	{
		write(1, b, *b_ind);
		*b_ind = 0;
	}
}
