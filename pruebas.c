
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "./Libft/libft.h"
#include <stdlib.h>


 int printinteger(long long int c)
{
	int len;
	char *ptr;
	printf("la funcion da %llu\n", c);
	ptr = ft_itoa(c);
	 
	len = ft_strlen(ptr);
	write(1,ptr,len);
	free(ptr);
	return(len);
}

int printunsignedinteger(unsigned long long int c)
{
	 
	 printf("la funcion da %llu\n", c);
	 
	return(printinteger(c));
}
int ft_printf(char const *array, ...)
{
	va_list ptr; 
	int x;
	int bytes= 0;

	x = 0;
	va_start(ptr, array);
	 while(array[x])
	 {
		 if(array[x]=='%')
		 {			 
			x++;			
			if(array[x]=='u')
				bytes += printunsignedinteger(va_arg(ptr, unsigned long long int));
			x++;	 		 	
		 }
		 else
		 {
		 	ft_putchar_fd(array[x], 1);
			x++;
			bytes++;
		 }		 
	 }	   
	 va_end(ptr);
	return (bytes);
} 

int main()
{	
	int bytes;

	bytes = 0;
	  
	  
	  	bytes = ft_printf("%u", -10);;
		  printf("\nbytes ft_printf: %d", bytes);

		 bytes = printf("\n%u", -10);  
		 printf("\nbytes printf: %d", bytes);
		 /* test_printf("%u", 0);
		test_printf("%u", -10);
		test_printf("%u", -200000);
		test_printf("%u", -6000023);
		test_printf("%u", 10);
		test_printf("%u", 10000);
		test_printf("%u", 100023);
		test_printf("%u", INT_MAX);
		test_printf("%u", INT_MIN);
		test_printf("%u", UINT_MAX);
		test_printf("dgs%uxx", 10);
		test_printf("%u%uu%u", 1, 2, -3); */
	 
	return 0;
		 
}