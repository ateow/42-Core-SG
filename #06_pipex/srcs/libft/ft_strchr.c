/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:54:39 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 08:54:40 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}
/*
int	main()
{
	printf("### Function: strchr ###");
	char s[] = "hello world";
	printf("\n\ninput: hello world\nchar: l");	
	printf("\nOG_strchr: %s", strchr(s, 'l'));
	printf("\nft_strchr: %s", ft_strchr(s, 'l'));
	
	printf("\n\ninput: hello world\nchar: z");	
	printf("\nOG_strchr: %s", strchr(s, 'z'));
	printf("\nft_strchr: %s", ft_strchr(s, 'z'));
	
	//The last if statment is to match the null terminator 
	printf("\n\ninput: hello world\nchar: null");	
	printf("\nOG_strchr: %s", strchr(s, '\0'));
	printf("\nft_strchr: %s", ft_strchr(s, '\0'));
	
	printf("\n\ninput: \nchar: a");	
	printf("\nOG_strchr: %s", strchr(s, 'a'));
	printf("\nft_strchr: %s", ft_strchr(s, 'a'));
	
	printf("\n\ninput: \nchar: null");	
	printf("\nOG_strchr: %s", strchr(s, '\0'));
	printf("\nft_strchr: %s", ft_strchr(s, '\0'));
}*/
