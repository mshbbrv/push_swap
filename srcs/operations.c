#include "../inc/pushswap.h"

void    sa(t_data *data)
{
	int tmp;

	if (data->a_len > 1)
	{
		tmp = data->a_stack[0];
		data->a_stack[0] = data->a_stack[1];
		data->a_stack[1] = tmp;
	}
	write(STDOUT_FILENO, "sa\n", 3);
}

void    sb(t_data *data)
{
	int tmp;

	if (data->b_len > 1)
	{
		tmp = data->b_stack[0];
		data->b_stack[0] = data->b_stack[1];
		data->b_stack[1] = tmp;
	}
	write(STDOUT_FILENO, "sb\n", 3);
}

void    ss(t_data *data)
{
	int tmp;

	if (data->a_len > 1)
	{
		tmp = data->a_stack[0];
		data->a_stack[0] = data->a_stack[1];
		data->a_stack[1] = tmp;
	}
	if (data->b_len > 1)
	{
		tmp = data->b_stack[0];
		data->b_stack[0] = data->b_stack[1];
		data->b_stack[1] = tmp;
	}
	write(STDOUT_FILENO, "ss\n", 3);
}

void    pa(t_data *data)
{
	int *tmp;
	int i;

	if (data->b_stack && data->b_len > 0)
	{
		tmp = copy_stack(data->a_stack, data->a_len, data);
		if (data->a_stack)
		{
			free(data->a_stack);
			data->a_stack = NULL;
		}
		data->a_len += 1;
		data->a_stack = malloc_stack(data->a_len, data);
		i = 0;
		data->a_stack[i] = data->b_stack[0];
		remove_first_element(&data->b_stack, &data->b_len, data);
		while (tmp && ++i < (int)data->a_len)
			data->a_stack[i] = tmp[i];
		if (tmp)
			free(tmp);
		write(STDOUT_FILENO, "pa\n", 3);
	}
}

void    pb(t_data *data)
{
	int *tmp;
	int i;

	if (data->a_stack && data->a_len > 0)
	{
		tmp = copy_stack(data->b_stack, data->b_len, data);
		if (data->b_stack)
		{
			free(data->b_stack);
			data->b_stack = NULL;
		}
		data->b_len += 1;
		data->b_stack = malloc_stack(data->b_len, data);
		i = 0;
		data->b_stack[i] = data->a_stack[0];
		remove_first_element(&data->a_stack, &data->a_len, data);
		while (tmp && ++i < (int)data->b_len)
			data->b_stack[i] = tmp[i];
		if (tmp)
			free(tmp);
		write(STDOUT_FILENO, "pb\n", 3);
	}
}