/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:06:41 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/10 20:47:46 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# define MININT -2147483648

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

typedef struct s_ps_data
{
	t_list	*a;
	t_list	*b;
	int		ac;
}	t_ps_data;

/* utilities */
int		invalid_input(int ac, char **av);
int		ft_atoi(const char *s);
int		init(int ac, char **av, t_ps_data *data);
void	free_mem(t_ps_data *data);
void	print_lists(t_ps_data *data);
int		stack_maxnum(t_list *list);

/* list functions */
t_list	*ft_lstnew(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	lst_clear(t_list **list);

/* push_swap operations */
void	swap(t_list *a, t_list *b);
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

#endif
