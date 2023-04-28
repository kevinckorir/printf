#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * _printf - prints next line in buffer
 * @format: checks format
 * Return: number of characters
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int counter = 0;

	va_start(arg, format);

	while (*format != '\0')
	{
	if (*format == '%')
	{
	format++;
		switch (*format)
		{
			case 'c':
			{
			int c = va_arg(arg, int);

			write(1, &c, 1);
			counter++;
			break;
			}
			case 's':
			{
			char *s = va_arg(arg, char*);
			size_t len = strlen(s);
			write(1, s, len);
			counter += len;
			break;
			}
			case 'd':
				case 'i':
				{
					size_t len;
					int num = va_arg(arg, int);
					char bufer[32];
					snprintf(bufer, 32, "%d", num);
					len = strlen(bufer);
					write(1, bufer, len);
					counter += len;
					break;
				}
			case '%':
			{
			char c = '%';
			write(1, &c, 1);
			counter++;
			break;
			}
			default: {
			char *str = (char*) malloc(2 * sizeof(char));
			str[0] = '%';
			str[1] = *format;
			write(1, str, 2);
			counter += 2;
			free(str);
			break;
			}
		}
	}
       	else
	{
		write(1, format, 1);
		counter++;
	}
	format++;
	}

	va_end(arg);

	return (counter);
}

