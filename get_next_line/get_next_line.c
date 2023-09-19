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

char	*get_next_line(int fd)
{
	char	*str;
	char	buf[2];
	int	n;
	
	str = malloc(sizeof(char) * 2);
	while ((n = read(fd, buf, 1)) > 0)
	{
		if (*buf == '\n')
		{
			str = ft_strjoin(str, buf);
			break;
		}
		buf[n] = '\0';
		str = ft_strjoin(str, buf);
	}
	str[ft_strlen(str)] = '\0';
	free(buf);
	return (str);
}

int	main(void)
{
	int fd1 = open("sample.txt", O_RDONLY, 0);
	char* z = get_next_line(fd1);
	char* x = get_next_line(fd1);
	printf("|string: %s|\n", z);
	printf("|string: %s|\n", x);
}


/*
	char	*c;
	char	*s;
	int 	len;
	int	i;
	
	len = 0;
	c = malloc(1);
	c[0] = 0;
	if (read(fd, c, 1) <= 0)
	{
		free(c);
		return (NULL);
	}
	while (read(fd, c, 1) > 0)
	{
		if (*c == '\n')
			break;
		len++;
	}
	s = malloc((len + 2) * sizeof(char));
	i = 0;
	while (read(fd, c, 1) > 0)
	{
		s[i] = *c;
		if (*c == '\n')
			break;
		i++;
	}
	s[i] = '\n';
	s[i++] = '\0';
	free(c);
	return (s);

*/
