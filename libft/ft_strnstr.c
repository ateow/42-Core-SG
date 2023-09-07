/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:58:32 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 11:58:34 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)(big));
	while (i < (int)len)
	{
		while (big[i + j] == little[j] && big[i + j] != '\0')
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
		j = 0;
	}
	return (0);
}
/*
int main ()
{
	char haystack[99] ="123456";
	char needle[99] = "34";
	
	char* ret = ft_strnstr(haystack, needle, 6);
	printf("%s", ret);
	
	//strstr(haystack, needle);
	//ft_strstr(haystack, needle);

	//printf("%s\n", strstr(haystack, needle));
}*/
