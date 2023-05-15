/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:09:00 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/15 17:06:26 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_line(char *str)
{
	int		i;
	char	*txt;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	txt = (char *)malloc(sizeof(char *) * (i + 1));
	if (txt == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		txt[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		txt[i++] = '\n';
	txt[i] = '\0';
	return (txt);
}

char	*removeline(char *str)
{
	size_t	i;
	int		j;
	char	*txt;
	size_t	len;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
		return (free (str), NULL);
	len = ft_strlen(str) - i;
	txt = (char *)malloc(sizeof(char *) * (len + 1));
	if (txt == 0)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
		txt[j++] = str[i++];
	txt[j] = '\0';
	free(str);
	return (txt);
}

char	*to_read(char *txt, int fd)
{
	char	*str;
	int		len;

	len = 1;
	str = (char *)malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while ((ft_strchr(txt, '\n')) == NULL && len != 0)
	{
		len = read(fd, str, BUFFER_SIZE);
		if (len == -1)
		{
			free(txt);
			free(str);
			return (NULL);
		}
		str[len] = '\0';
		txt = ft_strjoin(txt, str);
	}
	free (str);
	return (txt);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str == NULL)
		str = ft_strdup("");
	str = to_read(str, fd);
	if (str == NULL)
		return (NULL);
	line = get_line(str);
	str = removeline(str);
	return (line);
}
