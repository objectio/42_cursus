/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:12:28 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/24 09:59:39 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	ft_countredis(char **s, t_redi *redi) // s 안에 리다이렉션이 있으면 동적할당해주고 0 반환, 없으면 1 반환
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s && s[++i])
	{
		if (i == redi->rpos[j] - 1) // 리다이렉션 표시 있는 곳이면
		{
			j++;
			if (ft_strstr(s[i], ">>") || ft_strstr(s[i], ">")) // out 리다이렉션 있을때마다 n_out 개수 증가
				redi->n_out++;
			else if (ft_strstr(s[i], "<<") || ft_strstr(s[i], "<")) // in 리다이렉션의 개수 = n_in
				redi->n_in++;
		}
	}
	if (!redi->n_out && !redi->n_in) // 리다이렉션이 없으면 return 1
		return (1);
	if (redi->n_in) // in 리다이렉션 있으면 그 개수만큼 redi->in에 동적할당
		redi->in = (t_file *)malloc((redi->n_in + 1) * sizeof(t_file));
	if (redi->n_out) // out 리다이렉션 있으면 그 개수만큼 redi->out에 동적할당
		redi->out = (t_file *)malloc((redi->n_out + 1) * sizeof(t_file));
	return (0); // 정상종료 0 리턴
}

static int	ft_fill(t_file *file, int w, char *s) // file->file에 리디렉션의 오른쪽(파일)을 복사하고 spiderman 변수 설정
{   // file = redi->out[] 또는 redi->in[], 리디렉션이 연속해서 두개 붙어있으면 w = 1 하나면 w = 0, s=s[i+1]
	if (s)
		file->file = strdup(s); // s[i+1]을 파일에다 복사
	else
		return (1); // s가 널문자면 1 반환
	file->spiderman = w; // 리디렉션이 연속이면 1, 아니면 0
	return (0);  // 정상종료 리턴값 0
}

static int	ft_allocredi(char **s, t_redi *redi, int i, int j) // 리다이렉션을 찾아서 redi->out[]/in[]에 리디렉션 오른쪽(파일)을 넣음
{   // i = -1, j = 0
	int	in;
	int	out;
	int	error;

	in = 0;
	out = 0;
	while (s[++i])
	{
		if (i == redi->rpos[j] - 1) // 리다이렉션 위치에 도달
		{
			j++;
			if (!ft_strncmp(s[i], ">>", 2)) // >> 발견! 오른쪽 파일의 가장 마지막에 왼쪽을 추가함.
				error = ft_fill(&redi->out[out++], 1, s[i + 1]);
			else if (!ft_strncmp(s[i], ">", 1)) // > 왼쪽의 표준출력을 오른쪽 파일에 덮어씀.
				error = ft_fill(&redi->out[out++], 0, s[i + 1]);
			else if (!ft_strncmp(s[i], "<<", 2)) // << heredoc 
				error = ft_fill(&redi->in[in++], 1, s[i + 1]);
			else if (!ft_strncmp(s[i], "<", 1))  // < 오른쪽 파일의 데이터를 표준입력으로 넘김.
				error = ft_fill(&redi->in[in++], 0, s[i + 1]);
			if (error) // ft_fill 반환값이 1이면 return 1
				return (1);
		}
	}
	return (0);
}

static void	ft_doderedi(t_redi *redi, t_shell *shell)
{
	int	in;
	int	out;
	int	i;

	in = 0;
	out = 0;
	i = -1;
	while (redi->n_in > 0 && ++i < redi->n_in) // n_in 넣어야 될 게 있는 동안 while 문 돌림
	{
		if (redi->in[i].spiderman == 1) // 리다이렉션이 연속 입력 (<<)일 경우 - heredoc
			ft_doublein(&redi->in[in], shell, &in, redi->n_in);
		else
			ft_in(&redi->in[in], shell, &in, redi->n_in);
	}
	i = -1;
	while (redi->n_out > 0 && ++i < redi->n_out)
	{
		if (redi->out[i].spiderman == 1)
			ft_doubleout(&redi->out[out], shell, &out, redi->n_out);
		else
			ft_out(&redi->out[out], shell, &out, redi->n_out);
	}
}

char	**ft_redirections(char **s, t_redi *redi, t_shell *shell)
{
	char	**cmd;
	int		k;

	(void) shell;
	if (ft_countredis(s, redi)) // s에 리다이렉션이 있으면 동적할당 후 0 반환, 없으면 1 반환
		return (s);
	shell->rediexists = 0; // 리다이렉션 있다는 표시
	if (ft_allocredi(s, redi, -1, 0)) // 리다이렉션 찾아서 redi->in out에 파일을 넣어줌(전부 오른쪽임)
	{
		ft_printf("minishell: syntax error near unexpected token 'newline´\n");
		return (NULL);
	}
	ft_doderedi(redi, shell); // 리다이렉션대로 처리
	k = 0;
	ft_size_cmd(s, (int *)&k, redi);  // 리다이렉션의 경로인 부분 뺴주고 나머지인 커맨드 len세기 
	cmd = (char **)malloc((k + 1) * sizeof(char *)); // cmd에 동적할당
	cmd[k] = NULL;
	ft_fill_cmd(s, cmd, redi); 
	return (cmd);
}
