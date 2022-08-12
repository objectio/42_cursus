/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:22:24 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/24 16:10:06 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* nchild 개수 (파이프로 분할된 명령어들 개수) 만큼 pipes에 할당함 */
static void	ft_alloc(t_shell *shell)
{
	int	i;
	int	nchild;

	i = -1;
	nchild = 0;
	if (!shell->pipes)
		return ;
	while (shell->pipes[++i])
		nchild++;
	shell->nchild = nchild;
	shell->pid = (pid_t *)malloc(sizeof(pid_t) * shell->nchild);
	pipe(shell->fd[0]);
	pipe(shell->fd[1]);
}

static void	ft_close(t_shell *shell, int j)
{   // j = 1
	int	i;

	if (j != 0)
	{
		close(shell->fd[0][0]);
		close(shell->fd[0][1]);
		close(shell->fd[1][0]);
		close(shell->fd[1][1]);
		return ;
	} // j가 0이면
	i = -1;
	while (shell->pipes[++i])
		free(shell->pipes[i]);
	free(shell->pipes);
	free(shell->pid);
}

static void	ft_exe(t_shell *shell, int id, char *temp)
{    // id = i(파이프로 분리된 구 중 몇번째 구인지), char *temp = NULL
	t_redi	redi;

	ft_memset(&redi, 0, sizeof(redi));
	rl_catch_signals = 1;
	shell->split = ft_split_mini(shell->pipes[id], &redi); // pipes 로 분할된 애들을 토큰단위로 분할시키고 따옴표 안의 환경변수 처리.
	shell->split = ft_redirections(shell->split, &redi, shell); // 리다이렉션 처리해주고, 리디렉션 표시 제외시켜줌. 토큰단위였던 커맨드들만 split 저장
	if (!shell->split)
		exit (1);
	temp = shell->split[0];
	if (access(shell->split[0], X_OK) != 0  // split[0]안에 들어있는 이름의 파일의 존재 여부, 실행 여부를 확인하고 성공하면 0, 실패하면 1 반환
		&& ft_checkchild(shell->split) && ft_checkparent(shell->split))  // 즉 split[]이 파일이 아니면서 내부 명령어들 아닐 경우
		temp = ft_get_path(shell->split[0], -1, 0, NULL);  // shell에서 입력받은 명령을 실행할 떄 실행할 프로그램을 찾는 경로
	if (id != 0)  // 첫번째 구가 아닌 경우
		dup2(shell->fd[0][0], STDIN_FILENO);  // 표준입력을 fd[0][0]가 가리키고 있는 것으로 바꾸기.
	if (id != shell->nchild - 1) // 마지막 명령어 구가 아닌 경우
		dup2(shell->fd[1][1], STDOUT_FILENO);  // 표준출력을 fd[1][1]로 바꾸기.
	ft_close(shell, 1);
	ft_builtinc(shell->split, shell); // child 명령어 실행
	if (temp != NULL)
		execve(temp, shell->split, g_glob.g_env);
	if (ft_checkparent(shell->split) == 1)
		exit(ft_printf("minishell: %s: command not found\n", shell->split[0]));
	exit (0);
}

static void	ft_repipe_help(t_shell *shell)  // 자식프로세스에서 파이프 돌리느라 표준출력과 표준입력이 바뀌어있는 상황. 그래서 초기화시켜줌
{
	close(shell->fd[0][1]);
	close(shell->fd[0][0]);
	shell->fd[0][0] = shell->fd[1][0];
	shell->fd[0][1] = shell->fd[1][1];
	pipe(shell->fd[1]);
	rl_catch_signals = 0;
}

void	ft_fork(t_shell *shell, int i, int st)
{  // int i = -1, st = 0
	int	status;

	g_glob.pid = 0;
	shell->pipes = ft_split_pipe(shell->line, -1, 0);
	if (!shell->pipes)
		return ;
	ft_alloc(shell);
	while (++i < shell->nchild)
	{
		close(shell->fd[0][1]);
		shell->pid[i] = fork(); // i번째 자식 프로세스 생성
		if (shell->pid[i] == 0) // 자식 프로세스!
			ft_exe(shell, i, NULL); // nchild 애들 토큰단위로 분할시키고 환경변수값도 찾아서 저장. 리다이렉션 처리, 커맨드 실행
		else                    // 부모 프로세스!
		{
			if (shell->nchild == i + 1)
				st = ft_builtinp(ft_split_mini(shell->pipes[i], NULL), shell); // 부모 명령어 실행
			waitpid (shell->pid[i], &status, 0);
			if (st != 1)
				g_glob.error = WEXITSTATUS(status); // 에러코드 받음
			ft_repipe_help(shell);
		}
	}
	ft_close(shell, 1);
	ft_close(shell, 0);
}
