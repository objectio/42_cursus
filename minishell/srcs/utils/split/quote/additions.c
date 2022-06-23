/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:36:04 by younjkim          #+#    #+#             */
/*   Updated: 2022/06/23 17:51:57 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

static void	ft_check_inloop(char *str, int i, int *x, int *k)
{
	if (str[i] == '$')
	{
		*x = 1;
		*k = 0;
	}
	else if (str[i] != '$' && *x != 1)
		*k = 1;
}

int	ft_success(char *str, int i, int k, int x)
{
	if (!ft_strstr(str, "$"))  // $ 없으면 2 반환하고 종료
		return (2);
	while (str[i])
	{
		if (str[i] == '\"')    // ""  이면 k = 1
			while (str[++i] != '\"')
				k = 1;
		if (str[i] == '\'')   // '면 k = 0; 달러가 '' 안에 없으면 k = 1 
		{
			x = 0;
			while (str[++i] != '\'')
				ft_check_inloop(str, i, (int *)&x, (int *)&k);
		}
		if (str[i] == '$')   // $ 있으면 k = 1
			k = 1;
		if ((str[i] != '\'' || str[i] != '\"') && str[i])
			i++;
	}
	return (k);  // k가 0이면 안심하고 문자열 그대로 출력가능, k = 1이면 $ 고려해야함
}

static void	ft_looperdollar(char *str, int *i, int *w)
{
	*w = 1;
	*i = *i + 1; // $ 다음 위치로 이동
	if (str[*i] == '=' || str[*i] == '$' || str[*i] == ' ' || str[*i] == '\'') // $=또는, $$또는, $ 또는, $'
	{
		*w = *w + 1;
		*i = *i + 1; // 다음 위치 이동
		return ;
	}
	while (str[*i] && (str[*i] != ' ' && str[*i] != '\''  // $뒤에 어떤 문자열이 오는 경우!
			&& str[*i] != '\"' && str[*i] != '=' && str[*i] != '$'))
	{
		*w = *w + 1;  // $apfa w = 5    $=adfadf w = 2
		*i = *i + 1;  // 문자열의 끝까지 간다
	}
}

int	ft_dollarlen(char *str, int j, int w, int k) // j = 0, w = 0
{
	int		i;
	int		x;
	char	*p;
	char	*p2;

	i = 0;
	x = 0;
	while (str[i])
	{
		if ((str[i] == '$' && str[i + 1]) && k == 1) // 현재 위치에 고려해야하는 $가 있는 경우
		{
			ft_looperdollar(str, (int *)&i, (int *)&w); // 쉘 변수($$ 등)인지 $문자열 인지 고려하고 w($를 포함한 문자열의 길이), 현재 위치 i를 가져옴
			p2 = ft_substr(str, (i - w), w);   // str를 자른다. (i - w) 위치부터 w개의 문자열을 p2에 넣음 예)p2 = $adasflaf 
			p = ft_expand(p2, 0, 0);  // p2에서 $자르고 뒤에 = 붙임. 환경변수 리스트에서 발견하면 p에 변수 입력값 저장, 없으면 아무것도 출력하지 않음
			x += ft_strlen(p);   // 환경변수 안에 들어있는 값들 길이를 구하고 x변수에 더해서 넣음
			free(p2);
			free(p);
		}
		else
		{
			j++;
			i++;
		}
	}
	return (j + x); // j는 입력한 일반문자열($ 고려하지 않아도 되는), x는 환경변수에 들어있던 값 이 두 문자열들의 길이의 합 반환
}

void	ft_dollardup(char *str, char *aux, int w, int k)
{	
	int		i;
	int		j;
	char	*temp;
	char	*p;

	i = 0;
	j = 0;
	while (str[i])
	{
		w = 0;
		if ((str[i] == '$' && str[i + 1]) && k == 1)
		{
			ft_looperdollar(str, (int *)&i, (int *)&w);
			p = ft_substr(str, (i - w), w);
			temp = ft_expand(p, 0, 0);
			free(p);
			w = 0;
			while (temp[w])
				aux[j++] = temp[w++];
			free(temp);
		}
		else
			aux[j++] = str[i++];
	}
	ft_single_free(str);
}
