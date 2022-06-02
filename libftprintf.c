/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:05:20 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/02 17:58:48 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *s)
{	
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	write(fd, s, len);
}

int ft_printf(char const *array, ...)
{
	va_list ptr;
	int x;
	char *c;
	char d;
	x = 0;
	va_start(ptr, array);
	 while(array[x])
	 {
		 if(array[x]=='%')
		 {
			 
			x++;
			
			if(array[x ]=='s')
			{
			 	x++;
				c = va_arg(ptr, char*);
				ft_putstr_fd(c, 1);
		 	}
			if(array[x]=='c')
			{
				x++;
				d = va_arg(ptr, int);
				ft_putchar_fd(d, 1);
			}		 	

		 }
		 ft_putchar_fd(array[x], 1);
		x++;
	 }
	   
	 va_end(ptr);
	 

	 

	return 0;


}

int main()
{
	ft_printf("Quiero imprimir una string %s y una letra %c", "hola", 'h');

	return 0;
}