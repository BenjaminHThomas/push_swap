/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:06:41 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/10 10:47:02 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

/* list functions */
t_list	*ft_lstnew(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	lst_clear(t_list **list);

#endif
