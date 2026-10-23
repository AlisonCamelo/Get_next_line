/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:08:14 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/11 12:37:19 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_linebreak(char *leftovers)
{
	char	*line;
	size_t	i;

	if (!leftovers || !*leftovers)
		return (NULL);
	i = 0;
	while (leftovers[i] != '\0' && leftovers[i] != '\n')
		i++;
	if (leftovers[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (leftovers[i] != '\0' && leftovers[i] != '\n')
	{
		line[i] = leftovers[i];
		i++;
	}
	if (leftovers[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_clean_leftovers(char *leftovers)
{
	char	*new_leftovers;
	size_t	i;
	size_t	j;

	if (!leftovers)
		return (NULL);
	i = 0;
	while (leftovers[i] != '\0' && leftovers[i] != '\n')
		i++;
	if (leftovers[i] == '\0')
		return (free(leftovers), NULL);
	new_leftovers = malloc(sizeof(char) * (ft_strlen(leftovers) -i + 1));
	if (!new_leftovers)
		return (free(leftovers), NULL);
	i++;
	j = 0;
	while (leftovers[i] != '\0')
		new_leftovers[j++] = leftovers[i++];
	new_leftovers[j] = '\0';
	return (free(leftovers), new_leftovers);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*clean_line;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(leftovers), leftovers = NULL, NULL);
	bytes_read = 1;
	while ((!leftovers || !ft_strchr(leftovers, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(leftovers), leftovers = NULL, NULL);
		buffer[bytes_read] = '\0';
		leftovers = ft_strjoin(leftovers, buffer);
	}
	free (buffer);
	clean_line = ft_linebreak(leftovers);
	if (!clean_line)
		return (free(leftovers), leftovers = NULL, NULL);
	leftovers = ft_clean_leftovers(leftovers);
	return (clean_line);
}
