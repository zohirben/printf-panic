#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    int i;
    int tracker;
    va_list args;

    tracker = 0;
    i = 0;
    va_start(args, str);
    while(str[i])
    {
        if (str[i] == '%' && str[i+1] == 'c')
        {
            ft_putchar(va_arg(args, int), &tracker);
            i+=2;
        }
        else if (str[i] == '%' && str[i+1] == 's')
        {
            ft_putstr(va_arg(args, char *), &tracker);
            i+=2;
        }
        else if (str[i] == '%' && str[i+1] == 'p')
        {
            ft_write_numbers(va_arg(args, unsigned long),"0123456789abcdef", 1, &tracker);
            i+=2;
        }
        else if ((str[i] == '%' && str[i+1] == 'd') || (str[i] == '%' && str[i+1] == 'i'))
        {
            ft_write_numbers(va_arg(args, int), "0123456789", 0, &tracker);
            i+=2;
        }
        else if (str[i] == '%' && str[i+1] == 'u')
        {
            ft_write_numbers(va_arg(args, unsigned int), "0123456789", 2, &tracker);
            i+=2;
        }
        else if (str[i] == '%' && str[i+1] == 'x')
        {
            ft_write_numbers(va_arg(args, unsigned long), "0123456789abcdef", 3, &tracker);
            i+=2;
        }
        else if (str[i] == '%' && str[i+1] == 'X')
        {
            ft_write_numbers(va_arg(args, unsigned long), "0123456789ABCDEF", 3, &tracker);
            i+=2;
        }
        else if (str[i] == '%' && str[i+1] == '%')
        {
            ft_putchar('%', &tracker);
            i+=2;
        }
        else
        {
            ft_putchar(str[i], &tracker);
            i++;
        }
    }
    va_end(args);
    return (tracker);
}

int main()
{
    int number = 1337;
    ft_printf("%i, %d, %X, %i, %c, %s\n", number, 12, 479, 0x12342, 'A', "Zohir");
    printf("%i, %d, %X, %i, %c, %s\n", number, 12, 479, 0x12342, 'A', "Zohir");
}