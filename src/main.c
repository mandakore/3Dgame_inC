/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:12:08 by atashiro          #+#    #+#             */
/*   Updated: 2025/10/04 19:15:25 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


void	free_all(t_game game, char **map, size_t i)
{
	while (i > 0)
		free(map[--i]);
	free(map);
	mlx_clear_window(game.mlx_ptr, game.win_ptr);
	mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);
}

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_game *game)
{

	if (keysym == XK_Escape)
	{
		close_window(game);
		return (0);
	}
	//キーハンドラを記述
	return (0);
}

void	start_game_loop(t_game *game)
{
	mlx_hook(game->win_ptr, E_KEY_PRESS, M_KEY_PRESS, handle_keypress, game);
	mlx_hook(game->win_ptr, E_WIN_CLOSE, M_WIN_RESIZE, close_window, game);
	// mlx_hook(game->win_ptr, E_WIN_RESIZE, M_WIN_CLOSE, minimize_window, game);
	mlx_loop(game->mlx_ptr);
	free_all(*game, game->map.map, game->map.height);
}

int	main(int argc, char **argv)
{

	(void) argc;
	(void) argv;

	t_game	game;

	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 800, 600, "cub3D"); //可変？
	start_game_loop(&game);
}