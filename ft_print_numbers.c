/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:54:45 by zbenaiss          #+#    #+#             */
/*   Updated: 2022/11/09 14:31:37 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ptrcheck(int wptr, int *tracker)
{
	if (wptr == 1)
	{
		ft_putstr("0x", tracker);
		wptr = 3;
	}
	return (wptr);
}

void	nigativity(int *number, int *tracker)
{
	if (*number < 0)
	{
		ft_putchar('-', tracker);
		*number *= -1;
	}
}

void	ft_write_numbers(int number, char *basestr, int wptr, int *tracker)
{
	int	baselen;

	baselen = ft_strlen(basestr);
	wptr = ptrcheck(wptr, tracker);
	nigativity(&number, tracker);
	if (baselen == 10 && number > baselen - 1)
	{
		if (wptr == 0)
			ft_write_numbers(number / baselen, basestr, wptr, tracker);
		else if (wptr == 2)
			ft_write_numbers(((unsigned int)number) / baselen, basestr, wptr,
				tracker);
	}
	if (baselen == 16 && wptr == 3 && number > baselen - 1)
		ft_write_numbers(((unsigned long)number) / baselen, basestr, wptr,
			tracker);
	ft_putchar(basestr[number % baselen], tracker);
}

// int main()
// {
// 	int number = 47925535;
// 	int count = 0;
// 	int *tracker = &count;
// 	ft_write_numbers(023145, "0123456789", 0, tracker);
// 	printf("\n%i", 023145);
// }