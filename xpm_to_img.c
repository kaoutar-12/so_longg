/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:49:26 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/18 21:39:22 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	xpm_to_img(t_game *game)
{
	game->p = mlx_xpm_file_to_image (game->mlx, "./ironman.xpm", &game->img_w, &game->img_h);
	game->c = mlx_xpm_file_to_image(game->mlx, "./ironman_heart.xpm", &game->img_w, &game->img_h);
	game->w = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &game->img_w, &game->img_h);
	game->e = mlx_xpm_file_to_image(game->mlx, "./exit.xpm", &game->img_w, &game->img_h);
	game->f = mlx_xpm_file_to_image(game->mlx, "./floor.xpm", &game->img_w, &game->img_h);
}