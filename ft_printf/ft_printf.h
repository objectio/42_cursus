/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:30:05 by younjkim          #+#    #+#             */
/*   Updated: 2022/01/18 16:51:35 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_check(char format);
int		ft_task(char format, va_list *args);
int		ft_printf(const char *format, ...);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_hexdecimal(unsigned int nbr);
int		ft_hedecimal(unsigned int nbr);
int		ft_unsigned(int nbr);
int		ft_pointerhex(unsigned long nbr);
int		ft_pointer(void *ptr);

#endif
