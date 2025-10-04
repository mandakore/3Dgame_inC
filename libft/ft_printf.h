/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:49:07 by atashiro          #+#    #+#             */
/*   Updated: 2024/11/22 19:54:57 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *string, ...);
int		ft_check(va_list arg, char format, int *count);
int		ft_putstr(char *s, int *count);
void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putunbr(unsigned int n, int *count);
void	ft_puthex(unsigned int nbr, char c, int *count);
int		ft_print_address(unsigned long long address, int *count);
void	ft_putnbr_ptr(unsigned long long address, int *count);

#endif