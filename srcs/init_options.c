#include "../inc/pushswap.h"

int is_duplicate(int *stack, int i, int num)
{
	while (i >= 0)
	{
		if (num == stack[i])
			return (1);
		i--;
	}
	return (0);
}

int	parse_stack(t_data *data, int argc, char *argv[])
{
	int     i;
	long    tmp;

	data->a_len = argc - 1;
	data->a_stack = malloc_stack(data->a_len, data);
	i = -1;
	while (++i < (int)data->a_len)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (tmp == LONG_MAX || is_duplicate(data->a_stack, i - 1, (int)tmp))
			return (error_handler(data));
		else
			data->a_stack[i] = (int)tmp;
	}
	return (0);
}

int	is_option_digit(int argc, char *argv[], t_data *data)
{
	int	i;
	int	k;

	i = 0;
	while (++i < argc)
	{
		k = -1;
		while (argv[i][++k])
			if (argv[i][k] < '0' || argv[i][k] > '9')
				return (error_handler(data));
	}
	return (0);
}

void	init_data(t_data *data)
{
	data->a_stack = NULL;
	data->b_stack = NULL;
	data->a_len = 0;
	data->b_len = 0;
}

int	init_options(t_data *data, int argc, char *argv[])
{
	init_data(data);
	if (is_option_digit(argc, argv, data))
		return (1);
	if (parse_stack(data, argc, argv))
		return (1);
	return (0);
}
