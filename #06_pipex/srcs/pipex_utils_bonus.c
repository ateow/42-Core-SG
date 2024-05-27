/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:39:16 by ateow             #+#    #+#             */
/*   Updated: 2023/10/20 12:39:17 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
			break ;
		}
		write(file_fd, str, ft_strlen(str));
		free(str);
	}
	printf("%s", argv[1]);
	free(limiter);
	close(file_fd);
}
