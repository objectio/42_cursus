/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:44:03 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/22 09:48:34 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_checkinenv(int *j, int *i, char *s)
{
	while (!ft_strstr(g_glob.g_env[*j], s))
	{
		if (g_glob.g_env[*j + 1] == NULL)
		{
			*i = 1;
			break ;
		}
		*j = *j + 1;
	}
}

static char	*ft_return(char *s)
{
	ft_single_free(s);
	return (ft_strdup(""));
}

static int	ft_checkcondition(char *str)
{
	if (!ft_strcmp(str, "$\'") || !ft_strcmp(str, "$ ")
		|| !ft_strcmp(str, "$=") || !ft_strcmp(str, "$$"))
		return (0);
	return (1);
}

static char	*ft_weirdcondition(char *str)
{
	if (!ft_strcmp(str, "$\'") || !ft_strcmp(str, "$ ")
		|| !ft_strcmp(str, "$=") || !ft_strcmp(str, "$$"))
	{
		if (!ft_strcmp(str, "$$"))
			return (ft_itoa(59040));
		return (ft_strdup(str));
	}
	return (str);
}

char	*ft_expand(char *str, int i, int j)
{
	char	*s;
	char	*trim;

	if (ft_strstr(str, "$?"))
		return (ft_itoa(g_glob.error));
	if (ft_checkcondition(str) == 0)
		return (ft_weirdcondition(str));
	trim = ft_strtrim(str, "$");
	s = ft_strjoin(trim, "=");
	free(trim);
	if (str[i] == '$' && !(str[i + 1] == ' ' || str[i + 1] == '\0'))
	{
		ft_checkinenv((int *)&j, (int *)&i, s);
		if (i == 0)
		{
			trim = ft_substr(g_glob.g_env[j], (int)ft_strlen(s),
					(int)(ft_strlen(g_glob.g_env[j]) - ft_strlen(s)));
			free(s);
			return (trim);
		}
		else
			return (ft_return(s));
	}
	ft_single_free(s);
	return (str);
}
