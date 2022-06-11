/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsignedinteger.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:13:51 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/11 12:00:01 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "ft_printf.h"

int printunsignedinteger(unsigned long int c)
{
	int len;
	char *ptr;

	ptr = ft_itoa2(c);
	len = (ft_strlen(ptr));
	write(1,ptr,len);
	free(ptr);
	return(len);
}
int	static	ft_itoa_get_size(unsigned long int t)
{
	int		size;

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
	char	*ptr;
	int		size;
	unsigned  long	t;

	t = n;
	size = ft_itoa_get_size(t);
	 
	ptr = (char *)malloc(sizeof(char) * size +1);
	if (!ptr)
	{	free(ptr);
		return (NULL);
	}
	if (t < 0)
	{
		ptr[0] = '-';
		t *= -1;
	}
	ptr[size] = '\0';
	while (t >= 10)
	{
		ptr[size - 1] = (t % 10) + '0';
		t = (t - t % 10) / 10;
		size--;
	}
	ptr[size - 1] = t + '0';
	return (ptr);
}