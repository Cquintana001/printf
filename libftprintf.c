/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:05:20 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/11 12:17:04 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "./Libft/libft.h"
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

int	ft_check_flag(va_list list, const char c, int *len)
{
	if (c == 'c')
		*len += printchar(va_arg(list, int));
	else if (c == '%')
		*len += printchar('%');
	else if (c == 's')
		*len += printstring(va_arg(list, char *));
	else if (c == 'p')
		ft_printf_xxp(va_arg(list, unsigned long long int), 'p', len);
	else if (c == 'd' || c == 'i')
		*len += printinteger(va_arg(list, int));
	else if (c == 'u')
		*len += printunsignedinteger(va_arg(list, unsigned int));
	else if (c == 'x')
		ft_printf_xxp(va_arg(list, unsigned long long int), 'x', len);
	else if (c == 'X')
		ft_printf_xxp(va_arg(list, unsigned long int), 'X', len);
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	list;

	i = 0;
	len = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_check_flag(list, str[++i], &len);
		else
			len += printchar(str[i]);
		i++;
	}
	va_end(list);
	return (len);
}
