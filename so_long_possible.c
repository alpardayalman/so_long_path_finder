#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_game {
	char			**map; // Your own map.
	size_t			width; // The width of your map.
	size_t			height; // The height of your map.
	size_t			coin; // Collectible
	size_t			player_x; // player pos X
	size_t			player_y; // player pos Y
	size_t			exit_is_possible; // You need to add this to your own struct (Kendi struct'una eklemeyi unutma)
}	t_game;

void	free_map(char **map, size_t height) // Free the map, you can use your own.
{
	int	i;

	i = -1;
	while (++i < height)
		free(map[i]);
	free(map);
}
// Recursive manner, checks if it is possible to exit whilst collecting the collectible. (DFS search)
int	check_path(t_game *temp, size_t y, size_t x)
{
	if (temp->map[y][x] == '1')
		return (0);
	if (temp->map[y][x] == 'C')
		temp->coin--;
	if (temp->map[y][x] == 'E')
	{
		temp->exit_is_possible = 1;
		return (0);
	}
	temp->map[y][x] = '1';
	if (check_path(temp, y + 1, x))
		return (1);
	if (check_path(temp, y - 1, x))
		return (1);
	if (check_path(temp, y, x + 1))
		return (1);
	if (check_path(temp, y, x - 1))
		return (1);
	return (0);
}

void	flood_fill(t_game *game)
{
	t_game	temp;
	size_t	i;

	temp.height = game->height;
	temp.width = game->width;
	temp.coin = game->coin;
	temp.player_x = game->player_x;
	temp.player_y = game->player_y;
	temp.exit_is_possible = 0;
	temp.map = (char **)malloc(temp.height * sizeof(char *));
	if (!temp.map)
		return ;
	i = 0;
	while (i < temp.height)
	{
		temp.map[i] = strdup(game->map[i]);
		i++;
	}
	check_path(&temp, temp.player_y, temp.player_x);
	if (!(temp.exit_is_possible == 1 && temp.coin == 0)) // Check if the player could exit and all the coins are collected.
		printf("Faulty Map");
	else
		printf("Valid Map");
	free_map(temp.map, temp.height);
}


int main() {

	t_game *game = (t_game *)malloc(sizeof(t_game));
	// You should already get these values before. These are custom values depending on my custom map.
	game->coin = 2; // Number of collectible
	game->exit_is_possible = 0; // is exit possible
	game->height = 10; // height of map
	game->player_x = 10; // player x
	game->player_y = 6; // player y


	game->map = (char **)malloc(sizeof(char *) * 10); // Random map of choosing.
	game->map[0] = strdup("1111111111111111111111111");
	game->map[1] = strdup("1000000000000010000000001");
	game->map[2] = strdup("100001E000000010000000001");
	game->map[3] = strdup("1000010000000010000000001");
	game->map[4] = strdup("100001000C000010000000001");
	game->map[5] = strdup("1000010000000010000000001");
	game->map[6] = strdup("1000100000P00010000000001");
	game->map[7] = strdup("1000101001000011110C00001");
	game->map[8] = strdup("1000001000000010000000001");
	game->map[9] = strdup("1111111111111111111111111");

	game->width = strlen(game->map[0]);
	flood_fill(game);
	return 0;
}
