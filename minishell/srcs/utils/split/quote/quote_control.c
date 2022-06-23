/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:02:30 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/23 17:51:56 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static int	ft_count(char *str, int i, int j)
{
	char	c;

	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i];
			i++;
			while (str[i] != c && str[i])
			{
				i++;
				j++;
			}
		}
		else
			j++;
		i++;
	}
	return (j);
}

static void	ft_duperloop(char *str, char *aux, int i, int j)
{	
	char	c;

	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i];
			i++;
			while (str[i] != c && str[i])
			{
				aux[j] = str[i];
				j++;
				i++;
			}
		}
		else
		{
			aux[j] = str[i];
			j++;
		}
		i++;
	}
}

static char	*ft_dollar(char *str, int k)
{
	char	*aux;
	int		x;

	if (!str)
		return (NULL);
	if (!ft_strstr(str, "$") || k == 2) // $가 없는 경우 들어온 값 변경없이 그대로 리턴
		return (str);
	x = ft_dollarlen(str, 0, 0, k);    // 출력해야될 것들의 길이 ($고려안해도되는 일반문자열 길이 + $환경변수에 들어있는 문자열의 길이)
	aux = malloc(x * sizeof(char) + 1);
	aux[x] = '\0';
	ft_dollardup(str, aux, 0, k);  // aux에 저장
	return (aux);
}

char	*ft_trimed(char *str, int i)
{
	int		j;
	int		k;
	char	*aux;
	char	*temp;

	if (!str)
		return (NULL);
	k = ft_success(str, 0, 0, 0); // k = 0이면 문자열 그대로 출력, k =1 이면 $ 고려, k = 2이면 $ 없음
	j = ft_count(str, 0, 0);      // 출력할 문자의 개수를 카운트해서 j에 저장, 따옴표가 있으면 바깥 따옴표 뺀거임!
	aux = malloc(j * sizeof(char) + 1);
	aux[j] = '\0';
	ft_duperloop(str, aux, 0, 0); // 따옴표 안에 들어가있는 문자열을 aux에 담는다.
	temp = ft_tolower_chr(str);   // 현재 문자열에 대문자가 있으면 소문자로 바꿔줌
	if ((!ft_strcmp(temp, "echo") || !ft_strcmp(temp, "env")
			|| !ft_strcmp(temp, "pwd")) && i == 0)  // 얘네 세개는 대소문자 들어와도 잘 동작하므로 소문자로 미리 바꿔놓은 tmp가 필요
	{
		ft_single_free(aux);
		return (temp);
	}
	ft_single_free(temp);
	temp = ft_dollar(aux, k);  // 새삥 temp에 $환경변수 리턴값을 저장
	return (temp);
}

char	**ft_quote_control(char	**str)
{
	int		i;
	char	**aux;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	aux = (char **)malloc(sizeof(char *) * (i + 1));
	aux[i] = NULL;
	i = 0;
	aux[0] = ft_trimed(str[0], 0); // 첫번째 문자열들 먼저 손질, 명령어자리니까 trimed에서 처리할 수 있도록 두번째 인자에 0을 줌
	while (str[++i])
		aux[i] = ft_trimed(str[i], 1); // 차례차례 문자열들을 손질. 두번째 인자가 1이므로 명령어 고려할 필요 x.
	return (aux); // aux에 환경변수 값이 들어있는 문자열들이 잘 들어가게 됨
}
