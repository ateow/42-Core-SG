/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:25:21 by ateow             #+#    #+#             */
/*   Updated: 2023/11/01 17:25:23 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../includes/libft.h"

void	count_items(char **string_arr, t_coord **node, int *i, int *j)
{
	while (string_arr[*i] != NULL)
		*i = *i + 1;
	if (node != NULL)
	{
		while (node[*j] != NULL)
			*j = *j + 1;
	}
}

void	allocated_exisiting_data(t_coord **node, t_coord **ret, int *j)
{
	if (node != NULL)
	{
		while (node[*j] != NULL)
		{
			ret[*j] = malloc(sizeof(t_coord));
			ret[*j]->x = node[*j]->x;
			ret[*j]->y = node[*j]->y;
			ret[*j]->z = node[*j]->z;
			*j = *j + 1;
		}
	}
}

t_coord	**create_node(char *string, t_coord **node, int row)
{
	t_coord	**ret;
	char	**string_arr;
	int		i;
	int		j;

	string_arr = ft_split(string, ' ');
	i = 0;
	j = 0;
	count_items(string_arr, node, &i, &j);
	ret = malloc(sizeof(t_coord) * (i + j + 1));
	i = -1;
	j = 0;
	allocated_exisiting_data(node, ret, &j);
	while (string_arr[++i] != NULL)
	{
		ret[j] = malloc(sizeof(t_coord));
		ret[j]->x = i;
		ret[j]->y = row;
		ret[j]->z = ft_atoi(string_arr[i]);
		j++;
	}
	ret[j] = NULL;
	free_struct_arr(node);
	free_string_arr(string_arr);
	return (ret);
}
