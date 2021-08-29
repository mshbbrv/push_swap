#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_data   t_data;

struct s_data
{
	int     *a_stack;
	size_t  a_len;
	size_t  b_len;
	int     *b_stack;
};

int     init_options(t_data *data, int argc, char *argv[]);
int     error_handler(t_data *data);
long    ft_atoi(const char *str);
int     *copy_stack(int *stack, size_t len, t_data *data);
int     *malloc_stack(size_t len, t_data *data);
int     is_sorted(int *stack, int len);
void    remove_first_element(int **stack, size_t *len, t_data *data);
void    make_sort(t_data *data);
void    sa(t_data *data);
void    sb(t_data *data);
void    ss(t_data *data);
void    pa(t_data *data);
void    pb(t_data *data);
void    ra(t_data *data);
void    rb(t_data *data);
void    rr(t_data *data);
void    rra(t_data *data);
void    rrb(t_data *data);
void    rrr(t_data *data);
void    ra_blanc(t_data *data);
void    rb_blanc(t_data *data);
void    rra_blanc(t_data *data);
void    rrb_blanc(t_data *data);
#endif
