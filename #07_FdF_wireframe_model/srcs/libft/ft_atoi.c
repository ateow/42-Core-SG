/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:43:41 by ateow             #+#    #+#             */
/*   Updated: 2023/09/07 12:43:42 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	n;

	i = 0;
	res = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * n);
}
/*
int	main()
{
	printf("### Function: atoi ###");
	printf("output: %d\n",ft_atoi("-123#3"));
	printf("expected: %d\n\n",atoi("-123#3"));

	printf("output: %d\n",ft_atoi("  123@2"));
	printf("expected: %d\n\n",atoi("  123@2"));

	printf("output: %d\n",ft_atoi("  +  -12+3!1"));
	printf("expected: %d\n\n",atoi("   + -12+3!1"));

	printf("output: %d\n",ft_atoi("+123!1"));
	printf("expected: %d\n\n",atoi("+123!1"));

	printf("output: %d\n",ft_atoi("-+123a1"));
	printf("expected: %d\n\n",atoi("-+123a1"));

	printf("output: %d\n",ft_atoi("+-123a1"));
	printf("expected: %d\n\n",atoi("+-123a1"));

	printf("output: %d\n",ft_atoi("   -1-23a1"));
	printf("expected: %d\n\n",atoi("   -1-23a1"));

	printf("output: %d\n",ft_atoi(""));
	printf("expected: %d\n\n",atoi(""));

	printf("output: %d\n",ft_atoi("  -+  "));
	printf("expected: %d\n\n",atoi("  -+  "));

	printf("output: %d\n",ft_atoi("   +"));
	printf("expected: %d\n\n",atoi("   +"));
}*/
