/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:37:45 by ateow             #+#    #+#             */
/*   Updated: 2023/12/31 15:12:43 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_arr_lst_arr(char **arr1, t_list *lst, char **arr2)
{
	free_array(arr1);
	free_list(lst);
	free_array(arr2);
}

void	free_str_lst_arr(char *str, t_list *lst, char **arr)
{
	free(str);
	free_list(lst);
	free_array(arr);
}

void	free_list(t_list *head)
{
	t_list	*current;
	t_list	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}

void	free_t_cmd_list(t_cmd *head)
{
	free(head->cmdstr);
	free(head->infile);
	free(head->outfile);
	free(head);
}

char	**remove_empty_string(char **arr)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	j = 0;
	ret = ft_calloc(1, sizeof(char *));
	while (arr[i] != NULL)
	{
		if (arr[i][0] != '\0')
		{
			ret = ft_realloc(ret, (j + 2) * sizeof(char *),
					(j + 1) * sizeof(char *));
			ret[j] = ft_strdup(arr[i]);
			j++;
		}
		i++;
	}
	if (j == 0)
		return (free_array(ret), arr);
	ret[j] = NULL;
	free_array(arr);
	return (ret);
}
