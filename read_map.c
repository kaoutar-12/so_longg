/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:58:41 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/15 17:18:34 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **map_read(int fd)
{
    char *s = ft_strdup("");
    char *str = get_next_line(fd);
    while(str != NULL)
    {
        char *v = ft_strjoin(s, str);
        free (str);
        s = v;
        str = get_next_line(fd);
    }
    char **map = ft_split(s, '\n');
    free(str);
    free(s);
    return(map);
}
