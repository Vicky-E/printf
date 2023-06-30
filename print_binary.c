#include "main.h"

/**
 * print_binary_helper - Helper function to convert integer to binary.
 * @num: The integer to convert to binary.
 *
 * Return: Number of characters printed.
 */

int print_binary_helper(unsigned int num)
{
	unsigned int counter = 0;

	if (num >= 2)
		counter += print_binary_helper(num / 2);
	_putchar((num % 2) + '0');
	counter++;
	return (counter);
}

/**
 * print_binary - function to convert integer to binary.
 * @arg: Variable argument list.
 *
 * Return: Number of characters printed.
 */

int print_binary(va_list arg)
{
	unsigned int counter = 0, num = va_arg(arg, unsigned int);

	if (num >= 2)
		counter += print_binary_helper(num / 2);
	_putchar((num % 2) + '0');
	counter++;
	return (counter);
}
