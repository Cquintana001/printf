/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:05:20 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/05 13:31:02 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "./Libft/libft.h"
#include <stdlib.h>

 
 void ft_putptr(unsigned long int ptr, char *base)
 {
	  
	 unsigned long int x = 0;
	char *line = malloc(17);
	 int j;
	 j = 0;
		 
		 while(ptr>0)
		 {
			x = ptr%16;
		 	ptr = ptr/16;
			 line[j]=base[x]; 
			j++;
		 }
		 line[j] = '\0';
		  j--;
		  write(1,"0X",2);
		 while(j>=0)
		 {
			 write(1,&line[j],1);
			 j--;
		 } 
	  
	 

 }

 int ft_printf(char const *array, ...)
{
	va_list ptr;
	unsigned long int prueba;
	int x;
	   
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
			  	  prueba =  va_arg(ptr, unsigned long int);
				ft_putptr(prueba, "0123456789abcdef");
			}
			if(array[x]=='d')
			{
				x++;
			  	  prueba =  va_arg(ptr, unsigned long int);
				printf("%s",ft_itoa(prueba));
			}
			if(array[x]=='i')
			{
				x++;
			  	  prueba =  va_arg(ptr, unsigned long int);
				ft_putptr(prueba, "0123456789abcdef");
			}
			if(array[x]=='u')
			{
				x++;
			  	  prueba =  va_arg(ptr, unsigned long int);
				ft_putptr(prueba, "0123456789abcdef");
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
	
	 

	  
	ft_printf("%d" ,5);



	return 0;
}

