/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younjkim <younjkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 04:17:12 by younjkim          #+#    #+#             */
/*   Updated: 2021/11/28 16:25:17 by younjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_backup(char **backup)
{
	if (*backup)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	return (0);
}

char	*print_line(char *line, char **backup, int size, char *tmp)
{
	if (size == 0)
		line = ft_strdup(*backup);
	else if (size > 0)
		line = ft_substr(*backup, 0, (ft_strchr(*backup, '\n') - *backup + 1));
	else
	{
		free_backup(&line);
		free_backup(backup);
		return (NULL);
	}
	tmp = ft_strdup(*backup + ft_strlen(line));
	free_backup(backup);
	if (!tmp || !line)
		return (NULL);
	*backup = tmp;
	if (size == 0 && (ft_strlen(line) == 0))
	{
		free_backup(&line);
		free_backup(backup);
		return (NULL);
	}
	if (size == 0)
		free_backup(backup);
	return (line);
}

char	*ft_malloc(size_t size)
{
	char	*str;

	str = (char *)malloc(size);
	if (!str)
		return (NULL);
	str[0] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*backup[OPEN_MAX];
	int				size;
	char			*tmp;
	char			*line;

	size = 1;
	line = NULL;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup[fd])
		backup[fd] = ft_malloc(1);
	while (!(ft_strchr(backup[fd], '\n')))
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size <= 0)
			break ;
		buf[size] = '\0';
		tmp = ft_strjoin(backup[fd], buf);
		free_backup(&backup[fd]);
		if (!tmp)
			return (NULL);
		backup[fd] = tmp;
	}
	return (print_line(line, &(backup[fd]), size, tmp));
}
