/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:29:36 by pmolzer           #+#    #+#             */
/*   Updated: 2023/11/22 14:09:36 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
// # include <stdio.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *str, ...);

/* format functions */
void	ft_putchar_printf(char c, size_t *counter);
void	ft_putstr_printf(char *str, size_t *counter);
void	ft_putnbr_printf(int num, size_t *counter);
void	ft_putuint_printf(unsigned int num, size_t *counter);
void	ft_puthex_printf(unsigned int num, size_t *counter, char *base);
void	ft_putptr_printf(void *ptr, size_t *counter);

/* auxiliary functions */
char	*ft_aux_printf(unsigned long long n, char *base);

#endif
