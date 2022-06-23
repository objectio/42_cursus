/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:44:03 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/23 17:27:29 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_checkinenv(int *j, int *i, char *s)
{
	while (!ft_strstr(g_glob.g_env[*j], s)) // env[j]가 s가 아니면 찾을때까지 j 돌림
	{
		if (g_glob.g_env[*j + 1] == NULL) // env 끝까지 다 찾았는데 s가 없으면 i = 1로 바꾸고 빠져나감
		{
			*i = 1;
			break ;
		}
		*j = *j + 1;
	}
}

static char	*ft_return(char *s)
{
	ft_single_free(s);
	return (ft_strdup(""));
}

static int	ft_checkcondition(char *str)
{
	if (!ft_strcmp(str, "$\'") || !ft_strcmp(str, "$ ")
		|| !ft_strcmp(str, "$=") || !ft_strcmp(str, "$$"))
		return (0);
	return (1);
}

static char	*ft_weirdcondition(char *str)
{
	if (!ft_strcmp(str, "$\'") || !ft_strcmp(str, "$ ")
		|| !ft_strcmp(str, "$=") || !ft_strcmp(str, "$$"))
	{
		if (!ft_strcmp(str, "$$"))  // $$ 은 쉘 프로그램이 실행되면서 사용되는 프로세스 ID값을 가진다.
			return (ft_itoa(59040));
		return (ft_strdup(str));   // 나머지는 그대로 문자열 복사
	}
	return (str);
}

char	*ft_expand(char *str, int i, int j) // $로 시작하는 문자열 입력받음, i = 0, j = 0
{
	char	*s;
	char	*trim;

	if (ft_strstr(str, "$?"))    // $?이 있으면 에러코드 출력
		return (ft_itoa(g_glob.error));
	if (ft_checkcondition(str) == 0)  // $$ $  $' $= 이면 weirdcondition()
		return (ft_weirdcondition(str));
	trim = ft_strtrim(str, "$");  // str의 앞뒤에서 $ 제거
	s = ft_strjoin(trim, "=");    // $ 제거된 문자열 뒤에 = 붙이기
	free(trim);
	if (str[i] == '$' && !(str[i + 1] == ' ' || str[i + 1] == '\0')) // 현재 위치에 $ 있고, 다음 위치에 공백이나 널문자가 없는 경우
	{
		ft_checkinenv((int *)&j, (int *)&i, s);  // 해당 문자열 (예로 LOGUSER=)이 환경변수 env에 있으면 j가 위치를 가지고옴, 없으면 i = 1
		if (i == 0) // 0일때만 정상출력
		{
			trim = ft_substr(g_glob.g_env[j], (int)ft_strlen(s),
					(int)(ft_strlen(g_glob.g_env[j]) - ft_strlen(s)));  // trim=환경변수값 출력
			free(s);
			return (trim);
		}
		else
			return (ft_return(s)); // trim 프리하고 아무것도 출력하지 않음
	}
	ft_single_free(s);
	return (str);
}
