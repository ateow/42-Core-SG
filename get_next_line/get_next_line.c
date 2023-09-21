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

#include "get_next_line.h"

static char	*append_holding(int fd, char *buf, char *holding)
{
	char	*tmp;
	int		read_line;

	read_line = 1;
	while (read_line != 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (holding == NULL)
			holding = ft_substr("", 0, 1);
		tmp = ft_strjoin(holding, buf);
		free(holding);
		holding = ft_strjoin("", tmp);
		free(tmp);
		tmp = NULL;
		if (get_index(buf, '\n') != (-1))
			break ;
	}
	return (holding);
}

void	extract_line(char *line)
{
	int	index;

	index = get_index(line, '\n');
	if (index != -1)
		line[index + 1] = '\0';
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
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = append_holding(fd, buf, holding);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	holding = update_holding(line);
	extract_line(line);
	return (line);
}
/*
int	main(void)
{
	int fd1 = open("sample.txt", O_RDONLY, 0);
	printf("\noutput >>>>>>>%s\n", get_next_line(fd1));
	printf("\nouput >>>>>>>%s\n", get_next_line(fd1));
	printf("\nouput >>>>>>>%s\n", get_next_line(fd1));
	printf("\nouput >>>>>>>%s\n", get_next_line(fd1));
	printf("\nouput >>>>>>>%s\n", get_next_line(fd1));
}*/
