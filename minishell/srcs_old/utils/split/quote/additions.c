/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:36:04 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/22 09:49:04 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	ft_check_inloop(char *str, int i, int *x, int *k)
{
	if (str[i] == '$')
	{
		*x = 1;
		*k = 0;
	}
	else if (str[i] != '$' && *x != 1)
		*k = 1;
}

int	ft_success(char *str, int i, int k, int x)
{
	if (!ft_strstr(str, "$"))
		return (2);
	while (str[i])
	{
		if (str[i] == '\"')
			while (str[++i] != '\"')
				k = 1;
		if (str[i] == '\'')
		{
			x = 0;
			while (str[++i] != '\'')
				ft_check_inloop(str, i, (int *)&x, (int *)&k);
		}
		if (str[i] == '$')
			k = 1;
		if ((str[i] != '\'' || str[i] != '\"') && str[i])
			i++;
	}
	return (k);
}

static void	ft_looperdollar(char *str, int *i, int *w)
{
	*w = 1;
	*i = *i + 1;
	if (str[*i] == '=' || str[*i] == '$' || str[*i] == ' ' || str[*i] == '\'')
	{
		*w = *w + 1;
		*i = *i + 1;
		return ;
	}
	while (str[*i] && (str[*i] != ' ' && str[*i] != '\''
			&& str[*i] != '\"' && str[*i] != '=' && str[*i] != '$'))
	{
		*w = *w + 1;
		*i = *i + 1;
	}
}

int	ft_dollarlen(char *str, int j, int w, int k)
{
	int		i;
	int		x;
	char	*p;
	char	*p2;

	i = 0;
	x = 0;
	while (str[i])
	{
		if ((str[i] == '$' && str[i + 1]) && k == 1)
		{
			ft_looperdollar(str, (int *)&i, (int *)&w);
			p2 = ft_substr(str, (i - w), w);
			p = ft_expand(p2, 0, 0);
			x += ft_strlen(p);
			free(p2);
			free(p);
		}
		else
		{
			j++;
			i++;
		}
	}
	return (j + x);
}

void	ft_dollardup(char *str, char *aux, int w, int k)
{	
	int		i;
	int		j;
	char	*temp;
	char	*p;

	i = 0;
	j = 0;
	while (str[i])
	{
		w = 0;
		if ((str[i] == '$' && str[i + 1]) && k == 1)
		{
			ft_looperdollar(str, (int *)&i, (int *)&w);
			p = ft_substr(str, (i - w), w);
			temp = ft_expand(p, 0, 0);
			free(p);
			w = 0;
			while (temp[w])
				aux[j++] = temp[w++];
			free(temp);
		}
		else
			aux[j++] = str[i++];
	}
	ft_single_free(str);
}
