/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:05:20 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/03 13:54:45 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "./Libft/libft.h"

 
 int ft_printf(char const *array, ...)
{
	va_list ptr;
	int x;
	  int num;
	char d;
	 char *c;
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
			if(array[x]=='p')
			{
				x++;
			  	num = va_arg(ptr,  int);
				ft_putnbr_fd( num, 1);
			}		 	
		 }
		 else
		 {
		 	ft_putchar_fd(array[x], 1);
			x++;
		 }
		 
	 }
	   
	 va_end(ptr);
	 

	 

	return 0;


} 

int main()
{	

	 void *pt;

	 unsigned long int x = pt;

	 printf("el puntero es %p\n", pt);
	   
	 
	ft_printf("string %s letra %c puntero %p", "hola", 'h', pt);



	return 0;
}

 int ft_putptr(unsigned long int ptr, char*base)
 {
	 int index;

	 while(ptr>0)
	 {
		 
		 index = ptr%16;
		 ptr = ptr/16;
		 write(1,base[index-1],1)
		 
	 }

 }