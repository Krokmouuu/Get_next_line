/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:23:48 by bleroy            #+#    #+#             */
/*   Updated: 2021/12/09 15:26:02 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buf)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buf)
		return (NULL);
	tmp = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buf)) + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	if (str)
		while (str[++i] != '\0')
			tmp[i] = str[i];
	j = 0;
	while (buf[j] != '\0')
		tmp[i++] = buf[j++];
	tmp[ft_strlen(str) + ft_strlen(buf)] = '\0';
	free (str);
	return (tmp);
}

char	*ft_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc((sizeof(char) * (i + 2)));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_newline(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = (char *)malloc(sizeof (char) + (ft_strlen(str) - i + 1));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free (str);
	return (line);
}
