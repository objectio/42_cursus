/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:31:08 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/05 17:05:45 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_word(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	if ('A' <= c && c <= 'Z')
		return (1);
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int		is_up(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int		is_low(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int is_first;

	if (is_word(str[0]) && is_low(str[0]))
		str[0] = str[0] - 32;
	i = 1;
	while (str[i])
	{
		if (!(is_word(str[i - 1])) && is_word(str[i]))
			is_first = 0;
		else
			is_first++;
		if (is_first == 0 && is_low(str[i]))
			str[i] = str[i] - 32;
		if (is_first != 0 && is_up(str[i]))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
