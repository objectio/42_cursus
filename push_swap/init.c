/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:07:12 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/16 21:06:23 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *n)
{
	int		i;

	i = 0;
	if (n[i] == '-')
		i++;
	while (n[i] != '\0')
	{
		if (!ft_isdigit(n[i]))
			return (0);
		i++;
	}
	if (ft_atoi(n) < 2147483648 && ft_atoi(n) >= -2147483648)
		return (1);
	return (0);
}

static int	is_repeat(char **argv, char *s)
{
	int		count;
	int		i;

	count = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == ft_atoi(s))
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	return (1);
}

static void	init_stack_a(t_ps *data, char **argv)
{
	int		i;

	data->a = (char **)malloc(sizeof(char *) * (data->argc));
	data->b = (char **)malloc(sizeof(char *));
	if (!data->a || !data->b)
		error("Err");
	i = 1;
	while (argv[i])
	{
		data->a[i - 1] = argv[i];
		i++;
	}
	data->a[i - 1] = NULL;
	data->b[0] = NULL;
}

int	check_argv(t_ps *data, char **argv)
{
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (!is_int(argv[i]) || !is_repeat(argv, argv[i]))
			stderr("Error\n");
		i++;
	}
	init_stack_a(data, argv);
	return (1);
}
