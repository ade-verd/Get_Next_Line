/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:46:04 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/07 11:44:08 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_open_file(char *path, int flags)
{
	int		fd;

	fd = open(path, flags);
	if (fd == -1)
	{
		ft_putstr_fd("open() error\n", 2);
		return (-1);
	}
	return (fd);
}

/*int		ft_display_all_fd(int fd)
{
	int		ret;
	int		i;

	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret == -1)
		{
			printf("get_next_line() error\n");
			return (ret);
		}
		//printf("return: %-5d\tline: %-5d\t|%s|\n", ret, i, line);
		i++;
	}
	return (ret);
}*/

/*int		ft_two_fd(int fd1, int fd2)
{
	
}*/

int		main(int ac, char **av)
{
	int		i;
	char	*line;
	int		fd[ac - 1];
	int		ret;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if ((fd[i] = ft_open_file(av[i], O_RDONLY)) == -1)
				return (-1);
			ret = get_next_line(fd[i], &line);
			if (ret == -1)
			{
				printf("get_next_line() error\n");
				return (-1);
			}
			ret = get_next_line(fd[i], &line);
			if (ret == -1)
			{
				printf("get_next_line() error\n");
				return (-1);
			}
			if (close(fd[i]) == -1)
			{
				ft_putstr_fd("close() error" ,2);
				return (-1);
			}
			i++;
		}
	}
	return (0);
}
