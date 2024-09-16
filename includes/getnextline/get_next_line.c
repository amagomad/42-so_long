/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:48:15 by amagomad          #+#    #+#             */
/*   Updated: 2024/07/02 20:56:00 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_newline(int fd, char *buffer)
{
	char	*s;
	int		bytes;

	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, s, BUFFER_SIZE);
		if (bytes <= -1)
		{
			free(s);
			return (NULL);
		}
		s[bytes] = '\0';
		buffer = ft_strjoin(buffer, s);
	}
	free(s);
	return (buffer);
}

char	*extract_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (s[i] == '\0')
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*save_remainder(char *s)
{
	int		a;
	int		i;
	char	*remainder;

	a = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	remainder = malloc((sizeof(char)) * ((ft_strlengnl(s) - i) + 1));
	if (!remainder)
		return (NULL);
	i++;
	a = 0;
	while (s[i])
		remainder[a++] = s[i++];
	remainder[a] = '\0';
	free(s);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = read_until_newline(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = save_remainder(buffer);
	return (line);
}
