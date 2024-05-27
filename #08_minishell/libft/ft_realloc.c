/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:25:47 by cooi              #+#    #+#             */
/*   Updated: 2023/10/24 20:59:23 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_realloc(void *ptr, size_t size, size_t oldsize)
{
	void	*newptr;

	newptr = ft_calloc(1, size);
	if (!newptr)
		return (NULL);
	if (!ptr)
		return (newptr);
	if (size < oldsize)
		ft_memmove(newptr, ptr, size);
	else
		ft_memmove(newptr, ptr, oldsize);
	free (ptr);
	return (newptr);
}
