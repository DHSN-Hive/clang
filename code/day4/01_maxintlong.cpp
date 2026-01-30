#include<iostream>

int main()
{
	int i=1;
	long l=1;
	int prev_i = 0;

	while(prev_i < i)
	{
		prev_i = i;
		i = i * 2;
	}	
	
	std::cout << "i: " << i << std::endl;
	std::cout << "l: " << l << std::endl;

	int max_int = prev_i + i;

	std::cout << "Max int value: " << max_int << std::endl;

	return 0;
}
