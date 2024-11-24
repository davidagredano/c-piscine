/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:00:25 by dagredan          #+#    #+#             */
/*   Updated: 2024/11/24 16:17:14 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	range_len;
	int	i;

	range_len = max - min;
	if (range_len <= 0)
		return (NULL);
	range = (int *) malloc(range_len * sizeof(int));
	if (!range)
		return (NULL);
	i = 0;
	while (i < range_len)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
