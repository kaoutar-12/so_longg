/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:48:09 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/21 14:54:47 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_close_game(t_game *game)
{
    mlx_destroy_image(game->mlx,game->f);
    mlx_destroy_image(game->mlx,game->c);
    mlx_destroy_image(game->mlx,game->p);
    mlx_destroy_image(game->mlx,game->w);
    mlx_destroy_image(game->mlx,game->e);
    mlx_destroy_window(game->mlx, game->mlx_win);
    free(game);
    exit(0);
    return (0);
}