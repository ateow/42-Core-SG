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

char	*ft_store(const char *src)
{
	int	start;

	start = ft_strlen_special(src);
	if (start == 0)
		return (NULL);
	return(ft_strdup(src + start));
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*store;
	char		*buf;
	int		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	buf[BUFFER_SIZE + 1] = '\0';
	result = NULL;
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		result = ft_strjoin(result, store);
		result = ft_strjoin(result, buf);
		free(store);
		store = ft_store(buf);
		if (ft_strchr(buf, '\n') == 1)
		{
			free(buf);
			return (result);
		}
	}
	if (n == 0 && store != NULL)
	{
		result = ft_strjoin(result, ft_strdup_special(store));
		store = ft_store(store);
		if (*store == '\0')
		{
			printf("FREE");
			free(store);
			store = NULL;
			return (result);
		}
	}
	free(store);
	return (NULL);
}
/*
int	main(void)
{
	int fd1 = open("sample.txt", O_RDONLY, 0);
	printf("\n>>%s", get_next_line(fd1));
	printf("\n>>%s", get_next_line(fd1));
	printf("\n>>%s", get_next_line(fd1));
}
//printf("str:%s | buf:[%c][%c][%i]\n",str, buf[0], buf[1], buf[2]);*/
