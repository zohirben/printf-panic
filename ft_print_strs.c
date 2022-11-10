/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:29:44 by zbenaiss          #+#    #+#             */
/*   Updated: 2022/11/10 11:23:45 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *tracker)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		(*tracker) += 6;
		return ;
	}
	while (s[i])
		ft_putchar(s[i++], tracker);
}

void	ft_putchar(char c, int *tracker)
{
	write(1, &c, 1);
	(*tracker)++;
}
