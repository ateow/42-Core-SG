/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:26:42 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 09:26:43 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
int	main()
{
	printf("### Function: strrchr ###");
	char s[] = "hello world";
	printf("\n\ninput: hello world\nchar: l");	
	printf("\nOG_strrchr: %s", strrchr(s, 'l'));
	printf("\nft_strrchr: %s", ft_strrchr(s, 'l'));
	
	printf("\n\ninput: hello world\nchar: z");	
	printf("\nOG_strrchr: %s", strrchr(s, 'z'));
	printf("\nft_strrchr: %s", ft_strrchr(s, 'z'));
	//in this case, the first comparison will be \0 because check from back 
	printf("\n\ninput: hello world\nchar: null");	
	printf("\nOG_strrchr: %s", strrchr(s, '\0'));
	printf("\nft_strrchr: %s", ft_strrchr(s, '\0'));
	
	printf("\n\ninput: \nchar: a");	
	printf("\nOG_strrchr: %s", strrchr(s, 'a'));
	printf("\nft_strrchr: %s", ft_strrchr(s, 'a'));
	
	printf("\n\ninput: \nchar: null");	
	printf("\nOG_strrchr: %s", strrchr(s, '\0'));
	printf("\nft_strrchr: %s", ft_strrchr(s, '\0'));
}*/
