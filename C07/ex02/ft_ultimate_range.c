/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:34:09 by dagredan          #+#    #+#             */
/*   Updated: 2024/11/24 16:19:39 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	range_len;
	int	i;

	range_len = max - min;
	if (range_len <= 0)
	{
		*range = NULL;
		return (0);
	}
	range[0] = (int *) malloc(range_len * sizeof(int));
	if (!range)
		return (-1);
	i = 0;
	while (i < range_len)
	{
		range[0][i] = min + i;
		i++;
	}
	return (range_len);
}
