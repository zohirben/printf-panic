/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:36:52 by zbenaiss          #+#    #+#             */
/*   Updated: 2022/11/10 13:24:08 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(char *str);
int		ptrcheck(int wptr, int *tracker);
void	ft_write_numbers(unsigned long number, char *basestr, int wptr,
			int *tracker);
void	ft_write_integer(long number, char *basestr, int *tracker);
void	ft_putchar(char c, int *tracker);
void	ft_putstr(char *s, int *tracker);
void	nigativity(long *number, int *tracker);

#endif