#include "../inc/pushswap.h"

void    rrr(t_data *data)
{
	rra_blanc(data);
	rrb_blanc(data);
	write(STDOUT_FILENO, "rrr\n", 4);
}

void    ra_blanc(t_data *data)
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
	}
}

void    rb_blanc(t_data *data)
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
	}
}

void    rra_blanc(t_data *data)
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
	}
}

void    rrb_blanc(t_data *data)
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
	}
}
