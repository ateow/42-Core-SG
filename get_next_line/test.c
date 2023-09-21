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

char	*append_holding(int fd, char *holding)
{
	char	*buf;
	char	*tmp;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		if (holding == NULL)
			holding = ft_substr("", 0, 1);
		tmp = ft_strjoin(holding, buf);
		free(holding);
		holding = ft_strjoin("", tmp);
		free(tmp);
		if (get_index(buf, '\n') != -1)
			break ;
	}
	free(buf);
	return (holding);
}

char	*extract_line(char *holding)
{
	int		len;
	char	*line;

	if (holding == NULL)
		return (NULL);
	len = get_index(holding, '\n') + 1;
	line = ft_substr(holding, 0, len);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*update_holding(char *holding)
{
	int		new_len;
	char	*tmp;
	int		start;

	if (holding == NULL)
	{
		free(holding);
		return (NULL);
	}
	else
	{
		start = get_index(holding, '\n') + 1;
		new_len = ft_strlen(holding) - start;
		tmp = ft_substr(holding, start, new_len);
		free(holding);
		holding = ft_strjoin("", tmp);
		free(tmp);
		return (holding);
	}
}

char	*get_next_line(int fd)
{
	static char	*holding;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);

	holding = append_holding(fd, holding);
	line = extract_line(holding);
	holding = update_holding(holding);
	return (line);
}

int	main(void)
{
	int fd1 = open("sample.txt", O_RDONLY, 0);
	printf("\noutput >>>>>>>%s\n", get_next_line(fd1));
	printf("\nouput >>>>>>>%s\n", get_next_line(fd1));
	printf("\nouput >>>>>>>%s\n", get_next_line(fd1));
	printf("\nouput >>>>>>>%s\n", get_next_line(fd1));
}

