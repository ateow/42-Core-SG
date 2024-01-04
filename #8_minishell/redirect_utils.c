/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:37:13 by ateow             #+#    #+#             */
/*   Updated: 2023/12/29 21:37:14 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_meta(char *string, char x)
{
	int		single_quotes;
	int		double_quotes;
	int		i;

	single_quotes = 0;
	double_quotes = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\'')
			single_quotes = !single_quotes;
		if (string[i] == '\"')
			double_quotes = !double_quotes;
		if (string[i] == x && single_quotes == 0 && double_quotes == 0)
			return (1);
		i++;
	}
	return (0);
}

void	set_outfile(t_cmd **next, char **redir, int jdx, char *file)
{
	if ((*next)->outfd != 1)
		close ((*next)->outfd);
	if ((*next)->outfile != NULL)
		free((*next)->outfile);
	if (redir[jdx][1] == '>')
		(*next)->outfd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		(*next)->outfd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	(*next)->outfile = file;
}

void	set_infile(t_cmd **next, char **redir, int jdx, char *file)
{
	if ((*next)->infd != 0)
		close ((*next)->infd);
	if ((*next)->infile != NULL)
		free((*next)->infile);
	if (redir[jdx][1] == '<')
		write_heredoc(next, file);
	else
		(*next)->infd = open(file, O_RDONLY);
	(*next)->infile = file;
}

int	set_in_and_out(t_cmd **next, char **redir, int jdx)
{
	char	*tmpstr;
	char	*file;
	char	target;

	target = ' ';
	if (redir[jdx + 1][0] == '"' || redir[jdx + 1][0] == '\'')
		target = redir[jdx + 1][0];
	file = ft_substr(redir[jdx + 1], (target != ' '), ft_strchr(redir[jdx + 1]
				+ (target != ' '), target) - redir[jdx + 1] - (target != ' '));
	tmpstr = ft_strjoin((*next)->cmdstr, ft_strchr(redir[jdx + 1]
				+ (target != ' '), target) + (target != ' '));
	if (redir[jdx][0] == '<')
		set_infile(next, redir, jdx, file);
	if (redir[jdx][0] == '>')
		set_outfile(next, redir, jdx, file);
	if ((*next)->infd < 0 || (*next)->outfd < 0)
	{
		perror(file);
		free (tmpstr);
		return (-1);
	}
	free ((*next)->cmdstr);
	(*next)->cmdstr = tmpstr;
	return (0);
}
