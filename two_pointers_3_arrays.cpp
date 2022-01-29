#include <iostream>

int max_v(int a, int b, int c)
{
	if (a >= b && a >= c)
		return a;
	if (b >= a && b >= c)
		return b;
	if (c >= a && c >= b)
		return c;
}

int diff(int max, int array, int res)
{
	if (max - array < res)
		return max - array;
	return res;
}

void init(int array[], int a, int b, int c)
{
	array[0] = a;
	array[1] = b;
	array[2] = c;
}


int main(int args, char* argv[])
{
	int array[3];
	int n1, n2, n3, max, min, flag, result = 10000, i = 0, j = 0, k = 0;
	std::cin >> n1;
	int* array1 = new int[n1];
	for (i; i < n1; i++)
		std::cin >> array1[i];
	std::cin >> n2;
	int* array2 = new int[n2];
	for (j; j < n2; j++)
		std::cin >> array2[j];
	std::cin >> n3;
	int* array3 = new int[n3];
	for (k; k < n3; k++)
		std::cin >> array3[k];
	i = 0, j = 0, k = 0;
	while (i != n1 && j != n2 && k != n3)
	{
		flag = 0;
		max = max_v(array1[i], array2[j], array3[k]);
		if (array3[k] <= array1[i] && array3[k] <= array2[j])
		{
			if (diff(max, array3[k], result) < result)
			{
				init(array, array1[i], array2[j], array3[k]);
				result = diff(max, array3[k], result);
			}
			k++;
			flag = 1;
		}
		if (array2[j] <= array1[i] && array2[j] <= array3[k] && flag == 0)
		{
			if (diff(max, array2[j], result) < result)
			{
				init(array, array1[i], array2[j], array3[k]);
				result = diff(max, array2[j], result);
			}
			j++;
			flag = 1;
		}
		if (array1[i] <= array2[j] && array1[i] <= array3[k] && flag == 0)
		{
			if (diff(max, array1[i], result) < result)
			{
				init(array, array1[i], array2[j], array3[k]);
				result = diff(max, array1[i], result);
			}
			i++;
		}
	}
