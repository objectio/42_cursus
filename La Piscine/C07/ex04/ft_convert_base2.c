/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 05:02:26 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/15 06:00:40 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_white(char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

int		is_valid(char *base, int *len)
{
	int		check[256];
	int		i;
	char	c;

	i = 0;
	while (i < 256)
		check[i++] = 0;
	*len = 0;
	while (base[*len])
	{
		c = base[*len];
		if (check[(int)c] || c == '+' || c == '-' || is_white(c))
			return (0);
		check[(int)c] = 1;
		++*len;
	}
	if (*len <= 1)
		return (0);
	return (1);
}

int		nbr_size(long long nbr, int base_len)
{
	int result;

	if (!nbr)
		return (1);
	result = 0;
	if (nbr < 0)
		++result;
	while (nbr)
	{
		nbr /= base_len;
		++result;
	}
	return (result);
}
