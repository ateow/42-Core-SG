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

int	enter_pipe(char **argv, char **envp, int *fd)
{
	int		i;
	int		file;
	t_list	input1;

	input1.cmd = get_args(argv[2]);
	input1.bin_path = get_bin_path(input1.cmd[0], envp);
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(2, "pipex: line 1: ", 15);
		perror(argv[1]);
	}
	i = is_valid_command(input1.bin_path, input1.cmd[0]);
	if (i == -1 || file == -1)
		return (free_struct(input1, 127));
	close(fd[0]);
	dup2(file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (execve(input1.bin_path[i], input1.cmd, envp) == -1)
		perror(input1.cmd[0]);
	return (free_struct(input1, 1));
}

int	exit_pipe(int argc, char **argv, char **envp, int *fd)
{
	int		i;
	int		file;
	t_list	input2;

	input2.cmd = get_args(argv[3]);
	input2.bin_path = get_bin_path(input2.cmd[0], envp);
	file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		perror(argv[1]);
	i = is_valid_command(input2.bin_path, input2.cmd[0]);
	if (i == -1 || file == -1)
		return (free_struct(input2, 127));
	close(fd[1]);
	dup2(file, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	if (execve(input2.bin_path[i], input2.cmd, envp) == -1)
		perror(input2.cmd[0]);
	return (free_struct(input2, 1));
}

int	main(int argc, char **argv, char *envp[])
{
	int	fd[2];
	int	child_pid;

	if (argc < 5)
	{
		write(2, "Not enough arguments\n", 21);
		return (1);
	}
	if (pipe(fd) == -1)
	{
		perror("PIPE");
		return (1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("FORK");
		return (1);
	}
	if (child_pid == 0)
		return (enter_pipe(argv, envp, fd));
	else
		return (exit_pipe(argc, argv, envp, fd));
	close(fd[0]);
	close(fd[1]);
}
/*	i = 0;
	while (argv[i] != NULL)
	{
		printf("input argv[%d]:|%s|\n", i, argv[i]);
		i++;
	}
*/
	//print ARGS
/*	int i = 0;
	write(1,"\n",1);
	while (args[i] != NULL)
	{
		printf("flags args[%d]:|%s|\n", i, args[i]);
		i++;
	}
	write(1,"\n",1);*/
