#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int print(char *str, ...)
{
    va_list vl;
    va_start(vl, str);

    char *buff = malloc(100);
    int i = 0, j = 0;

    while (str && str[i])
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
                case 'c':
                {
                    char c = (char) va_arg(vl, int);
                    buff[j] = c;
                    j++;
                    break;
                }
                case 'd':
                {
                    int num = va_arg(vl, int);
                    char tmp[20];
                    itoa(num, tmp, 10);
                    int len = strlen(tmp);
                    memcpy(&buff[j], tmp, len);
                    j += len;
                    break;
                }
                case 'x':
                {
                    int num = va_arg(vl, int);
                    char tmp[20];
                    itoa(num, tmp, 16);
                    int len = strlen(tmp);
                    memcpy(&buff[j], tmp, len);
                    j += len;
                    break;
                }
            }
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
        i++;
    }

    write(STDOUT_FILENO, buff, j);
    free(buff);
    va_end(vl);
    return j;
}

