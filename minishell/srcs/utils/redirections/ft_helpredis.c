/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpredis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:12:21 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/24 09:38:07 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_in(t_file *file, t_shell *shell, int *n, int n_in)
{
	*n += 1;
	shell->fd[0][0] = open(file->file, O_RDWR);
	if (shell->fd[0][0] == -1)
	{
		ft_printf("%s file not found\n", file->file);
		if (*n == n_in)
			exit (1);
		return ;
	}
	if (*n == n_in)
		dup2(shell->fd[0][0], STDIN_FILENO);
}

void	ft_doublein(t_file *file, t_shell *shell, int *n, int n_in)
{  // file = redi->in[in], shell = shell, n = &in, n_in = redi->n_in
	int		hd;

	(void) n_in;
	*n += 1;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	unlink("heredoc.txt");
	hd = open("heredoc.txt",                               // 읽기쓰기전용 | 이미 있는 파일이고 쓰기 옵션으로 열었으면 내용 모두 지우고 시작 |
			O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 0644);  // 파일이 없으면 생성한다 | 파일의 맨 끝에 내용 추가, (0644=권한주기) 소유자는 읽기쓰기 가능, 나머지는 읽기만 가능
	if (shell->redi == -1)
		return ((void)ft_printf("%s file not found\n", file->file));
	ft_readline_doublein(file, hd);  //  > (입력문자열) 을 readline으로 계속 받는다. 개행 출력.  
	close(hd);  // heredoc 입력 닫음.
	if (*n == n_in) // 끝까지 도달
	{
		shell->fd[0][0] = open("heredoc.txt", O_RDWR);  // 읽기쓰기전용으로 heredoc.txt를 열고 fd[0][0]에 저장
		if (dup2(shell->fd[0][0], STDIN_FILENO) == -1)  // 표준입력을 fd[0][0]으로 바꿈
			ft_printf("Somehow broke the heredoc function\n");
	}
	unlink("heredoc.txt");
	signal(SIGINT, ft_sig_handler);  // 시그널 원래 핸들러대로
	signal(SIGQUIT, ft_sig_handler);
}

void	ft_out(t_file *file, t_shell *shell, int *n, int n_out)
{	
	*n += 1;
	shell->fd[1][1] = open(file->file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (*n == n_out)
		dup2(shell->fd[1][1], STDOUT_FILENO);
}

void	ft_doubleout(t_file *file, t_shell *shell, int *n, int n_out)
{
	*n += 1;
	shell->fd[1][1] = open(file->file, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (*n == n_out)
		dup2(shell->fd[1][1], STDOUT_FILENO);
}
