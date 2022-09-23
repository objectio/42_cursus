/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:31:03 by younjkim          #+#    #+#             */
/*   Updated: 2022/03/27 21:31:09 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_strjoinhelp(char *concs, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			concs[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		concs[i] = s2[j];
		i++;
		j++;
	}
	concs[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*concs;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	concs = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (concs == NULL)
		return (NULL);
	ft_strjoinhelp(concs, s1, s2);
	free(s1);
	return (concs);
}
