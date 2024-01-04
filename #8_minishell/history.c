/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:26:42 by ateow             #+#    #+#             */
/*   Updated: 2023/12/28 17:26:43 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	store_history(char *user_input, t_list **history_list)
{
	char	*input_copy;

	add_history(user_input);
	input_copy = strdup(user_input);
	ft_lstadd_back(history_list, ft_lstnew(input_copy));
}

int	print_history(t_list *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			printf("%5d  %-40s\n", i, (char *)lst->content);
			i++;
			lst = lst->next;
		}
	}
	return (0);
}
