/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:41:49 by cooi              #+#    #+#             */
/*   Updated: 2023/10/26 19:38:28 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, char *holding)
{
	char	*buf;
	char	*tmp;
	char	*hold;
	int		fdr;

	fdr = 1;
	hold = ft_substr(holding, 0, BUFFER_SIZE + 1);
	while (fdr > 0 && ft_strchr(hold, '\n') == NULL)
	{
		buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buf)
			return (NULL);
		fdr = read(fd, buf, BUFFER_SIZE);
		if (fdr < 0)
		{
			free (hold);
			free (buf);
			return (NULL);
		}
		tmp = ft_strjoin(hold, buf);
		free (hold);
		hold = tmp;
		free (buf);
	}
	return (hold);
}

char	*get_holding(char *result)
{
	char	*res;
	int		j;
	int		i;

	i = 0;
	while (result[i])
		i++;
	j = 0;
	while (result[j] != '\0' && result[j] != '\n')
		j++;
	res = ft_substr(result, j + 1, i - j);
	if (result[j] == '\n')
		result[j + 1] = '\0';
	if (res == NULL)
		return (NULL);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*result;
	int			i;
	char		*tmp;
	static char	holding[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	result = ft_read(fd, holding);
	ft_bzero(holding, BUFFER_SIZE + 1);
	if (!result)
		return (NULL);
	if (!*result)
	{
		free (result);
		return (NULL);
	}
	tmp = get_holding(result);
	i = -1;
	while (tmp[++i])
		holding[i] = tmp[i];
	free (tmp);
	return (result);
}
