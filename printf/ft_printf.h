/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 03:27:11 by ykoseki           #+#    #+#             */
/*   Updated: 2023/07/14 03:31:37 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_printf_helper(char const *format, va_list args);
int		ft_string(char *str);
int		ft_char(char ch);
int		output_handler(char output_type, va_list args);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		digit_len(int n);
int		ft_integer(int n);
int		ft_percent(char ch);
int		ft_unsigned(unsigned int n);
int		ft_hexlower(unsigned int n);
int		ft_hexupper(unsigned int n);
int		ft_pointer(unsigned long long n);

#endif