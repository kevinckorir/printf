#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/**
 * _printf - prints next line in buffer
 * @format: checks format
 * Return: number of characters
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int done = 0;

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
			done++;
			break;
			}
			case 's':
			{
			char *s = va_arg(arg, char*);
			size_t len = strlen(s);
			write(1, s, len);
			done += len;
			break;
			}
			case '%': 
			{
			char c = '%';
			write(1, &c, 1);
			done++;
			break;
			}
			default: {
			char *str = (char*) malloc(2 * sizeof(char));
			str[0] = '%';
			str[1] = *format;
			write(1, str, 2);
			done += 2;
			free(str);
			break;
			}
		}
	}
       	else
	{
		write(1, format, 1);
		done++;
	}
	format++;
	}

	va_end(arg);

	return (done);
}

