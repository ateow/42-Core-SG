/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:55:40 by ateow             #+#    #+#             */
/*   Updated: 2023/10/14 19:55:41 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// to write, read, close, access, pipe, dup, dup2, execve, fork
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

// malloc, free, exit
# include <stdlib.h>

// open, unlink
# include <fcntl.h>

// waitpid, wait
# include <sys/wait.h>

// strerror
# include <string.h>

// perror
# include <stdio.h>

typedef struct s_list
{
	char	**cmd;
	char	**bin_path;
}	t_list;

// functions
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strtrim(char const *s1, char const *set);

int		is_valid_command(char **path, char *cmd);
char	*amend_backslash(char *s);
char	**get_args(char *cmd);
char	**get_pathname(char **envp, char *cmd);
char	**get_bin_path(char *binarycmd, char **envp);

void	free_array(char **arr);
int		free_struct(t_list input, int ret);
int		free_all_struct(t_list input1, t_list input2, int ret);

#endif
