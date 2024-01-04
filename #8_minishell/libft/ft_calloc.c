/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:12:18 by cooi              #+#    #+#             */
/*   Updated: 2023/09/06 19:07:50 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (size == 0 || nmemb == 0 || INT_MAX / size < nmemb)
	{
		return (NULL);
	}
	ret = (void *)malloc(size * nmemb);
	if (!ret)
	{
		return (NULL);
	}
	ft_bzero(ret, size * nmemb);
	return (ret);
}
