/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmouradi <kmouradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:10:39 by kmouradi          #+#    #+#             */
/*   Updated: 2023/05/19 14:57:53 by kmouradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ft_up(t_game *game)
{
	game->j = 0;
	game->i = 0;
	while (game->new_map[game->j])
	{
		game->i = 0;
		while(game->new_map[game->j][game->i])
		{
			if (game->new_map[game->j][game->i] == 'P')
			{
				if (game->new_map[game->j - 1][game->i] == '0' || game->new_map[game->j - 1][game->i] == 'C')
				{
					game->new_map[game->j - 1][game->i] = 'P';
					game->new_map[game->j][game->i] = '0';
					if (game->new_map[game->j - 1][game->i] == 'C')
					{
						game->coli--;
					}
				}
				if (game->new_map[game->j - 1][game->i] == 'E' && game->coli == 0)
				{
					printf("win\n");
					exit(0);
				}
			}
			game->i++;
		}
		game->j++;
	}
}

void ft_down(t_game *game)
{
	int flag=0;
	game->j = 0;
	game->i = 0;
	while (game->new_map[game->j])
	{
		game->i = 0;
		while(game->new_map[game->j][game->i])
		{
			if (game->new_map[game->j][game->i] == 'P')
			{
				if (game->new_map[game->j + 1][game->i] == '0' || game->new_map[game->j + 1][game->i] == 'C')
				{
					game->new_map[game->j + 1][game->i] = 'P';
					game->new_map[game->j][game->i] = '0';
					if (game->new_map[game->j + 1][game->i] == 'C')
					{
						game->coli--;
					}
					flag=1;
					break;
				}
				if (game->new_map[game->j + 1][game->i] == 'E' && game->coli == 0)
				{
					printf("win\n");
					exit(0);
				}
			}
			if (flag==1)
				break;
			game->i++;
		}
		game->j++;
	}
}

void ft_right(t_game *game)
{
	int flag=0;
	game->j = 0;
	game->i = 0;
	while (game->new_map[game->j])
	{
		game->i = 0;
		while(game->new_map[game->j][game->i])
		{
			if (game->new_map[game->j][game->i] == 'P')
			{
				if (game->new_map[game->j][game->i +1] == '0' || game->new_map[game->j][game->i + 1] == 'C')
				{
					game->new_map[game->j][game->i + 1] = 'P';
					game->new_map[game->j][game->i] = '0';
					if (game->new_map[game->j][game->i + 1] == 'C')
					{
						game->coli--;
					}
					flag = 1;
					break;
			}
			if (game->new_map[game->j][game->i + 1] == 'E' && game->coli == 0)
			{
				printf("win\n");
				exit(0);
			}
			}
			if (flag==1)
				break;
			game->i++;
		}
		game->j++;
	}
}

void ft_left(t_game *game)
{
	game->j = 0;
	game->i = 0;
	while (game->new_map[game->j])
	{
		game->i = 0;
		while(game->new_map[game->j][game->i])
		{
			if (game->new_map[game->j][game->i] == 'P')
			{
				if (game->new_map[game->j][game->i - 1] == '0' || game->new_map[game->j][game->i - 1] == 'C')
				{
					game->new_map[game->j][game->i - 1] = 'P';
					game->new_map[game->j][game->i] = '0';
					if (game->new_map[game->j][game->i - 1] == 'C')
					{
						game->coli--;
					}
				}
				if (game->new_map[game->j][game->i - 1] == 'E' && game->coli == 0)
				{
					printf("win\n");
					exit(0);
				}
			}
			game->i++;
		}
		game->j++;
	}
}