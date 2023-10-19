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

int	enter_pipe_bonus(char **argv, char **envp, int **fd)
{
	int		i;
	int		file;
	int		child_pid;
	t_list	input1;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("FORK");
		return (1);
	}
	if (child_pid == 0)
	{
		input1.cmd = get_args(argv[3]);
		input1.bin_path = get_bin_path(input1.cmd[0], envp);
		file = open("bonus_infile", O_RDONLY);
		unlink("bonus_infile");
		if (file == -1)
		{
			write(2, "pipex: line 1: ", 15);
			perror(argv[1]);
		}
		i = is_valid_command(input1.bin_path, input1.cmd[0]);
		if (i == -1 || file == -1)
		{
			free_pipe_fd(fd);
			exit (free_struct(input1, 127));
		}
		dup2(file, STDIN_FILENO);  // Redirect stdin
		dup2(fd[0][1], STDOUT_FILENO);  // Redirect stdout
		close(fd[0][0]);  // Close the read end of the pipe		
		close(fd[0][1]);  // Close the write end of the pipe
		if (execve(input1.bin_path[i], input1.cmd, envp) == -1)
			perror(input1.cmd[0]);
		free_pipe_fd(fd);
		exit (free_struct(input1, 1));
	} 
	else
		return (0);
}

int	enter_pipe(char **argv, char **envp, int **fd)
{
	int		i;
	int		file;
	int		child_pid;
	t_list	input1;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("FORK");
		return (1);
	}
	if (child_pid == 0)
	{
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
		{
			free_pipe_fd(fd);
			exit (free_struct(input1, 127));
		}
		dup2(file, STDIN_FILENO);  // Redirect stdin
		dup2(fd[0][1], STDOUT_FILENO);  // Redirect stdout
		close(fd[0][0]);  // Close the read end of the pipe		
		close(fd[0][1]);  // Close the write end of the pipe
		if (execve(input1.bin_path[i], input1.cmd, envp) == -1)
			perror(input1.cmd[0]);
		free_pipe_fd(fd);
		exit (free_struct(input1, 1));
	} 
	else
		return (0);
}

int	middle_pipe(char *argv, char **envp, int **fd, int n)
{
	int		i;
	int		child_pid;
	t_list	input;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("FORK");
		return (1);
	}
	if (child_pid == 0)
	{
		input.cmd = get_args(argv);
		input.bin_path = get_bin_path(input.cmd[0], envp);
		i = is_valid_command(input.bin_path, input.cmd[0]);
		if (i == -1)
		{
			free_pipe_fd(fd);
			exit (free_struct(input, 1));
		}
		dup2(fd[n][0], STDIN_FILENO);
		dup2(fd[n+1][1], STDOUT_FILENO);
		close(fd[n][1]);
		close(fd[n][0]);
		if (execve(input.bin_path[i], input.cmd, envp) == -1)
			perror(input.cmd[0]);
		free_pipe_fd(fd);
		exit (free_struct(input, 1));
	} 
	else
	{
		close(fd[n][1]);
		close(fd[n][0]);
		return (0);
	}
}

int	exit_pipe(int argc, char **argv, char **envp, int *fd)
{
	int		i;
	int		file;
	t_list	input2;

	input2.cmd = get_args(argv[argc - 2]);
	input2.bin_path = get_bin_path(input2.cmd[0], envp);
	file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		perror(argv[argc - 1]);
	i = is_valid_command(input2.bin_path, input2.cmd[0]);
	if (i == -1 || file == -1)
		return (free_struct(input2, 127));
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);	
	if (execve(input2.bin_path[i], input2.cmd, envp) == -1)
		perror(input2.cmd[0]);
	return (free_struct(input2, 1));
}

int	**create_fd_pipes(int argc)
{
	int	**fd;
	int	i;

	i = 0;
	fd = malloc(sizeof(int*) * (argc - 4 + 1));
	if (!fd)
		return (NULL);
	while (i < (argc - 4))
	{
		fd[i] = malloc(sizeof(int) * 2);
		if (!fd[i])
			return (NULL);
		if (pipe(fd[i]) == -1)
		{
			perror("PIPE");
			return (NULL);
		}
		i++;
	}
	fd[i] = NULL;
	return (fd);
}

void	here_doc(char **argv)
{
	char	*str;
	char	*limiter;
	int		file_fd;

	file_fd = open("bonus_infile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	limiter = ft_strjoin(argv[2], "\n");
	while (file_fd != -1)
	{
		write(1, "heredoc> ", 9);
		str = get_next_line(0);
		if (ft_strncmp(limiter, str, ft_strlen(str)) == 0)
		{
			free(str);
			break;
		}
		write(file_fd, str, ft_strlen(str));
		free(str);
	}
	printf("%s", argv[1]);
	free(limiter);
	close(file_fd);
}

int	main(int argc, char **argv, char *envp[])
{
	int	**fd;
	int	i;
	int	ret_value;

	i = 0;
	if (argc < 5)
	{
		write(2, "Not enough arguments\n", 21);
		return (1);
	}
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		here_doc(argv);
		fd = create_fd_pipes(argc - 1);
		enter_pipe_bonus(argv, envp, fd);
		while (i < (argc - 6) && argc > 6)
		{
			middle_pipe(argv[i + 4], envp, fd, i);
			i++;
		}
	}
	else
	{
		fd = create_fd_pipes(argc);
		enter_pipe(argv, envp, fd);
		while (i < (argc - 5) && argc > 5)
		{
			middle_pipe(argv[i + 3], envp, fd, i);
			i++;
		}
	}
	ret_value = exit_pipe(argc, argv, envp, fd[i]);
	free_pipe_fd(fd);
	return (ret_value);
	
}
