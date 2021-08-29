#include "../inc/pushswap.h"

void    len_2(t_data *data)
{
	if (!is_sorted(data->a_stack, data->a_len))
		sa(data);
}

void    len_3(t_data *data)
{
	if (data->a_stack[0] > data->a_stack[1])
	{
		if (data->a_stack[1] < data->a_stack[2])
		{
			if (data->a_stack[2] > data->a_stack[0])
				sa(data);
			else
				ra(data);
		}
		else
		{
			sa(data);
			rra(data);
		}
	}
	else if (data->a_stack[0] < data->a_stack[2])
	{
		sa(data);
		ra(data);
	}
	else
		rra(data);
}

void    len_4(t_data *data)
{

}

void    make_sort(t_data *data)
{
	if (data->a_len == 2)
		len_2(data);
	else if (data->a_len == 3)
		len_3(data);
	else if (data->a_len == 4)
		len_4(data);
}