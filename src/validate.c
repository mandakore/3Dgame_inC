/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atashiro <atashiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:57:51 by atashiro          #+#    #+#             */
/*   Updated: 2025/10/06 17:37:41 by atashiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// --- プロトタイプ宣言 ---

int			is_valid_map(const char *file_path);

// .cub拡張子を持っているか確認する
// static int	has_cub_extension(const char *file_path)
// {
// 	const char	*ext;

// 	ext = ft_strrchr(file_path, '.');
// 	if (!ext || ft_strcmp(ext, ".cub") != 0)
// 	{
// 		write(2, "Error: File must have a .cub extension.\n", 40);
// 		return (0);
// 	}
// 	return (1);
// }

static int	has_cub_extension(const char *file_path)
{
	size_t	name_len;
	const char	*filename;

	filename = ft_strrchr(file_path, '/');
	if (filename)
		filename++;
	else
		filename = file_path;
	name_len = ft_strlen(filename);
	if (name_len <= 4
		|| ft_strncmp(filename + name_len - 4, ".cub", 4) != 0
		|| name_len == 4)
	{
		write(2, "Error: File must have a .cub extension.\n", 40);
		return (0);
	}
	return (1);
}

// テクスチャパスの形式を検証する
static int	is_valid_texture(const char *line)
{
	char	*path;

	path = ft_strchr(line, ' ');
	if (!path || *(path + 1) == '\0' || *(path + 1) == '\n')
	{
		write(2, "Error: Invalid texture path.\n", 29);
		return (0);
	}
	return (1);
}

// 色情報の形式と範囲を検証する
static int	is_valid_color(const char *line)
{
	char	**rgb_values;
	int		r;
	int		g;
	int		b;
	int		i;

	rgb_values = ft_split(line + 1, ',');
	if (!rgb_values || !rgb_values[0] || !rgb_values[1] || !rgb_values[2] || rgb_values[3])
	{
		write(2, "Error: Invalid color format.\n", 29);
		return (0);
	}
	r = ft_atoi(rgb_values[0]);
	g = ft_atoi(rgb_values[1]);
	b = ft_atoi(rgb_values[2]);
	i = 0;
	while (rgb_values[i])
		free(rgb_values[i++]);
	free(rgb_values);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		write(2, "Error: Color values must be in the range [0, 255].\n", 52);
		return (0);
	}
	return (1);
}

// マップの文字が有効か、プレイヤーが何人いるか検証する
static int	validate_map_content(char **map, int height, int *player_count)
{
	int	y;
	int	x;

	y = 0;
	*player_count = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (!ft_strchr(" 01NSEW", map[y][x]))
			{
				write(2, "Error: Invalid character in map.\n", 33);
				return (0);
			}
			if (ft_strchr("NSEW", map[y][x]))
				(*player_count)++;
			x++;
		}
		y++;
	}
	if (*player_count != 1)
	{
		write(2, "Error: Multiple or no player starting positions.\n", 49);
		return (0);
	}
	return (1);
}

// マップが壁で囲まれているか検証する
static int	is_enclosed_by_walls(char **map, int height)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (ft_strchr("0NSEW", map[y][x]))
			{
				if (y == 0 || y == height - 1 || x == 0 || !map[y][x + 1] || \
					map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || \
					map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
				{
					write(2, "Error: Map is not surrounded by walls.\n", 39);
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}


// --- メイン検証関数 ---

int	is_valid_map(const char *file_path)
{
	int		fd;
	char	*line;
	int		elements[6] = {0}; // NO, SO, WE, EA, F, C
	char	**map_buffer;
	int		map_height;
	int		player_count;

	if (!has_cub_extension(file_path))
		return (0);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}

	map_height = 0;
	map_buffer = NULL;
	line = get_next_line(fd);
	while (line)
	{
        // 必須要素の検証
		if (ft_strncmp(line, "NO ", 3) == 0 && is_valid_texture(line)) elements[0]++;
		else if (ft_strncmp(line, "SO ", 3) == 0 && is_valid_texture(line)) elements[1]++;
		else if (ft_strncmp(line, "WE ", 3) == 0 && is_valid_texture(line)) elements[2]++;
		else if (ft_strncmp(line, "EA ", 3) == 0 && is_valid_texture(line)) elements[3]++;
		else if (ft_strncmp(line, "F ", 2) == 0 && is_valid_color(line)) elements[4]++;
		else if (ft_strncmp(line, "C ", 2) == 0 && is_valid_color(line)) elements[5]++;
		else if (line[0] != '\n') // マップデータとして処理
		{
			map_buffer = (char **)realloc(map_buffer, sizeof(char *) * (map_height + 1));
			map_buffer[map_height++] = ft_strdup(line);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);

	// 最終検証
	int i = 0;
	while (i < 6)
	{
		if (elements[i] != 1)
		{
			write(2, "Error: Missing or duplicate required element.\n", 46);
			return (0);
		}
		i++;
	}

	if (!map_buffer || !validate_map_content(map_buffer, map_height, &player_count) || !is_enclosed_by_walls(map_buffer, map_height))
	{
		i = 0;
		while(i < map_height) free(map_buffer[i++]);
		free(map_buffer);
		return (0);
	}
	i = 0;
	while(i < map_height) free(map_buffer[i++]);
	free(map_buffer);
	return (1);
}

// --- テスト用メイン関数 ---
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <map_file.cub>\n", argv[0]);
		return (1);
	}

	if (is_valid_map(argv[1]))
	{
		printf("\033[36mMap '%s' is OK!!!!!!!!!!!!!.\n", argv[1]);
	}
	else
	{
		printf("Map '%s' is invalid.\n", argv[1]);
	}

	return (0);
}