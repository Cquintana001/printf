/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xxp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:05:01 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/11 12:23:33 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "./Libft/libft.h"
#include "printf.h"
#include <unistd.h>

int	printchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

void	printhexa(uintptr_t x, char *base, int *len)
{
	if (x / 16 != 0)
		printhexa(x / 16, base, len);
	*len += printchar(base[x % 16]);
}

int	ft_printf_xxp(uintptr_t x, char type, int *len)
{
	if (type == 'p')
	{
		*len += write(1, "0x", 2);
		if (x == 0)
			return (*len += write(1, "0", 1));
		printhexa(x, "0123456789abcdef", len);
	}
	if (type == 'x')
	{
		if (x == 0)
			return (*len += write(1, "0", 1));
		printhexa((unsigned int)x, "0123456789abcdef", len);
	}
	if (type == 'X')
	{
		if (x == 0)
			return (*len += write(1, "0", 1));
		printhexa((unsigned int)x, "0123456789ABCDEF", len);
	}
	return (0);
}
