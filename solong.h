/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soLong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeorgel <egeorgel@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:15:20 by egeorgel          #+#    #+#             */
/*   Updated: 2022/12/18 15:55:16 by egeorgel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SOLONG_H
# define SOLONG_H
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct s_frames{
	void **images;
	void **addr;
	int *bits_per_pixel;
	int *line_size;
	int *endian;
	int width;
	int *height;
	int	frame_iteration;
	int animation_speed;
	int max_frame;
} 	t_frames;

typedef struct s_player{
	t_frames walk_S;
	t_frames walk_E;
	t_frames walk_W;
	t_frames walk_N;
	t_frames stand_S;
	t_frames stand_E;
	t_frames stand_W;
	t_frames stand_N;
	t_frames shadow;
	t_frames last_direction;
	t_frames last_frame;
} 	t_player;

typedef struct s_map{
	char **map;
	bool **tried;
	int collectibles_nbr;
	int size_x;
	int size_y;
	t_frames grass;
	t_frames barrier;
	t_frames vertical_barrier;
	t_frames barrier_stick;
	t_frames teleport_off;
	t_frames teleport_on;
	t_frames collectible;
	t_frames border;
}	t_map;

typedef struct s_input{
    bool W_pressed;
    bool A_pressed;
    bool S_pressed;
    bool D_pressed;
}	t_input;

typedef struct s_data {
	t_input inputs;
    t_player player_imgs;
	t_map map;
    void *mlx;
    void *mlx_win;
	int window_x;
	int window_y;
	int player_x;
	int player_y;
	int move_x;
	int move_y;
}   t_data;

char *my_strjoin(char *s1, char *s2, bool free_s1, bool free_s2);
char *file_path(char *action, char *direction, int iteration);
void get_images(t_data *game);
int	check_file_type(const char *haystack, const char *needle);
t_map is_map_valid(char *map_path);
char	*get_next_line(int fd);
void	parsing_error(char **map, int x, int y);
void	check_path(t_map *map);
void screen_border(t_data *game, t_frames *border);
void malloc_img(t_frames *frames, int i);
void free_img(t_frames *frames);
int	upper_multiple_of_48(int nbr);
void get_movement(t_data *game);
void start_position(t_data *game);

#endif