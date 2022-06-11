/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:24:11 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/11 12:29:43 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "./Libft/libft.h"

int		ft_printf_xxp(uintptr_t x, char type, int *len);
int		ft_printf(char const *str, ...);
int		ft_check_flag(va_list list, const char c, int *len);
int		printchar(int c);
int		printstring(char *array);
int		printinteger(int c);
int		printunsignedinteger(unsigned long int c);
void	printhexa(uintptr_t x, char *base, int *len);
char	*ft_itoa2(unsigned long int n);

#endif