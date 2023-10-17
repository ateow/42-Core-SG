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

char	**get_pathname(char **envp, char *cmd)
{
	int		i;
	char	*string;
	char	**bin_path;
	char	*tmp_cmd;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	bin_path = ft_split(envp[i] + 5, ':');
	i = 0;
	tmp_cmd = ft_strjoin("/", cmd);
	while (bin_path[i] != NULL)
	{
		string = ft_strjoin(bin_path[i], tmp_cmd);
		free(bin_path[i]);
		bin_path[i] = string;
		i++;
	}
	free(tmp_cmd);
	return (bin_path);
}

int	is_valid_command(char **path, char *cmd)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		if (access(path[i], F_OK) != -1)
		{
			if (access(path[i], X_OK) != -1)
				return (i);
			else
			{
				write(2, cmd, ft_strlen(cmd));
				write(2, ": Permission Denied\n", 21);
			}
		}
		i++;
	}
	write(2, "pipex: line 1: ", 15);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 21);
	return (-1);
}

char	**get_args(char *inputcmd)
{
	char	**args;
	char	*tmp;

	args = ft_split(inputcmd, ' ');
	if (ft_strrchr(inputcmd, '"') != NULL || ft_strrchr(inputcmd, '\'') != NULL)
	{
		if (ft_strrchr(inputcmd, '"') != NULL && ft_strrchr(inputcmd, '\'') == NULL)
			tmp = ft_strtrim(inputcmd + ft_strlen(args[0]) + 1, "\"");
		if (ft_strrchr(inputcmd, '"') == NULL && ft_strrchr(inputcmd, '\'') != NULL)
			tmp = ft_strtrim(inputcmd + ft_strlen(args[0]) + 1, "'");
		else if (ft_strrchr(inputcmd, '"') != NULL && ft_strrchr(inputcmd, '\'') != NULL)
		{
			tmp = ft_strtrim(inputcmd + ft_strlen(args[0]) + 1, "'");
			if (ft_strrchr(tmp, '\'') != NULL)
				tmp = ft_strtrim(inputcmd + ft_strlen(args[0]) + 1, "\"");
		}
		free(args[1]);
		args[1] = ft_strdup(tmp);
		free(tmp);
		free(args[2]);
		args[2] = NULL;
	}
	return (args);
}

int	main(int argc, char **argv, char *envp[])
{
	int		i;
	int		fd[2];
	int		child_pid;
	int		file;
	t_list	input1;
	t_list	input2;

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
	if (child_pid == -1) // fork error
	{
		perror("FORK");
		return (1);
	}
	if (child_pid == 0) // child process
	{		
		input1.cmd  = get_args(argv[2]);
		if (ft_strrchr(input1.cmd[0], '/') != NULL || envp == NULL)
		{	
			input1.bin_path = malloc(sizeof(char *) * 2);
			input1.bin_path[0] = ft_strdup(input1.cmd[0]);
			input1.bin_path[1] = NULL;
		}
		else 
			input1.bin_path = get_pathname(envp, input1.cmd[0]);
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
	else // parent process
	{
		input2.cmd  = get_args(argv[3]);
		if (ft_strrchr(input2.cmd[0], '/') != NULL || envp == NULL)
		{	
			input2.bin_path = malloc(sizeof(char *) * 2);
			input2.bin_path[0] = ft_strdup(input2.cmd[0]);
			input2.bin_path[1] = NULL;
		}
		else
			input2.bin_path = get_pathname(envp, input2.cmd[0]);
	
		if (access(argv[argc - 1], F_OK) == 0)
			unlink(argv[argc - 1]);
		file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (file == -1)
			perror(argv[1]);
		i = is_valid_command(input2.bin_path, input2.cmd[0]);
		if (i == -1 || file == -1)
		{
			return (free_struct(input2, 127));
		}
		dup2(file, STDOUT_FILENO);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);	
		if (execve(input2.bin_path[i], input2.cmd, envp) == -1)
			perror(input2.cmd[0]);
		return (free_struct(input2, 1));
	}
	close(fd[0]);
	close(fd[1]);
}

/*
char	*get_read_string(char *file) //extract content from file1
{
	char	buf[2];
	char	*line;
	char	*tmp;
	int	fd;

	buf[1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = ft_strjoin("", "");
	while (read(fd, buf, 1) != 0)
	{
		//printf("buf:%s\n", buf);
		tmp = ft_strjoin(line, buf);
		free(line);
		line = ft_strjoin("", tmp);
		free(tmp);
	}
	return (line);
}

char	**get_args(char *file, char *string) //get args {"ls" "-la" "contentfile1"} to pass into execve
{
	char	**args;
	char	*line;
	char	*tmp;
	
	char	*tmp2;

	line = get_read_string(file);
	if (line == NULL)
	{
		args = ft_split(string, ' ');
		return (args);
	}
	tmp = ft_strjoin(string, " ");
	tmp2 = ft_strjoin(tmp, line);
	args = ft_split(tmp2, ' ');
	free(line);
	free(tmp);
	free(tmp2);
	return (args);
}
*/
