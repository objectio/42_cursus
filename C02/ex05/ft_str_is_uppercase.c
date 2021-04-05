/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:24:05 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/05 15:26:52 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_up(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int		ft_str_is_uppercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_is_up(str[i++]) != 1)
			return (0);
	}
	return (1);
}
