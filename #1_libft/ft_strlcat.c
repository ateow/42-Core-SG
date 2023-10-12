/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 05:46:12 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 05:46:14 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	j = dlen;
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && i < size - dlen - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (dlen >= size)
		dlen = size;
	return (dlen + slen);
}
/*
int main (void)
{
	char src[] = "123";
	char dest[] = "abcde";
	printf("ft len: %ld \n", ft_strlcat(dest, src, 7));
	printf("ft dest: %s \n", dest);

	char src2[] = "123";
	char dest2[] = "abcde";
	printf("og len: %ld \n", strlcat(dest2, src2, 7));
	printf("og dest: %s \n", dest2);
}*/
