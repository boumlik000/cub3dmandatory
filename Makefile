CC = cc
NAME = cube3d

CFLAGS = -Wall -Wextra -Werror -g3  #-fsanitize=address
source =   cube.c  utils/get_next_line.c utils/ft_strjoin.c\
			utils/utils1.c utils/utils2.c collectore.c color.c textur.c\
			tools_parse.c parse1.c parse2.c render.c initiale.c  trancp.c\
			make_3d.c make_3d1.c make_3d2.c edit_final_map.c\
			collectore_image.c hook.c drawing.c\
			movment_player.c turn.c draw_sky_walls_flower.c

obj = $(source:.c=.o)

all:$(NAME)

#-lSDL2
$(NAME): $(obj)
	$(CC) $(CFLAGS) $(obj) -fPIE -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz  -lSDL2 -o $(NAME)

clean	:
	rm -fr $(obj) 
fclean	: clean
	rm -fr $(NAME)

re: fclean all

.SECONDARY : $(obj) 
