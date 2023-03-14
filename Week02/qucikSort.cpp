#include <iostream>

void	arr_swap(int *a, int idx1, int idx2)
{
	int	tmp;

	tmp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = tmp;
}

int	partition(int *a, int low, int high)
{
	int	cur;
	int	pi;
	int	pivot_val;

	pivot_val = a[(low + high) / 2];
	arr_swap(a, (low + high) / 2, high);
	cur = low;
	pi = low;
	while (cur < high)
	{
		if (a[cur] <= a[high])
			arr_swap(a, pi++, cur);
		cur++;
	}
	arr_swap(a, high, pi);
	return (pi);
}

void	quick_sort(int *a, int low, int high)
{
	int	pi;

	if (low >= high)
		return ;
	pi = partition(a, low, high);
	quick_sort(a, low, pi - 1);
	quick_sort(a, pi + 1, high);
}

int	main(void)
{
	int		find[10] = { 3 , 0 , -1 , 5 , 11 , 12 , 15 , 20 , -20, -17};
	int	i;

	quick_sort(find, 0, 9);
	i = -1;
	while (++i < 9)
		printf("%d ", find[i]);
	printf("\n");
}