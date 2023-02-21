/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:17:35 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/05 17:11:08 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	complete_line(char **s1, char const *s2)
{
	size_t	i;
	size_t	o;

	if (!s1 || !s2)
		return ;
	i = 0;
	o = 0;
	while ((*s1)[o])
		o++;
	while (s2[i] != '\0')
		(*s1)[o++] = s2[i++];
	(*s1)[o] = '\0';
}

static char	*partial_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	if (buffer[0] == '\n')
		ft_strlcpy(buffer, &buffer[1], BUFFER_SIZE);
	else
		ft_strlcpy(buffer, &buffer[i], BUFFER_SIZE - i + 1);
	return (line);
}

static char	*get_line(char *buf, char *line, int fd, long int chars_read)
{
	char	*temp;

	while (ft_strchr(line, '\n') == NULL && chars_read != 0)
	{
		if (ft_strchr(&buf[0], '\n'))
		{
			temp = partial_line(&buf[0]);
			line = ft_realloc(line, ft_strlen(temp) + ft_strlen(line) + 1);
			complete_line(&line, temp);
			free(temp);
		}
		else
		{
			line = ft_realloc(line, ft_strlen(&buf[0]) + ft_strlen(line) + 1);
			complete_line(&line, &buf[0]);
			chars_read = read(fd, &buf[0], BUFFER_SIZE);
			buf[chars_read] = '\0';
		}
	}
	if (chars_read == 0 && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*read_file(char *buffer, char *line, int fd)
{
	long int	chars_read;

	if (buffer != NULL && buffer[0] != '\0')
	{
		line = ft_realloc(line, ft_strlen(&buffer[0]) + ft_strlen(line) + 1);
		complete_line(&line, &buffer[0]);
		buffer[0] = '\0';
	}
	chars_read = read(fd, &buffer[0], BUFFER_SIZE);
	if (chars_read < 0)
	{
		free(line);
		return (NULL);
	}
	buffer[chars_read] = '\0';
	return (get_line(&buffer[0], line, fd, chars_read));
}

char	*get_next_line(int fd)
{
	static char		*buffer[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (buffer[fd] == NULL)
	{
		buffer[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		buffer[fd][0] = '\0';
	}
	if (ft_strchr(buffer[fd], '\n') == NULL)
		line = ft_strdup((char *)"");
	if (ft_strchr(buffer[fd], '\n'))
		line = partial_line(buffer[fd]);
	else
		line = (read_file(buffer[fd], line, fd));
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
