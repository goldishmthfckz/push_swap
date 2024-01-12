/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:01:08 by estegana          #+#    #+#             */
/*   Updated: 2023/10/06 12:01:10 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_printf(const char *format, ...);
int		ft_nbrlen(int n);
char	*ft_itoa(int n);
int		ft_putnbr(int nb);
int		ft_unslen(unsigned int num);
char	*ft_unsitoa(unsigned int nb);
int		ft_putuns(unsigned int nb);
int		ft_printptr(unsigned long p);
int		ft_nblen(unsigned int nb);
void	ft_printhexa(unsigned int nb, char c);
int		convert_hexa(unsigned int nb, char c);

#endif
