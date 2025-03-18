/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:10:40 by rlamtaou          #+#    #+#             */
/*   Updated: 2025/03/18 13:51:30 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <SDL2/SDL.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define WALL_SCALE 900.0
# define ROTATE 2
# define SPEED 5
# define MAIN_MENU 1
# define SCEN 1
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define NAME "Abyss"
# define BUFFER_SIZE 42

typedef struct colectore
{
	void				*ptr;
	struct colectore	*next;

}						t_colec;

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct s_img
{
	void				*img_ptr;
	char				*addr;
	int					h;
	int					w;
	int					bpp;
	int					endian;
	int					line_len;
}						t_img;

typedef struct s_player
{
	double				px;
	double				py;
	double				pa;
	double				pdx;
	double				pdy;

	double				angle;
	double				r;
	double				rx1;
	double				ry1;
}						t_player;

typedef struct variable
{
	char				**av;
	int					x;
	int					y;
	int					f_ln;
	int					last_ln;
	int					num;
	int					line;
	int					largline;
	void				*load;
	void				*check_img;
	int					width;
	int					height;
	int					fd;
	void				*main;
	void				*t;
	int					start;
	int					num_player;
	int					music_flag;

	int					flag;
	char				*map;
	int					current_frame;
	int					last_time;
	int					img_val;
	char				*img_serch;
	void				*frames_main_menu[MAIN_MENU];
	void				*frames_scean[SCEN];

	char				**end_map;
	char				**fn_map;

	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	int					f[3];
	int					c[3];

	t_img				img_no;
	t_img				img_so;
	t_img				img_we;
	t_img				img_ea;
	char				char_of_player;

	int					x_old_mouse;

	char				*paths_main_menu[MAIN_MENU];
	char				*paths_scen[SCEN];

	int					camera_on;
	int					key_rels_up;
	int					tex_x;
	int					tex_y;
	int					color;
	double				darkness;
	double				line_height;
	int					r;
	int					g;
	int					b;
	double				tex_pos;
	double				step;
	int					in1;
}						t_var;

typedef struct delta
{
	Uint32				last_time;
	float				delta_time;
	Uint32				current_time;

}						t_delta;

typedef struct s_img_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_img_data;

typedef struct s_keys
{
	int					key_up;
	int					key_down;
	int					key_left;
	int					key_right;
}						t_keys;
typedef struct cube
{
	t_var				var;
	t_colec				*list_collecte_head;
	t_colec				*list_img_head;
	void				*mlx_init;
	void				*mlx_win;
	t_player			p_info;

	t_img_data			render_img;

	t_data				imgs_red;
	t_data				imgs_blue;
	t_data				imgs_player;
	t_data				imgs_row;
	t_keys				keys;

	int					side;
	double				ray_dir_x;
	double				ray_dir_y;
	double				perp_wall_dist;

	// draw line dda()
	double				d_rad;
	double				d_ray_dir_x;
	double				d_ray_dir_y;
	int					d_map_x;
	int					d_map_y;
	double				d_delta_dist_x;
	double				d_delta_dist_y;
	int					d_step_x;
	int					d_step_y;
	double				d_side_dist_x;
	double				d_side_dist_y;
	int					d_hit;
	int					d_side;

	// draw 3d()
	int					x;
	double				ray_angle;
	double				perp_dist;
	double				angle_diff;

	t_delta				delta;
}						t_cube;

size_t					strln(const char *s);
char					*ft_strjoin(char *s1, char *s2, int free_s);
char					*get_next_line(int fd, t_cube *data);
char					*ft_strchr(const char *s, int c);
void					*ft_calloc(size_t nitems, size_t size);
char					*ft_itoa(int n);
int						is_white_space(char c);
char					*ft_strjoin_char(char *s1, char c);
void					ft_collectore(t_colec **list_head, void *ptr,
							char *str);
void					ft_lstclear_collec(t_colec **lst);
long					ft_atoi(const char *nptr);
void					find_c(t_cube *data);
void					find_f(t_cube *data);
void					findea(t_cube *data);
void					findwe(t_cube *data);
void					findso(t_cube *data);
void					findno(t_cube *data);
void					ft_exit_1(t_cube *data, int err);
int						cheak_name(t_cube *data, char *name, char *exten);
int						ft_exit(t_cube *data);
int						ft_larg_line(char *str, int x);
int						is_valid(char c);
void					ft_parse(t_cube *data);
void					map_check(t_cube *data);
void					check_map_is_double(char *str, int x, t_cube *data);
void					cheak_player(char *str, int x, t_cube *data);
void					creat_2d_map(t_cube *data);
void					first_line(t_cube *data);
void					middl_line(t_cube *data, int j);
void					last_line(t_cube *data);
void					cheak_wall(t_cube *data, int d, int s);
int						display_frame(t_cube *data);

void					upload_files(t_cube *data);
void					inite(t_cube *data);
void					destroy_main_menu(t_cube *data);
void					edit_final_map(t_cube *data);
void					ft_lstclear_collec_img(t_colec **lst, t_cube *data);
void					ft_lstdelone_collec_img(t_colec *lst, t_cube *data);
void					cheak_load_img(t_cube *data, char *img);
void					init_image(t_cube *data);

void					draw_block(t_data *imgs, int color);
void					draw_map(t_cube *data);

void					put_pixel_img(t_img img, int x, int y, int color);
unsigned int			get_pixel_img(t_img img, int x, int y);
void					put_img_to_img(t_img dst, t_img src, int x, int y);
t_img					new_img(int w, int h, t_cube *data);
t_img					new_file_img(char *path, t_cube *data);

void					turn_player_right(t_cube *data);

void					turn_player_left(t_cube *data);

void					move_player_right(t_cube *data);

void					move_player_left(t_cube *data);

void					move_player_down(t_cube *data);
void					move_player_up(t_cube *data);
void					my_mlx_pixel_put2(t_img_data *img, int x, int y,
							int color);
int						valid_move(t_cube *data, int xx, int yy, char c);
void					render_3d_walls(t_cube *data);
int						key_release(int keycode, t_cube *data);
int						mouse_move(int x, int y, t_cube *data);
int						key_press(int keycode, t_cube *data);
int						mouse_click(int button, int x, int y, t_cube *data);
void					draw_player(t_data *imgs, int color);
void					draw_walls(t_cube *data, double wall_top,
							double wall_bottom, int x);
void					draw_flower(t_cube *data, double wall_bottom, int x);
void					draw_sky(t_cube *data, double wall_top, int x);
int						calculate_x(t_cube *data, t_img texture);
void					put_image_whit_dark(t_cube *data, int x, int y);
void					my_mlx_pixel_put2(t_img_data *img, int x, int y,
							int color);
void					calculate_step_dist_y(t_cube *data, double y1);
void					calculate_step_dist(t_cube *data, double x1);
void					init_ray_values(t_cube *data, double x1, double y1,
							double angle);
int						get_map_height(char **map);
void					calculate_perp_dist(t_cube *data, double x1, double y1);
void					draw_vertical_line(t_cube *data, int x);
int						check_wall(t_cube *data, int x, int y);
void					move_player_up(t_cube *data);
void					update_player_position(t_cube *data, double old_x,
							double old_y);
void					move_player_down(t_cube *data);
int						check_move_condition(t_cube *data, double new_x,
							double new_y, double old_x);
void					move_player_left_x(t_cube *data, double new_x,
							double new_y, double old_x);

#endif
