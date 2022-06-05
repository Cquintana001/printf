#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

int ft_putfloat(float num)
{

	int num1 = num;
	printf("%d\n", num1);

	return(num1);
	if((num-num1)>0)
	{
		
	}
}


int main()
{	 
	float x = 7.5;
	float d = x - ft_putfloat(x);
	printf("%f",d);
	return(0);

}