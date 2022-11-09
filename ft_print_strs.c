/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:29:44 by zbenaiss          #+#    #+#             */
/*   Updated: 2022/11/09 14:32:41 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putstr(char *s, int *tracker)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*tracker) += 6;
	}
	while (s[i])
	{
		ft_putchar(s[i], tracker);
		i++;
	}
}

void	ft_putchar(char c, int *tracker)
{
	write(1, &c, 1);
	(*tracker)++;
}
