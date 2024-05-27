/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:47:46 by ateow             #+#    #+#             */
/*   Updated: 2023/09/08 13:47:47 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int	main()
{
	char *s = "hello";
	printf("### Function: stdup ###");
	printf("\nOG:%s:", strdup(s));
	printf("\nft:%s:\n", ft_strdup(s));
}*/
