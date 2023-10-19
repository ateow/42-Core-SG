/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:43:02 by ateow             #+#    #+#             */
/*   Updated: 2023/10/15 15:43:03 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	free_all_struct(t_list input1, t_list input2, int ret)
{
	free_array(input1.cmd);
	free_array(input1.bin_path);
	free_array(input2.cmd);
	free_array(input2.bin_path);
	return (ret);
}

int	free_struct(t_list input, int ret)
{
	free_array(input.cmd);
	free_array(input.bin_path);
	return (ret);
}

void	free_pipe_fd(int **fd)
{
	int	i;

	i = 0;
	if (fd == NULL)
		return ;
	while (fd[i] != NULL)
	{
		free(fd[i]);
		i++;
	}
	free (fd);
}
