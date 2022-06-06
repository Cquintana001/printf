/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:05:20 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/06 11:51:28 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "./Libft/libft.h"
#include <stdlib.h>

 
 int ft_putptr(unsigned long int ptr, char *base, int *counter)
 {
	counter++; 
	unsigned long int x;
	char *line;
	int j;

	x=0;
	line =malloc(17);
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
		 j= ft_strlen(line)+2;
		 return(j);
 }

 int ft_putstring(char *array, int *index)
 {
	    *index+=1;
	 int x;

 
	 ft_putstr_fd(array,1);
	 x = ft_strlen(array);
	 return(x);
 }

int ft_printfchar(int c, int *index)
{
	*index+=1;
	ft_putchar_fd(c, 1);
	return(1);
}

int printfint(unsigned long int c,int *index )
{
	int len;

	*index+=01;
	len = ft_strlen(ft_itoa(c));
	write(1,ft_itoa(c),len);
	return(len);
}

int unsignedprintfint(unsigned long int c,int *index)
{
	if(c<0)
	 c = c * -1;
	return(printfint(c, index));
}

 int ft_printf(char const *array, ...)
{
	va_list ptr;
	unsigned long int prueba;
	int x;	   
	char d;
	 

	x = 0;
	va_start(ptr, array);
	 while(array[x])
	 {
		 if(array[x]=='%')
		 {			 
			x++;			
			if(array[x]=='s')
				ft_putstring((va_arg(ptr, char*)), &x);
			if(array[x]=='c')
				ft_printfchar((va_arg(ptr, int)), &x);	 	
			if(array[x]=='p')
				ft_putptr((va_arg(ptr, unsigned long int)), "0123456789abcdef", &x);
			if(array[x]=='d' ||array[x]=='i' )
				printfint(va_arg(ptr, unsigned long int), &x);			 
			if(array[x]=='u')
				unsignedprintfint(va_arg(ptr, unsigned long int), &x);
			if(array[x]=='x')				 
				ft_putptr((va_arg(ptr, unsigned long int)), "0123456789abcdef",&x);		
			if(array[x]=='X')	 
				ft_putptr((va_arg(ptr, unsigned long int)), "0123456789ABCDEF", &x);
			if(array[x]=='%')				 
			  	  write(1,"%",1);		 		 	
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
	
	 void *ptr;

	  
	ft_printf("%s %% otro entero %i hexa %p hexa mayuscula %X" ,"hola", 6, ptr, ptr);



	return 0;
}

