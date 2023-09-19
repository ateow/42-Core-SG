/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:07:08 by ateow             #+#    #+#             */
/*   Updated: 2023/09/18 13:07:10 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;

	if (!src)
		return (0);
	new = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (new == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strdup_special(const char *src)
{
	char	*new;
	size_t		i;

	if (!src)
		return (0);
	new = malloc(sizeof(char) * (ft_strlen_special(src) + 1));
	if (new == NULL)
		return (0);
	i = 0;
	while (i < ft_strlen_special(src))
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlen_special(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s2)
		return (NULL);

	new = malloc((ft_strlen(s1) + ft_strlen_special(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < (int)ft_strlen(s1))
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < (int)ft_strlen_special(s2))
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	//printf("inside:%s\n", new);
	return (new);
}
