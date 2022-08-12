/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:30:31 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/24 11:37:12 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_free_all(char **split, char *s, char *temp)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	free(s);
	free(temp);
	return (NULL);
}

static char	*ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (NULL);
}

static char	**ft_split_path(char *s)
{
	char	**split;

	s = ft_strtrim_begin(s, "PATH="); // PATH 떼고 : 기준으로 분리 /usr/local/bin  /usr/bin   /bin
	split = ft_split(s, ':');
	free(s);
	return (split);
}

static char	*ft_look_in_env(int i, int *x, char *temp)
{
	while (g_glob.g_env[++i])
	{
		if (!ft_strncmp(g_glob.g_env[i], "PATH=", 5))
		{
			*x = 1;
			temp = g_glob.g_env[i];
		}
	}
	return (temp);
}

char	*ft_get_path(char *s, int i, int x, char *join)
{    // s = shell->split[0], i = -1, x = 0, join = NULL
	char	**split;
	char	*temp;

	temp = ft_look_in_env(i, (int *)&x, NULL); // env에 PATH=가 있는지 찾고 리턴 / temp = PATH=/usr/local ......
	if (!temp || x == 0)
		return (NULL);
	split = ft_split_path(temp);
	s = ft_strjoin("/", s);
	i = -1;
	while (split[++i])
	{
		join = ft_strjoin(split[i], s);
		if (!access(join, X_OK))
		{
			ft_free_split(split);
			return (join);
		}
		free(join);
	}
	return (ft_free_all(split, s, temp));
}
