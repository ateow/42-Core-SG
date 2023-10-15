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

int	main(int argc, char **argv, char *envp[])
{
	int		i;
	int		fd[2];
	int		child_pid;
	int		file;
	t_list	input1;
	t_list	input2;

	//input1.cmd = get_args(argv[1], argv[2]); // for execve arguments
    	input1.cmd = ft_split(argv[2], ' ');	
	input1.bin_path = get_pathname(envp, input1.cmd[0]); // for execve binpath
    	input2.cmd = ft_split(argv[3], ' ');
	input2.bin_path = get_pathname(envp, input2.cmd[0]);
	//printf("input.cmd:%s\n", input1.cmd[2]);
	pipe(fd);
	child_pid = fork();
	if (child_pid == 0)
	{
		file = open(argv[1], O_RDONLY);
		dup2(file, STDIN_FILENO);
		close(file);
		
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		i = 0;
		while (execve(input1.bin_path[i], input1.cmd, NULL) == -1)
			i++;
		perror("execve");
	}
	else
	{
		file = open(argv[argc - 1], O_WRONLY | O_CREAT, 0777);
		dup2(file, STDOUT_FILENO);
		close(file);
			
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		i = 0;
    		while (execve(input2.bin_path[i], input2.cmd, NULL) == -1)
    			i++;
    		perror("execve");
	}
	close(fd[0]);
	close(fd[1]);
	free_struct(input1);
	free_struct(input2);
	return (0);
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