/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:10:09 by ateow             #+#    #+#             */
/*   Updated: 2023/12/28 17:10:10 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_directory(const char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir != NULL)
	{
		closedir(dir);
		return (1);
	}
	else
		return (0);
}

int	is_valid_command(char **path, char *cmd, int i)
{
	while (path && path[i] != NULL)
	{
		if (access(path[i], F_OK) == 0)
		{
			if (is_directory(path[i]) == 1)
			{
				write(2, cmd, ft_strlen(cmd));
				write(2, ": Is a directory\n", 17);
				return (126);
			}
			else if (access(path[i], X_OK) == 0)
				return (i);
			else
			{
				write(2, cmd, ft_strlen(cmd));
				write(2, ": Permission denied\n", 21);
				return (126);
			}
		}
		i++;
	}
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 21);
	return (127);
}

char	**get_pathname(char **envp, char *cmd)
{
	int		i;
	char	*string;
	char	**bin_path;
	char	*tmp_cmd;

	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	}
	if (!envp[i])
		return (NULL);
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

char	**get_bin_path(char *binarycmd, char **envp)
{
	char	**bin_path;

	if (ft_strrchr(binarycmd, '/') != NULL)
	{
		bin_path = malloc(sizeof(char *) * 2);
		bin_path[0] = ft_strdup(binarycmd);
		bin_path[1] = NULL;
	}
	else if (envp[0] == NULL)
	{
		bin_path = malloc(sizeof(char *) * 4);
		bin_path[0] = ft_strjoin("/bin/", binarycmd);
		bin_path[1] = ft_strjoin("/usr/bin/", binarycmd);
		bin_path[2] = ft_strjoin("/usr/local/bin/", binarycmd);
		bin_path[3] = NULL;
	}
	else
		bin_path = get_pathname(envp, binarycmd);
	return (bin_path);
}

int	get_path_index(char **bin_paths, char *cmd)
{
	int	i;

	if (cmd == NULL || *cmd == '\0')
		exit (0);
	i = is_valid_command(bin_paths, cmd, 0);
	if (i == 126 || i == 127)
		exit (i);
	return (i);
}
