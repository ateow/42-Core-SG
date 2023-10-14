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

int	main(int argc, char *argv[], char *envp[]) 
{
	int	status;
	int	i;
	char	**bin_path;
	char	*string;
	char	*cmd1;
	char	*flags1[3];

	i = 0;
	bin_path = ft_split(envp[40] + 5, ':');
	flags1[0] = argv[1];
	flags1[1] = argv[2];
	flags1[2] = NULL;

	cmd1 = ft_strjoin("/", argv[1]);

	while (bin_path[i] != NULL)
	{
		string = ft_strjoin(bin_path[i], cmd1);
		printf("%s\n", string);
		execve(string, flags1 , NULL);
		i++;
		free(string);
	}
	free(cmd1);
	i = 0;
	while (bin_path[i] != NULL)
	{
		free(bin_path[i]);
		i++;
	}
	free(bin_path);
	return (0);
}
	/*
	child_pid = fork();

	if (child_pid == 0) // this is child process
		printf("Child process (PID: %d)\n", getpid());
	else // This is the parent process
		printf("Parent process (PID: %d) created a child (PID: %d)\n", getpid(), child_pid);
	*/
