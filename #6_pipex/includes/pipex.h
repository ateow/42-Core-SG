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

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	char	**cmd;
	char	**bin_path;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		get_index(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strtrim(char const *s1, char const *set);

int		**create_fd_pipes(int argc);

int		open_file(char **argv, int **fd, t_list input);
int		get_path_index(t_list input, int **fd);
int		enter_pipe(char **argv, char **envp, int **fd);
int		middle_pipe(char *argv, char **envp, int **fd, int n);
int		exit_pipe(int argc, char **argv, char **envp, int *fd);

int		open_file_bonus(char *tmpfilename, int **fd, t_list input);
int		enter_pipe_bonus(char **argv, char **envp, int **fd);
int		exit_pipe_bonus(int argc, char **argv, char **envp, int *fd);

int		is_valid_command(char **path, char *cmd);
char	*amend_backslash(char *s);
char	**get_args(char *cmd);
char	**get_pathname(char **envp, char *cmd);
char	**get_bin_path(char *binarycmd, char **envp);

void	free_array(char **arr);
int		free_struct(t_list input, int ret);
int		free_struct_fd(t_list input, int **fd, int ret);
int		free_all_struct(t_list input1, t_list input2, int ret);
void	free_pipe_fd(int **fd);

void	here_doc(char **argv);

#endif
