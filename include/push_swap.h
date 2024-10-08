/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:06:41 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/16 21:46:16 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf.h"
# define MININT -2147483648
# define MAXINT 2147483647

typedef struct s_list
{
	int				num;
	int				idx;
	int				rank;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_ps_data
{
	t_list	*a;
	t_list	*b;
	int		ac;
	char	**av;
	int		split_av;
	int		lena;
	int		lenb;
	int		*sorted_av;
}	t_ps_data;

/* stores the rotations needed for stack A & B*/
typedef struct s_rots
{
	int	cost_a;
	int	cost_b;
}	t_rots;

/* utilities */
int		invalid_input(int ac, char **av, t_ps_data *data);
int		ft_atoi(const char *s);
int		init(t_ps_data *data);
void	free_mem(t_ps_data *data);
void	print_lists(t_ps_data *data);
int		stack_maxnum(t_list *list);
int		stack_minnum(t_list *list);
void	quicksort(int *arr, int low, int high);
void	debug_print(t_ps_data *data);
int		int_abs(int n);
void	del_element(t_ps_data *data, int pos);
void	print_ranks(t_list *list);
int		replace_av(char **av, t_ps_data *data);
int		contains_space(char *s);
int		numlen(long int n);

/* list functions */
t_list	*ft_lstnew(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	lst_clear(t_list **list);
t_list	*lst_last(t_list *list);

/* push_swap operations */
void	sa(t_ps_data *data);
void	sb(t_ps_data *data);
void	ss(t_ps_data *data);
void	pa(t_ps_data *data);
void	pb(t_ps_data *data);
void	ra(t_ps_data *data);
void	rb(t_ps_data *data);
void	rr(t_ps_data *data);
void	rra(t_ps_data *data);
void	rrb(t_ps_data *data);
void	rrr(t_ps_data *data);

/* Sorting algo */
void	sort(t_ps_data *data);
t_rots	get_rots(t_ps_data *data, int n, int rank, int is_to_b);
int		rotations(t_list *list, int listlen, int n);
void	execute_rots_1(t_ps_data *data, t_rots rots);
int		ops_needed(t_rots rots);
int		get_pos(t_list *list, int n);
void	to_b(t_ps_data *data);
void	to_a(t_ps_data *data);
int		a_solvable(t_ps_data *data);
void	clean_a(t_ps_data *data);
int		get_optimal_pos_a(t_list *list, int listlen, int rank);

#endif
