/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:12:37 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/24 10:19:12 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_size_cmd(char **s, int *k, t_redi *redi)
{       // s = s, k = 0, redi
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (s[++i])
	{
		if (redi->rpos[j] && i == redi->rpos[j] - 1 && s[i + 1]) // 리디렉션 표시 뒤에 문자열이 있는 경우(리디렉션 경로)
		{
			i++; // 인덱스증가
			j++; // 리디렉션 어디까지 왔는지 세는 변수 증가
		}
		else
			*k = *k + 1; // 커맨드인 경우 
	}
}

void	ft_fill_cmd(char **s, char **cmd, t_redi *redi)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	i = -1;
	while (s[++i])
	{
		if (redi->rpos[j] && i == redi->rpos[j] - 1 && s[i + 1]) // 리다이렉션 표시
		{
			i++;
			j++;
		}
		else
		{
			cmd[k] = ft_strdup(s[i]);
			k++;
		}
	}
	ft_double_free(s);
}

void	ft_readline_doublein(t_file *file, int hd)
{
	char	*s;

	while (1)
	{
		s = readline(">");
		if (!ft_strcmp(s, file->file))
			break ;
		else if (!s)
		{
			break ;
			unlink("heredoc.txt");
		}
		ft_putstr_fd(s, hd);
		ft_putstr_fd("\n", hd);
		free(s);
	}
	free(s);
}
