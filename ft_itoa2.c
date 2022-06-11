/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:11:12 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/11 12:22:10 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include "./Libft/libft.h"
#include "printf.h"

int static	ft_itoa_get_size(unsigned long int t)
{
	int	size;

	size = 0;
	if (t < 0)
	{
		t *= -1;
		size++;
	}
	while (t >= 10)
	{
		t = (t - t % 10) / 10;
		size++;
	}
	size++;
	return (size);
}

char	*ft_itoa2(unsigned long int n)
{
	char			*ptr;
	int				size;

	size = ft_itoa_get_size(n);
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	ptr[size] = '\0';
	while (n >= 10)
	{
		ptr[size - 1] = (n % 10) + '0';
		n = (n - n % 10) / 10;
		size--;
	}
	ptr[size - 1] = n + '0';
	return (ptr);
}
