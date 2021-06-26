/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:59:05 by younjkim          #+#    #+#             */
/*   Updated: 2021/04/12 20:45:21 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int num;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	num = nb;
	while (--power)
		num *= nb;
	return (num);
}
