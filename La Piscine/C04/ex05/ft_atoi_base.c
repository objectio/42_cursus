/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:05:39 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/10 14:07:42 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		whilte_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
			|| c == '\f' || c == '\v')
		return (1);
	return (0);
}

int		is_valid(char *str)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (0);
	while (*ptr)
	{
		if (whilte_space(*ptr) == 1 || *ptr == '+' || *ptr == '-')
			return (0);
		ptr++;
	}
	i = 0;
	while (i < ptr - str)
	{
		j = i + 1;
		while (j < ptr - str)
			if (str[i] == str[j++])
				return (0);
		i++;
	}
	return (1);
}

int		base_answer(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int len;
	int num;
	int sign;
	int bs;

	if (is_valid(base) == 0)
		return (0);
	num = 0;
	sign = 1;
	len = ft_strlen(base);
	while (whilte_space(*str) == 1)
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while ((bs = base_answer(base, *str)) != -1)
	{
		num *= len;
		num += bs;
		str++;
	}
	return (num * sign);
}
