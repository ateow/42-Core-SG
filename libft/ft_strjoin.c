/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:53:48 by ateow             #+#    #+#             */
/*   Updated: 2023/09/08 16:53:51 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new = malloc((ft_strlen(s1)+ ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < (int)ft_strlen(s1))
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < (int)ft_strlen(s2))
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

int	main()
{
	printf("### Function: ft_strjoin ###");
	printf("\nft_strjoin: %s\n",ft_strjoin("hello","world"));
}
