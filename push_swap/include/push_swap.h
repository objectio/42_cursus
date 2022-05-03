/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:28:38 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/23 13:37:44 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_ps
{
	char	**a;
	int		*aint;
	char	**b;
	int		argc;
}	t_ps;

void	sa(t_ps *data);
void	sb(t_ps *data);
void	ss(t_ps *data);
void	ra(t_ps *data, int mode);
void	rb(t_ps *data, int mode);
void	rr(t_ps *data);
void	rra(t_ps *data, int mode);
void	rrb(t_ps *data, int mode);
void	rrr(t_ps *data);
void	pa(t_ps *data);
void	error(char *s);
void	solve_med(t_ps *data);
void	solve_easy(t_ps *data);
void	solve_hard(t_ps *data);
void	move_rev(t_ps *data);
int		i_or_j(int i, int j);
int		move_b(t_ps *data);
int		pb(t_ps *data);
int		find_big(t_ps *data);
int		is_solved(t_ps *data);
int		check_argv(t_ps *data, char **argv);
int		rev_sort(t_ps *data);

#endif
