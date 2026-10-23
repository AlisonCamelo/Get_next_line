/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:55:43 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/11 12:17:54 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	iterate;

	iterate = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		iterate++;
		s++;
	}
	return (iterate);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	iterate;
	size_t	lenght;

	lenght = ft_strlen(src);
	iterate = 0;
	if (size == 0)
		return (lenght);
	while (src[iterate] != '\0' && iterate < size - 1)
	{
		dst[iterate] = src[iterate];
		iterate++;
	}
	dst[iterate] = '\0';
	return (lenght);
}

char	*ft_strdup(const char *s)
{
	char	*k;
	size_t	len;

	len = ft_strlen(s);
	k = malloc(sizeof(char) * (len + 1));
	if (k == NULL)
		return (NULL);
	ft_strlcpy(k, s, len + 1);
	return (k);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*return_data;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	return_data = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!return_data)
		return (free((void *)s1), NULL);
	while (s1[i] != '\0')
	{
		return_data[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		return_data[i++] = s2[j++];
	return_data[i] = '\0';
	return (free((void *)s1), return_data);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!*s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
