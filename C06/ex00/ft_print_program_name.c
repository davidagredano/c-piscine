/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:14:59 by dagredan          #+#    #+#             */
/*   Updated: 2024/11/12 11:15:32 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_print_program_name(char **argv)
{
	write(1, argv[0], ft_strlen(argv[0]));
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc)
		ft_print_program_name(argv);
}
