/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:54:45 by zbenaiss          #+#    #+#             */
/*   Updated: 2022/11/10 13:31:51 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	nigativity(long *number, int *tracker)
{
	if (*number < 0)
	{
		ft_putchar('-', tracker);
		*number *= -1;
	}
}

void	ft_write_numbers(unsigned long number, char *basestr, int wptr,
		int *tracker)
{
	size_t	baselen;

	baselen = ft_strlen(basestr);
	if (wptr == 1)
		wptr = ptrcheck(wptr, tracker);
	if (number > baselen - 1)
		ft_write_numbers(number / baselen, basestr, wptr, tracker);
	ft_putchar(basestr[number % baselen], tracker);
}

void	ft_write_integer(long number, char *basestr, int *tracker)
{
	int	baselen;

	baselen = ft_strlen(basestr);
	nigativity(&number, tracker);
	if (number > baselen - 1)
		ft_write_integer(number / baselen, basestr, tracker);
	ft_putchar(basestr[number % baselen], tracker);
}
