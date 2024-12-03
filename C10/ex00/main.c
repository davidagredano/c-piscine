/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:35:26 by dagredan          #+#    #+#             */
/*   Updated: 2024/12/03 18:48:18 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#define BUFFER_SIZE 1024

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

bool	ft_display_file(int fd)
{
	char	buf[BUFFER_SIZE];
	int		bytes_read;

	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_putstr_fd("Error reading file.\n", STDERR_FILENO);
			close(fd);
			return (false);
		}
		else if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		ft_putstr_fd(buf, STDOUT_FILENO);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		if (argc == 1)
			ft_putstr_fd("File name missing.\n", STDERR_FILENO);
		else
			ft_putstr_fd("Too many arguments.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot read file.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!ft_display_file(fd))
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	if (close(fd) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
