/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:34:28 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/04 16:23:01 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
}

bool	ft_display_file(int fd)
{
	char	buf[BUFFER_SIZE];
	int		bytes_read;

	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			write(STDOUT_FILENO, buf, bytes_read);
			continue ;
		}
		if (bytes_read < 0)
		{
			ft_putendl_fd(strerror(errno), STDERR_FILENO);
			close(fd);
			return (false);
		}
		break ;
	}
	return (true);
}

bool	ft_read_file(char *path)
{
	int		fd;
	bool	return_val;

	return_val = true;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (false);
	}
	if (!ft_display_file(fd))
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return_val = false;
	}
	if (close(fd) == -1)
	{
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return_val = false;
	}
	return (return_val);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		ft_display_file(STDIN_FILENO);
	else if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (!ft_read_file(argv[i]))
				return (EXIT_FAILURE);
			i++;
		}
		return (EXIT_SUCCESS);
	}
}
