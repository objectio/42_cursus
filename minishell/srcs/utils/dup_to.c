/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:19:43 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/22 09:48:17 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_dup_to_double(char *str)
{
	char	**s;

	s = (char **)malloc(sizeof(char *) * (2));
	s[0] = ft_strdup(str);
	s[1] = NULL;
	return (s);
}

char	**ft_dup_to_double_e(char *str)
{
	char	**s;

	s = (char **)malloc(sizeof(char *) * (3));
	s[0] = ft_strdup("export");
	s[1] = ft_strdup(str);
	s[2] = NULL;
	return (s);
}
