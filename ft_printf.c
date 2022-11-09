/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:29:20 by zbenaiss          #+#    #+#             */
/*   Updated: 2022/11/09 14:32:19 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	ft_cheki(char c, va_list args, int *tracker)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), tracker);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), tracker);
	else if (c == 'p')
		ft_write_numbers(va_arg(args, unsigned long), "0123456789abcdef", 1,
			tracker);
	else if (c == 'd' || c == 'i')
		ft_write_numbers(va_arg(args, int), "0123456789", 0, tracker);
	else if (c == 'u')
		ft_write_numbers(va_arg(args, unsigned int), "0123456789", 2, tracker);
	else if (c == 'x')
		ft_write_numbers(va_arg(args, unsigned long), "0123456789abcdef", 3,
			tracker);
	else if (c == 'X')
		ft_write_numbers(va_arg(args, unsigned long), "0123456789ABCDEF", 3,
			tracker);
	else if (c == '%')
		ft_putchar('%', tracker);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		tracker;
	va_list	args;

	tracker = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_cheki(str[i + 1], args, &tracker);
			i += 2;
		}
		else
			ft_putchar(str[i++], &tracker);
	}
	va_end(args);
	return (tracker);
}

// int	main(void)
// {
// 	int number = 1337;
// 	ft_printf("%i, %d, %X, %i, %c, %s\n", number, 12, 479, 0x12342, 'A',
// 		"Zohir");
// 	printf("%i, %d, %X, %i, %c, %s\n", number, 12, 479, 0x12342, 'A', "Zohir");
// }