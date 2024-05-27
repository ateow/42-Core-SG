/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:11:17 by ateow             #+#    #+#             */
/*   Updated: 2023/12/29 21:11:18 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_heredoc(t_cmd **next, char *file)
{
	int		pipefd[2];
	char	*line;

	if (pipe(pipefd) < 0)
		perror("pipe");
	(*next)->infd = pipefd[0];
	while (1)
	{
		write(1, ">", 1);
		line = get_next_line(0);
		if (!line || ((ft_strncmp(line, file, ft_strlen(file)) == 0)
				&& line[ft_strlen(file)] == '\n'))
		{
			free (line);
			break ;
		}
		write(pipefd[1], line, ft_strlen(line));
		free (line);
	}
	close(pipefd[1]);
}

void	initialise_cmd(t_cmd **next)
{
	(*next)->cmdstr = ft_strdup("");
	(*next)->infd = 0;
	(*next)->outfd = 1;
	(*next)->infile = NULL;
	(*next)->outfile = NULL;
}

int	parse_redir(t_cmd **cmds, char **redir, int jdx)
{
	char	*tmpstr;

	if (ft_strchr("<>", redir[jdx][0]) == NULL)
	{
		tmpstr = ft_strjoin((*cmds)->cmdstr, redir[jdx]);
		free ((*cmds)->cmdstr);
		(*cmds)->cmdstr = tmpstr;
	}
	else
	{
		if (redir[jdx + 1] == NULL || redir[jdx + 1][0] == '(')
		{
			printf("Minishell: syntax error near unexpected token");
			if (redir[jdx + 1] == NULL)
				printf("'newline'\n");
			else
				printf("'('\n");
			free_array(redir);
			free_t_cmd_list((*cmds));
			return (-1);
		}
		if (set_in_and_out(cmds, redir, jdx) == -1)
			return (-1);
	}
	return (jdx + (ft_strchr("<>", redir[jdx][0]) != NULL));
}

void	redirection(char *input, t_var *vars)
{
	int		jdx;
	char	**redir;
	t_cmd	*cmds;

	redir = split_redirection(input);
	jdx = 0;
	cmds = ft_calloc(1, sizeof(t_cmd));
	initialise_cmd(&cmds);
	while (redir[jdx])
	{
		jdx = parse_redir(&cmds, redir, jdx);
		if (jdx == -1)
			break ;
		jdx++;
	}
	free_array(redir);
	execute_redirect(cmds, vars);
	free_t_cmd_list(cmds);
}

void	execute_redirect(t_cmd	*cmds, t_var *vars)
{
	int	original_stdin;
	int	original_stdout;

	original_stdin = dup(0);
	original_stdout = dup(1);
	if (cmds->infile && cmds->infile[0] != '\0')
	{
		dup2(cmds->infd, 0);
		close(cmds->infd);
	}
	if (cmds->outfile && cmds->outfile[0] != '\0')
	{
		dup2(cmds->outfd, 1);
		close(cmds->outfd);
	}
	if (cmds->outfd < 0 || cmds->infd < 0)
		vars->exit_status = 1;
	else if (cmds->cmdstr[0] == '(')
		brackets_logic(cmds->cmdstr, vars);
	else
		expansion_execute(cmds->cmdstr, vars);
	dup2(original_stdin, 0);
	dup2(original_stdout, 1);
	close(original_stdin);
	close(original_stdout);
}
