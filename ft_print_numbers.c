#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_write_numbers(int number, unsigned int base, char *basestr, int wptr)
{
    if (wptr == 1)
    {
        write(1, "0x", 2);
        wptr = 0;
    }
    if (number < 0)
    {
        write(1, '-', 1);
        number *= -1;
    }
    if (number > base-1)
        ft_write_numbers(number / base, base, basestr, wptr);
    ft_putchar(basestr[number % base]);
}

// void    ft_write_uinumb(unsigned int number, unsigned int base, char *basestr)
// {
//     if (number > base-1)
//         ft_write_numbers(number / base, base, basestr);
//     ft_putchar(basestr[number % base]);
// }

int main()
{
    int number = 1337;
    ft_write_numbers(number, 5, "mohammed", 0);
}