/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:13:08 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/11 12:32:58 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

int	printinteger(int c)
{
	int		len;
	char	*ptr;

	ptr = ft_itoa(c);
	len = (ft_strlen(ptr));
	write(1, ptr, len);
	free(ptr);
	return (len);
}
