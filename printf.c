#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/**
 * _printf - prints anything.
 * @format: a list of types of arguments passed to the function.
 * Return: count
 */

int _printf(const char *format, ...)
{
	char ch, *str;
	int count = 0;
	va_list args;
	int n = 0, digit = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			if (*format == 'c')
				ch = (char)va_arg(args, int);
			putchar(ch);
			count++;
			if (*format == 's')
			{
				str = va_arg(args, char *);
				while (*str != '\0')
				{
					putchar(*str);
					count++;
					str++;
				}
			}
			if (*format == 'd')
			{
				n = va_arg(args, int);
				if (n > 0)
				{
					n *= -1;
				}
				while (n > 0)
				{
					while (n >0)
					digit = n % 10;
					putchar(digit + '0');
					n = n / 10;
				}
			}
			if (*format == 'i')
			{
				n = va_arg(args, int);
				if (n > 0)
				{
					n *= -1;
				}
				while (n > 0)
				{
					digit = n % 10;
					putchar(digit + '0');
					n = n / 10;
				}
			}
			format++;
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
