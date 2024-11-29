/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:26:08 by dagredan          #+#    #+#             */
/*   Updated: 2024/11/25 10:52:09 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_next_strlen(char *str, char *charset)
{
	int	len;
	int	i;

	len = 0;
	while (str[len])
	{
		i = 0;
		while (str[len + i] != '\0' && str[len + i] == charset[i])
		{
			if (charset[i + 1] == '\0')
				return (len);
			i++;
		}
		len++;
	}
	return (len);
}

int	ft_strslen(char *str, char *charset)
{
	int	strslen;
	int	next_strlen;
	int	i;

	strslen = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		next_strlen = ft_next_strlen(&str[i], charset);
		if (next_strlen > 0)
			strslen++;
		i += next_strlen;
		i += ft_strlen(charset);
	}
	return (strslen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	unsigned int	j;

	substr = (char *) malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	j = start;
	while (i < len)
	{
		substr[i] = s[j];
		i++;
		j++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		strslen;
	int		i;
	int		j;

	strslen = ft_strslen(str, charset);
	strs = (char **) malloc((strslen + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (j < strslen)
	{
		if (ft_next_strlen(&str[i], charset) > 0)
		{
			strs[j] = ft_substr(str, i, ft_next_strlen(&str[i], charset));
			j++;
		}
		i += ft_next_strlen(&str[i], charset);
		i += ft_strlen(charset);
	}
	strs[j] = NULL;
	return (strs);
}
