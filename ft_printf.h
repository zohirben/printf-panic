/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:36:52 by zbenaiss          #+#    #+#             */
/*   Updated: 2022/11/09 14:31:53 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

void	ft_write_numbers(int number, char *basestr, int wptr, int *tracker);
void	ft_putchar(char c, int *tracker);
void	ft_putstr(char *s, int *tracker);

#endif