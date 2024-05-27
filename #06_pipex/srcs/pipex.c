/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:06:33 by ateow             #+#    #+#             */
/*   Updated: 2023/10/14 16:06:36 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char **argv, int **fd, t_list input)
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(2, "pipex: line 1: ", 15);
		perror(argv[1]);
		exit (free_struct_fd(input, fd, 127));
	}
	return (file);
}

int	get_path_index(t_list input, int **fd)
{
	int	i;

	i = is_valid_command(input.bin_path, input.cmd[0]);
	if (i == 126 || i == -1)
		exit (free_struct_fd(input, fd, i));
	return (i);
}

int	enter_pipe(char **argv, char **envp, int **fd)
{
	int		i;
	int		file;
	int		child_pid;
	t_list	input;

	child_pid = fork();
	if (child_pid == -1)
		perror("FORK");
	else if (child_pid == 0)
	{
		input.cmd = get_args(argv[2]);
		input.bin_path = get_bin_path(input.cmd[0], envp);
		file = open_file(argv, fd, input);
		i = get_path_index(input, fd);
		dup2(file, STDIN_FILENO);
		dup2(fd[0][1], STDOUT_FILENO);
		close(fd[0][0]);
		close(fd[0][1]);
		if (execve(input.bin_path[i], input.cmd, envp) == -1)
			perror(input.cmd[0]);
		exit (free_struct_fd(input, fd, 1));
	}
	else
		return (0);
	return (1);
}

int	middle_pipe(char *argv, char **envp, int **fd, int n)
{
	int		i;
	int		child_pid;
	t_list	input;

	child_pid = fork();
	if (child_pid == -1)
		perror("FORK");
	else if (child_pid == 0)
	{
		input.cmd = get_args(argv);
		input.bin_path = get_bin_path(input.cmd[0], envp);
		i = get_path_index(input, fd);
		dup2(fd[n][0], STDIN_FILENO);
		dup2(fd[n + 1][1], STDOUT_FILENO);
		close(fd[n][1]);
		close(fd[n][0]);
		if (execve(input.bin_path[i], input.cmd, envp) == -1)
			perror(input.cmd[0]);
		exit (free_struct_fd(input, fd, 1));
	}
	else
		return (0);
	return (1);
}

int	exit_pipe(int argc, char **argv, char **envp, int *fd)
{
	int		i;
	int		file;
	t_list	input;

	input.cmd = get_args(argv[argc - 2]);
	input.bin_path = get_bin_path(input.cmd[0], envp);
	if (access(argv[argc - 1], F_OK) == 0
		&& (access(argv[argc - 1], W_OK) != 0))
		return (free_struct(input, 2));
	file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		perror(argv[argc - 1]);
	i = is_valid_command(input.bin_path, input.cmd[0]);
	if (i == 126)
		return (free_struct(input, 126));
	if (i == -1 || file == -1)
		return (free_struct(input, 127));
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (execve(input.bin_path[i], input.cmd, envp) == -1)
		perror(input.cmd[0]);
	return (free_struct(input, 1));
}
