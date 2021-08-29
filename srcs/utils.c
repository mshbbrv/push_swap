#include "../inc/pushswap.h"

void    remove_first_element(int **stack, size_t *len, t_data *data)
{
	int i;
	int *tmp;

	if (*stack)
	{
		if (*len > 1)
		{
			tmp = copy_stack(*stack, *len, data);
			free(*stack);
			(*len)--;
			*stack = malloc_stack(*len, data);
			i = -1;
			while (++i <= (int)*len)
				(*stack)[i] = tmp[i + 1];
			if (tmp)
				free(tmp);
		}
		else
		{
			free(*stack);
			*stack = NULL;
		}
	}
}

int is_sorted(int *stack, int len)
{
	int i;

	if (!stack)
		return (0);
	i = 0;
	while (++i < len)
	{
		if (stack[i] < stack[i - 1])
			return (0);
	}
	return (1);
}

int *malloc_stack(size_t len, t_data *data)
{
	int *stack;

	stack = (int *)malloc(sizeof(int) * len);
	if (!stack && error_handler(data))
		exit(1);
	return (stack);
}

int *copy_stack(int *stack, size_t len, t_data *data)
{
	int *copy;
	int i;

	if (!stack || !len)
		return (NULL);
	copy = malloc_stack(len, data);
	i = -1;
	while (++i < (int)len)
		copy[i] = stack[i];
	return (copy);
}

long	ft_atoi(const char *str)
{
	int			i;
	long long	result;
	long long	tmp;
	int			minus;

	minus = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i++] == '-')
		minus = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = result;
		result = result * 10 + (str[i++] - 48);
		if (tmp > result && minus > 0)
			return (-1);
		else if (tmp > result)
			return (0);
	}
	if (result > INT_MAX || result < INT_MIN)
		return (LONG_MAX);
	return (result * minus);
}