/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:02:35 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/11 12:33:54 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <unistd.h>

int	printstring(char *array)
{
	int	x;

	if (array)
	{
		ft_putstr_fd(array, 1);
		x = ft_strlen(array);
		return (x);
	}
	else
		write(1, "(null)", 6);
	return (6);
}
