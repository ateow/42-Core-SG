/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:05:01 by ateow             #+#    #+#             */
/*   Updated: 2023/09/18 13:05:04 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*add_buf_to_holding(char *holding, char *buf)
{
	char	*tmp;

	if (holding == NULL)
		holding = ft_substr("", 0, 1);
	tmp = ft_strjoin(holding, buf);
	free(holding);
	holding = ft_strjoin("", tmp);
	free(tmp);
	tmp = NULL;
	return (holding);
}

static char	*append_holding(int fd, char *holding)
{
	int		read_line;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	read_line = 1;
	while (read_line != 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
		{
			free(buf);
			return (NULL);
		}
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		holding = add_buf_to_holding(holding, buf);
		if (get_index(buf, '\n') != (-1))
			break ;
	}
	free(buf);
	return (holding);
}

static char	*update_holding(char *line)
{
	int		new_len;
	int		start;
	char	*holding;
	int		index;

	index = get_index(line, '\n');
	if (index != -1)
	{
		start = index + 1;
		new_len = ft_strlen(line) - start;
		holding = ft_substr(line, start, new_len);
		if (*holding == '\0')
		{
			free(holding);
			holding = NULL;
		}
	}
	else
		holding = NULL;
	return (holding);
}

char	*get_next_line(int fd)
{
	static char	*holding;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = append_holding(fd, holding);
	if (line == NULL)
	{
		if (holding != NULL)
		{
			free(holding);
			holding = NULL;
		}
		return (NULL);
	}
	holding = update_holding(line);
	if (get_index(line, '\n') != -1)
		line[get_index(line, '\n') + 1] = '\0';
	return (line);
}
