#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;  // Track the number of characters printed

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;  // Move past '%'

            if (*format == '%')
            {
                // Print a literal '%'
                putchar('%');
                count++;
            }
            else if (*format == 'c')
            {
                // Print a character
                char ch = (char)va_arg(args, int);
                putchar(ch);
                count++;
            }
            else if (*format == 's')
            {
                // Print a string
                char *str = va_arg(args, char *);
                while (*str != '\0')
                {
                    putchar(*str);
                    count++;
                    str++;
                }
            }

            format++;  // Move to the next character
        }
        else
        {
            // Print literal characters
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}

