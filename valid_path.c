#include "./so_long.h"

int check_surrounding(t_game *game, int posY, int posX)
{
    if ((game->path_map[posX - 1][posY] != '1' && game->path_map[posX - 1][posY] != 'P')
        || (game->path_map[posX + 1][posY] != '1' && game->path_map[posX + 1][posY] != 'P')
        || (game->path_map[posX][posY - 1] != '1' && game->path_map[posX][posY - 1] != 'P')
        || (game->path_map[posX][posY + 1] != '1' && game->path_map[posX][posY + 1] != 'P'))
        return (0);
    return (1);
}

int check_p(t_game *game)
{
    int i = 0;
    while (game->path_map && game->path_map[i])
    {
        int j = 0;
        while (game->path_map[i][j])
        {
            if (game->path_map[i][j] == 'P')
            {
                if (check_surrounding(game, j, i) == 0)
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

void    fill_p(t_game *game, int posY, int posX)
{
    if (game->path_map[posX - 1][posY] != '1')
        game->path_map[posX - 1][posY] = 'P';

    if (game->path_map[posX + 1][posY] != '1')
        game->path_map[posX + 1][posY] = 'P';

    if (game->path_map[posX][posY - 1] != '1')
        game->path_map[posX][posY - 1] = 'P';

    if (game->path_map[posX][posY + 1] != '1')
        game->path_map[posX][posY + 1] = 'P';
}

void    find_P(t_game *game)
{
    int i = 0;

    while (game->path_map && game->path_map[i])
    {
        int j = 0;
        while (game->path_map[i][j])
        {
            if (game->path_map[i][j] == 'P')
            {
                fill_p(game, j, i);
            }
            j++;
        }
        i++;
    }
}

int    valid_path(t_game *game)
{
    while (check_p(game) == 0)
    {
        find_P(game);
    }
    int i = 0;
    while (game->path_map && game->path_map[i])
    {
        int j = 0;
        while (game->path_map[i][j])
        {
            if (game->path_map[i][j] == 'C' || game->path_map[i][j] == 'E')
            {
                return(0);
            }
            j++;
        }
        i++;
    }
    return(1);
}