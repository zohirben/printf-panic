#include <unistd.h>

void    ft_write_numbers(int number, unsigned int base)
{
    // if (number < 0)
    // {
    //     write(1, '-', 1);
    //     number *= -1;
    // }
    if (number > 9)
        ft_write_numbers(number / base, base);
    write(1, &"0123456789ABCDEF"[number % base], 1);
}

int main()
{
    int number;
    
    number = 10;
    ft_write_numbers(number, 10);
}

