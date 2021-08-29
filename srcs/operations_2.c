#include "../inc/pushswap.h"

void    ra(t_data *data)
{
	int *tmp;
	int i;

	if (data->a_stack && data->a_len > 1)
	{
		tmp = copy_stack(data->a_stack, data->a_len, data);
		i = -1;
		while (++i < (int)data->a_len)
		{
			if (i == (int)data->a_len - 1)
				data->a_stack[i] = tmp[0];
			else
				data->a_stack[i] = tmp[i + 1];
		}
		if (tmp)
			free(tmp);
		write(STDOUT_FILENO, "ra\n", 3);
	}
}

void    rb(t_data *data)
{
	int *tmp;
	int i;

	if (data->b_stack && data->b_len > 1)
	{
		tmp = copy_stack(data->b_stack, data->b_len, data);
		i = -1;
		while (++i < (int)data->b_len)
		{
			if (i == (int)data->b_len - 1)
				data->b_stack[i] = tmp[0];
			else
				data->b_stack[i] = tmp[i + 1];
		}
		if (tmp)
			free(tmp);
		write(STDOUT_FILENO, "rb\n", 3);
	}
}

void    rr(t_data *data)
{
	ra_blanc(data);
	rb_blanc(data);
	write(STDOUT_FILENO, "rr\n", 3);
}

void    rra(t_data *data)
{
	int *tmp;
	int i;

	if (data->a_stack && data->a_len > 1)
	{
		tmp = copy_stack(data->a_stack, data->a_len, data);
		i = -1;
		while (++i < (int)data->a_len)
		{
			if (i == 0)
				data->a_stack[i] = tmp[data->a_len - 1];
			else
				data->a_stack[i] = tmp[i - 1];
		}
		if (tmp)
			free(tmp);
		write(STDOUT_FILENO, "rra\n", 4);
	}
}

void    rrb(t_data *data)
{
	int *tmp;
	int i;

	if (data->b_stack && data->b_len > 1)
	{
		tmp = copy_stack(data->b_stack, data->b_len, data);
		i = -1;
		while (++i < (int)data->b_len)
		{
			if (i == 0)
				data->b_stack[i] = tmp[data->b_len - 1];
			else
				data->b_stack[i] = tmp[i - 1];
		}
		if (tmp)
			free(tmp);
		write(STDOUT_FILENO, "rrb\n", 4);
	}
}
