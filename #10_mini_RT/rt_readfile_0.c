/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_readfile_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:20:23 by cooi              #+#    #+#             */
/*   Updated: 2024/01/27 09:25:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	put_error(char *str)
{
	if (errno != 0)
	{
		perror(str);
		exit(errno);
	}
	ft_putstr_fd(str, 2);
}

int	parse_object(t_rt **f, char **split)
{
	if (split[0] == NULL)
		return (free_array(split), 0);
	if (!ft_strncmp(split[0], "A", ft_strlen(split[0])) && arrlen(split) == 3)
		return (get_ambient(f, split));
	if (!ft_strncmp(split[0], "C", ft_strlen(split[0])) && arrlen(split) == 4)
		return (get_camera(f, split));
	if (((!ft_strncmp(split[0], "L", ft_strlen(split[0])))
			|| (!ft_strncmp(split[0], "l", ft_strlen(split[0]))))
		&& arrlen(split) == 4)
		return (get_light(f, split));
	if (!ft_strncmp(split[0], "sp", ft_strlen(split[0])) && (arrlen(split) == 4
			|| arrlen(split) == 5
			|| arrlen(split) == 10))
		return (get_sphere(f, split));
	if (!ft_strncmp(split[0], "pl", ft_strlen(split[0])) && arrlen(split) == 4)
		return (get_plane(f, split));
	if (!ft_strncmp(split[0], "cy", ft_strlen(split[0])) && arrlen(split) == 6)
		return (get_cylinder(f, split));
	if (!ft_strncmp(split[0], "co", ft_strlen(split[0])) && arrlen(split) == 6)
		return (get_cone(f, split));
	return (free_rt(f), free_array(split), -1);
}

void	check_acl(t_rt **f)
{
	if ((*f)->a == NULL || (*f)->c == NULL || (*f)->l == NULL)
	{
		put_error("Error\n");
		if ((*f)->a == NULL)
			put_error("missing ambient inputs\n");
		if ((*f)->c == NULL)
			put_error("missing camera inputs\n");
		if ((*f)->l == NULL)
			put_error("missing light inputs\n");
		free_rt(f);
	}
}

void	read_scene(t_rt **f, int fd)
{
	char	*line;
	char	*tmp;
	char	**split;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			check_acl(f);
			return ;
		}
		tmp = ft_strtrim(line, "\n");
		split = ft_split(tmp, ' ');
		free (tmp);
		if (parse_object(f, split) == -1)
		{
			put_error("Error\n");
			put_error(line);
			free (line);
			free_rt(f);
			return ;
		}
		free (line);
	}
}

t_rt	*open_scene(char **argv)
{
	t_rt	*f;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		put_error(argv[1]);
	f = ft_calloc(1, sizeof(t_rt));
	if (!f)
		put_error("Malloc error!");
	f->has_moon = 0;
	f->has_earth = 0;
	f->has_sun = 0;
	read_scene(&f, fd);
	close(fd);
	return (f);
}
