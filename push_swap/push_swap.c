/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:28:08 by younjkim          #+#    #+#             */
/*   Updated: 2022/04/15 20:30:23 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        int     **list;
        int     i;

        i = 1;
        while (i != argc)
        {
            list[i] = argv[i];
            i++;
        }
    }
    return (0);
}
