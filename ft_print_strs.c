#include <unistd.h>
#include "ft_printf.h"

void	ft_putstr(char *s, int *tracker)
{
	int	i;

	i = 0;
    if (s == NULL)
    {
        write(1,"(null)",6);
        (*tracker)+=6;
    }
    while (s[i])
    {
        ft_putchar(s[i], tracker);
        i++;
    }
}

void ft_putchar(char c, int *tracker)
{
	write(1, &c, 1);
	(*tracker)++;
}