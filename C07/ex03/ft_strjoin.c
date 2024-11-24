/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:49:24 by dagredan          #+#    #+#             */
/*   Updated: 2024/11/24 21:03:58 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strslen(int size, char **strs)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*joined_str;
	int		i;
	int		j;

	if (size == 0)
		return (ft_strdup(""));
	len = ft_strslen(size, strs) + ft_strlen(sep) * (size - 1) + 1;
	joined_str = (char *) malloc(len * sizeof(char));
	if (!joined_str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		ft_strcpy(&joined_str[j], strs[i]);
		j += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(&joined_str[j], sep);
			j += ft_strlen(sep);
		}
		i++;
	}
	return (joined_str);
}
