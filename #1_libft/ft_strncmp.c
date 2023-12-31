/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:39:39 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 09:39:41 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	printf("### Function: strncmp ###");

	printf("\n\nstring1: Geeks\nstring2: Geeks\nn: 0");	
	printf("\nOG: %d", strncmp("Geeks", "Geeks", 0));
	printf("\nft: %d", ft_strncmp("Geeks", "Geeks", 0));
	
	printf("\n\nstring1: Geeks\nstring2: Geeks\nn: -1");	
	printf("\nOG: %d", strncmp("Geeks", "Geeks", -1));
	printf("\nft: %d", ft_strncmp("Geeks", "Geeks", -1));
	
	printf("\n\nstring1: Geekaaa\nstring2: Geekzzz\nn: 4");	
	printf("\nOG: %d", strncmp("Geekaaa", "Geekzzz", 4));
	printf("\nft: %d", ft_strncmp("Geekaaa", "Geekzzz", 4));
	
	printf("\n\nstring1: Geekaaa\nstring2: Geekzzz\nn: 5");	
	printf("\nOG: %d", strncmp("Geekaaa", "Geekzzz", 5));
	printf("\nft: %d", ft_strncmp("Geekaaa", "Geekzzz", 5));
	
	printf("\n\nstring1: Geekzzz\nstring2: Geekaaa\nn: 5");	
	printf("\nOG: %d", strncmp("Geekzzz", "Geekaaa", 5));
	printf("\nft: %d", ft_strncmp("Geekzzz", "Geekaaa", 5));

	printf("\n\nstring1: ""\nstring2: Geekaaa\nn: 5");	
	printf("\nOG: %d", strncmp("", "Geekaaa", 5));
	printf("\nft: %d", ft_strncmp("", "Geekaaa", 5));
	
	printf("\n\nstring1: testslash200\nstring2: testslash0\nn: 5");	
	printf("\nOG: %d", strncmp("test\200", "test\0", 5));
	printf("\nft: %d", ft_strncmp("test\200", "test\0", 5));
	
	printf("\n\nstring1: testslash0\nstring2: testslash200\nn: 5");	
	printf("\nOG: %d", strncmp("test\0", "test\200", 5));
	printf("\nft: %d", ft_strncmp("test\0", "test\200", 5));
}*/
