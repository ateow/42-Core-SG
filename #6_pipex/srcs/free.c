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

int	free_struct(t_list input, int ret)
{
	free_array(input.cmd);
	free_array(input.bin_path);
	return (ret);
}

int	free_struct_fd(t_list input, int **fd, int ret)
{
	free_array(input.cmd);
	free_array(input.bin_path);
	free_pipe_fd(fd);
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
