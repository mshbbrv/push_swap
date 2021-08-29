#include "../inc/pushswap.h"

void free_data(t_data *data)
{
	if (data)
	{
		if (data->a_stack)
			free(data->a_stack);
		if (data->b_stack)
			free(data->b_stack);
		free(data);
	}
}

int error_handler(t_data *data)
{
	puts("Error\n"); //TODO заменить на либфт STDERROR
	free_data(data);
	return (1);
}

int main(int argc, char *argv[])
{
	t_data *data;
	int i;

	data = malloc(sizeof(t_data));
	if (init_options(data, argc, argv))
		return (1);
	make_sort(data);
	i = -1;
	while (++i < (int)data->a_len)
		printf("%d ", data->a_stack[i]);
	printf("\n");
	free_data(data);
    return (0);
}