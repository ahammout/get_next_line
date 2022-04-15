/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:52:19 by ahammout          #+#    #+#             */
/*   Updated: 2021/12/20 22:52:22 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include<stdio.h>

static char	*next_line(int fd, char **str_remainder)
{
	size_t	f;
	char	*line;
	char	*to_free;

	to_free = str_remainder[fd];
	f = 0;
	while ((str_remainder)[fd][f] != '\n' && (str_remainder)[fd][f] != '\0')
		f++;
	if (ft_strchr(str_remainder[fd], '\n'))
	{
		line = ft_substr(str_remainder[fd], 0, f + 1);
		str_remainder[fd] = ft_strdup(str_remainder[fd] + (f + 1));
	}
	else
	{
		line = ft_substr(str_remainder[fd], 0, f);
		str_remainder[fd] = NULL;
	}
	free (to_free);
	return (line);
}

static void	ft_tofill(int fd, char *buff, char **str)
{
	size_t	read_bytes;
	char	*tofree;

	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		buff[read_bytes] = '\0';
		tofree = str[fd];
		str[fd] = ft_strjoin(str[fd], buff);
		free (tofree);
		if ((ft_strchr(str[fd], '\n')))
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*line;
	char		*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, buff, 0) < 0))
	{
		free(buff);
		return (NULL);
	}
	if (!str[fd])
		str[fd] = ft_strdup("");
	ft_tofill(fd, buff, str);
	free(buff);
	line = next_line(fd, str);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
