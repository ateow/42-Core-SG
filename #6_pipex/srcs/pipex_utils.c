/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:22:12 by ateow             #+#    #+#             */
/*   Updated: 2023/10/18 11:22:13 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	is_valid_command(char **path, char *cmd)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		path[i] = amend_backslash(path[i]);
		if (access(path[i], F_OK) == 0)
		{
			if (access(path[i], X_OK) == 0)
				return (i);
			else
			{
				write(2, cmd, ft_strlen(cmd));
				write(2, ": Permission Denied\n", 21);
				return (126);
			}
		}
		i++;
	}
	write(2, "pipex: line 1: ", 15);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 21);
	return (-1);
}

char	*amend_backslash(char *s)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (i < ft_strlen(s) - 1)
	{
		if ((s[i] == '\\') && (s[i + 1] == '\\'))
		{
			j = i - 1;
			while (s[j++] != '\0')
				s[j] = s[j + 1];
		}
		if ((s[i] == '\\') && ((s[i + 1] == '\'') || (s[i + 1] == '\"')))
		{
			j = i - 1;
			while (s[j++] != '\0')
				s[j] = s[j + 1];
		}
		i++;
	}
	tmp = ft_strdup(s);
	free(s);
	return (tmp);
}

char	**get_args(char *cmd)
{
	char	**args;
	char	*tmp;

	args = ft_split(cmd, ' ');
	if (ft_strrchr(cmd, '"') != NULL || ft_strrchr(cmd, '\'') != NULL)
	{
		if (ft_strrchr(cmd, '"') != NULL && ft_strrchr(cmd, '\'') == NULL)
			tmp = ft_strtrim(cmd + ft_strlen(args[0]) + 1, " \"");
		if (ft_strrchr(cmd, '\'') != NULL)
		{
			tmp = ft_strtrim(cmd + ft_strlen(args[0]) + 1, " '");
			if (ft_strrchr(tmp, '\'') != NULL)
				tmp = ft_strtrim(cmd + ft_strlen(args[0]) + 1, " \"");
		}
		if (ft_strncmp(args[0], "awk", 3) == 0)
			tmp = amend_backslash(tmp);
		free(args[1]);
		args[1] = ft_strdup(tmp);
		free(tmp);
		free(args[2]);
		args[2] = NULL;
	}
	return (args);
}

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
// get_args Comments
// if no quotes in input cmd, do a ft_split on cmd and return
// if there are quotes in cmd flag check what quotes ' or " or both
// if only " " found, remove them and store what is in quote
// if ' ' found, remove them and store what is in quote
//	check if can trim ' '. if cannot trim, means wrap in " ' ' "
//	proceed to remove ". store 'XX'
// '"xx"' will become "xx" (no error but could break based on command)
// "'xx'" will become 'xx' (error to read single quote)
