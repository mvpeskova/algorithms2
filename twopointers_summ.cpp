#include <iostream>

int main(int args, char* argv[])
{
	
	int n, k, i = 0, j = 0, sum = 0, start = 0, finish = 0, min_length = 1000000,  max_sum = -1;
	std::cin >> n >> k;
	int* array = new int[n];
	for (i; i < n; i++)
		std::cin >> array[i];
	sum = array[0];
	i = 0; 
	j = 0;
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		while (flag == 0 && j < n)
		{
			if (sum >= k)
			{
				if ((j - i < min_length) | (j - i == min_length && max_sum < sum))
				{
					max_sum = sum;
					min_length = j - i;
					start = i;
					finish = j;
				}
				flag = 1;
			}
			else
			{
				j++;
				sum = sum + array[j];
			}
		}
		sum = sum - array[i];
	}
	
	if (max_sum == -1)
		std::cout << "No summ";
	else
		std::cout << "Length = " << min_length + 1<< "\nSum = " << max_sum << "\nStart = " << start << "\nFinish = " << finish;
	delete[] array;
	array = 0;
}
